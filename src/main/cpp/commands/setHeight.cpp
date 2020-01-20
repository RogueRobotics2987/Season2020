#include "commands/setHeight.h" 
#include <frc/smartdashboard/SmartDashboard.h>
#include <iostream>

int x = 0; 
setHeight::setHeight(double setpoint, Elevator* mElevator)
{
    heightVal = setpoint; 
    elevator = mElevator; 
    AddRequirements(mElevator); 
    SetName("setHeight"); 
    std::cout << "setHeight ctor" << std::endl;
}

void setHeight::Initialize(){
    std::cout << "init" << std::endl;
    frc::SmartDashboard::PutString("X initialize", "Yes"); 
}
void setHeight::Execute(){
    std::cout << "execute" <<std::endl;
    frc::SmartDashboard::PutNumber("x", x); 
    x++; 

    //elevator->setElevatorHeight(heightVal); 


}

bool setHeight::isFinished(){
    return false; 
}

void setHeight::End(){
    x = 999; 
    frc::SmartDashboard::PutNumber("End X", x); 
}



