#include "organiz/organize.h"
#include "main.h"


// Drivetrain constructor

pros::IMU inertial(5);

ez::Drive chassis(
    // These are your drive motors, the first motor is used for sensing! 
    //BACK TO FRONT
    {-10, -9, -8},     // Left Chassis Ports (negative port will reverse it!)
    {1, 2, 3},  // Right Chassis Ports (negative port will reverse it!

    inertial.get_port(),      // IMU Port
    3.25,  // Wheel Diameter (Remember, 4" wheels without screw holes are actually 4.125!)

    // External Gear Ratio (MUST BE DECIMAL) This is WHEEL GEAR / SENSOR GEAR
    // eg. if your drive is 84:36 where the 36t is sensored, your RATIO would be 84/36 which is 2.333
    // eg. if your drive is 36:60 where the 60t is sensored, your RATIO would be 36/60 which is 0.6
    1.66,

    -9,  // Left Rotation Port (negative port will reverse it!)
    2 // Right Rotation Port (negative port will reverse it!)
); 


// using namespace okapi;


// Define the chassis configuration
/*auto drive = ChassisControllerBuilder()
    .withMotors({-1, -5, -18}, {10, 7, 20}) // Left and right motors
    .withDimensions(AbstractMotor::gearset::blue, {{4_in, 10_in}, imev5GreenTPR})
    .withOdometry({{2.75_in, 7_in}, quadEncoderTPR}, StateMode::CARTESIAN)
    .withSensors(leftencoder, rightencoder)
    .buildOdometry(); 
*/

using namespace pros;
// okapi::Motor intake1(6);
// okapi::Motor intake2(7);
pros::v5::MotorGroup intake({6, 7});
// okapi::MotorGroup intake({intake1, intake2});
ez::Piston intakePiston(0); //true is down
ez::Piston backClamp(6); // true is down
ez::Piston doinkerRight(5); // true is down
ez::Piston doinkerLeft(4);


/*

*/
pros::Motor ladybrown(14);

/*
ladybrown is geared 6:36, so all angle degrees from sensor should be x6
sensor is reversed in init
*/
pros::Rotation ladyBrownSensor(20);
// pros::Optical color_checker(3);

pros::Controller master (CONTROLLER_MASTER);