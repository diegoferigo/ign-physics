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

#include <ignition/math/Pose3.hh>

#include "Model.hh"
#include "World.hh"

using namespace ignition;
using namespace physics;
using namespace tpesim;

/////////////////////////////////////////////////
World::World() : Entity()
{
}

/////////////////////////////////////////////////
void World::SetTime(double _time)
{
  this->time = _time;
}

/////////////////////////////////////////////////
double World::GetTime()
{
  return this->time;
}

/////////////////////////////////////////////////
void World::SetTimeStep(double _timeStep)
{
  this->timeStep = _timeStep;
}

/////////////////////////////////////////////////
double World::GetTimeStep()
{
  return this->timeStep;
}

/////////////////////////////////////////////////
void World::Step()
{
  // apply updates to each model
  for (auto it = children.begin(); it != children.end(); ++it)
  {
    auto &model = it->second;
    model.UpdatePose(this->timeStep);
  }

  // increment world time by step size
  this->time += this->timeStep;
}

/////////////////////////////////////////////////
Entity &World::AddModel()
{
  Model model;
  uint64_t modelId = model.GetId();
  const auto [it, success]  = this->children.insert({modelId, model});
  return it->second;
}

///////////////////////////////////////////////
Entity &World::GetModelByName(const std::string &_name)
{
  for (auto it = this->children.begin(); it != this->children.end(); ++it)
  {
    if (it->second.GetName() == _name)
    {
      return it->second;
    }
  }
  return Entity::kNullEntity;
}
