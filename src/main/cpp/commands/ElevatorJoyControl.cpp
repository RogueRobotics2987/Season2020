#include "commands/ElevatorJoyControl.h"

ElevatorJoyControl::ElevatorJoyControl(std::function<double()> xboxVal, Elevator* elevator) {
    xboxValue = xboxVal;
    realElevator = elevator;
    AddRequirements(realElevator);
    SetName("ElevatorJoyControl");

}

void ElevatorJoyControl::Execute(){
    realElevator->setElevator(xboxValue()); 

}