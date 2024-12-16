target_sources(03_Proxy PUBLIC
        FILE_SET proxy_smart_proxy
        TYPE CXX_MODULES
        FILES main_smart_proxy.ixx
        Image.ixx
        Bitmap.ixx
        Pointer.ixx
)