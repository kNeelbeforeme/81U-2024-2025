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


const int numStates = 4;
int states[numStates] = {0, 28, 150, 160};

//constants we use later
int currState = 0;
int target = 0;
double lb_kP = 2.5;

const int MAX_LB_SPEED = 127;
const int NEG_MAX_LB_SPEED = -127;



void lb_liftControl(bool enabled) {
    if (enabled) {
    //if the movement is smaller/ it needs to move from idle to loading, the kP is boosted
    // meaning that it will provide more power/more exact movement
    if ((target <= 50)) {
        lb_kP = 3;
    } else {
        lb_kP = 2.8;
    }
    //current position (reversed because of how we placed our sensor)
    double currentPos = -1 * (ladyBrownSensor.get_position() / 100.00);

    //distance from our target(in degrees)
    double error = target - currentPos;

    //calculates the speed it should go based on the power(kP) and distance from the target(error)
    double velocity = lb_kP * error;

    ladybrown.move(velocity);

    //These are used for debugging
    // std::cout << "Current position /100: " << currentPos << "\n";
    // std::cout << "Current position from lb sensor: " << ladyBrownSensor.get_position() << "\n";
    // std::cout << "Current error: " << error << "\n";
    // std::cout << "Current velocity: " << velocity << "\n";

    }
}

// Sets the target of the lift to either the next in the array, or to the idle position
void lb_nextState() {
    //Debugging messages
    std::cout << "current state :" << currState << "\n";
    std::cout << "target angle:" << target << "\n";
    std::cout << "Current angle from lb sensor: " << ladyBrownSensor.get_angle() << "\n";
    // std::cout << "Current position from lb sensor: " << ladyBrownSensor.get_position() << "\n";

    currState += 1;
    if (currState >= 3) {
        currState = 0;
    }
    target = states[currState];
    std::cout << "new target :" << target << "\n";
}



/** 0 is idle, 
 * 1 is loading
 * 2 is aligning with stake
 * 3 is tipping position
 **/
void lb_setState(int targetState) {
    if (targetState >= numStates) {
        currState = (numStates-1);
    } else {
        currState = targetState;
    }
    target = states[currState];

}


void lb_test_print() {
    std::cout << "current state: " << currState << "\n";
    std::cout << "target angle: " << target << "\n";
    std::cout << "Current position from lb sensor: " << ladyBrownSensor.get_position() / 100 << "\n";
}

void lb_task_func() {
    while (true)
    {
        //turn off auton control
      lb_liftControl_AUTON(false);
      //turn on opcontrol control
      lb_liftControl();
      pros::delay(ez::util::DELAY_TIME);
    }
}

void lb_task_func_AUTON() {
    while (true)
    {
        //turn off opcontrol control
      lb_liftControl(false);
      //turn on auton control
      lb_liftControl_AUTON();
      pros::delay(ez::util::DELAY_TIME);
    }
}
   
bool lb_finished = false;
void lb_liftControl_AUTON(bool enabled) {
if (enabled) {
    // lbPID.target_set(target);
    // if ((target <= 50)) {
    //     lb_kP = 4;
    // } else {
    //     lb_kP = 3.7;
    // }

    if ((target <= 50)) {
        lb_kP = 3;
    } else {
        lb_kP = 2.8;
    }
    double currentPos = -1 * (ladyBrownSensor.get_position() / 100.00);
    double error = target - currentPos;
    double velocity = lb_kP * error;
    // double velocity = lbPID.compute(currentPos);    
   
    // if ((error < 2) && (error > -2)) {
    //     velocity = 0;
    // }
    // if (error < -360) {
    //     velocity = 0;
    // }

    ladybrown.move(velocity);
}
}

void lb_wait() {
    double counter = 0;
    bool isDone = false;
    while (true) {
    double currentPos = -1 * (ladyBrownSensor.get_position() / 100.00);
    double error = target - currentPos;
        if (abs(error) <= 2) {
            isDone = true;
            break;
        }
        pros::delay(10);
        counter++;
        if ((isDone == false) && (counter >= 100)) {
            if ((abs(error) <= 5) || counter >= 400) {
                isDone = true;
                break;
            }
        }
    }
    
}

//degrees is how close it should be to the target before exiting
void lb_wait_until(double degrees) {
    double counter = 0;
    bool isDone = false;
    while (true) {
    double currentPos = -1 * (ladyBrownSensor.get_position() / 100.00);
    double error = target - currentPos;
        if (abs(error) <= degrees) {
            isDone = true;
            break;
        }
        pros::delay(10);
        counter++;
        if ((isDone == false) && (counter >= 400)) {
            isDone == true;
            break;
        }
    }
}
