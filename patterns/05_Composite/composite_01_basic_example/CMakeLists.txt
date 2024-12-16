target_sources(05_Composite PUBLIC
        FILE_SET composite_basic_example
        TYPE CXX_MODULES
        FILES main_basic_example.ixx
        Component.ixx
        Leaf.ixx
        Composite.ixx

)