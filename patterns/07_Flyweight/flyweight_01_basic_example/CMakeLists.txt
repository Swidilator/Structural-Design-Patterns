target_sources(07_Flyweight PUBLIC
        ConcreteFlyweight.cpp
        UnsharedConcreteFlyweight.cpp
        FlyweightFactory.cpp
)

target_sources(07_Flyweight PUBLIC
        FILE_SET flyweight_basic_example
        TYPE CXX_MODULES
        FILES main_basic_example.cppm
        Flyweight.cppm
        ConcreteFlyweight.cppm
        UnsharedConcreteFlyweight.cppm
        FlyweightFactory.cppm

)