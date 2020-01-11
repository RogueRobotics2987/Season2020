/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2019 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include "rev/ColorSensorV3.h"

// #include <frc/AnalogGyro.h>
// #include <frc/AnalogInput.h>
// #include <frc/Encoder.h>
// #include <frc/PWMVictorSPX.h>
// #include <frc/Sh>
// #include <frc/drive/DifferentialDrive.h>
#include <frc2/command/SubsystemBase.h>
// #include "rev/CANSparkMax.h"


// namespace frc {
// class Joystick;
// }  // namespace frc

/**
 * The DriveTrain subsystem incorporates the sensors and actuators attached to
 * the robots chassis. These include four drive motors, a left and right encoder
 * and a gyro.
 */
class ColorSensor : public frc2::SubsystemBase {
 public:
  ColorSensor();
std::string getColor();

 
 private:
    frc::I2C::Port i2cPort;
    rev::ColorSensorV3 m_colorSensor{i2cPort};
    frc::Color myColorSensor;


};
