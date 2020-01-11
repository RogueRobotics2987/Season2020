/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2019 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
 
#include "Robot.h"
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandScheduler.h>

void Robot::RobotInit() {}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want to run during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
// this is a whole bunch of new code I added to my personal branch that I wanna copy over eventually
// this is a whole bunch of new code I added to my personal branch that I wanna copy over eventually
// this is a whole bunch of new code I added to my personal branch that I wanna copy over eventually
// this is a whole bunch of new code I added to my personal branch that I wanna copy over eventually
// this is a whole bunch of new code I added to my personal branch that I wanna copy over eventually
// this is a whole bunch of new code I added to my personal branch that I wanna copy over eventually
// this is a whole bunch of new code I added to my personal branch that I wanna copy over eventually
// this is a whole bunch of new code I added to my personal branch that I wanna copy over eventually
// this is a whole bunch of new code I added to my personal branch that I wanna copy over eventually
// this is a whole bunch of new code I added to my personal branch that I wanna copy over eventually
// this is a whole bunch of new code I added to my personal branch that I wanna copy over eventually
// this is a whole bunch of new code I added to my personal branch that I wanna copy over eventually
// this is a whole bunch of new code I added to my personal branch that I wanna copy over eventually
// this is a whole bunch of new code I added to my personal branch that I wanna copy over eventually
// this is a whole bunch of new code I added to my personal branch that I wanna copy over eventually
// this is a whole bunch of new code I added to my personal branch that I wanna copy over eventually
// this is a whole bunch of new code I added to my personal branch that I wanna copy over eventually
// this is a whole bunch of new code I added to my personal branch that I wanna copy over eventually
// this is a whole bunch of new code I added to my personal branch that I wanna copy over eventually
void Robot::RobotPeriodic() { frc2::CommandScheduler::GetInstance().Run(); }
//test
//test
/**
 * This function is called once each time the robot enters Disabled mode. You
 * can use it to reset any subsystem information you want to clear when the
 * robot is disabled.
 */
void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

/**
 * This autonomous runs the autonomous command selected by your {@link
 * RobotContainer} class.
 */
void Robot::AutonomousInit() {
  m_autonomousCommand = m_container.GetAutonomousCommand();

  if (m_autonomousCommand != nullptr) {
    m_autonomousCommand->Schedule();
  }
}

void Robot::AutonomousPeriodic() {

}

void Robot::TeleopInit() {
  // This makes sure that the autonomous stops running when
  // teleop starts running. If you want the autonomous to
  // continue until interrupted by another command, remove
  // this line or comment it out.
  if (m_autonomousCommand != nullptr) {
    m_autonomousCommand->Cancel();
    m_autonomousCommand = nullptr;
  }
}

/**
 * This function is called periodically during operator control.
 */
void Robot::TeleopPeriodic() {
  
 //    PULLING LIMELIGHT DATA FROM NETWORK TABLE
    std::shared_ptr<NetworkTable> table = nt::NetworkTableInstance::GetDefault().GetTable("limelight-rr");
    double targetValidity = table->GetNumber("tv",0.0);
    double targetOffsetAngle_Horizontal = table->GetNumber("tx",0.0);
    double targetOffsetAngle_Vertical = table->GetNumber("ty",0.0);
    double targetArea = table->GetNumber("ta",0.0);
    double targetSkew = table->GetNumber("ts",0.0);
    double targetLatency = table->GetNumber("tl",0.0);
    double targetLengthShortSide = table->GetNumber("tshort",0.0);
    double targetLengthLongSide = table->GetNumber("tlong",0.0);
    double targetHorizontalLength = table->GetNumber("thor",0.0);
    double targetVerticalLength = table->GetNumber("tvert",0.0);
    double targetPipe = table->GetNumber("getpipe",0.0);
    double targetTranslation = table->GetNumber("camtran",0.0);

    bool tarVal = targetValidity;

    //    DISPLAYING LIMELIGHT DATA TO SMART DASHBOARD
    frc::SmartDashboard::PutBoolean("Target Validity", tarVal);     //check shuffleboard docs on r/g boolean tabs instead of text
    frc::SmartDashboard::PutNumber("Target Offset Angle (Horizontal)", targetOffsetAngle_Horizontal);
    frc::SmartDashboard::PutNumber("Target Offset Angle (Vertical)", targetOffsetAngle_Vertical);
    frc::SmartDashboard::PutNumber("Target Area", targetArea);
    frc::SmartDashboard::PutNumber("Target Skew", targetSkew);
    frc::SmartDashboard::PutNumber("Target Latency", targetLatency);
    frc::SmartDashboard::PutNumber("Target Length (Short Side)", targetLengthShortSide);
    frc::SmartDashboard::PutNumber("Target Length (Long Side)", targetLengthLongSide);
    frc::SmartDashboard::PutNumber("Target Length (Horizontal)", targetHorizontalLength);
    frc::SmartDashboard::PutNumber("Target Length (Vertical)", targetVerticalLength);
    frc::SmartDashboard::PutNumber("Target Pipe", targetPipe);
    frc::SmartDashboard::PutNumber("Target Translation", targetTranslation);

  // NON CMD-BASED Approach:
  //drive robot 
    //joystick input
      // 2 axis
        // x and y
    //send joystick input to drivetrain
  
  // get the 2 joystick objects (joyLeft, joyRight)
  // get drivetrain object (DiffDrivetrain)
  // DiffDrivetrain.Drive(joyLeft.getYAxis(), joyRight.getYAxis())




}

/**
 * This function is called periodically during test mode.
 */
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
