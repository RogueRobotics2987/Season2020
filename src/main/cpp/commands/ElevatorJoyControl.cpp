#include "commands/ElevatorJoyControl.h"

ElevatorJoyControl::ElevatorJoyControl(double motorOutput, Elevator* elevator)
: motorSpeed(motorOutput), realElevator(elevator){
    AddRequirements(realElevator);
    SetName("ElevatorJoyControl");

}

void ElevatorJoyControl::Execute(){
    realElevator->setElevator(motorSpeed); 

}