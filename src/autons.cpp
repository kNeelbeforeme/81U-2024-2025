#include "main.h"

/////
// For installation, upgrading, documentations and tutorials, check out our website!
// https://ez-robotics.github.io/EZ-Template/
/////

// These are out of 127
const int DRIVE_SPEED = 90;  
const int SLOW_DRIVE_SPEED = 70;  
const int TURN_SPEED = 90;
const int SWING_SPEED = 100;

///
// Constants
///
void default_constants() {
  chassis.pid_heading_constants_set(4, 0, 20);
  chassis.pid_drive_constants_forward_set(45, 5, 200);
  chassis.pid_drive_constants_backward_set(45, 5, 200);
  chassis.pid_turn_constants_set(3.4, 0.002, 16, 1);
  chassis.pid_swing_constants_set(5, 0, 30);

  chassis.pid_turn_exit_condition_set(300_ms, 3_deg, 500_ms, 7_deg, 750_ms, 750_ms);
  chassis.pid_swing_exit_condition_set(300_ms, 3_deg, 500_ms, 7_deg, 750_ms, 750_ms);
  chassis.pid_drive_exit_condition_set(300_ms, 1_in, 500_ms, 3_in, 750_ms, 750_ms);

  chassis.slew_drive_constants_set(7_in, 40);
  chassis.slew_turn_constants_set(5_deg, 50);
  chassis.slew_swing_constants_set(5_deg, 50);

  chassis.pid_turn_chain_constant_set(3_deg);
  chassis.pid_swing_chain_constant_set(5_deg);
  chassis.pid_drive_chain_constant_set(2_in);
  
}

void slow_constants() {
  chassis.pid_drive_constants_forward_set(50, 5, 250, 1);
  chassis.pid_drive_constants_backward_set(50, 5, 250, 1);
}

void do_nothing() {
  backClamp.set(false);
}


//first auton sketfch out
void blue_ring_rush() {
  chassis.drive_angle_set(180);
  // // chassis.pid_drive_set(0,0);
  // // lb_setState(3);
  // // pros::delay(1000);
  // // lb_setState(0);

  // intake.move(120);
  // pros::delay(800);

  chassis.pid_drive_set(-15, 80, true);
  // chassis.pid_wait_until(-10);
  // chassis.pid_speed_max_set(90);
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(-12, 40);
  chassis.pid_wait();

  backClamp.set(true);
  pros::delay(100);

  chassis.pid_turn_set(45, TURN_SPEED);
  chassis.pid_wait();
  intake.move(127);

  chassis.pid_drive_set(13, DRIVE_SPEED);
  chassis.pid_wait_quick();

  // intake.move(-10);

  // chassis.pid_drive_set(-5, DRIVE_SPEED);
  // chassis.pid_wait_quick_chain();

  chassis.pid_swing_set(ez::LEFT_SWING, 90, TURN_SPEED);
  chassis.pid_wait_quick();
  intake.move(127);
  
  chassis.pid_drive_set(20, SLOW_DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-10, DRIVE_SPEED);
  chassis.pid_wait_quick();

  chassis.pid_turn_set(180, TURN_SPEED);
  chassis.pid_wait_quick();
  
  chassis.pid_drive_set(22, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-5, DRIVE_SPEED);
  chassis.pid_wait_quick();

  chassis.pid_turn_set(270, TURN_SPEED);
  chassis.pid_wait_quick();

  intake.move(-100);
  lb_setState(2);

  chassis.pid_drive_set(20, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_swing_set(LEFT_SWING, 315, SWING_SPEED);
  chassis.pid_wait();


//--------------
  // chassis.pid_drive_set(-36_in, 100, true);
  // chassis.pid_wait();

  // backClamp.set(true);

  // chassis.pid_drive_set(0,0);
  // pros::delay(800);    

  // chassis.pid_swing_set(ez::LEFT_SWING, 90, TURN_SPEED-10, true);
  // chassis.pid_wait();

  // intake.move(127);
  
  // chassis.pid_drive_set(32_in, DRIVE_SPEED);
  // chassis.pid_wait();

  // chassis.pid_drive_set(0,0);
  // pros::delay(2000);

  // chassis.pid_turn_set(-90, TURN_SPEED-10, true);
  // chassis.pid_wait();
  
  // chassis.pid_drive_set(47, DRIVE_SPEED);
  // chassis.pid_wait();
}

void blue_disruptor() {
  chassis.drive_angle_set(0);

  chassis.pid_drive_set(44, DRIVE_SPEED);
  chassis.pid_wait_until(20);
  chassis.pid_speed_max_set(60);
  intake.move(50);
  chassis.pid_wait();

  intake.brake();
  doinkerLeft.set(true);
  doinkerRight.set(true);
  pros::delay(500);

  chassis.pid_drive_set(-10, DRIVE_SPEED);
  chassis.pid_wait_quick();

  chassis.pid_turn_set(90, TURN_SPEED);
  chassis.pid_wait_quick();

  doinkerLeft.set(false);
  doinkerRight.set(false);

  chassis.pid_drive_set(-18, SLOW_DRIVE_SPEED);
  chassis.pid_wait_quick();

  backClamp.set(true);
  intake.move(100);
  pros::delay(500);

  chassis.pid_swing_set(LEFT_SWING, 125, SWING_SPEED);
  chassis.pid_wait_quick();

  chassis.pid_drive_set(20, DRIVE_SPEED);
  chassis.pid_wait_quick();

  chassis.pid_swing_set(RIGHT_SWING, 0, SWING_SPEED);
  chassis.pid_wait_quick();

  intake.move(127);
  chassis.pid_drive_set(16, SLOW_DRIVE_SPEED);
  chassis.pid_wait_quick();

  chassis.pid_drive_set(-16, SLOW_DRIVE_SPEED);
  chassis.pid_wait_quick();
}
//second auton sketfch out
void blue_goal_rush() {
  chassis.drive_angle_set(0);

  chassis.pid_drive_set(29, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_swing_set(LEFT_SWING, 45, SWING_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_swing_set(RIGHT_SWING, 15, SWING_SPEED);
  chassis.pid_wait_quick_chain();

  doinkerRight.set(true);
  pros::delay(500);

  chassis.pid_swing_set(RIGHT_SWING, 45, SWING_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_swing_set(LEFT_SWING, 0, SWING_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-30, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(180, TURN_SPEED);
  chassis.pid_wait();

  doinkerRight.set(false);

  chassis.pid_turn_set(90, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(20, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(205, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-10, DRIVE_SPEED, true);
  chassis.pid_wait_until(-8);

  chassis.pid_drive_set(-13, 30);
  chassis.pid_wait();

  backClamp.set(true);
  intake.move(100);


  // chassis.pid_drive_set(-10, DRIVE_SPEED);
  // chassis.pid_wait_quick();

  chassis.pid_turn_set(270, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(20, DRIVE_SPEED);
  chassis.pid_wait();
//   chassis.drive_angle_set(-180);

//   chassis.pid_drive_set(-35, DRIVE_SPEED);
//   chassis.pid_wait();

//   chassis.pid_turn_set(-100, TURN_SPEED);
//   chassis.pid_wait_quick();

//   chassis.pid_drive_set(-10, DRIVE_SPEED);
//   chassis.pid_wait();

//   backClamp.set(true);

//   chassis.pid_drive_set(10, DRIVE_SPEED);
//   chassis.pid_wait();

//   chassis.pid_turn_set(60, TURN_SPEED);
//   chassis.pid_wait();

//   backClamp.set(false);

//   chassis.pid_drive_set(-10, DRIVE_SPEED);
//   chassis.pid_wait_quick();

//   chassis.pid_turn_set(-60, TURN_SPEED);
//   chassis.pid_wait();

//   chassis.pid_drive_set(-30, DRIVE_SPEED);
//   chassis.pid_wait();

//   backClamp.set(true);

//   chassis.pid_drive_set(-10, DRIVE_SPEED);
//   chassis.pid_wait();

//   chassis.pid_turn_set(-90, TURN_SPEED);
//   chassis.pid_wait();

//   chassis.pid_drive_set(20, DRIVE_SPEED);
//   chassis.pid_wait();

//   chassis.pid_turn_set(-270, TURN_SPEED);
//   chassis.pid_wait();


//----------------
  // chassis.pid_turn_set(180, TURN_SPEED);
  // chassis.pid_wait();

  // intake.move(127);

  // chassis.pid_drive_set(15, DRIVE_SPEED);
  // chassis.pid_wait();

  // chassis.pid_turn_set(270, TURN_SPEED);
  // chassis.pid_wait();

  // chassis.pid_drive_set(-20, DRIVE_SPEED);
  // chassis.pid_wait();

  // chassis.pid_swing_set(ez::RIGHT_SWING, 45, SWING_SPEED);
  // chassis.pid_wait();
  // intake.brake();
  

  //---------------
  // chassis.drive_angle_set(-90);
  // // doinker.set(true);
  // backClamp.set(false);

  // chassis.pid_drive_set(-10, DRIVE_SPEED);
  // chassis.pid_wait();

  // chassis.pid_swing_set(ez::RIGHT_SWING, 0, SWING_SPEED);
  // chassis.pid_wait();

  // // doinker.set(false);
  // intake.move(120);
  // pros::delay(1000);
  // intake.brake();

  // chassis.pid_drive_set(10, DRIVE_SPEED);
  // chassis.pid_wait();

  // chassis.pid_swing_set(ez::RIGHT_SWING, -45, SWING_SPEED);
  // chassis.pid_wait();

  // chassis.pid_drive_set(18, DRIVE_SPEED);
  // chassis.pid_wait();

  // chassis.pid_turn_set(135, TURN_SPEED);
  // chassis.pid_wait();

  // chassis.pid_drive_set(-15, DRIVE_SPEED);
  // chassis.pid_wait();

  // backClamp.set(true);
  // pros::delay(200);

  // chassis.pid_turn_set(260, TURN_SPEED);
  // chassis.pid_wait();

  // intake.move(100);
  // chassis.pid_drive_set(28, DRIVE_SPEED);
  // chassis.pid_wait();

  // chassis.pid_turn_set(95, TURN_SPEED);
  // chassis.pid_wait();

  // chassis.pid_drive_set(60, DRIVE_SPEED);
  // chassis.pid_wait();
  // intake.brake();

  // chassis.pid_drive_set(-20.5, DRIVE_SPEED);
  // chassis.pid_wait();

  // backClamp.set(true);

  // chassis.pid_drive_set(0,0);
  // pros::delay(800);    

  // chassis.pid_swing_set(ez::RIGHT_SWING, -100, TURN_SPEED-10, true);
  // chassis.pid_wait();

  // intake.move(127);
  
  // chassis.pid_drive_set(12_in, 100);
  // chassis.pid_wait();

  // pros::delay(2000);

  // chassis.pid_drive_set(-31_in, DRIVE_SPEED);
  // chassis.pid_wait();

  // chassis.pid_drive_set(0,0);
  // pros::delay(2000);

  // //doinker.set(true);

  // chassis.pid_turn_set(90_deg, 70);
  // chassis.pid_wait();

  // chassis.pid_drive_set(10, DRIVE_SPEED);
  // chassis.pid_wait();

  // intake.brake();
  chassis.pid_drive_set(0, 0);

}


//RING RUSH
void red_ring_rush() {
  chassis.drive_angle_set(-180);

  // // chassis.pid_drive_set(0,0);
  // // lb_setState(3);
  // // pros::delay(1000);
  // // lb_setState(0);

  // intake.move(120);
  // pros::delay(800);

  chassis.pid_drive_set(-13, DRIVE_SPEED);
  chassis.pid_wait_quick();


  backClamp.set(true);

  chassis.pid_turn_set(-90, TURN_SPEED);
  chassis.pid_wait();
  intake.move(127);

  chassis.pid_drive_set(11, DRIVE_SPEED);
  chassis.pid_wait_quick();

  // intake.move(-10);

  // chassis.pid_drive_set(-5, DRIVE_SPEED);
  // chassis.pid_wait_quick_chain();

  chassis.pid_turn_set(0, TURN_SPEED);
  chassis.pid_wait_quick();
  intake.move(127);
  
  chassis.pid_drive_set(18, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-10, DRIVE_SPEED);
  chassis.pid_wait_quick();

  chassis.pid_turn_set(-12, TURN_SPEED);
  chassis.pid_wait_quick();
  
  chassis.pid_drive_set(22, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-5, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(-20, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();




  //CODE FOR QUALS

  //chassis.pid_turn_set(90, TURN_SPEED);
  //chassis.pid_wait_quick();

  // intake.move(-100);
  // lb_setState(2);

  // chassis.pid_drive_set(24, DRIVE_SPEED);
  // chassis.pid_wait();

  // chassis.pid_swing_set(RIGHT_SWING, 45, SWING_SPEED);
  // chassis.pid_wait();
// CODE FOR QUALS


  //OLD CODE
  // chassis.pid_drive_set(10, DRIVE_SPEED);
  // chassis.pid_wait_quick_chain();
  //   chassis.drive_angle_set(-90);
  // // doinker.set(true);
  // backClamp.set(false);

  // chassis.pid_drive_set(-10, DRIVE_SPEED);
  // chassis.pid_wait();

  // chassis.pid_swing_set(ez::RIGHT_SWING, 0, SWING_SPEED);
  // chassis.pid_wait();

  // // doinker.set(false);
  // intake.move(120);
  // pros::delay(1000);
  // intake.brake();

  // chassis.pid_drive_set(10, DRIVE_SPEED);
  // chassis.pid_wait();

  // chassis.pid_swing_set(ez::RIGHT_SWING, -45, SWING_SPEED);
  // chassis.pid_wait();

  // chassis.pid_drive_set(18, DRIVE_SPEED);
  // chassis.pid_wait();

  // chassis.pid_turn_set(135, TURN_SPEED);
  // chassis.pid_wait();

  // chassis.pid_drive_set(-15, DRIVE_SPEED);
  // chassis.pid_wait();

  // backClamp.set(true);
  // pros::delay(200);

  // chassis.pid_turn_set(260, TURN_SPEED);
  // chassis.pid_wait();

  // intake.move(100);
  // chassis.pid_drive_set(28, DRIVE_SPEED);
  // chassis.pid_wait();

  // chassis.pid_turn_set(362, TURN_SPEED);
  // chassis.pid_wait();

  // intake.move(120);
  // chassis.pid_drive_set(24, DRIVE_SPEED);
  // chassis.pid_wait();

  // chassis.pid_drive_set(0,0);
  // pros::delay(500);

  // chassis.pid_drive_set(-5, DRIVE_SPEED);
  // chassis.pid_wait();

  // chassis.pid_turn_set(431, TURN_SPEED);
  // chassis.pid_wait();

  // chassis.pid_drive_set(40, DRIVE_SPEED);
  // chassis.pid_wait();
  // intake.brake();
}

//RING DISRUPTOR
void red_disruptor() {
  chassis.drive_angle_set(0);


}

void red_goal_rush() {
  chassis.drive_angle_set(-180);

  chassis.pid_drive_set(-20, DRIVE_SPEED);
  chassis.pid_wait_quick();

  chassis.pid_drive_set(-10, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-225, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-10, DRIVE_SPEED);
  chassis.pid_wait();

  backClamp.set(true);

  chassis.pid_turn_set(-180, TURN_SPEED);
  chassis.pid_wait();

  intake.move(127);

  chassis.pid_drive_set(15, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-90, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(20, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::LEFT_SWING, -45, SWING_SPEED);
  chassis.pid_wait();
  intake.brake();
  //   chassis.drive_angle_set(30);
  // doinkerLeft.set(true);

  // chassis.pid_drive_set(190, DRIVE_SPEED, true);
  // chassis.pid_wait();
  
  // chassis.pid_turn_set(10, TURN_SPEED);
  // chassis.pid_wait();
  // doinkerLeft.set(false);

  // chassis.pid_drive_set(-10, DRIVE_SPEED, true);
  // chassis.pid_wait();

  // chassis.pid_turn_set(180, TURN_SPEED);
  // doinkerLeft.set(true);
  // chassis.pid_wait();

  // chassis.pid_turn_set(90, TURN_SPEED);
  // doinkerLeft.set(false);
  // chassis.pid_wait();

  // chassis.pid_drive_set(-10, DRIVE_SPEED);
  // chassis.pid_wait();

  // backClamp.set(true);
  // intake.move(100);

  // chassis.pid_drive_set(0,0);
  // chassis.pid_wait();

  // pros::delay(2000);
  // intake.brake();
}

void simple_right() {
  chassis.drive_angle_set(180);
    chassis.pid_drive_set(-36_in, 100, true);
  chassis.pid_wait();

  backClamp.set(true);

  chassis.pid_drive_set(0,0);
  pros::delay(800);    

  chassis.pid_swing_set(ez::LEFT_SWING, 90, TURN_SPEED-10, true);
  chassis.pid_wait();

  intake.move(127);
  
  chassis.pid_drive_set(14, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(0,0);
  pros::delay(2000);

  chassis.pid_turn_set(-90, TURN_SPEED-10, true);
  chassis.pid_wait();
  
  chassis.pid_drive_set(47, DRIVE_SPEED);
  chassis.pid_wait();
}

void simple_left() {
  chassis.drive_angle_set(-180);
  chassis.pid_drive_set(-36_in, 100, true);
  chassis.pid_wait();

  backClamp.set(true);

  chassis.pid_drive_set(0,0);
  pros::delay(800);    

  chassis.pid_swing_set(ez::RIGHT_SWING, -90, TURN_SPEED-10, true);
  chassis.pid_wait();

  intake.move(127);
  
  chassis.pid_drive_set(14, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(0,0);
  pros::delay(2000);

  chassis.pid_turn_set(90, TURN_SPEED-10, true);
  chassis.pid_wait();
  
  chassis.pid_drive_set(47, DRIVE_SPEED);
  chassis.pid_wait();
}


void skills_red_left_side() {

  intake.move(127);
  pros::delay(700);

  chassis.pid_drive_set(12, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(90, TURN_SPEED);
  chassis.pid_wait();

  intake.brake();

  chassis.pid_drive_set(-20, DRIVE_SPEED);
  chassis.pid_wait();

  backClamp.set(true);

  chassis.pid_turn_set(0, TURN_SPEED);
  chassis.pid_wait_quick();

  intake.move(120);

  chassis.pid_drive_set(14, DRIVE_SPEED);
  chassis.pid_wait_quick();

  chassis.pid_swing_set(ez::RIGHT_SWING, -65, TURN_SPEED);
  chassis.pid_wait_quick();

  chassis.pid_drive_set(16, DRIVE_SPEED);
  chassis.pid_wait_quick();

  chassis.pid_swing_set(ez::RIGHT_SWING, -90, SWING_SPEED);
  chassis.pid_wait_quick();

  chassis.pid_drive_set(6, DRIVE_SPEED);
  chassis.pid_wait_quick();

  chassis.pid_drive_set(-10, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-180, SWING_SPEED);
  chassis.pid_wait_quick();

  chassis.pid_drive_set(15, DRIVE_SPEED);
  chassis.pid_wait();
  pros::delay(500);
  chassis.pid_drive_set(10, DRIVE_SPEED);
  chassis.pid_wait_quick();
  chassis.pid_drive_set(5, DRIVE_SPEED);
  chassis.pid_wait_quick();
  chassis.pid_drive_set(13, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();


  // chassis.pid_swing_set(ez::LEFT_SWING, -60, SWING_SPEED);
  // chassis.pid_wait_quick();
  // chassis.pid_drive_set(20, DRIVE_SPEED);
  // chassis.pid_wait_quick();

  chassis.pid_drive_set(-5, DRIVE_SPEED);
  chassis.pid_wait_quick();


  chassis.pid_turn_set(-315, SWING_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-25, DRIVE_SPEED);
  chassis.pid_wait();

  backClamp.set(false);
  intake.move(-100);

  chassis.pid_drive_set(5, DRIVE_SPEED);
  chassis.pid_wait_quick();

  chassis.pid_turn_set(-270, SWING_SPEED);
  chassis.pid_wait_quick();

  chassis.pid_drive_set(80, DRIVE_SPEED);
  chassis.pid_wait();
}
void skills_red_right_side() {

  intake.brake();

  chassis.pid_turn_set(-90, TURN_SPEED);
  chassis.pid_wait();

  intake.move(-120);

  chassis.pid_drive_set(-12, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();

  backClamp.set(true);
  intake.brake();

  chassis.pid_drive_set(9, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(0, TURN_SPEED);
  chassis.pid_wait();

  intake.move(120);

  chassis.pid_drive_set(10, DRIVE_SPEED);
  chassis.pid_wait_quick();

  chassis.pid_swing_set(ez::LEFT_SWING, 60, SWING_SPEED);
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(20, DRIVE_SPEED);
  chassis.pid_wait_quick();

  chassis.pid_swing_set(ez::LEFT_SWING, 90, SWING_SPEED);
  chassis.pid_wait_quick();

  chassis.pid_drive_set(8, DRIVE_SPEED);
  chassis.pid_wait_quick();
  
  chassis.pid_drive_set(-5, DRIVE_SPEED);
  chassis.pid_wait_quick();

  chassis.pid_turn_set(180, SWING_SPEED);
  chassis.pid_wait_quick();

  // for (int i = 0; i < 6; i++)
  // {
  //   chassis.pid_drive_set(15, DRIVE_SPEED);
  //   chassis.pid_wait_quick();
  // }
  chassis.pid_drive_set(18, DRIVE_SPEED);
  chassis.pid_wait();
  pros::delay(500);
  chassis.pid_drive_set(10, DRIVE_SPEED);
  chassis.pid_wait_quick();
  chassis.pid_drive_set(6, DRIVE_SPEED);
  chassis.pid_wait_quick();
  chassis.pid_drive_set(10, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();


  // chassis.pid_swing_set(ez::LEFT_SWING, -60, SWING_SPEED);
  // chassis.pid_wait_quick();
  // chassis.pid_drive_set(20, DRIVE_SPEED);
  // chassis.pid_wait_quick();

  chassis.pid_drive_set(-5, DRIVE_SPEED);
  chassis.pid_wait_quick();

  chassis.pid_turn_set(315, SWING_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-25, DRIVE_SPEED);
  chassis.pid_wait();

  backClamp.set(false);

  chassis.pid_swing_set(ez::LEFT_SWING, 360, SWING_SPEED);
  chassis.pid_wait();
}
void skills_blue_side() {

  chassis.pid_turn_set(311, TURN_SPEED);
  chassis.pid_wait_quick();

  chassis.pid_drive_set(30, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();  
  chassis.pid_drive_set(15, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(270, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-30, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();

  backClamp.set(false);

  chassis.pid_swing_set(ez::LEFT_SWING, 215, SWING_SPEED);
  chassis.pid_wait_quick();

  chassis.pid_drive_set(-10, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();

  chassis.pid_swing_set(ez::LEFT_SWING, 275, SWING_SPEED);
  chassis.pid_wait_quick();

  chassis.pid_drive_set(15, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();

  chassis.pid_turn_set(90, TURN_SPEED);
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(-30, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(-10, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();  
  chassis.pid_wait();

  chassis.pid_swing_set(ez::RIGHT_SWING, 125, SWING_SPEED);
  chassis.pid_wait_quick();

  chassis.pid_drive_set(-10, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();

  chassis.pid_swing_set(ez::RIGHT_SWING, 90, SWING_SPEED);
  chassis.pid_wait_quick();

}

void new_skills_right() {
  chassis.drive_angle_set(0);
  intake.move(127);
  pros::delay(700);
  intake.brake();

  chassis.pid_drive_set(12, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(-90, TURN_SPEED, true);
  chassis.pid_wait_quick();

  chassis.pid_drive_set(-25, SLOW_DRIVE_SPEED, true);
  chassis.pid_wait_quick_chain();

  backClamp.set(true);
  pros::delay(100);

  chassis.pid_swing_set(LEFT_SWING, 25, TURN_SPEED, 0, true);
  chassis.pid_wait_quick();

  intake.move(127);
  chassis.pid_drive_set(20, DRIVE_SPEED, true);
  chassis.pid_wait_quick();

  chassis.pid_swing_set(ez::LEFT_SWING, 45, SWING_SPEED, 0, true);
  chassis.pid_wait_quick();

  intake.move(110);
  chassis.pid_drive_set(19, SLOW_DRIVE_SPEED, true);
  chassis.pid_wait_quick();

  chassis.pid_swing_set(ez::LEFT_SWING, 90, 80, 0, true);
  chassis.pid_wait();

  lb_setState(1);

  intake.move(127);

  chassis.pid_drive_set(14, SLOW_DRIVE_SPEED, true);
  chassis.pid_wait_quick();

  chassis.pid_drive_set(0,0);
  pros::delay(1500);
  intake.move(-40);
  pros::delay(100);
  lb_setState(3);
  intake.brake();
  chassis.pid_drive_set(3, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  lb_wait_until(10);


  intake.move(-120);

  lb_setState(0);
  lb_wait_until(80);


  // chassis.pid_drive_set(-8, DRIVE_SPEED, true);
  // chassis.pid_wait_quick();

  chassis.pid_swing_set(ez::LEFT_SWING, 0, SWING_SPEED, 0, true);
  chassis.pid_wait();

  chassis.pid_drive_set(28, SLOW_DRIVE_SPEED, true);
  intake.move(127);
  chassis.pid_wait();

  chassis.pid_turn_set(180, 70, true);
  chassis.pid_wait();

  chassis.pid_drive_set(90, 90, true);
  chassis.pid_wait_until(20);
  chassis.pid_speed_max_set(40);
  chassis.pid_wait_until(10);
  intake.move(127);
  chassis.pid_wait_quick();

  chassis.pid_drive_set(-10, SLOW_DRIVE_SPEED);
  chassis.pid_wait_quick_chain();

  chassis.pid_turn_set(90, TURN_SPEED);
  chassis.pid_wait_quick();

  chassis.pid_drive_set(12, DRIVE_SPEED);
  chassis.pid_wait_quick();

  chassis.pid_swing_set(ez::LEFT_SWING, -35, SWING_SPEED);
  chassis.pid_wait_quick();

  chassis.pid_drive_set(-20, DRIVE_SPEED);
  chassis.pid_wait_quick();

  backClamp.set(false);

  chassis.pid_drive_set(10, DRIVE_SPEED, true);
  chassis.pid_wait_quick();

  chassis.pid_swing_set(ez::RIGHT_SWING, -90, TURN_SPEED);
  chassis.pid_wait_quick();
}
void new_skills_left() {

  chassis.pid_drive_set(40, DRIVE_SPEED);
  chassis.pid_wait_quick();

  chassis.pid_turn_set(90, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-25, SLOW_DRIVE_SPEED, true);
  chassis.pid_wait_quick();

  backClamp.set(true);
  chassis.pid_drive_set(0, 0);
  pros::delay(100);

  chassis.pid_swing_set(RIGHT_SWING, -25, TURN_SPEED, 0, true);
  chassis.pid_wait_quick();

  intake.move(127);
  chassis.pid_drive_set(22, DRIVE_SPEED, true);
  chassis.pid_wait_quick();

  chassis.pid_swing_set(ez::RIGHT_SWING, -45, SWING_SPEED, 0, true);
  chassis.pid_wait_quick();

  chassis.pid_drive_set(20, DRIVE_SPEED, true);
  chassis.pid_wait_quick();

  chassis.pid_swing_set(ez::RIGHT_SWING, -90, 80, 0, true);
  chassis.pid_wait();

  lb_setState(1);

  chassis.pid_drive_set(11, SLOW_DRIVE_SPEED, true);
  chassis.pid_wait_quick();

  chassis.pid_drive_set(0,0);
  pros::delay(1500);
  // lb_setState(2);
  intake.move(-40);
  pros::delay(100);
  lb_setState(3);
  intake.brake();
  chassis.pid_drive_set(3, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  lb_wait();

  chassis.pid_drive_set(10, DRIVE_SPEED);
  chassis.pid_wait_quick();

  intake.move(120);

  lb_setState(0);
  lb_wait_until(80);


  // chassis.pid_drive_set(-8, DRIVE_SPEED, true);
  // chassis.pid_wait_quick();

  chassis.pid_swing_set(ez::RIGHT_SWING, 0, SWING_SPEED, 0, true);
  chassis.pid_wait();


  chassis.pid_drive_set(28, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-180, 70, true);
  chassis.pid_wait();

  chassis.pid_drive_set(90, 90, true);
  chassis.pid_wait_until(20);
  chassis.pid_speed_max_set(40);
  chassis.pid_wait_until(10);
  intake.move(127);
  chassis.pid_wait_quick();

  chassis.pid_drive_set(-10, SLOW_DRIVE_SPEED);
  chassis.pid_wait_quick_chain();

  chassis.pid_turn_set(-90, TURN_SPEED);
  chassis.pid_wait_quick();

  chassis.pid_drive_set(12, DRIVE_SPEED);
  chassis.pid_wait_quick();

  chassis.pid_swing_set(ez::RIGHT_SWING, 35, SWING_SPEED);
  chassis.pid_wait_quick();

  chassis.pid_drive_set(-20, DRIVE_SPEED);
  chassis.pid_wait_quick();

  backClamp.set(false);

  chassis.pid_drive_set(10, DRIVE_SPEED, true);
  chassis.pid_wait_quick();

  chassis.pid_swing_set(ez::RIGHT_SWING, 0, TURN_SPEED);
  chassis.pid_wait_quick();
}

void new_skills_blueside() {
  chassis.pid_drive_set(40, SLOW_DRIVE_SPEED, true);
  chassis.pid_wait_quick_chain();

  chassis.pid_turn_set(45, TURN_SPEED);
  chassis.pid_wait_quick();
  intake.move(50);

  chassis.pid_drive_set(40, SLOW_DRIVE_SPEED, true);
  chassis.pid_wait_until(20);
  intake.brake();
  chassis.pid_wait();

  chassis.pid_turn_set(-135, TURN_SPEED);
  chassis.pid_wait_quick();

  chassis.pid_drive_set(-10, SLOW_DRIVE_SPEED, true);
  chassis.pid_wait();

  backClamp.set(true);
  pros::delay(100);

  chassis.pid_swing_set(ez::LEFT_SWING, -90, TURN_SPEED, 10);
  chassis.pid_wait_quick();

  intake.move(120);
  chassis.pid_drive_set(18, DRIVE_SPEED, true);
  chassis.pid_wait_quick();

  chassis.pid_turn_set(0, TURN_SPEED);
  chassis.pid_wait_quick();

  chassis.pid_drive_set(18, SLOW_DRIVE_SPEED, true);
  chassis.pid_wait_quick();

  chassis.pid_drive_set(-18, DRIVE_SPEED, true);
  chassis.pid_wait_quick();

  chassis.pid_turn_set(-240, TURN_SPEED);
  chassis.pid_wait_quick();

  chassis.pid_drive_set(-30, DRIVE_SPEED, true);
  chassis.pid_wait_quick();

  chassis.pid_swing_set(ez::RIGHT_SWING, -270, SWING_SPEED);

  chassis.pid_drive_set(120, DRIVE_SPEED, true);
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(12, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::LEFT_SWING, 45, SWING_SPEED);
  chassis.pid_wait_quick();

  chassis.pid_drive_set(-40, DRIVE_SPEED, true);
  lb_setState(3);
  chassis.pid_wait_quick();
}
void skills_code() {
  chassis.drive_angle_set(0);
  backClamp.set(false);
  
  new_skills_right();
  new_skills_left();

  new_skills_blueside();

  // skills_red_left_side();
  // skills_red_right_side();

  // //time to go across the field and get other mogo
  // chassis.pid_drive_set(100, DRIVE_SPEED);
  // chassis.pid_wait();

  // skills_blue_side();

  // chassis.pid_drive_set(10, DRIVE_SPEED);
  // chassis.pid_wait_quick();
}
///
// Drive Example
///
void drive_example() {
  // The first parameter is target inches
  // The second parameter is max speed the robot will drive at
  // The third parameter is a boolean (true or false) for enabling/disabling a slew at the start of drive motions
  // for slew, only enable it when the drive distance is greater then the slew distance + a few inches

  chassis.pid_drive_set(12_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(12_in, DRIVE_SPEED);
  chassis.pid_wait();

  // chassis.pid_drive_set(24_in, DRIVE_SPEED);
  // chassis.pid_wait();

  // chassis.pid_drive_set(-24_in, DRIVE_SPEED);
  // chassis.pid_wait();

}

///
// Turn Example
///
void turn_example() {
  // The first parameter is target degrees
  // The second parameter is max speed the robot will drive at

  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();
}

///
// Combining Turn + Drive
///
void drive_and_turn() {
  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-24_in, DRIVE_SPEED, true);
  chassis.pid_wait();
}

///
// Wait Until and Changing Max Speed
///
void wait_until_change_speed() {
  // pid_wait_until will wait until the robot gets to a desired position

  // When the robot gets to 6 inches, the robot will travel the remaining distance at a max speed of 30
  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait_until(6_in);
  chassis.pid_speed_max_set(30);  // After driving 6 inches at DRIVE_SPEED, the robot will go the remaining distance at 30 speed
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  // When the robot gets to -6 inches, the robot will travel the remaining distance at a max speed of 30
  chassis.pid_drive_set(-24_in, DRIVE_SPEED, true);
  chassis.pid_wait_until(-6_in);
  chassis.pid_speed_max_set(30);  // After driving 6 inches at DRIVE_SPEED, the robot will go the remaining distance at 30 speed
  chassis.pid_wait();
}

///
// Swing Example
///
void swing_example() {
  // The first parameter is ez::LEFT_SWING or ez::RIGHT_SWING
  // The second parameter is target degrees
  // The third parameter is speed of the moving side of the drive
  // The fourth parameter is the speed of the still side of the drive, this allows for wider arcs

  chassis.pid_swing_set(ez::LEFT_SWING, 45_deg, SWING_SPEED, 45);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::RIGHT_SWING, 0_deg, SWING_SPEED, 45);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::RIGHT_SWING, 45_deg, SWING_SPEED, 45);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::LEFT_SWING, 0_deg, SWING_SPEED, 45);
  chassis.pid_wait();
}

///
// Auto that tests everything
///
void combining_movements() {
  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::RIGHT_SWING, -45_deg, SWING_SPEED, 45);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-24_in, DRIVE_SPEED, true);
  chassis.pid_wait();
}

///
// Interference example
///
void tug(int attempts) {
  for (int i = 0; i < attempts - 1; i++) {
    // Attempt to drive backwards
    printf("i - %i", i);
    chassis.pid_drive_set(-12_in, 127);
    chassis.pid_wait();

    // If failsafed...
    if (chassis.interfered) {
      chassis.drive_sensor_reset();
      chassis.pid_drive_set(-2_in, 20);
      pros::delay(1000);
    }
    // If robot successfully drove back, return
    else {
      return;
    }
  }
}

// If there is no interference, robot will drive forward and turn 90 degrees.
// If interfered, robot will drive forward and then attempt to drive backwards.
void interfered_example() {
  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  if (chassis.interfered) {
    tug(3);
    return;
  }

  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();
}

// . . .
// Make your own autonomous functions here!
// . . .
///
// Motion Chaining
///
void motion_chaining() {
  // Motion chaining is where motions all try to blend together instead of individual movements.
  // This works by exiting while the robot is still moving a little bit.
  // To use this, replace pid_wait with pid_wait_quick_chain.
  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();

  chassis.pid_turn_set(-45_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  // Your final motion should still be a normal pid_wait
  chassis.pid_drive_set(-24_in, DRIVE_SPEED, true);
  chassis.pid_wait();
}

// . . .
// Make your own autonomous functions here!
// . . .