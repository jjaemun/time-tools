#pragma once 


#include "types.hpp"


namespace tts {
    // linear!
    class MilliSeconds {
        
        /**
         * Milliseconds timespan abstaction.
        */

    private:
        i32 value;

    public:
        // constructor!
        explicit constexpr MilliSeconds(i32 value_) noexcept 
            : value(value_) {}

        // named-constructors!
        static constexpr MilliSeconds from_seconds(i32 seconds) noexcept {
            return MilliSeconds{seconds * i32{1000}};
        }
        
        static constexpr MilliSeconds from_minutes(i32 minutes) noexcept {
            return MilliSeconds{minutes * i32{60} 
                * i32{1000}};
        }
        
        static constexpr MilliSeconds from_hours(i32 hours) noexcept {
            return MilliSeconds{hours * i32{60} * i32{60} 
                * i32{1000}};
        }
        
        static constexpr MilliSeconds from_days(i32 days) noexcept {
            return MilliSeconds{days * i32{24} * i32{60} 
                * i32{60} * i32{1000}};
        }
        
        static constexpr MilliSeconds from_weeks(i32 weeks) noexcept {
            return MilliSeconds{weeks * i32{7} * i32{24} 
                * i32{60} * i32{60} * i32{1000}};
        }

        // copy-accessors.
    };

    class Seconds {
        
        /**
         * Seconds timespan abstaction.
        */

    private:
        i32 value;

    public:
        // constructor!
        explicit constexpr Seconds(i32 value_) noexcept
            : value(value_) {}

        // named-constructors!
        static constexpr Seconds from_milliseconds(i32 milliseconds) noexcept {
            return Seconds{seconds / i32{1000}};
        }
        
        static constexpr Seconds from_minutes(i32 minutes) noexcept {
            return Seconds{minutes * i32{60}};
        }
        
        static constexpr Seconds from_hours(i32 hours) noexcept {
            return Seconds{hours * i32{60} * i32{60}};
        }
        
        static constexpr Seconds from_days(i32 days) noexcept {
            return Seconds{days * i32{24} * i32{60} 
                * i32{60}};
        }
        
        static constexpr Seconds from_weeks(i32 weeks) noexcept {
            return Seconds{weeks * i32{7} * i32{24} 
                * i32{60} * i32{60}};
        }

        // copy-accessors.
  
    };

    class Minutes {
        
        /**
         * Minutes timespan abstaction.
        */

    private:
        i32 value;

    public:
        // constructor!
        explicit constexpr Minutes(i32 value_) noexcept
            : value(value_) {}

        // named-constructors!
        static constexpr Minutes from_milliseconds(i32 milliseconds) noexcept {
            i32 minutes = milliseconds / (i32{1000} 
                * i32{60});
        
            return Minutes{minutes};
        }
        
        static constexpr Minutes from_seconds(i32 seconds) noexcept {
            i32 minutes = seconds / i32{60};

            return Minutes{minutes};
        }
        
        static constexpr Minutes from_hours(i32 hours) noexcept {
            i32 minutes = hours * i32{60};

            return Minutes{minutes};
        }
        
        static constexpr Minutes from_days(i32 days) noexcept {
            i32 minutes = hours * i32{24} * i32{60};

            return Minutes{minutes};
        }
        
        static constexpr Minutes from_weeks(i32 weeks) noexcept {
            i32 minutes = weeks * i32{7} * i32{24} 
                * i32{60};

            return Minutes{minutes};
        }

        // copy-accessors.
    };


    class Hours {
        
        /**
         * Hours timespan abstaction.
        */

    private:
        i32 value;

    public:
        // constructor!
        explicit constexpr Hours(i32 value_) noexcept
            : value(value_) {}

        // named-constructors!
        static constexpr Seconds from_milliseconds(i32 milliseconds) noexcept {
            return MilliSeconds{seconds / i32{1000}};
        }
        
        static constexpr Seconds from_minutes(i32 minutes) noexcept {
            return MilliSeconds{minutes * i32{60}};
        }
        
        static constexpr Seconds from_hours(i32 hours) noexcept {
            return Seconds{hours * i32{60} * i32{60}};
        }
        
        static constexpr Seconds from_days(i32 days) noexcept {
            return Seconds{days * i32{24} * i32{60} 
                * i32{60}};
        }
        
        static constexpr Seconds from_weeks(i32 weeks) noexcept {
            return MilliSeconds{weeks * i32{7} * i32{24} 
                * i32{60} * i32{60}};
        }

        // copy-accessors.
  

};
    class Days final {
        
        /**
         * Days timespan abstraction. True days.
        */

    private:
        i32 value;

    public:
        // constructor!
        explicit constexpr Days(i32 days_) : days(days_) {}
    };

    class Weeks {};
} //namespace tts.
