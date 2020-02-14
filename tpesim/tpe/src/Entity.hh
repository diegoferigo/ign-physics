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

#ifndef IGNITION_PHYSICS_TPESIM_TPE_ENTITY_HH_
#define IGNITION_PHYSICS_TPESIM_TPE_ENTITY_HH_

#include <string>
#include <ignition/math/Pose3.hh>

namespace ignition {
namespace physics {
namespace tpesim {

class Entity
{
  /// \brief Constructor
  public: Entity();

  /// \brief Destructor
  public: ~Entity();

  /// \brief Set the name of the entity
  public: virtual void SetName(const std::string &_name);

  /// \brief Set the pose of the entity
  public: virtual void SetPose(const math::Pose3d &_pose);

  /// \brief Name of entity
  protected: std::string name;

  /// \brief Entity pose
  protected: math::Pose3d pose;
};


}
}
}

#endif
