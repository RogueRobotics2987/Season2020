/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Shooter.h"

Shooter::Shooter(){
  SetName("Shooter");
  shooterMotor = new rev::CANSparkMax(0, rev::CANSparkMax::MotorType::kBrushless);
}

void Shooter::HighGoal(){ shooterMotor->Set(0.77); }

void Shooter::Log() {}


// Put methods for controlling this subsystem
// here. Call these from Commands.
 