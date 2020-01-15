/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/ColorSensor.h"

ColorSensor::ColorSensor() : Subsystem("ColorSensor") {
  // Asigned the colorSensor pointer to a new i2cPort
  colorSensor = new rev::ColorSensorV3(i2cPort);

}

void ColorSensor::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
