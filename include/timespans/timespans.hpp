#pragma once 


#include "types.hpp"

namespace tts {
    template <typename T, const i32 LEN>
    class TimeSpan final {

        /**
         * Generalised linear timespan abstraction, parametrised on 
         * milliseconds. Propagates to all scales.
        */

    private:
        T value;

    public:
        // alias!
        using Type = T;
        
        // constructor!
        explicit constexpr TimeSpan(T value_) noexcept 
            : value(value_) {}
 
        // named-constructors!
        template <typename From, i32 N>
        [[nodiscard]]
        static constexpr TimeSpan from_raw(From from) noexcept {
            return TimeSpan{static_cast<T>(from) * N / LEN};
        }

        template <typename From, i32 N>
        [[nodiscard]]
        static constexpr TimeSpan from(TimeSpan<From, N> from) noexcept {
            return from_raw<From, N>(from.count());
        }

        // copy-to-accessors.
        [[nodiscard]]
        constexpr T count() const noexcept {
            return value;
        }
        
        template <typename To, i32 N>
        [[nodiscard]]
        constexpr TimeSpan<To, N> to() const noexcept {
            return TimeSpan<To, N>::from(*this);
        }
        
        template <typename To, i32 N>
        [[nodiscard]]
        constexpr To to_raw() const noexcept {
            return TimeSpan<To, N>::from(*this).count();
        }

        // immutable ref-accessor!
        [[nodiscard]]
        constexpr const T &as_count() const noexcept {
            return value;
        }
        
        // mutable ref-accessor!
        constexpr T &as_mut_count() noexcept {
            return value;
        }
    
        // attr!
        [[nodiscard]]
        constexpr i32 len() const noexcept {
            return LEN;
        }
    };
} // namespace tts.
