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

#ifndef IGNITION_PHYSICS_TPESIM_BASE_HH_
#define IGNITION_PHYSICS_TPESIM_BASE_HH_

#include <map>
#include <string>

#include "../tpe/src/Engine.hh"
#include "../tpe/src/World.hh"
#include "../tpe/src/Model.hh"
#include "../tpe/src/Link.hh"
#include "../tpe/src/Collision.hh"
#include "../tpe/src/Shape.hh"

#include <ignition/physics/Implements.hh>

namespace ignition {
namespace physics {
namespace tpesim {

/// \brief The structs ModelInfo, LinkInfo, JointInfo, and ShapeInfo are used
/// for two reasons:
/// 1) Holding extra information such as the name or offset
///    that will be different from the underlying engine
/// 2) Wrap shared pointers to DART entities. Since these shared pointers (eg.
///    dart::dynamics::BodyNodePtr) are different from std::shared_ptr, we
///    cannot use them directly as parameters to GenerateIdentity. Instead we
///    create a std::shared_ptr of the struct that wraps the corresponding DART
///    shared pointer.

class Base : public Implements3d<FeatureList<Feature>>
{

  public: inline Identity InitiateEngine(std::size_t /*_engineID*/) override
  {
    // tpesim does not have multiple "engines"
    return this->GenerateIdentity(0);
  }

  public: inline Identity AddWorld(World world)
  {
    auto worldPtr = std::make_shared<World>(world);
    this->worlds.insert({world.GetId(), worldPtr});

    return this->GenerateIdentity(world.GetId(), worldPtr);
  }

  public: inline Identity AddModel(uint64_t _worldId, Model model)
  {
    auto modelPtr = std::make_shared<Model>(model);
    this->models.insert({model.GetId(), modelPtr});
    this->childIdToParentId.insert({model.GetId(), _worldId});

    return this->GenerateIdentity(model.GetId(), modelPtr);
  }

  public: inline Identity AddLink(uint64_t _modelId, Link link)
  {
    auto linkPtr = std::make_shared<Link>(link);
    this->links.insert({link.GetId(), linkPtr});
    this->childIdToParentId.insert({link.GetId(), _modelId});

    return this->GenerateIdentity(link.GetId(), linkPtr);
  }

  public: std::map<uint64_t, std::shared_ptr<World>> worlds;
  public: std::map<uint64_t, std::shared_ptr<Model>> models;
  public: std::map<uint64_t, std::shared_ptr<Link>> links;
  public: std::map<uint64_t, std::shared_ptr<Collision>> collisions;
  public: std::map<uint64_t, uint64_t> childIdToParentId;
};

}
}
}

#endif
