if (WIN32)
    include_directories(Window.h)
    target_sources(06_Bridge PUBLIC
            Window.cpp
    )

    target_sources(06_Bridge PUBLIC
            FILE_SET bridge
            TYPE CXX_MODULES
            FILES Point.ixx
    )
endif (WIN32)