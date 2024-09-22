target_sources(01_Adapter PUBLIC
        FILE_SET adapter_basic_modules
        TYPE CXX_MODULES
        FILES adapter_basic.ixx
        main_adapter_basic.ixx
)

target_sources(
        01_Adapter PUBLIC
        adapter_basic.cpp
)