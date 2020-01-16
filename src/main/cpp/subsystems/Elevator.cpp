/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2019 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#include <iostream> 
#include "subsystems/Elevator.h"

#include <frc/controller/PIDController.h>
#include <frc/livewindow/LiveWindow.h>
#include <frc/smartdashboard/SmartDashboard.h>
using namespace std; 
Elevator::Elevator()
    : frc2::PIDSubsystem(frc2::PIDController(kP_real, kI_real, 0)) {
#ifdef SIMULATION  // Check for simulation and update PID values
  GetPIDController()->SetPID(kP_simulation, kI_simulation, 0, 0);
#endif
  m_controller.SetTolerance(0.005);
  //David also likes comments...
  SetName("Elevator");
  elevatorMotor = new rev::CANSparkMax(41, rev::CANSparkMax::MotorType::kBrushless);
  //myPID = elevatorMotor->GetPIDController();
  elevatorPID = new rev::CANPIDController(*elevatorMotor);
  elevatorEncoder = new rev::CANEncoder(*elevatorMotor); 

  
  elevatorPID->SetP(0.0008);
  elevatorPID->SetI(0);
  elevatorPID->SetD(0.0032);

  //elevatorPID = elevatorMotor->GetPIDController(); 
  // Let's show everything on the LiveWindow
  // Corey added a comment to brandons file
  // Corey is trying to break git
  // Hello 

  // Corey is adding more code
 // AddChild("Motor", &m_motor);
  AddChild("Pot", &m_pot);
}

void Elevator::Log() { frc::SmartDashboard::PutData("Wrist Pot", &m_pot); 
frc::SmartDashboard::PutNumber("P GaiN", elevatorPID->GetP());
frc::SmartDashboard::PutNumber("Elevator Encoder Value", elevatorEncoder->GetPosition());
}

double Elevator::GetMeasurement() { return m_pot.Get(); }

void Elevator::UseOutput(double output, double setpoint) {
//m_motor.Set(output);
}

void Elevator::setElevator(double joyVal){
  elevatorMotor->Set(joyVal); 
}

void Elevator::setElevatorHeight(double setpoint){
  elevatorPID->SetReference(setpoint, rev::ControlType::kSmartMotion, 0);
}

//brandon
//test
//i have headache - sydsquid
//i have headache - sydsquid
// sorry about your headache - alex
