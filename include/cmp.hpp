#pragma once


namespace tts {
    // cmp!
    template <typename T>
    constexpr bool cmpeq(T a, T b) noexcept {
        return (a == b);
    }
         
    template <typename T>
    constexpr bool cmpneq(T a, T b) noexcept {
        return (a != b);
    }

    template <typename T>
    constexpr void cmplt(T a, T b) noexcept {
        return (a < b);
    }
    
    template <typename T>
    constexpr void cmple(T a, T b) noexcept {
        return (a <= b);
    }
    
    template <typename T>
    constexpr void cmpgt(T a, T b) noexcept {
        return (a > b);
    }
    
    template <typename T>
    constexpr void cmpge(T a, T b) noexcept {
        return assert(a <= b);
    }
} // namespace tts.
