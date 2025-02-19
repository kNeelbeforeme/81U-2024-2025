#include "main.h"
#include "organiz/organize.h"

void intake_func() {
    pros::c::optical_rgb_s_t rgbval = color_checker.get_rgb();
    if (rgbval.blue > 230 && rgbval.red < 230) {
        //blue ring is in the intake
        
    } else if (rgbval.red > 230 && rgbval.blue < 230) {
        //red ring is in the intake
        
    } else {
        
    }
}


const int numStates = 5;
int states[numStates] = {0, 30, 145, 170, 220};
int currState = 0;
int target = 0;

ez::PID lbPID(2.0);

const int MAX_LB_SPEED = 100;
const int NEG_MAX_LB_SPEED = -100;

void lb_liftControl() {
    lbPID.target_set(target);
    
    // double kP = 0.5;
    double currentPos = (ladyBrownSensor.get_position() / 100.00);
    // double error = target - currentPos;
    // double velocity = kP * error;
    double velocity = lbPID.compute(currentPos);

    if ((currentPos > 330) && (target != 0)) {
        velocity = -10;
    } 
    // if ((target <= 50)) {
    //     lbPID.constants_set(3.5);
    // } else {
    //     lbPID.constants_set(2.0);
    // }

    
   
    // if ((error < 2) && (error > -2)) {
    //     velocity = 0;
    // }
    // if (error < -360) {
    //     velocity = 0;
    // }

    
    if (velocity > MAX_LB_SPEED) {
        velocity = MAX_LB_SPEED;

    } else if (velocity < NEG_MAX_LB_SPEED) {
        velocity = NEG_MAX_LB_SPEED;

    } else if (abs(velocity) < 2) {
        velocity = 0;
    }

    ladybrown.move(velocity);


    std::cout << "Current position /100: " << currentPos << "\n";
    // std::cout << "Current position from lb sensor: " << ladyBrownSensor.get_position() << "\n";
    // std::cout << "Current error: " << error << "\n";
    std::cout << "Current velocity: " << velocity << "\n";


}

void lb_nextState() {
    std::cout << "current state :" << currState << "\n";
    std::cout << "target angle:" << target << "\n";
    std::cout << "Current angle from lb sensor: " << ladyBrownSensor.get_angle() << "\n";
    // std::cout << "Current position from lb sensor: " << ladyBrownSensor.get_position() << "\n";

    currState += 1;
    if (currState >= 3) {
        currState = 0;
    }
    target = states[currState];
    std::cout << "current target :" << target << "\n";
}



/** 0 is idle, 
 * 1 is loading
 * 2 is aligning w stake
 * 3 is to push ring down
 * 4 is tipping position
 **/
void lb_setState(int setState) {
    currState = setState;
    target = states[currState];

}



void lb_task_func() {
    while (true)
    {
      lb_liftControl();
      pros::delay(ez::util::DELAY_TIME);
    }
}
