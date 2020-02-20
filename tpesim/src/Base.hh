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

#include "../tpe/src/Engine.hh"
#include "../tpe/src/World.hh"

#include <ignition/physics/Implements.hh>

namespace ignition {
namespace physics {
namespace tpesim {

class Base: public Implements3d<FeatureList<Feature>>
{
  public: using Identity = ignition::physics::Identity;

  public: Identity InitiateEngine(std::size_t /*_engineID*/) override
  {
    auto world = this->engine.AddWorld();
    // tpesim does not have multiple engines
    return this->GenerateIdentity(0);
  }

  public: Engine engine;
};

}
}
}

#endif