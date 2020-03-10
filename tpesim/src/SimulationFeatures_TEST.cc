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

#include <ignition/math/Vector3.hh>
#include <ignition/math/eigen3/Conversions.hh>

#include <ignition/physics/FindFeatures.hh>
#include <ignition/plugin/Loader.hh>
#include <ignition/physics/RequestEngine.hh>

// Features
#include <ignition/physics/ForwardStep.hh>
#include <ignition/physics/GetEntities.hh>
#include <ignition/physics/Shape.hh>
#include <ignition/physics/sdf/ConstructWorld.hh>

#include <sdf/World.hh>

#include <test/PhysicsPluginsList.hh>
#include <test/Utils.hh>

struct TestFeatureList : ignition::physics::FeatureList<
  ignition::physics::ForwardStep,
  ignition::physics::GetEngineInfo,
  ignition::physics::GetWorldFromEngine,
  ignition::physics::GetModelFromWorld,
  ignition::physics::GetLinkFromModel,
  ignition::physics::GetShapeFromLink,
  ignition::physics::GetShapeBoundingBox,
  ignition::physics::sdf::ConstructSdfWorld
> { };

using TestWorldPtr = ignition::physics::World3dPtr<TestFeatureList>;
using TestShapePtr = ignition::physics::Shape3dPtr<TestFeatureList>;

std::unordered_set<TestWorldPtr> LoadWorlds(
    const std::string &_library,
    const std::string &_world)
{
  ignition::plugin::Loader loader;
  loader.LoadLib(_library);

  const std::set<std::string> pluginNames =
      ignition::physics::FindFeatures3d<TestFeatureList>::From(loader);

  EXPECT_LT(0u, pluginNames.size());
  std::unordered_set<TestWorldPtr> worlds;

  return worlds;
}

class SimulationFeatures_TEST
  : public ::testing::Test,
    public ::testing::WithParamInterface<std::string>
{};


INSTANTIATE_TEST_CASE_P(PhysicsPlugins, SimulationFeatures_TEST,
    ::testing::ValuesIn(ignition::physics::test::g_PhysicsPluginLibraries),); // NOLINT

int main(int argc, char *argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
