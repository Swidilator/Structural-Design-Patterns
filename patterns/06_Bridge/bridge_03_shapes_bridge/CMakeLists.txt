if (WIN32)
    include_directories(.)
    target_sources(06_Bridge PUBLIC
            GDI.cpp
    )

    target_sources(06_Bridge PUBLIC
            FILE_SET bridge_shapes_bridge
            TYPE CXX_MODULES
            FILES main_shapes_bridge.ixx
            Renderer.ixx
            Shape.ixx
            Line.ixx
            Circle.ixx
            OpenGL.ixx
    )
endif (WIN32)

if (LINUX)
    target_sources(06_Bridge PUBLIC
            FILE_SET bridge_shapes_bridge
            TYPE CXX_MODULES
            FILES main_shapes_bridge_linux.ixx
    )
endif (LINUX)