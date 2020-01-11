#pragma once 
#include <frc2/command/CommandHelper.h>
#include <frc2/command/PIDCommand.h>
#include "subsystems/Elevator.h" 

class ElevatorJoyControl: public frc2::CommandHelper<frc2::CommandBase, ElevatorJoyControl>{
    public:
        ElevatorJoyControl(std::function<double()> xboxVal, Elevator* elevator); 
        void Execute(); 
    private: 
        std::function<double()> xboxValue; 
        Elevator realElevator; 


};