#pragma once 
#include <frc2/command/CommandHelper.h>
#include <frc2/command/PIDCommand.h>
#include "subsystems/Elevator.h" 

class ElevatorJoyControl : public frc2::CommandHelper<frc2::CommandBase, ElevatorJoyControl>{
    public:
        ElevatorJoyControl(double motorOutput, Elevator* elevator); 
        void Execute(); 
    private: 
        double motorSpeed; 
        Elevator* realElevator; 


};