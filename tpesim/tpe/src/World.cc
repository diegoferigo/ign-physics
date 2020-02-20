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

#include "Model.hh"
#include "World.hh"

using namespace ignition;
using namespace physics;
using namespace tpesim;

uint64_t World::nextId = 0;
World World::kNullWorld = World(kNullWorldId);

/////////////////////////////////////////////////
World::World()
{
  this->id = World::GetNextId();
}

/////////////////////////////////////////////////
World::World(uint64_t _id)
{
  this->id = _id;
}

/////////////////////////////////////////////////
void World::SetId(uint64_t _id)
{
  this->id = _id;
}

/////////////////////////////////////////////////
uint64_t World::GetId() const
{
  return this->id;
}

/////////////////////////////////////////////////
void World::SetName(const std::string &_name)
{
  this->name = _name;
}

/////////////////////////////////////////////////
std::string World::GetName() const
{
  return this->name;
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
void World::Step()
{
  // only increment time for now, no model action yet
  this->time += this->timeStep;
}

/////////////////////////////////////////////////
Entity &World::AddModel()
{
  Model model;
  uint64_t modelId = model.GetId();
  const auto [it, success]  = this->models.insert({modelId, model});
  return it->second;
}

/////////////////////////////////////////////////
// bool World::HasModel(const std::string &_name)
// {
//   for (auto const& [mId, model] : this->models)
//   {
//     if (model.GetName() == _name)
//       return true;
//   }
//   return false;
// }

/////////////////////////////////////////////////
// bool World::HasModel(const int _id)
// {
//   for (auto const& [mId, model] : this->models)
//   {
//     if (mId == _id)
//       return true;
//   }
//   return false;
// }

/////////////////////////////////////////////////
bool World::RemoveModelByName(const std::string &_name)
{
  // if (World::HasModel(_name))
  // {
  //   auto m = World::GetModelByName(_name);
  //   this->models.erase(m->GetId());
  // }
  // else
  // {
  //   ignwarn << "This model with name [" << _name
  //     << "] does not exist" << std::endl;
  // }
  for (auto it = this->models.begin(); it != this->models.end(); ++it)
  {
    if (it->second.GetName() == _name)
    {
      this->models.erase(it);
      return true;
    }
  }
  return false;
}

/////////////////////////////////////////////////
bool World::RemoveModelById(int _id)
{
  // if (World::HasModel(_id))
  // {
  //   this->models.erase(_id);
  // }
  // else
  // {
  //   ignwarn << "This model with id [" << _id 
  //     << "] does not exist" << std::endl;
  // }
  auto it = this->models.find(_id);
  if (it != this->models.end())
  {
    this->models.erase(it);
    return true;
  }

  return false; 
}

/////////////////////////////////////////////////
size_t World::GetModelCount() const
{
  return this->models.size();
}

///////////////////////////////////////////////
Entity &World::GetModelByName(const std::string &_name)
{
  for (auto it = this->models.begin(); it != this->models.end(); ++it)
  {
    if (it->second.GetName() == _name)
    {
      return it->second;
    }
  }
  return Entity::kNullEntity;
}

/////////////////////////////////////////////////
Entity &World::GetModelById(int _id)
{
  auto it = this->models.find(_id);
  if (it != this->models.end())
  {
    return it->second;
  }

  return Entity::kNullEntity;
}

/////////////////////////////////////////////////
uint64_t World::GetNextId()
{
  return nextId++;
}
