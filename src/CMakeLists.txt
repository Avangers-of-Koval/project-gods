# Generic test that uses conan libs
add_executable(intro main.cpp Player.h Entity.h TexturedEntity.h PhysicsEntity.h DebugObject.h)
target_link_libraries(
        intro
        PUBLIC project_options project_warnings
        PRIVATE raylib box2d)
