#include "main.h"

/////
// For installation, upgrading, documentations, and tutorials, check out our website!
// https://ez-robotics.github.io/EZ-Template/
/////

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
bool AreBlue = true;

void initialize() {
  // Initialize the LCD
	pros::lcd::initialize();
  chassis.initialize();
  inertial.reset(true);
  master.rumble(".");


  ladyBrownSensor.reset();
  // ladyBrownSensor.set_reversed(true);
  ladyBrownSensor.reset_position();
  ladybrown.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	// pros::lcd::register_btn1_cb([]{sunaiControls != sunaiControls});


  // Print our branding over your terminal :D
  ez::ez_template_print();
  pros::delay(500); // Stop the user from doing anything while legacy ports configure
    
  // Configure your chassis controls
  chassis.opcontrol_curve_buttons_toggle(false); // Enables modifying the controller curve with buttons on the joysticks
  chassis.opcontrol_drive_activebrake_set(0); // Sets the active brake kP. We recommend 2.
  chassis.opcontrol_curve_default_set(0, 0); // Defaults for curve. If using tank, only the first parameter is used. (Comment this line out if you have an SD card!)  
  default_constants(); // Set the drive to your own constants from autons.cpp!

  // These are already defaulted to these buttons, but you can change the left/right curve buttons here!
  // chassis.opcontrol_curve_buttons_left_set(pros::E_CONTROLLER_DIGITAL_LEFT, pros::E_CONTROLLER_DIGITAL_RIGHT);  // If using tank, only the left side is used.
  // chassis.opcontrol_curve_buttons_right_set(pros::E_CONTROLLER_DIGITAL_Y, pros::E_CONTROLLER_DIGITAL_A);

  // make team switch with center button
  pros::Task switchTeams([]{
    while (true) {
      if ((pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1) {
        AreBlue = !AreBlue;
      }
      if (AreBlue) {
        pros::lcd::set_text(3, "BLUE TEAM");
      } else {
        pros::lcd::set_text(3, "RED TEAM");
      }
      pros::delay(ez::util::DELAY_TIME);
    }
  });

  // Autonomous Selector using LLEMU
  ez::as::auton_selector.autons_add({

    Auton("BLUE RING SIDE", blue_ring_rush),
    Auton("BLUE GOAL SIDE", blue_goal_rush),
    // Auton("BLUE DISRUPTOR", blue_disruptor),
    Auton("RED RING SIDE CODE", red_ring_rush),
    Auton("RED GOAL SIDE CODE", red_goal_rush),

    Auton("SKILLS CODE", skills_code),

    // Auton("RED DISRUPTOR", red_disruptor),
    Auton("SIMPLE LEFT SIDE", simple_left),
    Auton("SIMPLE RIGHT SIDE", simple_right),

    Auton("drive example", drive_example),

      // Auton("Example Turn\n\nTurn 3 times.", turn_example),
      // Auton("Drive and Turn\n\nDrive forward, turn, come back. ", drive_and_turn),
      // Auton("Drive and Turn\n\nSlow down during drive.", wait_until_change_speed),
      // Auton("Swing Example\n\nSwing in an 'S' curve", swing_example),
      // Auton("Motion Chaining\n\nDrive forward, turn, and come back, but blend everything together :D", motion_chaining),
      // Auton("Combine all 3 movements", combining_movements),
      // Auton("Interference\n\nAfter driving forward, robot performs differently if interfered or not.", interfered_example),
    Auton("DO NOTHING \n THIS CODE STAYS STILL AND DOES NOTHING", do_nothing)

    
  });

  // Initialize chassis and auton selector

  ladybrown.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  ez::as::initialize();
  master.rumble("...");
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
  // . . .

}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
  // . . .
}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
  chassis.pid_targets_reset();                // Resets PID targets to 0
  chassis.drive_imu_reset();                  // Reset gyro position to 0
  chassis.drive_sensor_reset();               // Reset drive sensors to 0
  chassis.drive_brake_set(MOTOR_BRAKE_HOLD);// Set motors to hold.  This helps autonomous consistency
  pros::Task lb_control_auton_task(lb_task_func_AUTON);
  default_constants(); // Set the drive to your own constants from autons.cpp!


  ez::as::auton_selector.selected_auton_call();  // Calls selected auton from autonomous selector
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
  // This is preference to what you like to drive on
  pros::motor_brake_mode_e_t driver_preference_brake = MOTOR_BRAKE_COAST;
  chassis.drive_brake_set(driver_preference_brake);
  bool sunaiControls = false;
  pros::Task lb_control_task(lb_task_func);

  pros::Task print_stuff([]{while (true) {
  
    lb_test_print();
    pros::delay(1000);
}}, "PRINT STUFF AS TEST");

  while (true) {
    pros::lcd::print(4, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
    (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
    (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);  // Prints status of the emulated screen LCDs

    // PID Tuner
    // After you find values that you're happy with, you'll have to set them in auton.cpp
    if (!pros::competition::is_connected()) { 
      // Enable / Disable PID Tuner
      //  When enabled: 
      //  * use A and Y to increment / decrement the constants
      //  * use the arrow keys to navigate the constants
      if (master.get_digital_new_press(DIGITAL_UP)) {
        chassis.pid_tuner_toggle();
      }
      // Trigger the selected autonomous routine
      if (master.get_digital_new_press(DIGITAL_DOWN)) {
        autonomous();
      }
      chassis.pid_tuner_iterate(); // Allow PID Tuner to iterate
    } 

    doinkerLeft.button_toggle(master.get_digital_new_press(DIGITAL_LEFT));
    doinkerRight.button_toggle(master.get_digital_new_press(DIGITAL_RIGHT));
    // intakePiston.button_toggle(master.get_digital_new_press(DIGITAL_Y));
    if (master.get_digital_new_press(DIGITAL_A)) {
      lb_nextState();
    }

    if (master.get_digital_new_press(DIGITAL_Y)) {
      //sets lb to tipping position
      lb_setState(3);
    }

    // if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
    //   if (sunaiControls) {
    //     sunaiControls = false;
    //   } else {
    //     sunaiControls = true;
    //   }
    // }

    if (sunaiControls) {
      chassis.opcontrol_arcade_standard(ez::SINGLE); // Standard single arcade
    } else {
      chassis.opcontrol_arcade_standard(ez::SPLIT); // Standard split arcade
    }
    
    // chassis.opcontrol_tank();  // Tank control
    // chassis.opcontrol_arcade_standard(ez::SPLIT);   // Standard split arcade
    // chassis.opcontrol_arcade_standard(ez::SINGLE);  // Standard single arcade
    // chassis.opcontrol_arcade_flipped(ez::SPLIT);    // Flipped split arcade
    // chassis.opcontrol_arcade_flipped(ez::SINGLE);   // Flipped single arcade

        
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
      intake.move(127);
    } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
      intake.move(-127);
    } else {
      intake.brake();
    }    

    if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2)) {
      backClamp.set(true);
    } else if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1)) {
      backClamp.set(false);
    }




    pros::delay(ez::util::DELAY_TIME);  // This is used for timer calculations!  Keep this ez::util::DELAY_TIME
  }
}