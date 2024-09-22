target_sources(04_Decorator PUBLIC
        FILE_SET decorator_basic_example
        TYPE CXX_MODULES
        FILES main_basic_example.ixx
        Component.ixx
        Decorator.ixx
        ConcreteComponent.ixx
        ConcreteDecoratorA.ixx
        ConcreteDecoratorB.ixx
)
