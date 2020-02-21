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

#include <ignition/physics/Implements.hh>

namespace ignition {
namespace physics {
namespace tpesim {

struct WorldInfo
{
  World* world;
  std::string name;
};

struct ModelInfo
{
  Model* model;
  std::string name;
  Identity world;
};

struct LinkInfo
{
  Link* link;
  std::string name;
  Identity model;
};

class Base: public Implements3d<FeatureList<Feature>>
{
  public: using WorldInfoPtr = std::shared_ptr<WorldInfo>;
  public: using ModelInfoPtr = std::shared_ptr<ModelInfo>;
  public: using LinkInfoPtr = std::shared_ptr<LinkInfo>;

  public: using Identity = ignition::physics::Identity;

  public: std::size_t entityCount = 0;
  
  public: inline std::size_t GetNextEntity()
  {
    return entityCount++;
  }

  public: inline Identity InitiateEngine(std::size_t /*_engineID*/) override
  {
    // tpesim does not have multiple engines
    return this->GenerateIdentity(0);
  }

  public: inline Identity AddWorld(WorldInfo _worldInfo)
  {
    const auto id = this->GetNextEntity();
    this->worlds[id] = std::make_shared<WorldInfo>(_worldInfo);
    return this->GenerateIdentity(id, this->worlds.at(id));
  }

  public: inline Identity AddModel(ModelInfo _modelInfo)
  {
    const auto id = this->GetNextEntity();
    this->models[id] = std::make_shared<ModelInfo>(_modelInfo);
    return this->GenerateIdentity(id, this->models.at(id));
  }

  public: inline Identity AddLink(LinkInfo _linkInfo)
  {
    const auto id = this->GetNextEntity();
    this->links[id] = std::make_shared<LinkInfo>(_linkInfo);
    return this->GenerateIdentity(id, this->links.at(id));
  }

  // public: Engine engine;
  public: std::map<std::size_t, WorldInfoPtr> worlds;
  public: std::map<std::size_t, ModelInfoPtr> models;
  public: std::map<std::size_t, LinkInfoPtr> links;
};

}
}
}

#endif
