/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/DigitalInput.h>
#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>
#include <frc/Timer.h>

class Intake : public frc2::SubsystemBase {
 public:
  Intake();
  void startIntake();
  void startConveyor();
  void testIntake();

  //test intake variables
  bool testButton;


  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  rev::CANSparkMax* intakeMotor;
  rev::CANSparkMax* pusherMotor;
  rev::CANSparkMax* conveyorMotor;
  frc::DigitalInput* sensorA;
  frc::DigitalInput* sensorB;
  int state = 0;
  frc::Timer* conveyorTimer;
  double initTime = 0; 

  //test state machine
  rev::CANSparkMax* testMotor;
  frc::DigitalInput* testSensor;
  int testState = 0;
};
