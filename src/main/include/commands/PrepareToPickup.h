/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2019 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

#include "subsystems/Claw.h"
#include "subsystems/Elevator.h"
#include "subsystems/Wrist.h"

/**
 * Make sure the robot is in a state to pickup soda cans.
 */
class PrepareToPickup : public frc2::CommandHelper<frc2::SequentialCommandGroup,
                                                   PrepareToPickup> {
 public:
  PrepareToPickup(Claw* claw, Wrist* wrist, Elevator* elevator);
};
