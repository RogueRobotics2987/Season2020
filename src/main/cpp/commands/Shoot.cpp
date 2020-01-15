#include "commands/Shoot.h" 
#include "Robot.h" 

Shoot::Shoot(Shooter* pShooter): mShooter(pShooter){ 
    SetName("Shoot"); 
    AddRequirements(mShooter); 

}

void Shoot::Execute(){ 
    mShooter->HighGoal();


}
