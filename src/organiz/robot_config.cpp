#include "organiz/organize.h"
#include "main.h"

using namespace pros;
pros::v5::Motor intake(-10);
// pros::v5::MotorGroup intake({6, 7});
ez::Piston intakePiston(0); //true is down
ez::Piston backClamp('c'); // true is down
ez::Piston doinkerRight('a'); // true is down
ez::Piston doinkerLeft('e'); // true is down


//16 IS A BAD PORT ITS BAD

pros::v5::Motor ladybrown(3, pros::v5::MotorGears::red, pros::v5::MotorEncoderUnits::degrees);

Rotation ladyBrownSensor(-9);
// pros::Optical color_checker(3);

Controller master (CONTROLLER_MASTER);
// Drivetrain constructor

IMU inertial(16);

ez::Drive chassis(
    // These are your drive motors, the first motor is used for sensing! 
    //BACK TO FRONT
    {-18, -19, -20},     // Left Chassis Ports (negative port will reverse it!)
    {13, 12, 11},  // Right Chassis Ports (negative port will reverse it!

    inertial.get_port(),      // IMU Port
    3.25,  // Wheel Diameter (Remember, 4" wheels without screw holes are actually 4.125!)
    450);   // Wheel RPM



// using namespace okapi;


// Define the chassis configuration
/*auto drive = ChassisControllerBuilder()
    .withMotors({-1, -5, -18}, {10, 7, 20}) // Left and right motors
    .withDimensions(AbstractMotor::gearset::blue, {{4_in, 10_in}, imev5GreenTPR})
    .withOdometry({{2.75_in, 7_in}, quadEncoderTPR}, StateMode::CARTESIAN)
    .withSensors(leftencoder, rightencoder)
    .buildOdometry(); 
*/
