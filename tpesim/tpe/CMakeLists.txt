# set (tpe_sources
#   src/Collision.cc
#   src/Engine.cc
#   src/Link.cc
#   src/Model.cc
#   src/World.cc
# )

ign_get_libsources_and_unittests(sources test_sources)

message("========================== sources: $sources") 

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

# install(TARGETS ${rendering_target} DESTINATION ${IGN_LIB_INSTALL_DIR})

