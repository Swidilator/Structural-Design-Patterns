cmake_minimum_required(VERSION 3.28)
project(Structural_Design_Patters)

if (CMAKE_EXPORT_COMPILE_COMMANDS)
    set(CMAKE_CXX_STANDARD_INCLUDE_DIRECTORIES ${CMAKE_CXX_IMPLICIT_INCLUDE_DIRECTORIES})
endif ()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})


set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)
#set(CMAKE_CXX_FLAGS "-###")
#set(CMAKE_CXX_COMPILER clang++)

# 01_Adapter
add_executable(01_Adapter patterns/01_Adapter/main_01_adapter.cpp)
add_subdirectory(patterns/01_Adapter/adapter_basic)
add_subdirectory(patterns/01_Adapter/adapter_flight_simulator)

# 02_Facade
add_executable(02_Facade patterns/02_Facade/main_02_facade.cpp)
add_subdirectory(patterns/02_Facade/facade_basic_example)
# [TODO]removed due to windows/linux differences, needs to be fixed
#add_subdirectory(patterns/02_Facade/facade_console_project)

# 03_Proxy
add_executable(03_Proxy patterns/03_Proxy/main_03_proxy.cpp)
add_subdirectory(patterns/03_Proxy/proxy_basic_example)
add_subdirectory(patterns/03_Proxy/proxy_virtual_proxy)
add_subdirectory(patterns/03_Proxy/proxy_protection_proxy)
# [TODO]removed due to windows/linux differences, needs to be fixed
#add_subdirectory(patterns/03_Proxy/proxy_remote_proxy)
add_subdirectory(patterns/03_Proxy/proxy_smart_proxy)

# 04_Decorator
add_executable(04_Decorator patterns/04_Decorator/main_04_decorator.cpp)
add_subdirectory(patterns/04_Decorator/decorator_01_basic_example)
add_subdirectory(patterns/04_Decorator/decorator_02_stream_library)
add_subdirectory(patterns/04_Decorator/decorator_03_static)
add_subdirectory(patterns/04_Decorator/decorator_04_functional)

# 05_Composite
add_executable(05_Composite patterns/05_Composite/main_05_composite.cpp)
add_subdirectory(patterns/05_Composite/composite_01_basic_example)
add_subdirectory(patterns/05_Composite/composite_02_ui_composite)

# 06_Bridge
add_executable(06_Bridge patterns/06_Bridge/main_06_bridge.cpp)
# simple2d libs, installed with simple2d.sh on Linux (https://github.com/simple2d/simple2d)
# build above with clang using CC=clang when installing
if (WIN32)
    set(SIMPLE2D_INSTALL_DIR "C:/Users/Kyle/AppData/Local/simple2d")
    target_link_libraries(06_Bridge ${SIMPLE2D_INSTALL_DIR}/simple2d.lib)

    target_include_directories(06_Bridge PUBLIC ${SIMPLE2D_INSTALL_DIR})
    target_include_directories(06_Bridge PUBLIC ${SIMPLE2D_INSTALL_DIR}/SDL2)
endif (WIN32)

if (LINUX)
    set(SIMPLE2D_LIBS -lsimple2d -I/usr/include/SDL2 -D_REENTRANT -lSDL2 -lGL -lm -lSDL2_image -lSDL2_mixer -lSDL2_ttf)
    target_link_libraries(06_Bridge ${SIMPLE2D_LIBS})
endif (LINUX)
add_subdirectory(patterns/06_Bridge)
add_subdirectory(patterns/06_Bridge/bridge_01_basic_example)
add_subdirectory(patterns/06_Bridge/bridge_02_shapes)
add_subdirectory(patterns/06_Bridge/bridge_03_shapes_bridge)
add_subdirectory(patterns/06_Bridge/bridge_04_shared_implementation)
add_subdirectory(patterns/06_Bridge/bridge_05_PIMPL)

# 07_Flyweight
add_executable(07_Flyweight patterns/07_Flyweight/main_07_flyweight.cpp)
add_subdirectory(patterns/07_Flyweight/flyweight_01_basic_example)
add_subdirectory(patterns/07_Flyweight/flyweight_02_game_assets)