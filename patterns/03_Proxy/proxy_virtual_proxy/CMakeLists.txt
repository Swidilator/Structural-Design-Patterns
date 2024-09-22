target_sources(03_Proxy PUBLIC
        FILE_SET proxy_virtual_proxy
        TYPE CXX_MODULES
        FILES main_virtual_proxy.ixx
        Image.ixx
        Bitmap.ixx
        BitmapProxy.ixx
        RepoProxy.ixx
)