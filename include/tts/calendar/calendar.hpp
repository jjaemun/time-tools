#pragma once


#include <string>
#include <utility>


#include "tts/types.hpp"
#include "tts/calendar/weekend.hpp"
#include "tts/calendar/businessday.hpp"
#include "tts/date/prelude.hpp"
#include "tts/holidays/prelude.hpp"


namespace tts {
    class Calendar final {

        /**
         * Implements business day calendar logic.
        */

    private:
        std::string name;
        Holidays holidays;
        conventions::weekend weekend;
 
    public:
        // constructor!
        Calendar(Holidays holidays_, conventions::weekend weekend_) noexcept
         : holidays(std::move(holidays_)), weekend(weekend_) {}
        
        // predicates!
        [[nodiscard]]
        bool is_holiday(Date date) const noexcept {
            return holidays.is_holiday(date);
        }

        [[nodiscard]]
        bool is_business_day(Date date) const noexcept {
            return (!is_holiday(date) && !is_weekend(date));
        } 

        [[nodiscard]]
        bool is_weekend(Date date) const noexcept {
            return conventions::is_weekend(date, weekend);
        }

        [[nodiscard]]
        Date adjust(Date date, 
                    conventions::businessday conv) const noexcept {
            
            /**
             * Heavy branching due to width of possibilities, but otherwise
             * straightforward.
            */

            using namespace conventions;

            if (conv == businessday::unadjusted)
                // early return.
                return date;

            // deepcopy;
            auto adjusted = date;
            switch (conv) {
                case (businessday::following):
                    while (!is_business_day(adjusted))
                        ++adjusted;

                    return adjusted;

                case (businessday::modified_following):
                    while (!is_business_day(adjusted))
                        ++adjusted;

                    if (adjusted.get_month() != date.get_month()) {
                        adjusted = date;
                        while (!is_business_day(adjusted))
                            --adjusted;
                    }

                    return adjusted;

                case (businessday::preceding):
                    while (!is_business_day(adjusted))
                        --adjusted;

                    return adjusted;

                case (businessday::modified_preceding):
                     while (!is_business_day(adjusted))
                        --adjusted;

                    if (adjusted.get_month()) != date.get_month()) {
                        adjusted = date;
                        while (!is_business_day(adjusted))
                            ++adjusted;
                    }

                    return adjusted;

                case (businessday::nearest):

                    /**
                     * If both become simultaneously business days, 
                     * return preceding over following.
                    */

                    auto back = adjusted;
                    auto fore = adjusted;

                    while(!is_business_day(back) && !is_business_day(fore)) {
                        --back;
                        ++fore;
                    }
                
                    if (is_business_day(back))
                        return back;
                    else
                        return fore;

                default:
                    __builtin_unreachable();
            }
        }
    };

} // namespace tts.
