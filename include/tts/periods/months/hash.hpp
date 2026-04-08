#pragma once


#include <functional>
#include "tts/periods/months/months.hpp"


namespace std {
    // hash!
    template <>
    struct hash<tts::Months> {

        /**
         * Specialization is favoured over custom hashing for 
         * stl interoperability.
        */

        [[nodiscard]]
        std::size_t operator()(const tts::Months &months) const noexcept {
            return std::hash<tts::i32>{}(months.count());
        }
    };
} // namespace std.



