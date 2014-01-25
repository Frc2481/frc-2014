#include "LSM303.h"

#include <math.h>
#include "../RobotParameters.h"
#include "../Robotmap.h"
// Defines ////////////////////////////////////////////////////////////////

// The Arduino two-wire interface uses a 7-bit number for the address,
// and sets the last bit correctly based on reads and writes
#define D_SA0_HIGH_ADDRESS              0x1d // D with SA0 high
#define D_SA0_LOW_ADDRESS               0x1e // D with SA0 low or non-D magnetometer
#define NON_D_MAG_ADDRESS               0x1e // D with SA0 low or non-D magnetometer
#define NON_D_ACC_SA0_LOW_ADDRESS       0x18 // non-D accelerometer with SA0 low
#define NON_D_ACC_SA0_HIGH_ADDRESS      0x19 // non-D accelerometer with SA0 high

#define TEST_REG_NACK -1

#define D_WHO_ID    0x49
#define DLM_WHO_ID  0x3C

// Constructors ////////////////////////////////////////////////////////////////

LSM303::LSM303(uint8_t moduleNumber)
{
  /*
  These values lead to an assumed magnetometer bias of 0.
  Use the Calibrate example program to determine appropriate values
  for your particular unit. The Heading example demonstrates how to
  adjust these values in your own sketch.
  */
  m_min = (LSM303::vector<int16_t>){-32767, -32767, -32767};
  m_max = (LSM303::vector<int16_t>){+32767, +32767, +32767};
  _dev = DigitalModule::GetInstance(moduleNumber)->GetI2C(COMPASS_ADDRESS);
  
}
/*
Enables the LSM303's accelerometer and magnetometer. Also:
- Sets sensor full scales (gain) to default power-on values, which are
  +/- 2 g for accelerometer and +/- 1.3 gauss for magnetometer
  (+/- 4 gauss on LSM303D).
- Selects 50 Hz ODR (output data rate) for accelerometer and 7.5 Hz
  ODR for magnetometer (6.25 Hz on LSM303D). (These are the ODR
  settings for which the electrical characteristics are specified in
  the datasheets.)
- Enables high resolution modes (if available).
Note that this function will also reset other settings controlled by
the registers it writes to.
*/
bool LSM303::init()
{
	if (_dev->AddressOnly())
		return false;
	
    // Accelerometer

    // 0x57 = 0b01010111
    // AFS = 0 (+/- 2 g full scale)
    writeReg(CTRL2, 0x00);

    // 0x57 = 0b01010111
    // AODR = 0101 (50 Hz ODR); AZEN = AYEN = AXEN = 1 (all axes enabled)
    writeReg(CTRL1, 0x57);

    // Magnetometer

    // 0x64 = 0b01100100
    // M_RES = 11 (high resolution mode); M_ODR = 001 (6.25 Hz ODR)
    writeReg(CTRL5, 0x64);

    // 0x20 = 0b00100000
    // MFS = 01 (+/- 4 gauss full scale)
    writeReg(CTRL6, 0x20);

    // 0x00 = 0b00000000
    // MLP = 0 (low power mode off); MD = 00 (continuous-conversion mode)
    writeReg(CTRL7, 0x00);
    
    return true;
}

// Writes an accelerometer register
void LSM303::writeAccReg(regAddr reg, byte value)
{  
  _dev->Write(reg, value);
}

// Reads an accelerometer register
byte LSM303::readAccReg(regAddr reg)
{
  byte value;

  _dev->Read(reg, 1, &value);
  return value;
}

// Writes a magnetometer register
void LSM303::writeMagReg(regAddr reg, byte value)
{
  _dev->Write(reg, value);
}

// Reads a magnetometer register
byte LSM303::readMagReg(regAddr reg)
{
  byte value;

  _dev->Read(reg, 1, &value);

  return value;
}

void LSM303::writeReg(regAddr reg, byte value)
{
    writeMagReg(reg, value);
}

// Reads the 3 accelerometer channels and stores them in vector a
void LSM303::readAcc(void)
{

  byte xla, xha, yla, yha, zla, zha;
  
  _dev->Read(OUT_X_L_A, 1, &xla);
  _dev->Read(OUT_X_H_A, 1, &xha);
  _dev->Read(OUT_Y_L_A, 1, &yla);
  _dev->Read(OUT_Y_H_A, 1, &yha);
  _dev->Read(OUT_Z_L_A, 1, &zla);
  _dev->Read(OUT_Z_H_A, 1, &zha);

  // combine high and low bytes
  // This no longer drops the lowest 4 bits of the readings from the DLH/DLM/DLHC, which are always 0
  // (12-bit resolution, left-aligned). The D has 16-bit resolution
  a.x = (int16_t)(xha << 8 | xla);
  a.y = (int16_t)(yha << 8 | yla);
  a.z = (int16_t)(zha << 8 | zla);
}

// Reads the 3 magnetometer channels and stores them in vector m
void LSM303::readMag(void)
{

  byte xlm, xhm, ylm, yhm, zlm, zhm;

    /// D: X_L, X_H, Y_L, Y_H, Z_L, Z_H
   _dev->Read(D_OUT_X_L_M, 1, &xlm);
   _dev->Read(D_OUT_X_H_M, 1, &xhm);
   _dev->Read(D_OUT_Y_L_M, 1, &ylm);
   _dev->Read(D_OUT_Y_H_M, 1, &yhm);
   _dev->Read(D_OUT_Z_L_M, 1, &zlm);
   _dev->Read(D_OUT_Z_H_M, 1, &zhm);

  // combine high and low bytes
  m.x = (int16_t)(xhm << 8 | xlm);
  m.y = (int16_t)(yhm << 8 | ylm);
  m.z = (int16_t)(zhm << 8 | zlm);
}

// Reads all 6 channels of the LSM303 and stores them in the object variables
void LSM303::read(void)
{
  readAcc();
  readMag();
}

/*
Returns the angular difference in the horizontal plane between a
default vector and north, in degrees.

The default vector here is chosen to point along the surface of the
PCB, in the direction of the top of the text on the silkscreen.
This is the +X axis on the Pololu LSM303D carrier and the -Y axis on
the Pololu LSM303DLHC, LSM303DLM, and LSM303DLH carriers.
*/
float LSM303::heading(void)
{
    return heading((vector<int>){1, 0, 0});
}

/*
Returns the angular difference in the horizontal plane between the
"from" vector and north, in degrees.

Description of heading algorithm:
Shift and scale the magnetic reading based on calibration data to find
the North vector. Use the acceleration readings to determine the Up
vector (gravity is measured as an upward acceleration). The cross
product of North and Up vectors is East. The vectors East and North
form a basis for the horizontal plane. The From vector is projected
into the horizontal plane and the angle between the projected vector
and horizontal north is returned.
*/
template <typename T> float LSM303::heading(vector<T> from)
{
    vector<int32_t> temp_m = {m.x, m.y, m.z};

    // subtract offset (average of min and max) from magnetometer readings
    temp_m.x -= ((int32_t)m_min.x + m_max.x) / 2;
    temp_m.y -= ((int32_t)m_min.y + m_max.y) / 2;
    temp_m.z -= ((int32_t)m_min.z + m_max.z) / 2;

    // compute E and N
    vector<float> E;
    vector<float> N;
    vector_cross(&temp_m, &a, &E);
    vector_normalize(&E);
    vector_cross(&a, &E, &N);
    vector_normalize(&N);

    // compute heading
    float heading = atan2(vector_dot(&E, &from), vector_dot(&N, &from)) * 180 / M_PI;
    if (heading < 0) heading += 360;
    return heading;
}

template <typename Ta, typename Tb, typename To> void LSM303::vector_cross(const vector<Ta> *a,const vector<Tb> *b, vector<To> *out)
{
  out->x = (a->y * b->z) - (a->z * b->y);
  out->y = (a->z * b->x) - (a->x * b->z);
  out->z = (a->x * b->y) - (a->y * b->x);
}

template <typename Ta, typename Tb> float LSM303::vector_dot(const vector<Ta> *a, const vector<Tb> *b)
{
  return (a->x * b->x) + (a->y * b->y) + (a->z * b->z);
}

void LSM303::vector_normalize(vector<float> *a)
{
  float mag = sqrt(vector_dot(a, a));
  a->x /= mag;
  a->y /= mag;
  a->z /= mag;
}
