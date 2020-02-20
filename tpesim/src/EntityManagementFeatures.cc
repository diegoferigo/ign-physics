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
  static const std::string engineName = "tpe";
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
  return engine.GetWorldCount();
}

/////////////////////////////////////////////////
Identity EntityManagementFeatures::GetWorld(
    const Identity &, std::size_t _worldIndex) const
{
  // assuming worldIndex is the same as worldId
  auto world = engine.GetWorldById(_worldIndex);
  auto worldPtr = std::make_shared<World>(world);
  return this->GenerateIdentity(_worldIndex, worldPtr);
}

/////////////////////////////////////////////////
Identity EntityManagementFeatures::GetWorld(
    const Identity &, const std::string &_worldName) const
{
  auto world = engine.GetWorldByName(_worldName);
  auto worldPtr = std::make_shared<World>(world);
  return this->GenerateIdentity(world.GetId(), worldPtr);
}

/////////////////////////////////////////////////
const std::string &EntityManagementFeatures::GetWorldName(
    const Identity &_worldID) const
{
  // assuming worldIndex is the same as worldId
  auto world = engine.GetWorldById(_worldID);
  return world.GetName();
}

/////////////////////////////////////////////////
std::size_t EntityManagementFeatures::GetWorldIndex(
    const Identity &_worldID) const
{
  // assuming worldIndex is the same as worldId
  return _worldID;
}

/////////////////////////////////////////////////
Identity EntityManagementFeatures::GetEngineOfWorld(
  const Identity &/*_worldID*/) const
{
  return this->GenerateIdentity(0);
}

}
}
}
