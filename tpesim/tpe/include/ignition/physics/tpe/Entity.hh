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
#include <map>
#include <ignition/math/Pose3.hh>

namespace ignition {
namespace physics {
namespace tpe {

/// \brief Represents an invalid Id.
static const uint64_t kNullEntityId = math::MAX_UI64;

class Entity
{
  /// \brief Constructor
  public: Entity();

  /// \brief Destructor
  public: ~Entity() = default;

  /// \brief Constructor with id
  /// \param[in] _id Id to set the entity to
  protected: explicit Entity(uint64_t _id);

  /// \brief Set the name of the entity
  /// \param[in] _name Name of entity
  public: virtual void SetName(const std::string &_name);

  /// \brief Get the name of the entity
  /// \return Name of entity
  public: virtual std::string GetName() const;

  /// \brief Set the id of the entity
  /// \param[in] _unique Id
  public: virtual void SetId(uint64_t _id);

  /// \brief Get the id of the entity
  /// \return Entity id
  public: virtual uint64_t GetId() const;

  /// \brief Set the pose of the entity
  /// \param[in] _pose Pose of entity to set to
  public: virtual void SetPose(const math::Pose3d &_pose);

  /// \brief Get the pose of the entity
  /// \return Pose of entity to set to
  public: virtual math::Pose3d GetPose() const;

  public: virtual void UpdatePose(double _timeStep);

  /// \brief Get a child entity by id
  /// \param[in] _id Id of child entity
  /// \return Child entity
  public: virtual Entity &GetChildById(uint64_t _id);

  /// \brief Remove a child entity by id
  /// \param[in] _id Id of child entity to remove
  public: virtual bool RemoveChildById(uint64_t _id);

  /// \brief Remove a child entity by name
  /// \param[in] _name Name of child entity to remove
  /// \return True if child entity was removed, false otherwise
  public: virtual bool RemoveChildByName(const std::string &_name);

  /// \brief Remove a child entity by index
  /// \param[in] _index Index of child entity to remove
  // public: virtual void RemoveChildByIndex(size_t _index);

  /// \brief Get number of children
  public: virtual size_t GetChildCount() const;

  /// \brief An invalid vertex.
  public: static Entity kNullEntity;

  /// \brief
  protected: static uint64_t GetNextId();

  /// \brief Name of entity
  protected: std::string name;

  /// \brief Entity pose
  protected: math::Pose3d pose;

  /// \brief Entity Id
  protected: uint64_t id;

  /// \brief Child entities
  protected: std::map<uint64_t, Entity> children;

  /// \brief Entity id counter
  private: static uint64_t nextId;
};


}
}
}

#endif
