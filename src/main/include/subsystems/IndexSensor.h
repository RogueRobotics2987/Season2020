/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include <frc/DigitalInput.h>
#include <frc2/command/SubsystemBase.h>

class IndexSensor : public frc2::SubsystemBase {
 public:
  IndexSensor(

  

  );

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();
  void SomethingWithBalls();
  void Get();

 private:
  frc::DigitalInput * m_IndexSensor;
  int BallCount = 0;
  bool SucckyBoiIndexState = false;
  bool YeetIndexState = false;
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
