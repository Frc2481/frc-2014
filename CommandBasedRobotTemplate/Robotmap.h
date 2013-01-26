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

// PWM Channels
#define LEFT_DRIVE_MOTOR		1
#define RIGHT_DRIVE_MOTOR		2
#define SHOOTER_MOTOR 			3
#define ARM_LIFT_MOTOR			4
#define ROBOT_LIFT_MOTOR		5

// Digital Input Channels
#define LEFT_DRIVE_ENCODER_A	1
#define LEFT_DRIVE_ENCODER_B 	2
#define RIGHT_DRIVE_ENCODER_A 	3
#define RIGHT_DRIVE_ENCODER_B 	4
#define SHOOTER_ENCODER_A 		5
#define SHOOTER_ENCODER_B		6
#define LOWER_ARM_SENSOR		7
#define UPPER_ARM_SENSOR		8
#define COMPRESSOR_SENSOR		9
#define RIGHT_HOOK_MAGNET		10
#define LEFT_HOOK_MAGNET		11
#define LIFT_ROBOT_SENSOR		12

// Solenoid Channels
#define LEFT_DRIVE_SOLENOID 	1
#define RIGHT_DRIVE_SOLENOID	2
#define HOPPER_SOLENOID 		2
#define SHOOTER_LIFT_SOLENOID	3
#define ROBOT_LIFT_SOLENOID		4
#define LOCK_HOOK_SOLENOID		5
#define UNLOCK_HOOK_SOLENOID	6

// Analog Input Channels
#define ARM_EXTENSION_SENSOR	1


#define	COMPRESSOR_SPIKE		1

#endif
