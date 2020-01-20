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
  myColorSensor = colorSensor->GetColor(); 
  if ((myColorSensor.blue>=0.35) && 
       (myColorSensor.green>myColorSensor.blue) &&
       (myColorSensor.blue>myColorSensor.red))
        return "red"; //color sensor reads blue, shield generator reads red

    else if ((myColorSensor.green>myColorSensor.blue) &&
            (myColorSensor.blue>myColorSensor.red) &&
            (abs(myColorSensor.red-myColorSensor.blue)<=.07))
            return "yellow"; //color sensor reads green, shield generator reads yellow

    else if  ((myColorSensor.green>myColorSensor.red) &&
             (myColorSensor.red>myColorSensor.blue)
             )
             return "green"; //color sensor reads yellow, shield generator reads green

    else if  (((myColorSensor.red>myColorSensor.blue) &&
             (myColorSensor.blue>myColorSensor.green))
             || (abs(myColorSensor.red-myColorSensor.green)<=.1)
             )
             return "blue";//color sensor reads red, shield generator reads blue

    else{
    return "";
    }

}
void ColorSensor::PrintColor(){
  frc::SmartDashboard::PutNumber("Red Value", myColorSensor.red); 
  frc::SmartDashboard::PutNumber("Green Value", myColorSensor.green); 
  frc::SmartDashboard::PutNumber("Blue Value", myColorSensor.blue); 

  frc::SmartDashboard::PutString("Shield Generator Color", GetColor());

}
