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


#include <ignition/common/Console.hh>

#include "Entity.hh"

using namespace ignition;
using namespace physics;
using namespace tpesim;

uint64_t Entity::nextId = 0;
Entity Entity::kNullEntity = Entity(kNullEntityId);

//////////////////////////////////////////////////
Entity::Entity()
{
  this->id = Entity::GetNextId();
}

//////////////////////////////////////////////////
Entity::Entity(uint64_t _id)
{
  this->id = _id;
}

//////////////////////////////////////////////////
void Entity::SetName(const std::string &_name)
{
  this->name = _name;
}

//////////////////////////////////////////////////
std::string Entity::GetName() const
{
  return this->name;
}

//////////////////////////////////////////////////
void Entity::SetPose(const math::Pose3d &_pose)
{
  this->pose = _pose;
}

//////////////////////////////////////////////////
math::Pose3d Entity::GetPose() const
{
  return this->pose;
}

//////////////////////////////////////////////////
void Entity::SetId(uint64_t _id)
{
  this->id = _id;
}

//////////////////////////////////////////////////
uint64_t Entity::GetId() const
{
  return this->id;
}

//////////////////////////////////////////////////
Entity &Entity::GetChildById(uint64_t _id)
{
  auto it = this->children.find(_id);
  if (it != this->children.end())
  {
    return it->second;
  }

  return kNullEntity;
}

//////////////////////////////////////////////////
bool Entity::RemoveChildById(uint64_t _id)
{
  // for (size_t i = 0; i < this->children.size(); ++i)
  // {
  //   if (this->children[i].GetId() == _id)
  //   {
  //     this->children.erase(this->children.begin() + i);
  //     return;
  //   }
  // }
  auto it = this->children.find(_id);
  if (it != this->children.end())
  {
    this->children.erase(it);
    return true;
  }

  return false;
}

//////////////////////////////////////////////////
bool Entity::RemoveChildByName(const std::string &_name)
{
//  for (size_t i = 0; i < this->children.size(); ++i)
//  {
//    if (this->children[i]->GetName() == _name)
//    {
//      this->children.erase(this->children.begin() + i);
//      return;
//    }
//  }

  for (auto it = this->children.begin(); it != this->children.end(); ++it)
  {
    if (it->second.GetName() == _name)
    {
      this->children.erase(it);
      return true;
    }
  }
  return false;
}

// ///////////////////////////////////////////////
// void Entity::RemoveChildByIndex(size_t _index)
// {
//   if (_index >= this->children.size())
//   {
//     ignerr << "Unable to remove child with index " << _index << std::endl;
//     return;
//   }
//
//   this->children.erase(this->children.begin() + _index);
// }

//////////////////////////////////////////////////
size_t Entity::GetChildCount() const
{
  return this->children.size();
}

//////////////////////////////////////////////////
uint64_t Entity::GetNextId()
{
  return nextId++;
}
