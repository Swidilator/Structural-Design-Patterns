if (WIN32)
    include_directories(Window.h)
    target_sources(06_Bridge PUBLIC
            Window.cpp
    )

    target_sources(06_Bridge PUBLIC
            FILE_SET bridge_shapes
            TYPE CXX_MODULES
            FILES main_shapes.ixx
            Line.ixx
            Point.ixx

    )
endif (WIN32)

if (LINUX)
    target_sources(06_Bridge PUBLIC
            FILE_SET bridge_shapes
            TYPE CXX_MODULES
            FILES main_shapes_linux.ixx
    )
endif (LINUX)