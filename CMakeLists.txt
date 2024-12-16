cmake_minimum_required(VERSION 3.28.1)
project(Structural_Design_Patters)

if(CMAKE_EXPORT_COMPILE_COMMANDS)
    set(CMAKE_CXX_STANDARD_INCLUDE_DIRECTORIES ${CMAKE_CXX_IMPLICIT_INCLUDE_DIRECTORIES})
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})



set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)
set(CMAKE_CXX_COMPILER clang++)
#set(CMAKE_CXX_COMPILER_IMPORT_STD ON)

#set(CMAKE_C_COMPILER "/usr/bin/gcc-14")
#set(CMAKE_CXX_COMPILER "/usr/bin/g++-14")



#find_package(SDL2)

# Then, link your executable or library with the corresponding package targets:





add_executable(01_Adapter patterns/01_Adapter/main_01_adapter.cpp)

add_subdirectory(patterns/01_Adapter/adapter_basic)
add_subdirectory(patterns/01_Adapter/adapter_flight_simulator)


add_executable(02_Facade patterns/02_Facade/main_02_facade.cpp)

add_subdirectory(patterns/02_Facade/facade_basic_example)
# [TODO]removed due to windows/linux differences, needs to be fixed
#add_subdirectory(patterns/02_Facade/facade_console_project)

add_executable(03_Proxy patterns/03_Proxy/main_03_proxy.cpp)

add_subdirectory(patterns/03_Proxy/proxy_basic_example)
add_subdirectory(patterns/03_Proxy/proxy_virtual_proxy)
add_subdirectory(patterns/03_Proxy/proxy_protection_proxy)
# [TODO]removed due to windows/linux differences, needs to be fixed
#add_subdirectory(patterns/03_Proxy/proxy_remote_proxy)
add_subdirectory(patterns/03_Proxy/proxy_smart_proxy)

add_executable(04_Decorator patterns/04_Decorator/main_04_decorator.cpp)

add_subdirectory(patterns/04_Decorator/decorator_01_basic_example)
add_subdirectory(patterns/04_Decorator/decorator_02_stream_library)
add_subdirectory(patterns/04_Decorator/decorator_03_static)
add_subdirectory(patterns/04_Decorator/decorator_04_functional)

add_executable(05_Composite patterns/05_Composite/main_05_composite.cpp)

add_subdirectory(patterns/05_Composite/composite_01_basic_example)
add_subdirectory(patterns/05_Composite/composite_02_ui_composite)