//
// Created by kyle on 2024/09/08.
//

module;
#include <string>

export module decorator.static_decorator.OutputStreamDecoratorStatic;

import decorator.static_decorator.OutputStreamStatic;

namespace decorator::static_decorator {
    export class OutputStreamDecorator
            : public OutputStream {
        OutputStream *m_pOS;

    public:
        OutputStreamDecorator(OutputStream *pOS)
            : m_pOS(pOS) {
        }

        auto Write(const ::std::string &text) -> void override = 0;

        auto Close() -> void override = 0;
    };

    auto OutputStreamDecorator::Write(const ::std::string &text) -> void {
        m_pOS->Write(text);
    }

    auto OutputStreamDecorator::Close() -> void {
        m_pOS->Close();
    }
}
