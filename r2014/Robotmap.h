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
#define FLDRIVE 1
#define FRDRIVE 2
#define BLDRIVE 3
#define BRDRIVE 4
#define FLSTEER 5
#define FRSTEER 6
#define BLSTEER 7
#define BRSTEER 8

//Analog Inputs
#define FLENCODER 1
#define FRENCODER 2
#define BLENCODER 3
#define BRENCODER 4

#endif
