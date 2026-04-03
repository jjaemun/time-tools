#pragma once 


#include <algorithm>
#include <string>
#include <vector>
#include <type_traits>
#include <utility>


#include "tts/cmp.hpp"
#include "tts/types.hpp"
#include "tts/holidays/errors.hpp"
#include "tts/holidays/exceptions.hpp"
#include "tts/date/prelude.hpp"


namespace tts {
    class Holidays final {
        
        /**
         * Represents a set of holidays over specified years. 
         * Essentially, it is a named vector.
        */

    private:

        /**
         * Date lookups on std::vector are O(log(n)) which is modest. 
         * Using a hash map would reduce lookups to O(1) but perform
         * worse in memory footprint and locality.
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
            dates.erase(std::unique(dates.begin(), 
                                    dates.end()), dates.end());

            return Holidays{name, dates};
        }

            /**
             * From serials, we check in the safe variants, so that
             * Dates are safe by construction.
            */

        [[nodiscard]]
        static Holidays from_unix_serials(std::string name, 
                                          std::vector<i32> serials) {
            std::vector<Date> dates{};
            dates.reserve(serials.size());

            for (auto s : serials)
                dates.push_back(Date::from_unix_serial(s));
        
            return from_dates(name, dates);
        }

        [[nodiscard]]
        static Holidays from_excel_serials(std::string name, 
                                            std::vector<i32> serials) {
            std::vector<Date> dates{};
            dates.reserve(serials.size());

            for (auto s : serials)
                dates.push_back(Date::from_excel_serial(s));

            return from_dates(name, dates);
        }

        [[nodiscard]]
        static Holidays from_murex_serials(std::string name, 
                                           std::vector<i32> serials) {
            std::vector<Date> dates{};
            dates.reserve(serials.size());

            for (auto s : serials)
                dates.push_back(Date::from_murex_serial(s));
        
            return from_dates(name, dates);
        
        }
 
         [[nodiscard]]
         static Holidays from_julian_serials(std::string name, 
                                             std::vector<i32> serials) {
            std::vector<Date> dates{};
            dates.reserve(serials.size());

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
            std::vector<Date> dates{};
            dates.reserve(serials.size());

            for (auto s : serials)
                dates.push_back(Date::from_unix_serial_unsafe(s));
        
            return from_dates(name, dates);
        }

        [[nodiscard]]
        static Holidays from_excel_serials_unsafe(std::string name, 
                                                  std::vector<i32> serials) noexcept {
            std::vector<Date> dates{};
            dates.reserve(serials.size());

            for (auto s : serials)
                dates.push_back(Date::from_excel_serial_unsafe(s));

            return from_dates(name, dates);
        }

        [[nodiscard]]
        static Holidays from_murex_serials_unsafe(std::string name, 
                                                  std::vector<i32> serials) noexcept {
            std::vector<Date> dates{};
            dates.reserve(serials.size());

            for (auto s : serials)
                dates.push_back(Date::from_murex_serial_unsafe(s));
        
            return from_dates(name, dates);
        }
 
        [[nodiscard]]
         static Holidays from_julian_serials_unsafe(std::string name, 
                                                    std::vector<i32> serials) noexcept {
            std::vector<Date> dates{};
            dates.reserve(serials.size());

            for (auto s : serials)
                dates.push_back(Date::from_julian_serial_unsafe(s));
        
            return from_dates(name, dates);
        }

        // copy-to accessor!
        [[nodiscard]]
        std::vector<Date> to_dates() const noexcept {
            return values;
        }

        // immutable-ref-accessor!
        [[nodiscard]]
        const std::string &get_name() const noexcept {
            return name;
        }

        [[nodiscard]]
        const std::vector<Date> &as_dates() const noexcept {
            return values;
        }

        // mutable-ref-accessor!
        std::vector<Date> &as_mut_dates() noexcept {
        
            /**
             * Beware **unsafe**, invokes mutability and so maintaining
             * a valid state (sorted, uniqueness) is necessary.
            */

            return values;
        }

        // look-ups!
        [[nodiscard]]
        bool is_holiday(Date date) const noexcept {

            /**
             * Assumes all holidays are known. 
            */

            return std::binary_search(values.begin(), values.end(), date);
        }
 
        [[nodiscard]]
        bool is_holiday_bounded(Date date) const {

            /**
             * Assumes that not all holidays are know; year bounding is 
             * enough to check whether we have a meaningful comparison.
            */

            if (cmplt(date.get_year(), start_year())
                    || cmpgt(date.get_year(), end_year()))
                throw HolidaysError(err::holidays::invalid);
            
            return is_holiday(date);
        }
 
        // n-ary merge!
        template <typename... Others>
        void join(const Others&... others) noexcept {
            
            /**
             * k-way merge on variadic pack of Holidays. Mutates 
             * internal state. Simple to keep it maintainable.
            */

            static_assert((std::is_same_v<std::remove_cvref_t<Others>, 
                Holidays> && ...));
    
            // deepcopy.         
            auto merged = values;
            std::vector<const Holidays*> holidays = { &others... };
            for (auto holiday : holidays) {
                std::vector<Date> placeholder;

                const auto &dates = holiday->as_dates();
                std::merge(merged.begin(), merged.end(), dates.begin(), 
                           dates.end(),std::back_inserter(placeholder));
                std::swap(merged, placeholder);
            }

            merged.erase(std::unique(merged.begin(), 
                                     merged.end()), merged.end());
            std::swap(values, merged);
        }

        // attr!
        [[nodiscard]]
        i32 start_year() const {
            if (values.empty()) 
                throw HolidaysError(err::holidays::empty);

            return values.front().get_year();
        }
        
        [[nodiscard]]
        i32 end_year() const {
            if (values.empty()) 
                throw HolidaysError(err::holidays::empty);

            return values.back().get_year();
        }
   };
} // namespace tts.
