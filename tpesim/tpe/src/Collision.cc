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

#include "ignition/physics/tpe/Collision.hh"
#include "ignition/physics/tpe/Shape.hh"

/// \brief Private data class for Collision
class ignition::physics::tpe::CollisionPrivate
{
  /// \brief Collision's geometry shape
  public: std::shared_ptr<Shape> shape = nullptr;
};

using namespace ignition;
using namespace physics;
using namespace tpe;

//////////////////////////////////////////////////
Collision::Collision()
  : Entity(), dataPtr(new CollisionPrivate)
{
}

//////////////////////////////////////////////////
Collision::Collision(uint64_t _id)
  : Entity(_id), dataPtr(new CollisionPrivate)
{
}

//////////////////////////////////////////////////
Collision::Collision(const Collision &_other)
  : Entity(), dataPtr(new CollisionPrivate)
{
  this->dataPtr->shape = _other.dataPtr->shape;
}

//////////////////////////////////////////////////
Collision &Collision::operator=(const Collision &_other)
{
  return *this = Collision(_other);
}

//////////////////////////////////////////////////
Collision::~Collision()
{
  delete this->dataPtr;
  this->dataPtr = nullptr;
}

//////////////////////////////////////////////////
void Collision::SetShape(const Shape &_shape)
{
  // \todo(anyone) use templates?
  if (_shape.GetType() == ShapeType::BOX)
  {
    const BoxShape *typedShape = static_cast<const BoxShape *>(&_shape);
    this->dataPtr->shape.reset(new BoxShape(*typedShape));
  }
  else if (_shape.GetType() == ShapeType::CYLINDER)
  {
    const CylinderShape *typedShape = static_cast<const CylinderShape *>(&_shape);
    this->dataPtr->shape.reset(new CylinderShape(*typedShape));
  }
  else if (_shape.GetType() == ShapeType::SPHERE)
  {
    const SphereShape *typedShape = dynamic_cast<const SphereShape *>(&_shape);
    this->dataPtr->shape.reset(new SphereShape(*typedShape));
  }
  else if (_shape.GetType() == ShapeType::MESH)
  {
    const MeshShape *typedShape = dynamic_cast<const MeshShape *>(&_shape);
    this->dataPtr->shape.reset(new MeshShape(*typedShape));
  }
  else
  {
  }
}

//////////////////////////////////////////////////
Shape *Collision::GetShape() const
{
  return this->dataPtr->shape.get();
}

/*
//////////////////////////////////////////////////
BoxShape Collision::AddBoxShape()
{
  BoxShape newShape;
  this->boxShapes.push_back(newShape);
  return newShape;
}

//////////////////////////////////////////////////
std::vector<BoxShape> Collision::GetBoxShapes()
{
  return this->boxShapes;
}

//////////////////////////////////////////////////
uint64_t Collision::GetBoxShapeCount()
{
  return this->boxShapes.size();
}

//////////////////////////////////////////////////
CylinderShape Collision::AddCylinderShape()
{
  CylinderShape newShape;
  this->cylinderShapes.push_back(newShape);
  return newShape;
}

//////////////////////////////////////////////////
std::vector<CylinderShape> Collision::GetCylinderShapes()
{
  return this->cylinderShapes;
}

//////////////////////////////////////////////////
uint64_t Collision::GetCylinderShapeCount()
{
  return this->cylinderShapes.size();
}

//////////////////////////////////////////////////
SphereShape Collision::AddSphereShape()
{
  SphereShape newShape;
  this->sphereShapes.push_back(newShape);
  return newShape;
}

//////////////////////////////////////////////////
std::vector<SphereShape> Collision::GetSphereShapes()
{
  return this->sphereShapes;
}

//////////////////////////////////////////////////
uint64_t Collision::GetSphereShapeCount()
{
  return this->sphereShapes.size();
}

//////////////////////////////////////////////////
MeshShape Collision::AddMeshShape()
{
  MeshShape newShape;
  this->meshShapes.push_back(newShape);
  return newShape;
}

//////////////////////////////////////////////////
std::vector<MeshShape> Collision::GetMeshShapes()
{
  return this->meshShapes;
}

//////////////////////////////////////////////////
uint64_t Collision::GetMeshShapeCount()
{
  return this->meshShapes.size();
}
*/
