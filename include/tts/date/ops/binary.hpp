#pragma once 


#include "tts/cmp.hpp"
#include "tts/date/date.hpp"
#include "tts/timespans/prelude.hpp"


namespace tts {
    // sub!
    [[nodiscard]]
    constexpr Days operator-(Date lhs, Date rhs) noexcept {
        
        /**
         * Sub operator overload directly delegates to strong type variant
         * as the main api. Add operator is unnecesary for date-date ops and
         * has no meaningful physical interpretation. Safe by definition.
        */

        return lhs.days_between(rhs);
    }

    // tspan-add!
    template <typename T, i64 N>
    [[nodiscard]]
    inline Date operator+(Date date, TimeSpan<T, N> tspan) {
        const auto advanced = date.to_unix_serial() + tspan.to_raw_days();
        if (cmpgt(advanced, unix::date::MAX))
            throw DateError(err::date::overflow);
    
        return Date::from_unix_serial_unsafe(advanced);
    }

    // tspan-sub!
    template <typename T, i64 N>
    [[nodiscard]]
    inline Date operator-(Date date, TimeSpan<T, N> tspan) {
        const auto regressed = date.to_unix_serial() - tspan.to_raw_days();
        if (cmplt(regressed, unix::date::MIN))
            throw DateError(err::date::underflow);
    
        return Date::from_unix_serial_unsafe(regressed);
    }
} // namespace tts.
