#pragma once


namespace tts {
    // cmp!
    template <typename T>
    [[nodiscard]]
    constexpr bool cmpeq(T a, T b) noexcept {
        return (a == b);
    }
         
    template <typename T>
    [[nodiscard]]
    constexpr bool cmpneq(T a, T b) noexcept {
        return (a != b);
    }

    template <typename T>
    [[nodiscard]]
    constexpr bool cmplt(T a, T b) noexcept {
        return (a < b);
    }
    
    template <typename T>
    [[nodiscard]]
    constexpr bool cmple(T a, T b) noexcept {
        return (a <= b);
    }
    
    template <typename T>
    [[nodiscard]]
    constexpr bool cmpgt(T a, T b) noexcept {
        return (a > b);
    }
    
    template <typename T>
    [[nodiscard]]
    constexpr bool cmpge(T a, T b) noexcept {
        return (a >= b);
    }
} // namespace tts.
