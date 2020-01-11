#include "commands/ElevatorJoyControl.h"

ElevatorJoyControl::ElevatorJoyControl(std::function<double()> xboxVal, Elevator* elevator)
: xboxValue(xboxVal), realElevator(elevator){

}

void ElevatorJoyControl::Execute(){

}