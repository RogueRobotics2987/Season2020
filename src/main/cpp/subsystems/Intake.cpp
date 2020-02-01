/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Intake.h"

Intake::Intake() {
    sensorA = new frc::DigitalInput(6);
    sensorB = new frc::DigitalInput(7);
    intakeMotor = new rev::CANSparkMax{0, rev::CANSparkMax::MotorType::kBrushless};
    pusherMotor = new rev::CANSparkMax{0, rev::CANSparkMax::MotorType::kBrushless};
    conveyorMotor = new rev::CANSparkMax{0, rev::CANSparkMax::MotorType::kBrushless};
    conveyorTimer = new frc::Timer;
    conveyorTimer->Start(); 

    //test stuff
    testButton = false;
    testSensor = new frc::DigitalInput(8);
    testMotor = new rev::CANSparkMax{49, rev::CANSparkMax::MotorType::kBrushless};
}

// This method will be called once per scheduler run
void Intake::Periodic() {
    testIntake();
}

void Intake::startIntake() {
    if(state == 0){
        intakeMotor->Set(0.3);
        pusherMotor->Set(0.3);
        if(sensorA->Get()){
            pusherMotor->Set(0);
            state = 1;
            initTime = conveyorTimer->Get(); 
        }
    }
    if(state == 1){
       conveyorMotor->Set(0.3);
       if((conveyorTimer->Get() - initTime) > .5){
        state = 2; 
        conveyorMotor->Set(0);
       }    
    }
    if(state == 2){
        state = 0;
    }
}

void Intake::startConveyor() {

}

void Intake::testIntake(){
    if(testState == 0){
        testMotor->Set(0);
        if(testButton){
            testState = 1;
        }
    }
    if(testState == 1){
        testMotor->Set(0.5);
        testButton = false;
        if(testSensor->Get()){
            testState = 0;
        }
    }
}