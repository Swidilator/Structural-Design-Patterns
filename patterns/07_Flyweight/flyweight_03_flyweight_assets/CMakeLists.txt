target_sources(07_Flyweight PUBLIC
        Model.cpp
        Vegetation.cpp
        VegetationFactory.cpp
)

target_sources(07_Flyweight PUBLIC
        FILE_SET flyweight_flyweight_assets
        TYPE CXX_MODULES
        FILES main_flyweight_assets.cppm
        Model.cppm
        Vegetation.cppm
        VegetationFactory.cppm
)