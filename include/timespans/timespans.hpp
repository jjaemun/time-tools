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
        [[nodiscard]]
        static constexpr MilliSeconds from_seconds(i32 seconds) noexcept {
            return MilliSeconds{seconds * i32{1000}};
        }
        
        [[nodiscard]]
        static constexpr MilliSeconds from_minutes(i32 minutes) noexcept {
            return MilliSeconds{minutes * i32{60} 
                * i32{1000}};
        }
        
        [[nodiscard]]
        static constexpr MilliSeconds from_hours(i32 hours) noexcept {
            return MilliSeconds{hours * i32{60} * i32{60} 
                * i32{1000}};
        }
        
        [[nodiscard]]
        static constexpr MilliSeconds from_days(i32 days) noexcept {
            return MilliSeconds{days * i32{24} * i32{60} 
                * i32{60} * i32{1000}};
        }
        
        [[nodiscard]]
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
        [[nodiscard]]
        static constexpr Seconds from_milliseconds(i32 milliseconds) noexcept {
            return Seconds{milliseconds / i32{1000}};
        }
        
        [[nodiscard]]
        static constexpr Seconds from_minutes(i32 minutes) noexcept {
            return Seconds{minutes * i32{60}};
        }
        
        [[nodiscard]]
        static constexpr Seconds from_hours(i32 hours) noexcept {
            return Seconds{hours * i32{60} * i32{60}};
        }
        
        [[nodiscard]]
        static constexpr Seconds from_days(i32 days) noexcept {
            return Seconds{days * i32{24} * i32{60} 
                * i32{60}};
        }
        
        [[nodiscard]]
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
        [[nodiscard]]
        static constexpr Minutes from_milliseconds(i32 milliseconds) noexcept {
            return Minutes{milliseconds / (i32{1000} 
                * i32{60})};
        }
        
        [[nodiscard]]
        static constexpr Minutes from_seconds(i32 seconds) noexcept {
            return Minutes{seconds / i32{60}};
        }
        
        [[nodiscard]]
        static constexpr Minutes from_hours(i32 hours) noexcept {
            return Minutes{hours * i32{60}};
        }
        
        [[nodiscard]]
        static constexpr Minutes from_days(i32 days) noexcept {
            return Minutes{days * i32{24} * i32{60}};
        }
        
        [[nodiscard]]
        static constexpr Minutes from_weeks(i32 weeks) noexcept {
            return Minutes{weeks * i32{7} * i32{24} 
                * i32{60}};
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
        [[nodiscard]]
        static constexpr Hours from_milliseconds(i32 milliseconds) noexcept {
            return Hours{milliseconds / (i32{1000} 
                * i32{60} * i32{60})};
        }
        
        [[nodiscard]]
        static constexpr Hours from_seconds(i32 seconds) noexcept {
            return Hours{seconds / (i32{60} 
                * i32{60})};
        }
         
        [[nodiscard]]
        static constexpr Hours from_minutes(i32 minutes) noexcept {
            return Hours{minutes / i32{60}};
        }       
       
        [[nodiscard]]
        static constexpr Hours from_days(i32 days) noexcept {
            return Hours{days * i32{24}}; 
        }
        
        [[nodiscard]]
        static constexpr Hours from_weeks(i32 weeks) noexcept {
            return Hours{weeks * i32{7} * i32{24}};
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
        explicit constexpr Days(i32 value_) noexcept 
            : value(value_) {}
        
        // named-constructors!
        [[nodiscard]]
        static constexpr Days from_milliseconds(i32 milliseconds) noexcept {
            return Days{milliseconds / (i32{1000} 
                * i32{60} * i32{60} * i32{24})};
        }
        
        [[nodiscard]]
        static constexpr Days from_seconds(i32 seconds) noexcept {
            return Days{seconds / (i32{60} 
                * i32{60} * i32{24})};
        }
         
        [[nodiscard]]
        static constexpr Days from_minutes(i32 minutes) noexcept {
            return Days{minutes / (i32{60}
                * i32{24})};
        }       
       
        [[nodiscard]]
        static constexpr Days from_hours(i32 hours) noexcept {
            return Days{days / i32{24}}; 
        }
        
        [[nodiscard]]
        static constexpr Days from_weeks(i32 weeks) noexcept {
            return Hours{weeks * i32{7}};
        }

        // copy-accessors.
    };

    class Weeks {
                
        /**
         * Weeks timespan abstraction. True weeks.
        */

    private:
        i32 value;

    public:
        // constructor!
        explicit constexpr Weeks(i32 value_) noexcept 
            : value(value_) {}
        
        // named-constructors!
        [[nodiscard]]
        static constexpr Weeks from_milliseconds(i32 milliseconds) noexcept {
            return Weeks{milliseconds / (i32{1000} * i32{60} 
                * i32{60} * i32{24} * i32{7})};
        }
        
        [[nodiscard]]
        static constexpr Weeks from_seconds(i32 seconds) noexcept {
            return Weeks{seconds / (i32{60} * i32{60} 
                * i32{24} * i32{7})};
        }
         
        [[nodiscard]]
        static constexpr Weeks from_minutes(i32 minutes) noexcept {
            return Weeks{minutes / (i32{60} * i32{24} 
                * i32{7})};
        }       
       
        [[nodiscard]]
        static constexpr Weeks from_hours(i32 hours) noexcept {
            return Weeks{days / (i32{24} * i32{7}}; 
        }
        
        [[nodiscard]]
        static constexpr Weeks from_days(i32 days) noexcept {
            return Weeks{days / i32{7}};
        }

        // copy-accessors.
    };
} //namespace tts.
