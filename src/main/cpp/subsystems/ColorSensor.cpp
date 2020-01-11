/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2019 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/ColorSensor.h"


// coreys code is now different than brandons!
ColorSensor::ColorSensor() {
    i2cPort = frc::I2C::Port::kOnboard;
}
std::string ColorSensor::getColor(){
    myColorSensor = m_colorSensor.GetColor();
    // double IR = m_colorSensor.GetIR();
    // uint32_t proximity = m_colorSensor.GetProximity();

    // frc::SmartDashboard::PutNumber("Proximity",
    //  proximity);

    // frc::SmartDashboard::PutNumber("Red", myColorSensor.red);
    // frc::SmartDashboard::PutNumber("Green", myColorSensor.green);
    // frc::SmartDashboard::PutNumber("Blue", myColorSensor.blue);
    // frc::SmartDashboard::PutNumber("IR", IR);
    // frc::SmartDashboard::PutString("Wheel Color", matching(myColorSensor));





    if ((myColorSensor.blue>=0.30) && 
 (myColorSensor.green>myColorSensor.blue) &&
 (myColorSensor.green>myColorSensor.red))
 return "blue";

 else if  ((myColorSensor.green>myColorSensor.blue) &&
 (myColorSensor.green>myColorSensor.red) &&
 (abs(myColorSensor.red-myColorSensor.blue)<=.07)
 )
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
 
   return "";



}
