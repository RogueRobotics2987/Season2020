/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/SpinWheel.h"

SpinWheel::SpinWheel(ColorSensor* mSensor):cSensor(mSensor) {
  AddRequirements(cSensor);
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void SpinWheel::Initialize() {
  cSensor->ResetNums(); 

}

// Called repeatedly when this Command is scheduled to run
void SpinWheel::Execute() {
  cSensor->SpinNum();

}

// Called once the command ends or is interrupted.
void SpinWheel::End(bool interrupted) {}

// Returns true when the command should end.
bool SpinWheel::IsFinished() { return false; }
