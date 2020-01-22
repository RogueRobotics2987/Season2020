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
  curColor = colorSensor->GetColor();

  spinner = new rev::CANSparkMax(0, rev::CANSparkMax::MotorType::kBrushless); //a random motor was assigned, don't know what motor will be used on the actual robot
}

std::string ColorSensor::GetColor(){
  curColor = colorSensor->GetColor(); 
  if ((curColor.blue>=0.35) && 
       (curColor.green>curColor.blue) &&
       (curColor.blue>curColor.red))
        return "R"; //color sensor reads blue, shield generator reads red

    else if ((curColor.green>curColor.blue) &&
            (curColor.blue>curColor.red) &&
            (abs(curColor.red-curColor.blue)<=.07))
            return "Y"; //color sensor reads green, shield generator reads yellow

    else if  ((curColor.green>curColor.red) &&
             (curColor.red>curColor.blue)
             )
             return "G"; //color sensor reads yellow, shield generator reads green

    else if  (((curColor.red>curColor.blue) &&
             (curColor.blue>curColor.green))
             || (abs(curColor.red-curColor.green)<=.1)
             )
             return "B";//color sensor reads red, shield generator reads blue

    else{
    return "";
    }
}

std::string ColorSensor::GetGameData(){
   gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
  
  if(gameData.length() > 0 && gameData == GetColor()){
    return "T";
  } else{
    return "F";
  }
}

void ColorSensor::SetMotor(){
  spinner->Set(.3);
}

void ColorSensor::SpinNum(){
  static std::string ogColor = GetColor();
  if(onColor && ogColor == GetColor()){
    colorCount++;
    onColor = false; 
  }

  else if(ogColor != GetColor()){
    onColor = true; 
  }

  //To get number of rotations of table use formula
  // (colorCount - 1)/2
  if((colorCount- 1)/2 < 3.5){
    spinner -> Set(.3);
  }
  else {
    spinner -> Set(0);
}
  frc::SmartDashboard::PutNumber("Color count", colorCount); 

}

void ColorSensor::ResetNums(){
  colorCount = 0; 

}

void ColorSensor::PrintColor(){
  frc::SmartDashboard::PutNumber("Red Value", curColor.red); 
  frc::SmartDashboard::PutNumber("Green Value", curColor.green); 
  frc::SmartDashboard::PutNumber("Blue Value", curColor.blue); 

  frc::SmartDashboard::PutString("Shield Generator Color", GetColor());
  frc::SmartDashboard::PutString("Game Data Match", GetGameData());
  frc::SmartDashboard::PutString("Game Data", gameData);
  
}
