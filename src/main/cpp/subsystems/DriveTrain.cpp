/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2019 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/DriveTrain.h"

#include <frc/Joystick.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include "AHRS.h"

// coreys code is now different than brandons!
DriveTrain::DriveTrain() {
// Encoders may measure differently in the real world and in
// simulation. In this example the robot moves 0.042 barleycorns
// per tick in the real world, but the simulated encoders
// simulate 360 tick encoders. This if statement allows for the
// real robot to handle this difference in devices.
#ifndef SIMULATION
  // m_leftEncoder.SetDistancePerPulse(0.042);
  // m_rightEncoder.SetDistancePerPulse(0.042);
#else
  // Circumference in ft = 4in/12(in/ft)*PI
  // m_leftEncoder.SetDistancePerPulse(static_cast<double>(4.0 / 12.0 * M_PI) /
  //                                   360.0);
  // m_rightEncoder.SetDistancePerPulse(static_cast<double>(4.0 / 12.0 * M_PI) /
  //                                    360.0);
#endif
  SetName("DriveTrain");
  //LeftBack = new rev::CANSparkMax(44, rev::CANSparkMax::MotorType::kBrushless);
  LeftFront = new rev::CANSparkMax(43, rev::CANSparkMax::MotorType::kBrushless);
  //RightBack = new rev::CANSparkMax(40, rev::CANSparkMax::MotorType::kBrushless);
  RightFront = new rev::CANSparkMax(42, rev::CANSparkMax::MotorType::kBrushless);
  myAhrs = new AHRS(SerialPort::kMXP); 



  m_robotDrive = new frc::DifferentialDrive(*LeftFront, *RightFront);
 // m_odometry = new frc::DifferentialDriveOdometry{frc::Rotation2d(units::degree_t(GetHeading()))}

  // Let's show everything on the LiveWindow
  // AddChild("Front_Left Motor", &m_frontLeft);
  // AddChild("Rear Left Motor", &m_rearLeft);
  // AddChild("Front Right Motor", &m_frontRight);
  // AddChild("Rear Right Motor", &m_rearRight);
  // AddChild("Left Encoder", &m_leftEncoder);
  // AddChild("Right Encoder", &m_rightEncoder);
  // AddChild("Rangefinder", &m_rangefinder);
  // AddChild("Gyro", &m_gyro);
}

void DriveTrain::Log() {
  // frc::SmartDashboard::PutNumber("Left Distance", m_leftEncoder.GetDistance());
  // frc::SmartDashboard::PutNumber("Right Distance",
  //                                m_rightEncoder.GetDistance());
  // frc::SmartDashboard::PutNumber("Left Speed", m_leftEncoder.GetRate());
  // frc::SmartDashboard::PutNumber("Right Speed", m_rightEncoder.GetRate());
  // frc::SmartDashboard::PutNumber("Gyro", m_gyro.GetAngle());
}

void DriveTrain::Drive(double left, double right) { 
  //leftFrontEncoder->SetDistancePerPulse();
  m_robotDrive->ArcadeDrive(-left, right);
}

double DriveTrain::GetHeading() { 
myAhrs->GetAngle(); }

void DriveTrain::Reset() {
  // m_gyro.Reset();
  // m_leftEncoder.Reset();
  // m_rightEncoder.Reset();
}

double DriveTrain::GetDistance() {
  // return (m_leftEncoder.GetDistance() + m_rightEncoder.GetDistance()) / 2.0;
  return 0;
}

double DriveTrain::GetDistanceToObstacle() {
  // Really meters in simulation since it's a rangefinder...
  // return m_rangefinder.GetAverageVoltage();
  return 0;
}
