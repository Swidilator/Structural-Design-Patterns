//
// Created by kyle on 2024/07/09.
//

module;
#include <memory>

export module proxy.smart_proxy.main;

import proxy.smart_proxy.Bitmap;
import proxy.smart_proxy.Pointer;



namespace proxy::smart_proxy {
    export auto main_smart_proxy() -> void {
        std::unique_ptr<Bitmap> p{new Bitmap{"./patterns/03_Proxy/proxy_smart_proxy/Smiley.txt"}};
        p->Load();
        p->Display();
    }
}