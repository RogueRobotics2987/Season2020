/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <iostream>

#include "commands/ExampleCommand.h"

using namespace std;

ExampleCommand::ExampleCommand(DriveTrain* subsystem)
    : m_subsystem{subsystem} {
        AddRequirements({m_subsystem});
    }
    void ExampleCommand::Initialize() {
        cout << "this is Initialize" << endl;
    }
    void ExampleCommand::Execute() {
        cout << "this is Execute" << endl;
    m_subsystem->MoveForward();
    }