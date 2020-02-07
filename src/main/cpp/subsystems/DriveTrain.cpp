/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/DriveTrain.h"

DriveTrain::DriveTrain() {
    Motor = new rev::CANSparkMax(49, rev::CANSparkMax::MotorType::kBrushless);
    Motor2 = new rev::CANSparkMax(56, rev::CANSparkMax::MotorType::kBrushless);
    Driver = new frc::DifferentialDrive(*Motor, *Motor2);
}

// This method will be called once per scheduler run
void DriveTrain::Periodic() {}
void DriveTrain::MoveForward(){
    Driver->ArcadeDrive(0.2, 0.2);
}
