target_sources(03_Proxy PUBLIC
        FILE_SET proxy_remote_proxy
        TYPE CXX_MODULES
        FILES main_remote_proxy.ixx
        IAnimate.ixx
        Sprite.ixx
)