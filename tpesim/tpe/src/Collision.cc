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

#include "Collision.hh"
#include "Shape.hh"

using namespace ignition;
using namespace physics;
using namespace tpesim;

//////////////////////////////////////////////////
Collision::Collision() : Entity()
{
}

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
