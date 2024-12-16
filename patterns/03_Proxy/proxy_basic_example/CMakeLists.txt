target_sources(03_Proxy PUBLIC
        FILE_SET proxy_basic_example
        TYPE CXX_MODULES
        FILES main_basic_example.ixx
        Subject.ixx
        RealSubject.ixx
        Proxy.ixx
)