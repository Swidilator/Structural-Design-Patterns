target_sources(03_Proxy PUBLIC
        FILE_SET proxy_protection_proxy
        TYPE CXX_MODULES
        FILES main_protection_proxy.ixx
        Storage.ixx
        Repository.ixx
        Employee.ixx
)