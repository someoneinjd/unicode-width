#include <iostream>
#include <optional>
#include <ostream>

#include "unicode_width.hpp"

using std::optional;
using unicode_width::width;

template <typename T>
std::ostream &operator<<(std::ostream &out, const optional<T> &val) {
    if (val)
        out << *val;
    else
        out << "std::nullopt";
    return out;
}

std::ostream &operator<<(std::ostream &out, std::nullopt_t) {
    out << "std::nullopt";
    return out;
}

template <typename T, typename R>
void assert_eq_impl(T expr, R val, const char *name, const char *file,
                    int line) {
    if (expr != val)
        std::cerr << "[DEBUG] " << file << ":" << line << ": Assertion failed\n"
                  << "\tExpected: " << name << " = " << val
                  << "\n\tBut:      " << name << " = " << expr << "\n";
}

#define assert_eq(expr, val) \
    assert_eq_impl(expr, val, #expr, __FILE__, __LINE__)

#define test_text(text, val0, val1) \
    assert_eq(width(text), val0); \
    assert_eq(width(text, false), val1); \
    assert_eq(width(u8##text), val0); \
    assert_eq(width(u8##text, false), val1); \
    assert_eq(width(u##text), val0); \
    assert_eq(width(u##text, false), val1); \
    assert_eq(width(U##text), val0); \
    assert_eq(width(U##text, false), val1); \
    assert_eq(width(L##text), val0); \
    assert_eq(width(L##text, false), val1)

int main() {
    test_text("ｈｅｌｌｏ", 10, 10);
    test_text("\0\0\0\x01\x01", std::nullopt, std::nullopt);
    test_text("", 0, 0);
    test_text("\u2081\u2082\u2083\u2084", 8, 4);

    test_text("👩", 2, 2);           // Woman
    test_text("🔬", 2, 2);           // Microscope
    test_text("👩‍🔬", 4, 4);   // Woman scientist

    assert_eq(width(U'ｈ'), 2);
    assert_eq(width(U'ｈ', false), 2);
    assert_eq(width('\x00'), 0);
    assert_eq(width('\x00', false), 0);
    assert_eq(width('\x01'), std::nullopt);
    assert_eq(width('\x01', false), std::nullopt);
    assert_eq(width(U'\u2081'), 2);
    assert_eq(width(U'\u2081', false), 1);

    assert_eq(width('\x00'), 0);
    assert_eq(width('\x00', false), 0);

    assert_eq(width('\x0A'), std::nullopt);
    assert_eq(width('\x0A', false), std::nullopt);

    assert_eq(width('w'), 1);
    assert_eq(width('w', false), 1);

    assert_eq(width(U'ｈ'), 2);
    assert_eq(width(U'ｈ', false), 2);

    assert_eq(width(U'\u00AD'), 1);
    assert_eq(width(U'\u00AD', false), 1);

    assert_eq(width(U'\u1160'), 0);
    assert_eq(width(U'\u1160', false), 0);

    assert_eq(width(U'\u00a1'), 2);
    assert_eq(width(U'\u00a1', false), 1);

    assert_eq(width(U'\u0300'), 0);
    assert_eq(width(U'\u0300', false), 0);
}
