target_sources(06_Bridge PUBLIC
        FILE_SET bridge_shared_implementation
        TYPE CXX_MODULES
        FILES main_shared_implementation.ixx
        String.ixx
)
