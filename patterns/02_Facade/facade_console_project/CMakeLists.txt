# facade.console_project
target_sources(02_Facade PUBLIC
        FILE_SET facade_console_project
        TYPE CXX_MODULES
        FILES main_console_project.ixx
        Console.ixx
)

if (WIN32)
    target_sources(02_Facade PUBLIC
            FILE_SET facade_console_project
            TYPE CXX_MODULES
            FILES
            ConsoleWindows.ixx

    )

    target_sources(
            02_Facade PUBLIC
            ConsoleWindows.cpp
    )
endif (WIN32)

if (LINUX)
    target_sources(02_Facade PUBLIC
            FILE_SET facade_console_project
            TYPE CXX_MODULES
            FILES
            ConsoleLinux.ixx
    )

    target_sources(
            02_Facade PUBLIC
            ConsoleLinux.cpp
    )
endif (LINUX)


#target_sources(
#        02_Facade PUBLIC facade_console_project/*.cpp
#)