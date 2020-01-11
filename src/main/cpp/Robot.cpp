/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2019 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandScheduler.h>
#include "rev/ColorSensorV3.h"
#include <frc/TimedRobot.h>

void Robot::RobotInit() {}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want to run during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
static constexpr auto i2cPort = frc::I2C::Port::kOnboard;

rev::ColorSensorV3 m_colorSensor{i2cPort};

 std::string matching(frc::Color myColorSensor)
 {if ((myColorSensor.blue>=0.30) && 
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

 else if  ((myColorSensor.red<=0.47 && myColorSensor.red>=0.17) &&
 (myColorSensor.green<=0.70 && myColorSensor.green>=0.40) &&
 (myColorSensor.blue<=0.27 && myColorSensor.blue>=0.0))
 return "yellow";
 
   return "";
 }
  void RobotPeriodic() {
    /**
     * The method GetColor() returns a normalized color value from the sensor and can be
     * useful if outputting the color to an RGB LED or similar. To
     * read the raw color, use GetRawColor().
     * 
     * The color sensor works best when within a few inches from an object in
     * well lit conditions (the built in LED is a big help here!). The farther
     * an object is the more light from the surroundings will bleed into the 
     * measurements and make it difficult to accurately determine its color.
     */
    frc::Color myColorSensor = m_colorSensor.GetColor();

    /**
     * The sensor returns a raw IR value of the infrared light detected.
     */
    double IR = m_colorSensor.GetIR();

    /**
     * Open Smart Dashboard or Shuffleboard to see the color detected by the 
     * sensor.
     */
    frc::SmartDashboard::PutNumber("Red", myColorSensor.red);
    frc::SmartDashboard::PutNumber("Green", myColorSensor.green);
    frc::SmartDashboard::PutNumber("Blue", myColorSensor.blue);
    frc::SmartDashboard::PutNumber("IR", IR);
    frc::SmartDashboard::PutString("Wheel Color", matching(myColorSensor));

//std::string Bob= matching(myColorSensor);


    /**
     * In addition to RGB IR values, the color sensor can also return an 
     * infrared proximity value. The chip contains an IR led which will emit
     * IR pulses and measure the intensity of the return. When an object is 
     * close the value of the proximity will be large (max 2047 with default
     * settings) and will approach zero when the object is far away.
     * 
     * Proximity can be used to roughly approximate the distance of an object
     * or provide a threshold for when an object is close enough to provide
     * accurate color values.
     */
    uint32_t proximity = m_colorSensor.GetProximity();

    frc::SmartDashboard::PutNumber("Proximity",
     proximity);
  }
//void Robot::RobotPeriodic() { frc2::CommandScheduler::GetInstance().Run(); }

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
