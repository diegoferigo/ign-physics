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

#include "Engine.hh"
#include "World.hh"

using namespace ignition;
using namespace physics;
using namespace tpesim;

/////////////////////////////////////////////////
Engine::Engine()
{
}

/////////////////////////////////////////////////
World &Engine::AddWorld()
{
  World world;
  uint64_t worldId = world.GetId();
  const auto [it, success]  = this->worlds.insert({worldId, world});
  return it->second;
}

/////////////////////////////////////////////////
// World Engine::GetWorldByName(const std::string &_name) const
// {
//   for (auto const&[id, world] : this->worlds)
//   {
//     if (world.GetName() == _name)
//       return world;
//   }
//   ignerr << "The World [" << _name << "] does not exist." << std::endl;
// }

/////////////////////////////////////////////////
World Engine::GetWorldById(const int _id) const
{
  // return this->worlds[_id];
  auto it = this->worlds.find(_id);
  if (it != this->worlds.end())
  {
    return it->second;
  }

  return World::kNullWorld;
}
