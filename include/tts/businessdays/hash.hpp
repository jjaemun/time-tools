#pragma once


#include <functional>
#include "tts/businessdays/businessdays.hpp"


namespace std {
    // hash!
    template <>
    struct hash<tts::BusinessDays> {

        /**
         * Specialization is favoured over custom hashing for 
         * stl interoperability.
        */

        [[nodiscard]]
        std::size_t operator()(const tts::BusinessDays &bds) const noexcept {
            return std::hash<tts::i32>{}(bds.count());
        }
    };
} // namespace std.



