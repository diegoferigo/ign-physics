/*
 * Copyright (C) 2020 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/

#include "FreeGroupFeatures.hh"

namespace ignition {
namespace physics {
namespace tpesim {

/////////////////////////////////////////////////
Identity FreeGroupFeatures::FindFreeGroupForModel(
  const Identity &_modelID) const
{
}

/////////////////////////////////////////////////
Identity FreeGroupFeatures::FindFreeGroupForLink(
  const Identity &_linkID) const
{
}

/////////////////////////////////////////////////
Identity FreeGroupFeatures::GetFreeGroupCanonicalLink(
  const Identity &_groupID) const
{
}

/////////////////////////////////////////////////
void FreeGroupFeatures::SetFreeGroupWorldPose(
  const Identity &_groupID,
  const PoseType &_pose)
{
}

/////////////////////////////////////////////////
void FreeGroupFeatures::SetFreeGroupWorldLinearVelocity(
  const Identity &_groupID,
  const LinearVelocity &_linearVelocity)
{
}

/////////////////////////////////////////////////
void FreeGroupFeatures::SetFreeGroupWorldAngularVelocity(
  const Identity &_groupID, const AngularVelocity &_angularVelocity)
{
}

}
}
}
