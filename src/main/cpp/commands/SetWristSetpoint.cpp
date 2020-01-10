/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2019 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/SetWristSetpoint.h"

#include "Robot.h"

SetWristSetpoint::SetWristSetpoint(double setpoint, Wrist* wrist)
    : m_setpoint(setpoint), m_wrist(wrist) {
  SetName("SetWristSetpoint");
  AddRequirements({m_wrist});
}

// Called just before this Command runs the first time
void SetWristSetpoint::Initialize() {
  m_wrist->SetSetpoint(m_setpoint);
  m_wrist->Enable();
}

// Make this return true when this Command no longer needs to run execute()
bool SetWristSetpoint::IsFinished() {
  return m_wrist->GetController().AtSetpoint();
}
