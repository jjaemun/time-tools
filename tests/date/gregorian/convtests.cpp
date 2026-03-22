#include <array>
#include <gtest/gtest.h>


#include "timetools.hpp"


namespace detail {
    namespace civil {
        static constexpr tts::CivilDate epoch{1970, 1, 1};
        static constexpr tts::CivilDate min{1980, 1, 1};
        static constexpr tts::CivilDate max{2200, 12, 31};
        static constexpr tts::CivilDate leap{2000, 2, 29};
        static constexpr tts::CivilDate nonleap{2100, 2, 28};
        static constexpr tts::CivilDate y2k{2000, 1, 1};
        static constexpr tts::CivilDate eoy{2000, 12, 31};
        static constexpr tts::CivilDate soy{2024, 1, 1};
    } // namespace civil.

    namespace serial {}
} // namespace detail.
