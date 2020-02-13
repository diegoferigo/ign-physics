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

#include <string>

#include "EntityManagementFeatures.hh"

namespace ignition {
namespace physics {
namespace tpesim {

/////////////////////////////////////////////////
const std::string &EntityManagementFeatures::GetEngineName(
  const Identity &/*_engineID*/) const
{
  static const std::string engineName = "tpe"; // TODO[claire]: change to TPE API
  return engineName;
}

/////////////////////////////////////////////////
std::size_t EntityManagementFeatures::GetEngineIndex(
  const Identity &/*_engineID*/) const
{
  return 0;
}

/////////////////////////////////////////////////
std::size_t EntityManagementFeatures::GetWorldCount(
    const Identity &/*_engineID*/) const
{
  return worlds.size();
}

// const std::string &EntityManagementFeatures::GetWorldName(
//   const Identity &_worldID) const
// {
//   return this->worlds.at(_worldID)->name;
// }

/////////////////////////////////////////////////
// Identity EntityManagementFeatures::GetEngineOfWorld(
//   const Identity &/*_worldID*/) const
// {
//   return this->GenerateIdentity(0);
// }

}
}
}
