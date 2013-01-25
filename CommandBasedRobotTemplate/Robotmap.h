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

#define LEFT_DRIVE_MOTOR		1
#define RIGHT_DRIVE_MOTOR		2
#define LEFT_DRIVE_ENCODER_A	1
#define LEFT_DRIVE_ENCODER_B 	2
#define RIGHT_DRIVE_ENCODER_A 	3
#define RIGHT_DRIVE_ENCODER_B 	4
#define LEFT_DRIVE_SOLENOID 	1
#define RIGHT_DRIVE_SOLENOID	2

#define SHOOTER_MOTOR 			3
#define HOPPER_SOLENOID 		2
#define SHOOTER_ENCODER_A 		5
#define SHOOTER_ENCODER_B		6
#define SHOOTER_LIFT_SOLENOID	3
#define ROBOT_LIFT_SOLENOID		4
#define COMPRESSOR_SENSOR		7
#define	COMPRESSOR_SPIKE		1

#endif
