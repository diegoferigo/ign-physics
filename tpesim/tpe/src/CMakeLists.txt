ign_get_libsources_and_unittests(sources test_sources)

ign_add_component(tpe
  SOURCES ${sources}
  GET_TARGET_NAME tpe_target
  CXX_STANDARD 17)

target_link_libraries(${tpe_target}
  PUBLIC
  PRIVATE
    ignition-common${IGN_COMMON_VER}::ignition-common${IGN_COMMON_VER}
    # ignition-plugin${IGN_PLUGIN_VER}::register
)

target_include_directories(${tpe_target}
  PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

