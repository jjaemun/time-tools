#pragma once 


#include <algorithm>
#include <string>
#include <vector>
#include <utility>


#include "tts/date/prelude.hpp"
#include "tts/holidays/algorithms.hpp"
#include "tts/types.hpp"


namespace tts {
    class Holidays final {
        
        /**
         * Represents a set of holidays over specified years. 
         * Essentially, it is a named vector.
        */

    private:

        /**
         * Date lookups on std::vector are O(log(n)) which is modest. 
         * Using a hash map or unordered map would reduce lookups to
         * O(1) but perform worse in memory footprint and locality.
        */

        std::string name;
        std::vector<Date> values;

        // constructor!
        Holidays(std::string name_, std::vector<Date> values_) noexcept
            : name(std::move(name_)), values(std::move(values_)) {}

    public:
        // named-constructors!
        [[nodiscard]]
        static Holidays from_dates(std::string name, 
                                   std::vector<Date> dates) noexcept {
            
            /**
             * std::sort is only constexpr from c++20 onwards, so we 
             * do not use it here.
            */

            std::sort(dates.begin(), dates.end());
            return Holidays{name, dates};
        }

        [[nodiscard]]
        static Holidays from_unix_serials(std::string name, 
                                          std::vector<i32> serials) {
            std::vector<Date> dates;
            for (auto s : serials)
                dates.push_back(Date::from_unix_serial(s));
        
            std::sort(dates.begin(), dates.end());
            return Holidays{name, dates};
        }

        // merge!
        constexpr void join(const Holidays &other) noexcept;
    };
} // namespace tts.

