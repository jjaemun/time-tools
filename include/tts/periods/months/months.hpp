#pragma once


#include "tts/types.hpp"


namespace tts {
    class Months final {
        
        /**
         * Months (non-linear) period abstraction. Safe by 
         * definition.
        */
        
    private:
        i32 value;

    public:
        // constructor!
        explicit constexpr Months(i32 value_) noexcept 
            : value(value_) {}

        // copy-to-accessor!
        [[nodiscard]]
        constexpr i32 count() const noexcept {
            return value;
        }

        // immutable-ref accessor!
        [[nodiscard]]
        constexpr i32 const &as_count() const noexcept {
            return value;
        }

        // mutable-ref accessor!
        constexpr i32 &as_mut_count() noexcept {
            return value;
        }
    };
} // namespace tts.
