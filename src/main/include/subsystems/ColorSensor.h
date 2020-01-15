/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/util/Color.h>
#include "rev/ColorSensorV3.h"
#include "rev/ColorMatch.h"

class ColorSensor : public frc::Subsystem {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

 public:
  ColorSensor();
  // Made i2cPort and declared it to port type kOnboard
  // Made a pointer called ColorSensor
  rev::ColorSensorV3* colorSensor;
  static constexpr auto i2cPort = frc::I2C::Port::kOnboard;

  void InitDefaultCommand() override;
};
