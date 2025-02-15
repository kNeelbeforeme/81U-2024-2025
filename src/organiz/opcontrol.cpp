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
int states[numStates] = {0, 180, 540, 600, 660};
int currState = 0;
int target = 0;

void lb_nextState() {
    currState += 1;
    if (currState >= 3) {
        currState = 0;
    }
    target = states[currState];
}



/** 0 is idle, 
 * 1 is loading
 * 2 is aligning w stake
 * 3 is to push ring down
 * 4 is tipping position
 **/
void lb_setState(int setState) {
    target = states[setState];
}

void lb_liftControl() {
    double kP = 0.6;
    double error = target - ladyBrownSensor.get_position();
    double velocity = kP * error;

    ladybrown.move(velocity);

}
