#include "commands/setHeight.h" 
#include <frc/smartdashboard/SmartDashboard.h>

int x = 0; 
setHeight::setHeight(std::function<double()> setpoint, Elevator* mElevator)
: heightVal(setpoint), elevator(mElevator)
{
    AddRequirements(mElevator); 
    SetName("setHeight"); 
}

void setHeight::Execute(){
    frc::SmartDashboard::PutNumber("x", x); 
    x++; 

    elevator->setElevatorHeight(heightVal()); 


}

bool setHeight::isFinished(){
    return false; 
}

void setHeight::End(){
    
}



