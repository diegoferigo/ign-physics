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

#include <gtest/gtest.h>

#include "Collision.hh"
#include "Shape.hh"

using namespace ignition;
using namespace physics;
using namespace tpe;

/////////////////////////////////////////////////
TEST(Collision, BasicAPI)
{
  Collision collision;
  collision.SetId(1234u);
  EXPECT_EQ(1234u, collision.GetId());

  collision.SetName("collision_1");
  EXPECT_EQ("collision_1", collision.GetName());

  collision.SetPose(math::Pose3d(1, 2, 3, 0.1, 0.2, 0.3));
  EXPECT_EQ(math::Pose3d(1, 2, 3, 0.1, 0.2, 0.3), collision.GetPose());

  Collision collision2;
  EXPECT_NE(collision.GetId(), collision2.GetId());
}

/////////////////////////////////////////////////
TEST(Collision, BoxShape)
{
  Collision collision;
  BoxShape boxShape;
  collision.SetShape(boxShape);
  Shape shape = collision.GetShape();
  BoxShape *box = static_cast<BoxShape *>(&shape);
  EXPECT_NE(nullptr, box);

//  Collision collision;
//  EXPECT_EQ(0u, collision.GetBoxShapeCount());
//
//  // add a box shape
//  BoxShape boxShape = collision.AddBoxShape();
//  EXPECT_EQ(1u, collision.GetBoxShapeCount());
//
//  BoxShape *box = static_cast<BoxShape *>(&boxShape);
//  EXPECT_NE(nullptr, box);
}

/////////////////////////////////////////////////
TEST(Collision, CylinderShape)
{
  Collision collision;
  CylinderShape cylinderShape;
  collision.SetShape(cylinderShape);
  Shape shape = collision.GetShape();
  CylinderShape *cylinder = static_cast<CylinderShape *>(&shape);
  EXPECT_NE(nullptr, cylinder);

//  Collision collision;
//  EXPECT_EQ(0u, collision.GetCylinderShapeCount());
//
//  // add a cylinder shape
//  CylinderShape cylinderShape = collision.AddCylinderShape();
//  EXPECT_EQ(1u, collision.GetCylinderShapeCount());
//
//  CylinderShape *cylinder = static_cast<CylinderShape *>(&cylinderShape);
//  EXPECT_NE(nullptr, cylinder);
}

/////////////////////////////////////////////////
TEST(Collision, SphereShape)
{
  Collision collision;
  SphereShape sphereShape;
  collision.SetShape(sphereShape);
  Shape shape = collision.GetShape();
  SphereShape *sphere = static_cast<SphereShape *>(&shape);
  EXPECT_NE(nullptr, sphere);

//  Collision collision;
//  EXPECT_EQ(0u, collision.GetSphereShapeCount());
//
//  // add a sphere shape
//  SphereShape sphereShape = collision.AddSphereShape();
//  EXPECT_EQ(1u, collision.GetSphereShapeCount());
//
//  SphereShape *sphere = static_cast<SphereShape *>(&sphereShape);
//  EXPECT_NE(nullptr, sphere);
}

/////////////////////////////////////////////////
TEST(Collision, MeshShape)
{
  Collision collision;
  MeshShape meshShape;
  collision.SetShape(meshShape);
  Shape shape = collision.GetShape();
  MeshShape *mesh = static_cast<MeshShape *>(&shape);
  EXPECT_NE(nullptr, mesh);

//  Collision collision;
//  EXPECT_EQ(0u, collision.GetMeshShapeCount());
//
//  // add a mesh shape
//  MeshShape meshShape = collision.AddMeshShape();
//  EXPECT_EQ(1u, collision.GetMeshShapeCount());
//
//  MeshShape *mesh = static_cast<MeshShape *>(&meshShape);
//  EXPECT_NE(nullptr, mesh);
}
