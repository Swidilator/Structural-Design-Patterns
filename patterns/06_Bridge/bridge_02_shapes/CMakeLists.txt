if (WIN32)
    target_sources(06_Bridge PUBLIC
            FILE_SET bridge_shapes
            TYPE CXX_MODULES
            FILES main_shapes.ixx
            Line.ixx
            Shape.ixx
            Circle.ixx
            all_simple2d.ixx
    )
endif (WIN32)

if (LINUX)
    target_sources(06_Bridge PUBLIC
            FILE_SET bridge_shapes
            TYPE CXX_MODULES
            FILES main_shapes_linux.ixx
    )
endif (LINUX)