#pragma once 
#include "subsystems/Shooter.h" 
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "Robot.h" 

class Shoot : public frc2::CommandHelper<frc2::CommandBase, Shoot>{
    public:
        Shoot(Shooter* pShooter); 
        void Execute(); 


    private: 
        Shooter* mShooter; 


};