#pragma once 


#include "tts/date/date.hpp"


namespace tts::conventions {
    // conventions!
    enum class weekend {
        satsun,
        frisat,
        sun,
        fri,
        noweekend
    };

    // predicates!
    [[nodiscard]]
    inline bool is_weekend(Date date, weekend conv) noexcept {
        
        /**
         * Checks whether current date fall on weekend 
         * under given convention. 
        */
        
        switch (conv) {
            case (weekend::satsun):
                return (date.is_saturday() || date.is_sunday());

            case (weekend::frisat):
                return (date.is_friday() || date.is_saturday());

            case (weekend::sun):
                return (date.is_sunday());
        
            case (weekend::fri):
                return (date.is_friday());

            case (weekend::noweekend):
                return (false);

            default:
                __builtin_unreachable(); 
        }
    }

} // namespace tts::conventions.
