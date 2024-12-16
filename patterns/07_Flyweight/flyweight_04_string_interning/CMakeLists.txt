target_sources(07_Flyweight PUBLIC
        String.cpp
)

target_sources(07_Flyweight PUBLIC
        FILE_SET flyweight_string_interning
        TYPE CXX_MODULES
        FILES main_string_interning.cppm
        String.cppm

)