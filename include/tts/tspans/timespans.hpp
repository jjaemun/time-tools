#pragma once 


#include "tts/constants.hpp"


namespace tts {
    template <typename T, i32 N>
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
 
        // generic named-constructors!
        template <typename From, i32 M>
        [[nodiscard]]
        static constexpr TimeSpan from_raw(From from) noexcept {
        
            /**
             * Beware **unsafe** overflow potential on careless 
             * conversions.
            */

            return TimeSpan{static_cast<T>(static_cast<i64>(from) 
                * M / LEN())};
        }

        template <typename From, i32 M>
        [[nodiscard]]
        static constexpr TimeSpan from(TimeSpan<From, M> tspan) noexcept {
            return from_raw<From, M>(tspan.count());
        }

        // explicit named-constructors!
        [[nodiscard]]
        static constexpr TimeSpan 
        from_raw_milliseconds(i64 milliseconds) noexcept {
            return from_raw<i64, timespan::MILLISECONDS>(milliseconds);
        }

        [[nodiscard]]
        static constexpr TimeSpan from_raw_seconds(i64 seconds) noexcept {
            return from_raw<i64, timespan::SECONDS>(seconds);
        }

        [[nodiscard]]
        static constexpr TimeSpan from_raw_minutes(i32 minutes) noexcept {
            return from_raw<i32, timespan::MINUTES>(minutes);
        }

        [[nodiscard]]
        static constexpr TimeSpan from_raw_hours(i32 hours) noexcept {
            return from_raw<i32, timespan::HOURS>(hours);
        }

        [[nodiscard]]
        static constexpr TimeSpan from_raw_days(i32 days) noexcept {
            return from_raw<i32, timespan::DAYS>(days);
        }

        [[nodiscard]]
        static constexpr TimeSpan from_raw_weeks(i32 weeks) noexcept {
            return from_raw<i32, timespan::WEEKS>(weeks);
        }
        
        [[nodiscard]]
        static constexpr TimeSpan 
        from_milliseconds(TimeSpan<i64, timespan::MILLISECONDS> milliseconds) noexcept {
            return from_raw_milliseconds(milliseconds.count());
        }

        [[nodiscard]]
        static constexpr TimeSpan 
        from_seconds(TimeSpan<i64, timespan::SECONDS> seconds) noexcept {
            return from_raw_seconds(seconds.count());
        }

        [[nodiscard]]
        static constexpr TimeSpan 
        from_minutes(TimeSpan<i32, timespan::MINUTES> minutes) noexcept {
            return from_raw_minutes(minutes.count());
        }

        [[nodiscard]]
        static constexpr TimeSpan 
        from_hours(TimeSpan<i32, timespan::HOURS> hours) noexcept {
            return from_raw_hours(hours.count());
        }

        [[nodiscard]]
        static constexpr TimeSpan 
        from_days(TimeSpan<i32, timespan::DAYS> days) noexcept {
            return from_raw_days(days.count());
        }

        [[nodiscard]]
        static constexpr TimeSpan 
        from_weeks(TimeSpan<i32, timespan::WEEKS> weeks) noexcept {
            return from_raw_weeks(weeks.count());
        }

        // copy-to-accessors!
        [[nodiscard]]
        constexpr T count() const noexcept {
            return value;
        }
       
        // generic copy-to-accessors!
        template <typename To, i32 M>
        [[nodiscard]]
        constexpr To to_raw() const noexcept {
            return TimeSpan<To, M>::from(*this).count();
        }
    
        template <typename To, i32 M>
        [[nodiscard]]
        constexpr TimeSpan<To, M> to() const noexcept {
            return TimeSpan<To, M>::from(*this);
        }
        
        // explicit copy-to-accessors!
        [[nodiscard]]
        constexpr i64 to_raw_milliseconds() const noexcept {
            return to_raw<i64, timespan::MILLISECONDS>();
        }

        [[nodiscard]]
        constexpr i64 to_raw_seconds() const noexcept {
            return to_raw<i64, timespan::SECONDS>();
        }

        [[nodiscard]]
        constexpr i32 to_raw_minutes() const noexcept {
            return to_raw<i32, timespan::MINUTES>();
        }

        [[nodiscard]]
        constexpr i32 to_raw_hours() const noexcept {
            return to_raw<i32, timespan::HOURS>();
        }

        [[nodiscard]]
        constexpr i32 to_raw_days() const noexcept {
            return to_raw<i32, timespan::DAYS>();
        }

        [[nodiscard]]
        constexpr i32 to_raw_weeks() const noexcept {
            return to_raw<i32, timespan::WEEKS>();
        }
        
        [[nodiscard]]
        constexpr TimeSpan<i64, timespan::MILLISECONDS> 
        to_milliseconds() const noexcept {
            return to<i64, timespan::MILLISECONDS>();
        }

        [[nodiscard]]
        constexpr TimeSpan<i64, timespan::SECONDS> 
        to_seconds() const noexcept {
            return to<i64, timespan::SECONDS>();
        }

        [[nodiscard]]
        constexpr TimeSpan<i32, timespan::MINUTES> 
        to_minutes() const noexcept {
            return to<i32, timespan::MINUTES>();
        }

        [[nodiscard]]
        constexpr TimeSpan<i32, timespan::HOURS> 
        to_hours() const noexcept {
            return to<i32, timespan::HOURS>();
        }

        [[nodiscard]]
        constexpr TimeSpan<i32, timespan::DAYS> 
        to_days() const noexcept {
            return to<i32, timespan::DAYS>();
        }

        [[nodiscard]]
        constexpr TimeSpan<i32, timespan::WEEKS> 
        to_weeks() noexcept {
            return to<i32, timespan::WEEKS>();
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
        static constexpr i32 LEN() noexcept {

            /**
             * Returns timespan units expressed in milliseconds.
            */

            return N;
        }
    };

    // aliases!
    using MilliSeconds = TimeSpan<i64, timespan::MILLISECONDS>;
        
        /**
         * Public api for linear timespan denoting milliseconds.
        */

    using Seconds = TimeSpan<i64, timespan::SECONDS>;
        
        /**
         * Public api for linear timespan denoting seconds.
        */
    
    using Minutes = TimeSpan<i32, timespan::MINUTES>;
        
        /**
         * Public api for linear timespan denoting minutes.
        */
    
    using Hours = TimeSpan<i32, timespan::HOURS>;
        
        /**
         * Public api for linear timespan denoting hours.
        */
    
    using Days = TimeSpan<i32, timespan::DAYS>;
        
        /**
         * Public api for linear timespan denoting days.
        */ 
    
    using Weeks = TimeSpan<i32, timespan::WEEKS>;
        
        /**
         * Public api for linear timespan denoting weeks.
        */ 

} // namespace tts.
