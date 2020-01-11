/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2019 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/PrintColor.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include "Robot.h"

PrintColor::PrintColor() {
  SetName("PrintColor");
  AddRequirements({myColorSensor});
}

// Called repeatedly when this Command is scheduled to run
void PrintColor::Execute() {
        frc::SmartDashboard::PutString("Wheel Color", myColorSensor->getColor());
     }

// Make this return true when this Command no longer needs to run execute()
bool PrintColor::IsFinished() { return false; }

// Called once after isFinished returns true
void PrintColor::End(bool) {  }

