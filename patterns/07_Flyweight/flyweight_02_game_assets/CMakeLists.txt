target_sources(07_Flyweight PUBLIC
        Model.cpp
        Vegetation.cpp
)

target_sources(07_Flyweight PUBLIC
        FILE_SET flyweight_game_assets
        TYPE CXX_MODULES
        FILES main_game_assets.cppm
        Model.cppm
        Vegetation.cppm
)