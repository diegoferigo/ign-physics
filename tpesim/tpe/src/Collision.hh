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

#ifndef IGNITION_PHYSICS_TPESIM_TPE_COLLISISION_HH_
#define IGNITION_PHYSICS_TPESIM_TPE_COLLISISION_HH_

#include "Entity.hh"
#include "Shape.hh"

namespace ignition {
namespace physics {
namespace tpesim {

/// \brief Collision class
class Collision : public Entity
{
  /// \brief Constructor
  public: Collision();

  /// \brief Destructor
  public: ~Collision() = default;

  /// \brief Add shape to collision
  /// \return Box geometry
  public: BoxShape &AddBoxShape();

  /// \brief Get all box shapes in collision
  /// \return boxShapes vector
  public: std::vector<BoxShape> GetBoxShapes();

  /// \brief Get number of box shapes
  /// \return number of box shapes
  public: uint64_t GetBoxShapeCount();

  /// \brief Add shape to collision
  /// \return Cylinder geometry
  public: CylinderShape &AddCylinderShape();

  /// \brief Get cylinder shapes
  /// \return cylinderShape vector
  public: std::vector<CylinderShape> GetCylinderShapes();

  /// \brief Get number of cylinder shapes
  /// \return Number of cylinder shapes
  public: uint64_t GetCylinderShapeCount();

  /// \brief Add shape to collision
  /// \return Sphere geometry
  public: SphereShape &AddSphereShape();

  /// \brief Get sphere shapes
  /// \return sphereShapes vector
  public: std::vector<SphereShape> GetSphereShapes();

  /// \brief Get number of sphere shapes
  /// \return number of sphere shapes
  public: uint64_t GetSphereShapeCount();

  /// \brief Add shape to collision
  /// \return Mesh geometry
  public: MeshShape &AddMeshShape();

  /// \brief Get mesh shapes
  /// \return meshShapes vector
  public: std::vector<MeshShape> GetMeshShapes();

  /// \brief Get number of mesh shapes
  /// \return number of mesh shapes
  public: uint64_t GetMeshShapeCount();

  protected: std::vector<BoxShape> boxShapes;

  protected: std::vector<CylinderShape> cylinderShapes;

  protected: std::vector<SphereShape> sphereShapes;

  protected: std::vector<MeshShape> meshShapes;
};

}
}
}

#endif
