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

#ifndef IGNITION_PHYSICS_TPESIM_TPE_ENGINE_HH_
#define IGNITION_PHYSICS_TPESIM_TPE_ENGINE_HH_

#include <string>
#include <map>

#include "World.hh"

namespace ignition
{
namespace physics
{
namespace tpesim
{
  class Engine
  {
    /// \brief Constructor
    public: Engine();

    /// \brief Destructor
    public: ~Engine() = default;

    /// \brief Add world to engine
    /// \brief assume one world per engine
    /// \param[in] _name world name
    public: World &AddWorld();

    // public: World &GetWorldByName(const std::string &_world_name) const;

    /// \brief Get the world object from engine
    /// \param[in] _id world id
    public: World GetWorldById(const int _id) const;

    /// \brief List of worlds attach to this engine
    /// \brief Only support one world per engine
    protected: std::map<uint64_t, World> worlds{};

  };
} // namespace tpe
} // namespace physics
} // namespace ignition

#endif