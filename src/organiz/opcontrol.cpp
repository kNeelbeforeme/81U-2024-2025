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
int states[numStates] = {0, 50, 360, 390, 450};
int currState = 0;
int target = 0;

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
    target = states[setState];
}

void lb_liftControl() {
    double kP = 0.1;
    double currentPos = - (ladyBrownSensor.get_position() / 100.00);
    double error = target - currentPos;
    double velocity = kP * error;

    if (velocity > 127) {
        velocity = 127;
    } else if (velocity < -127) {
        velocity = -127;
    }

    ladybrown.move(velocity);
    std::cout << "Current position /100: " << currentPos << "\n";
    // std::cout << "Current position from lb sensor: " << ladyBrownSensor.get_position() << "\n";
    std::cout << "Current error: " << error << "\n";
    std::cout << "Current velocity: " << velocity << "\n";

    pros::delay(1000);

}
