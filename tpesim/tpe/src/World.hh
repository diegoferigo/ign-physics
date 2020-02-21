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

#ifndef IGNITION_PHYSICS_TPESIM_TPE_WORLD_HH_
#define IGNITION_PHYSICS_TPESIM_TPE_WORLD_HH_

#include <string>
#include <map>

#include "Model.hh"

namespace ignition {
namespace physics {
namespace tpesim {
  class World
  {
    /// \brief Constructor
    public: World();

    /// \brief Destructor
    public: virtual ~World() = default;

    /// \brief Constructor with id
    /// \param[in] _id Id to set the world to
    protected: explicit World(uint64_t _id);

    /// \brief Set the name of the world
    /// \param[in] _name world name
    public: void SetName(const std::string &_name);

    /// \brief Get the name of the world
    /// \return World name
    public: std::string GetName() const;

    // /// \brief Set the id of the world
    // /// \param[in] _unique Id
    // public: virtual void SetId(uint64_t _id);

    // /// \brief Get the id of the world
    // /// \return World id
    // public: virtual uint64_t GetId() const;

    /// \brief Set the time of the world
    /// \param _time time of the world
    public: void SetTime(double _time);

    /// \brief Get the time of the world
    /// \return double current time of the world
    public: double GetTime();

    /// \brief Step forward at a constant timestep
    public: void Step();

    /// \brief Add a model to this world
    /// \return Model addded to the world
    public: Entity &AddModel();

    // /// \brief Check if world has a specific model
    // /// \param _name model name
    // public: bool HasModel(const std::string &_name);

    // /// \brief Check if world has a specific model
    // /// \param _id model id
    // public: bool HasModel(const int _id);

    /// \brief Remove a specified model
    /// \param _name model name
    public: bool RemoveModelByName(const std::string &_name);

    /// \brief Remove a specified model
    /// \param _id model id
    public: bool RemoveModelById(const int _id);

    /// \brief Get total amount of models in the world
    /// \return number of models
    public: virtual size_t GetModelCount() const;

    /// \brief Get model from current world
    /// \param _name model name 
    /// \return pointer to the model object
    public: Entity &GetModelByName(const std::string &_name);

    /// \brief Get model from current world
    /// \param _id model id
    /// \return pointer to the model object
    public: Entity &GetModelById(int _id);

    /// \brief increment world id once it's created
    // protected: static size_t GetNextId();

    /// \brief An invalid vertex.
    // public: static World kNullWorld;

    /// \brief Name of world
    protected: std::string name;

    /// \brief World time
    protected: double time{0.0};

    /// \brief Time step size
    protected: double timeStep{0.1};

    /// \brief World Id
    protected: uint64_t id;

    /// \brief Models inside World
    protected: std::map<uint64_t, Entity> models;

    /// \brief Entity id counter
    // private: static uint64_t nextId;

  };

} // namespace tpe
} // namespace physics
} // namespace ignition


#endif