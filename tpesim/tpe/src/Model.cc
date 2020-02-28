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

#include "ignition/physics/tpe/Link.hh"
#include "ignition/physics/tpe/Model.hh"

using namespace ignition;
using namespace physics;
using namespace tpe;

//////////////////////////////////////////////////
Model::Model() : Entity()
{
}

//////////////////////////////////////////////////
Model::Model(uint64_t _id) : Entity(_id)
{
}

//////////////////////////////////////////////////
Entity &Model::AddLink()
{
  // Link link;
  // uint64_t linkId = link.GetId();
  uint64_t linkId = Entity::GetNextId();
  const auto [it, success]  = this->GetChildren().insert(
      {linkId, std::make_shared<Link>(linkId)});
  return *it->second.get();
}

//////////////////////////////////////////////////
Entity &Model::GetLinkByName(const std::string &_name)
{
  auto children = this->GetChildren();
  for (auto it = children.begin(); it != children.end(); ++it)
  {
    if (it->second->GetName() == _name)
    {
      return *it->second.get();
    }
  }
  return Entity::kNullEntity;
}

//////////////////////////////////////////////////
void Model::SetLinearVelocity(const LinearVector3d _velocity)
{
  this->linearVelocity = _velocity;
}

//////////////////////////////////////////////////
void Model::SetAngularVelocity(const AngularVector3d _velocity)
{
  this->angularVelocity = _velocity;
}
