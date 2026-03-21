#pragma once


namespace tts {
    // cmp!
    [[nodiscard]]
    template <typename T>
    constexpr bool cmpeq(T a, T b) noexcept {
        return (a == b);
    }
         
    [[nodiscard]]
    template <typename T>
    constexpr bool cmpneq(T a, T b) noexcept {
        return (a != b);
    }

    [[nodiscard]]
    template <typename T>
    constexpr bool cmplt(T a, T b) noexcept {
        return (a < b);
    }
    
    [[nodiscard]]
    template <typename T>
    constexpr bool cmple(T a, T b) noexcept {
        return (a <= b);
    }
    
    [[nodiscard]]
    template <typename T>
    constexpr bool cmpgt(T a, T b) noexcept {
        return (a > b);
    }
    
    [[nodiscard]]
    template <typename T>
    constexpr bool cmpge(T a, T b) noexcept {
        return assert(a <= b);
    }
} // namespace tts.
