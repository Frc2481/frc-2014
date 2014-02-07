#ifndef ROBOTMAP_H
#define ROBOTMAP_H


/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
 
// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
// #define LEFTMOTOR 1
// #define RIGHTMOTOR 2

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// #define RANGE_FINDER_PORT 1
// #define RANGE_FINDER_MODULE 1

//Motors
#define FRDRIVE 1
#define FRSTEER 2
#define BRDRIVE 7
#define BRSTEER 8
#define BLDRIVE 5
#define BLSTEER 6
#define FLDRIVE 3
#define FLSTEER 4
#define WINCH 9
#define INTAKE 10

//Solenoids
#define EARS 1
#define RELEASE 2
#define READY 3
#define CAPTURE 4

//Analog Inputs
#define GYRO_CHANNEL 1
#define FRENCODER 2
#define BLENCODER 3
#define BRENCODER 4
#define FLENCODER 5
#define WINCH_SENSOR 6
#define ULTRASONIC_RIGHT 7
#define ULTRASONIC_LEFT 8

//Digital Inputs
#define POT_SWITCH 1


//Module Number
#define COMPASS_MODULE 1

#define COMPASS_ADDRESS 0x3b
#define WIIGYRO_ADDRESS 0

#endif
