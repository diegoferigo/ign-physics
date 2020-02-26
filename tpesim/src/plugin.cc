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

// #include <string>

#include <ignition/physics/Register.hh>

#include "EntityManagementFeatures.hh"
#include "FreeGroupFeatures.hh"
#include "SimulationFeatures.hh"

namespace ignition {
namespace physics {
namespace tpesim {

struct TpesimFeatures : FeatureList<
  EntityManagementFeatureList,
  FreeGroupFeatureList,
  SimulationFeatureList
> { };

class Plugin :
  public virtual Implements3d<TpesimFeatures>,
  public virtual Base,
  public virtual EntityManagementFeatures,
  public virtual FreeGroupFeatures,
  public virtual SimulationFeatures { };

IGN_PHYSICS_ADD_PLUGIN(Plugin, FeaturePolicy3d, TpesimFeatures)

}
}
}
