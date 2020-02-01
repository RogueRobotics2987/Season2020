/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include <frc2/command/SubsystemBase.h>

#include <frc/commands/Subsystem.h>
#include "rev/CANSparkMax.h"


class Shooter : public frc2::SubsystemBase {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
  
 public:
  Shooter();
  rev::CANSparkMax* shooterMotor;

  void Log() ;
  void HighGoal() ;
  
};
