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

#ifndef IGNITION_PHYSICS_TPESIM_SRC_GETENTITIESFEATURE_HH_
#define IGNITION_PHYSICS_TPESIM_SRC_GETENTITIESFEATURE_HH_

#include <string>

#include <ignition/physics/ConstructEmpty.hh>
#include <ignition/physics/GetEntities.hh>
#include <ignition/physics/RemoveEntities.hh>
#include <ignition/physics/Implements.hh>

#include "Base.hh"

namespace ignition {
namespace physics {
namespace tpesim {

struct EntityManagementFeatureList : FeatureList<
  GetEngineInfo,
  GetWorldFromEngine,
  GetModelFromWorld,
  GetLinkFromModel,
  RemoveEntities,
  ConstructEmptyWorldFeature,
  ConstructEmptyModelFeature,
  ConstructEmptyLinkFeature
> { };

class EntityManagementFeatures :
  public virtual Base,
  public virtual Implements3d<EntityManagementFeatureList>
{
  // ----- Get entities -----
  public: const std::string &GetEngineName(const Identity &) const override;

  public: std::size_t GetEngineIndex(const Identity &) const override;

  public: std::size_t GetWorldCount(const Identity &) const override;

  public: Identity GetWorld(
    const Identity &, std::size_t /*_worldIndex*/) const override;
    // { return this->GenerateInvalidId(); };

  public: Identity GetWorld(
    const Identity &, const std::string &/*_worldName*/) const override;
    // { return this->GenerateInvalidId(); };

  public: const std::string &GetWorldName(
    const Identity &_worldID) const override;

  public: std::size_t GetWorldIndex(
    const Identity &/*_worldID*/) const override;
    // { return 0; };

  public: Identity GetEngineOfWorld(
    const Identity &/*_worldID*/) const override;

  public: std::size_t GetModelCount(
    const Identity &_worldID) const override;

  public: Identity GetModel(
    const Identity &_worldID, std::size_t _modelIndex) const override;

  public: Identity GetModel(
    const Identity &_worldID, const std::string &_modelName) const override;

  public: const std::string &GetModelName(
    const Identity &_modelID) const override;

  public: std::size_t GetModelIndex(const Identity &_modelID) const override;

  public: Identity GetWorldOfModel(const Identity &_modelID) const override;

  public: std::size_t GetLinkCount(const Identity &_modelID) const override;

  public: Identity GetLink(
    const Identity &_modelID, std::size_t _linkIndex) const override;

  public: Identity GetLink(
    const Identity &_modelID, const std::string &_linkName) const override;

  public: const std::string &GetLinkName(
    const Identity &_linkID) const override;

  public: std::size_t GetLinkIndex(const Identity &_linkID) const override;

  public: Identity GetModelOfLink(const Identity &_linkID) const override;

  // ----- Remove entities -----
  public: bool RemoveModelByIndex(
    const Identity &_worldID, std::size_t _modelIndex) override;

  public: bool RemoveModelByName(
    const Identity &_worldID, const std::string &_modelName) override;

  public: bool RemoveModel(const Identity &_modelID) override;

  public: bool ModelRemoved(const Identity &_modelID) const override;

  // ----- Construct empty entities -----
  public: Identity ConstructEmptyWorld(
    const Identity &_engineID, const std::string &_name) override;

  public: Identity ConstructEmptyModel(
    const Identity &_worldID, const std::string &_name) override;

  public: Identity ConstructEmptyLink(
    const Identity &_modelID, const std::string &_name) override;
};

}
}
}

#endif