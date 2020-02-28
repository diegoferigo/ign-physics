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

#ifndef IGNITION_PHYSICS_TPESIM_TPE_MODEL_HH_
#define IGNITION_PHYSICS_TPESIM_TPE_MODEL_HH_

#include <ignition/physics/Geometry.hh>

#include "ignition/physics/tpe/Entity.hh"

namespace ignition {
namespace physics {
namespace tpe {

class Link;

/// \brief Model class
class Model : public Entity
{
  /// \brief Constructor
  public: Model();

  /// \brief Constructor
  /// \param[in] _id Model id
  public: Model(uint64_t _id);

  /// \brief Destructor
  public: ~Model() = default;

  /// \brief Add a link
  /// \return Newly created Link
  public: Entity &AddLink();

  /// \brief Get a link
  /// \param[in] _linkName link name
  /// \return Link
  public: Entity &GetLinkByName(const std::string &_name);

  public: void SetLinearVelocity(const LinearVector3d _velocity);

  public: void SetAngularVelocity(const AngularVector3d _velocity);

  protected: LinearVector3d linearVelocity;

  protected: AngularVector3d angularVelocity;

};

}
}
}

#endif
