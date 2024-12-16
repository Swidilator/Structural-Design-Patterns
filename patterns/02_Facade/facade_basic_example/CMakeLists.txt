# facade.basic
target_sources(02_Facade PUBLIC
        FILE_SET facade_basic_example
        TYPE CXX_MODULES
        FILES main_basic_example.ixx
        A.ixx
        B.ixx
        C.ixx
        Client.ixx
        Facade.ixx
)