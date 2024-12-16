target_sources(06_Bridge PUBLIC
        FILE_SET bridge_basic_example
        TYPE CXX_MODULES
        FILES main_basic_example.ixx
        Implementor.ixx
        ConcreteImplementorA.ixx
        ConcreteImplementorB.ixx
        Abstraction.ixx
        RefinedAbstraction.ixx

)