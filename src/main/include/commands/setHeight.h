#pragma once 
#include "subsystems/Elevator.h" 
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>


class setHeight : public frc2::CommandHelper<frc2::CommandBase, setHeight>{ 
    public: 
        setHeight(std::function<double()> setPoint, Elevator* mElevator); 
        void Execute(); 
        bool isFinished(); 
        void End(); 



    private: 
        Elevator* elevator; 
        std::function<double()> heightVal; 


};

