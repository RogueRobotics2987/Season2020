/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/button/JoystickButton.h>

#include "commands/CloseClaw.h"
#include "commands/OpenClaw.h"
#include "commands/Pickup.h"
#include "commands/Place.h"
#include "commands/PrepareToPickup.h"
#include "commands/SetElevatorSetpoint.h"
#include "commands/TankDrive.h"
#include "commands/ElevatorJoyControl.h"
#include "commands/setHeight.h" 

RobotContainer::RobotContainer()
    : m_autonomousCommand(&m_claw, &m_wrist, &m_elevator, &m_drivetrain) {
  frc::SmartDashboard::PutData(&m_drivetrain);
  frc::SmartDashboard::PutData(&m_elevator);
  frc::SmartDashboard::PutData(&m_wrist);
  frc::SmartDashboard::PutData(&m_claw);

  m_claw.Log();
  m_wrist.Log();
  m_elevator.Log();
  m_drivetrain.Log();

  m_drivetrain.SetDefaultCommand(TankDrive(
      [this] { return m_joy.GetY(); },
      [this] { return m_joy.GetZ(); },
      &m_drivetrain));
  m_elevator.SetDefaultCommand(ElevatorJoyControl([this]{ return xbox.GetRawAxis(3) * .5;}, &m_elevator));

  // Configure the button bindings
  ConfigureButtonBindings();
}


void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here

  frc2::JoystickButton j1{&m_joy, 1}; 
  
    
 j1.WhenPressed(setHeight([this]{return 10;}, &m_elevator)); 
 

}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}
