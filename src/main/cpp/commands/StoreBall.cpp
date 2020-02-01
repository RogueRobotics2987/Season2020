/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/StoreBall.h"

StoreBall::StoreBall(Intake* a_Intake) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(m_Intake);
  m_Intake = a_Intake;
}

// Called when the command is initially scheduled.
void StoreBall::Initialize() {
  m_Intake->testButton = true;
}

// Called repeatedly when this Command is scheduled to run
void StoreBall::Execute() {}

// Called once the command ends or is interrupted.
void StoreBall::End(bool interrupted) {}

// Returns true when the command should end.
bool StoreBall::IsFinished() { return true; }
