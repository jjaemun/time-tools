#pragma once


#include <functional>
#include "tts/years/years.hpp"


namespace std {
    // hash!
    template <>
    struct hash<tts::Years> {

        /**
         * Specialization is favoured over custom hashing for 
         * stl interoperability.
        */

        [[nodiscard]]
        std::size_t operator()(const tts::Years &years) const noexcept {
            return std::hash<tts::i32>{}(years.count());
        }
    };
} // namespace std.



