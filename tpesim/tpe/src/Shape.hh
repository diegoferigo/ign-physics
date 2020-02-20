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

#ifndef IGNITION_PHYSICS_TPESIM_TPE_SHAPE_HH_
#define IGNITION_PHYSICS_TPESIM_TPE_SHAPE_HH_

#include <string>
#include <map>
#include <ignition/common/Mesh.hh>
#include <ignition/math/Vector3.hh>
#include <ignition/math/AxisAlignedBox.hh>

namespace ignition {
namespace physics {
namespace tpesim {

/// \brief Base shape geometry class
class Shape
{
  /// \brief Constructor
  public: Shape() = default;

  /// \brief Destructor
  public: ~Shape() = default;

  /// \brief Get bounding box of shape
  /// \return Shape's bounding box
  public: virtual math::AxisAlignedBox BoundingBox();

  /// \brief Update the shape's bounding box
  protected: virtual void UpdateBoundingBox() = 0;

   /// \brief Bounding Box
  protected: math::AxisAlignedBox bbox;

   /// \brief Flag to indicate if dimensions changed
  protected: bool dirty = false;
};

/// \brief Box geometry
class BoxShape : public Shape
{
  /// \brief Constructor
  public: BoxShape() = default;

  /// \brief Destructor
  public: ~BoxShape() = default;

  /// \brief Set size of box
  /// \param[in] _size Size of box
  public: void SetSize(const math::Vector3d &_size);

  // Documentation inherited
  protected: virtual void UpdateBoundingBox() override;

  /// \brief Size of box
  private: math::Vector3d size;
};

/// \brief Cylinder geometry
class CylinderShape : public Shape
{
  /// \brief Constructor
  public: CylinderShape() = default;

  /// \brief Destructor
  public: ~CylinderShape() = default;

  /// \brief Set cylinder radius
  /// \param[in] _radius Cylinder radius
  public: void SetRadius(double _radius);

  /// \brief Set cylinder length
  /// \param[in] _length Cylinder length
  public: void SetLength(double _length);

  // Documentation inherited
  protected: virtual void UpdateBoundingBox() override;

  /// \brief Cylinder radius
  private: double radius = 0.0;

  /// \brief Cylinder length
  private: double length = 0.0;
};

/// \brief Sphere geometry
class SphereShape : public Shape
{
  /// \brief Constructor
  public: SphereShape() = default;

  /// \brief Destructor
  public: ~SphereShape() = default;

  /// \brief Set sphere radius
  /// \param[in] _radius Sphere radius
  public: void SetRadius(double _radius);

  // Documentation inherited
  protected: virtual void UpdateBoundingBox() override;

  /// \brief Sphere radius
  private: double radius = 0.0;
};

/// \brief Mesh geometry
class MeshShape : public Shape
{
  /// \brief Constructor
  public: MeshShape() = default;

  /// \brief Destructor
  public: ~MeshShape() = default;

  /// \brief Set mesh
  /// \param[in] _mesh Mesh object
  public: void SetMesh(const ignition::common::Mesh &_mesh);

  /// \brief Set mesh scale
  /// \param[in] _scale Mesh scale
  public: void SetScale(double _scale);

  // Documentation inherited
  protected: virtual void UpdateBoundingBox() override;

  /// \brief Mesh scale
  private: double scale = 1.0;

  /// \brief Mesh object
  private: math::AxisAlignedBox meshAABB;
};
}
}
}

#endif
