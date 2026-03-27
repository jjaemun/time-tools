#pragma once


#include <functional>
#include "tts/date/date.hpp"


namespace std {
    // hash!
    template <>
    struct hash<tts::Date> {

        /**
         * Specialization is favoured over custom hashing for 
         * stl interoperability.
        */

        [[nodiscard]]
        std::size_t operator()(const tts::Date &date) const noexcept {
            return std::hash<tts::i32>{}(date.to_unix_serial());
        }
    };
} // namespace std.



