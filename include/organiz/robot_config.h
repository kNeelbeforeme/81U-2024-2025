#ifndef ROBOT_CONFIG
#define ROBOT_CONFIG
#include "main.h"

extern ez::Drive chassis;
extern pros::Controller master;
// extern pros::MotorGroup intake;

extern pros::Motor intake;
extern ez::Piston backClamp;
extern ez::Piston intakePiston;

extern pros::Motor ladybrown;
extern ez::Piston doinkerLeft;
extern ez::Piston doinkerRight; // true is down
extern pros::IMU inertial;
extern pros::Rotation ladyBrownSensor;
extern pros::Optical color_checker;

#endif //ROBOT_CONFIG