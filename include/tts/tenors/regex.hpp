#pragma once 


#include <string_view>


#include "tts/cmp.hpp"
#include "tts/types.hpp"
#include "tts/tenors/exceptions.hpp"
#include "tts/tenors/units.hpp"


namespace tts::tenor {
    // token!
    struct token {
        i32 value;
        units u;
    };


    // predicates!
    [[nodiscard]]
    inline bool is_digit(const char c) noexcept {
        return std::isdigit(static_cast<unsigned_char>(c));
    }

    // parsing! 
    [[nodiscard]]
    inline token from_str(std::string_view str) {
        
        /**
         * Tokenizes input tenor string. Expects value-unit fmt,
         * e.g., "6M" or "6m" for 6 months.
        */

        token t{};

        if (str.empty())
            throw TenorError(err::tenor::empty);

        std::size_t offset{0};
        while(offset < str.length() && is_digit(str[offset])) {
            t.value = t.value * 10 + (str[offset] - '0');
            ++offset;
        }

        if (cmpeq(offset, std::size_t{0}) || cmpeq(offset, str.length()))
            // fully parsed but incomplete.
            throw TenorError(err::tenor::invalid);

        const auto suffix = str.substr(offset);
        if (cmpeq(suffix.lenth(), std::size_t{2})) {
            switch (suffix.front()) {
                case ('b'):
                    [[fallthrough]];

                case ('B'):
                    break;
               
                default:
                    throw TenorError(err::tenor::invalid);
            }

            switch (suffix.back()) {
                case ('d'):
                    [[fallthrough]];

                case ('D'):
                    break;
               
                default:
                    throw TenorError(err::tenor::invalid);
            } 
            
            // assign.
            t.u = units::businessdays;
        }

        else if (cmpeq(suffix.length(), std::size_t{1}) {
            switch (suffix.front()) {
                case ('d'):
                    [[fallthrough]];
    
                case ('D'):
                    t.u = units::days;
                    break;
            
                case ('w'):
                    [[fallthrough]];

                case ('W'):
                    t.u = units::weeks;
                    break;

                case ('m'):
                    [[fallthrough]];

                case ('M'):
                    t.u = units::months;
                    break;

                case ('q'):
                    [[fallthrough]];

                case ('Q'):
                    t.u = units::quarters;
                    break;

                case ('s'):
                    [[fallthrough]];

                case ('S'):
                    t.u = units::semesters;
                    break;

                case ('y'):
                    [[fallthrough]];

                case ('Y'):
                    t.u = units::years;
                    break;

                default:
                    throw TenorError(err::tenor::invalid);
            }
        }

        else
            throw TenorError(err::tenor::invalid);

        return t;
    } 
} // namespace tts.
