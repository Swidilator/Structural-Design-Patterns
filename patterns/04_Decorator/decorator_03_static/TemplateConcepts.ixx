//
// Created by kyle on 2024/09/14.
//

module;

#include <string>
#include <concepts>

export module decorator.static_decorator.TemplateConcepts;

namespace decorator::static_decorator {

    export template<typename T>
    concept InputStreamConcept = requires(T os, std::string &text)
    {
        { os.Read(text) } -> std::convertible_to<bool>;
        { os.Close() } -> std::same_as<void>;
    };

    export template<typename T>
    concept OutputStreamConcept = requires(T os, const std::string &text)
    {
        { os.Write(text) } -> std::same_as<void>;
        { os.Close() } -> std::same_as<void>;
    };
}
