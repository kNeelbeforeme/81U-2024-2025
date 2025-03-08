#ifndef ROBOT_OPCONTROL
#define ROBOT_OPCONTROL
#include "main.h"

void intake_func();
void lb_nextState();
void lb_liftControl(bool enabled = true);
void lb_liftControl_AUTON(bool enabled = true);
void lb_setState(int setState);
void lb_task_func();
void lb_task_func_AUTON();
void lb_test_print();
void lb_wait();
void lb_wait_until(double degrees);

// extern ez::PID lbPID;

#endif //ROBOT_OPCONTROL