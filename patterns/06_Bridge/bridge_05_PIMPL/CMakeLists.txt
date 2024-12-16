target_sources(06_Bridge PUBLIC
        Employee.cpp
)

target_sources(06_Bridge PUBLIC
        FILE_SET bridge_PIMPL
        TYPE CXX_MODULES
        FILES main_PIMPL.cppm
        Employee.cppm
        tax.cppm
        accounts.cppm
)
