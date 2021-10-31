add_library(
    Engine 
    engine.cpp
    controller/controller.cpp
    core/gameObject.cpp
    renderer/renderer.cpp
    sprite/sprite.cpp
)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

target_include_directories(
    Engine 
    PUBLIC ${CMAKE_SOURCE_DIR}/include
    PUBLIC ${CMAKE_SOURCE_DIR}/src/engine
    PRIVATE ${SDL2_INCLUDE_DIRS}
    PRIVATE ${SDL2_IMAGE_INCLUDE_DIRS}
)

string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)      # TODO why this is needed?

target_link_libraries(
    Engine
    ${SDL2_LIBRARIES}
)

target_compile_features(
    Engine
    PUBLIC cxx_std_17
)
