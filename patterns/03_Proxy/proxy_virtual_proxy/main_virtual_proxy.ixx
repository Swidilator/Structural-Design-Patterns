//
// Created by Kyle on 2024/04/07.
//

module;

#include <iostream>
#include <string>
//#include <chrono>

export module proxy.virtual_proxy.main;

import proxy.virtual_proxy.Image;
import proxy.virtual_proxy.Bitmap;
import proxy.virtual_proxy.BitmapProxy;


namespace proxy::virtual_proxy
{
    export auto main_virtual_proxy() -> void
    {
        Image* p = new BitmapProxy{};
        p->Load("../patterns/03_Proxy/proxy_virtual_proxy/Smiley.txt");
        p->Display();
        delete p;
    }
}
