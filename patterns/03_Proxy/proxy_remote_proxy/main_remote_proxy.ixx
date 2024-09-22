//
// Created by Kyle on 2024/07/05.
//

module;

export module proxy.remote_proxy.main;

import proxy.remote_proxy.IAnimate;
import proxy.remote_proxy.Sprite;

namespace proxy::remote_proxy
{
    auto Draw(IAnimate* p) {
        p->SetImage('A');
        p->Animate(5);
    }

    export auto main_remote_proxy() -> void {
        Sprite s;
        Draw(&s);
    }
}
