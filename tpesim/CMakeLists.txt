add_subdirectory(tpe)

# This component expresses custom features of the dartsim plugin, which can
# expose native dartsim data types.
ign_add_component(tpesim INTERFACE
  DEPENDS_ON_COMPONENTS sdf mesh
  GET_TARGET_NAME features)

target_link_libraries(${features} INTERFACE)
target_include_directories(${features} SYSTEM INTERFACE)

ign_get_libsources_and_unittests(sources test_sources)

# TODO(MXG): Think about an ign_add_plugin(~) macro for ign-cmake
ign_add_component(tpesim-plugin
  SOURCES ${sources}
  DEPENDS_ON_COMPONENTS tpesim
  GET_TARGET_NAME tpesim_plugin)

target_link_libraries(${tpesim_plugin}
  PUBLIC
    ${features}
    ${PROJECT_LIBRARY_TARGET_NAME}-sdf
    ${PROJECT_LIBRARY_TARGET_NAME}-mesh
    ignition-common${IGN_COMMON_VER}::ignition-common${IGN_COMMON_VER}
    ignition-math${IGN_MATH_VER}::eigen3)

# We need to link this, even when the profiler isn't used to get headers.
target_link_libraries(${tpesim_plugin}
  PRIVATE
  ignition-common${IGN_COMMON_VER}::profiler
)

# add test later
