/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/ColorSensor.h"

ColorSensor::ColorSensor() {
  // Asigned the colorSensor pointer to a new i2cPort
  colorSensor = new rev::ColorSensorV3(i2cPort);
  myColorSensor = colorSensor->GetColor();
}

std::string ColorSensor::GetColor(){
  
  if ((myColorSensor.blue>=0.30) && 
       (myColorSensor.green>myColorSensor.blue) &&
       (myColorSensor.green>myColorSensor.red))
        return "blue";

    else if ((myColorSensor.green>myColorSensor.blue) &&
            (myColorSensor.green>myColorSensor.red) &&
            (abs(myColorSensor.red-myColorSensor.blue)<=.07))
            return "green";

    else if  (((myColorSensor.red>myColorSensor.blue) &&
             (myColorSensor.red>myColorSensor.green))
             || (abs(myColorSensor.red-myColorSensor.green)<=.1)
             )
             return "red";

    else if  ((myColorSensor.green>myColorSensor.blue) &&
             (myColorSensor.green>myColorSensor.red)
             )
             return "yellow";

    else{
    return "";
    }

}
void ColorSensor::PrintColor(){
  frc::SmartDashboard::PutString("Wheel Color", GetColor());

}
