/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#include <iostream>
#include "subsystems/IndexSensor.h"

IndexSensor::IndexSensor() {
    m_IndexSensor = new frc::DigitalInput(0);
    
    
}
void IndexSensor::Get(){
   bool m_output = m_IndexSensor->Get();

   std::cout<<"m_output = "<< m_output <<std::endl;
   
    // std::cout<<"hello world"<<std::endl;

}



// This method will be called once per scheduler run
void IndexSensor::Periodic() {



}
