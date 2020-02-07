/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"


RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem) {
  // Initialize all of your commands and subsystems here
  m_subsystem.SetDefaultCommand(ExampleCommand(&m_subsystem));
  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
  exampleButton.WhenPressed(ExampleCommand(&m_subsystem));
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}
