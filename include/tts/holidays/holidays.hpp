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
             * std::sort is only constexpr from c++20 onwards, so 
             * we do not use it here. Safe by definition.
            */

            std::sort(dates.begin(), dates.end());
            return Holidays{name, dates};
        }

            /**
             * From serials, we check in the safe variants, so that
             * Dates are safe by construction.
            */

        [[nodiscard]]
        static Holidays from_unix_serials(std::string name, 
                                          std::vector<i32> serials) {
            std::vector<Date> dates;
            for (auto s : serials)
                dates.push_back(Date::from_unix_serial(s));
        
            return from_dates(name, dates);
        }

        [[nodiscard]]
        static Holidays from_excel_serials(std::string name, 
                                            std::vector<i32> serials) {
            std::vector<Date> dates;
            for (auto s : serials)
                dates.push_back(Date::from_excel_serial(s));

            return from_dates(name, dates);
        }

        [[nodiscard]]
        static Holidays from_murex_serials(std::string name, 
                                           std::vector<i32> serials) {
            std::vector<Date> dates;
            for (auto s : serials)
                dates.push_back(Date::from_murex_serial(s));
        
            return from_dates(name, dates);
        
        }
 
        [[nodiscard]]
         static Holidays from_julian_serials(std::string name, 
                                             std::vector<i32> serials) {
            std::vector<Date> dates;
            for (auto s : serials)
                dates.push_back(Date::from_julian_serial(s));
        
            return from_dates(name, dates);
        }

            /**
             * Unsafe (faster) variants for ingestion workflows from 
             * safe data pipelines.
            */

        [[nodiscard]]
        static Holidays from_unix_serials_unsafe(std::string name, 
                                                 std::vector<i32> serials) noexcept {
            std::vector<Date> dates;
            for (auto s : serials)
                dates.push_back(Date::from_unix_serial_unsafe(s));
        
            return from_dates(name, dates);
        }

        [[nodiscard]]
        static Holidays from_excel_serials_unsafe(std::string name, 
                                                  std::vector<i32> serials) noexcept {
            std::vector<Date> dates;
            for (auto s : serials)
                dates.push_back(Date::from_excel_serial_unsafe(s));

            return from_dates(name, dates);
        }

        [[nodiscard]]
        static Holidays from_murex_serials_unsafe(std::string name, 
                                                  std::vector<i32> serials) noexcept {
            std::vector<Date> dates;
            for (auto s : serials)
                dates.push_back(Date::from_murex_serial_unsafe(s));
        
            return from_dates(name, dates);
        
        }
 

        [[nodiscard]]
         static Holidays from_julian_serials_unsafe(std::string name, 
                                                    std::vector<i32> serials) noexcept {
            std::vector<Date> dates;
            for (auto s : serials)
                dates.push_back(Date::from_julian_serial_unsafe(s));
        
            return from_dates(name, dates);
        }


        // merge!
        constexpr void join(const Holidays &other) noexcept;
    };
} // namespace tts.
