#pragma once 


#include <string_view>


#include "tts/types.hpp"
#include "tts/tenors/units.hpp"
#include "tts/tenors/regex.hpp"


namespace tts {
    class Tenor final {
        
        /**
         * Tenor (period) abstraction. Can be either linear or 
         * non-linear. Delegates to strong types downstream.
        */

    private:
        i32 value;
        tenor::units units;

    public:
        // constructor!
        constexpr Tenor(i32 value_, tenor::units units_) noexcept
            : value(value_), units(units_) {}

        // runtime named-constructor!
        [[nodiscard]]
        static Tenor from_str(std::string_view str) {
            const auto token = tenor::from_str(str);
            return Tenor{token.value, token.u};
        }

        // copy-to-accessors!
        [[nodiscard]]
        constexpr i32 duration() const noexcept {
            return value;
        }

        [[nodiscard]]
        constexpr tenor::units get_units() const noexcept {
            return units;
        }
        
        // immutable-ref accessor!
        [[nodiscard]]
        constexpr const i32 &as_duration() const noexcept {
            return value;
        }
        
        // imutable-ref accessor!
        constexpr i32 &as_mut_duration() noexcept {
            return value;
        }

        // attr!
        [[nodiscard]]
        std::string to_str() const noexcept {
            std::string suffix{};
            switch (units) {
                case (tenor::units::days):
                    suffix = "D";
                    break;

                case (tenor::units::businessdays):
                    suffix = "BD";
                    break;

                case (tenor::units::weeks):
                    suffix = "W";
                    break;

                case (tenor::units::months):
                    suffix = "M";
                    break;
            
                case (tenor::units::quarters):
                    suffix = "Q";
                    break;

                case (tenor::units::semesters):
                    suffix = "S";
                    break;

                case (tenor::units::years):
                    suffix = "Y";
                    break;
            }

        return std::to_string(value) + suffix;
    };
} // namespace tts.
