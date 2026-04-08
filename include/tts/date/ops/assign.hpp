#pragma once 


#include "tts/cmp.hpp"
#include "tts/date/date.hpp"
#include "tts/timespans/prelude.hpp"


namespace tts {
    // tspan-add-assign!
    template <typename T, i64 N>
    inline Date &operator+=(Date &date, TimeSpan<T, N> tspan) {
        const auto advanced = date.to_unix_serial() + tspan.to_raw_days();
        if (!cmplt(advanced, unix::date::MAX))
            throw DateError(err::date::overflow);

        date.as_mut_unix_serial() = advanced;
        return date;
    }

    // tspan-sub-assign!
    template <typename T, i64 N>
    inline Date &operator-=(Date &date, TimeSpan<T, N> tspan) {
        const auto regressed = date.to_unix_serial() - tspan.to_raw_days();
        if (!cmpgt(regressed, unix::date::MIN))
            throw DateError(err::date::underflow);
    
        date.as_mut_unix_serial() = regressed;
        return date;
    }
} // namespace tts.
