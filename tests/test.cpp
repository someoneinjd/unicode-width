#include "boost/ut.hpp"
#include "sc/unicode_width.hpp"

using sc::unicode_width::width;

int main() {
    using namespace boost::ut;
    R"(text: "\0\0\0\x01\x01")"_test = [] {
        "char (cjk && not cjk)"_test = [] {
            expect(width("\0\0\0\x01\x01").has_value() == not "has_value"_b);
            expect(width("\0\0\0\x01\x01", false).has_value() == not "has_value"_b);
        };
        "char8_t (cjk && not cjk)"_test = [] {
            expect(width(u8"\0\0\0\x01\x01").has_value() == not "has_value"_b);
            expect(width(u8"\0\0\0\x01\x01", false).has_value() == not "has_value"_b);
        };
        "char16_t (cjk && not cjk)"_test = [] {
            expect(width(u"\0\0\0\x01\x01").has_value() == not "has_value"_b);
            expect(width(u"\0\0\0\x01\x01", false).has_value() == not "has_value"_b);
        };
        "char32_t (cjk && not cjk)"_test = [] {
            expect(width(U"\0\0\0\x01\x01").has_value() == not "has_value"_b);
            expect(width(U"\0\0\0\x01\x01", false).has_value() == not "has_value"_b);
        };
        "wchar_t (cjk && not cjk)"_test = [] {
            expect(width(L"\0\0\0\x01\x01").has_value() == not "has_value"_b);
            expect(width(L"\0\0\0\x01\x01", false).has_value() == not "has_value"_b);
        };
    };

    R"(text: "ｈｅｌｌｏ")"_test = [] {
        "char (cjk && not cjk)"_test = [] {
            auto cjk_result = width("ｈｅｌｌｏ"), result = width("ｈｅｌｌｏ", false);
            expect(cjk_result.has_value() == "has_value"_b && *cjk_result == 10_ull);
            expect(result.has_value() == "has_value"_b && *result == 10_ull);
        };
        "char8_t (cjk && not cjk)"_test = [] {
            auto cjk_result = width(u8"ｈｅｌｌｏ"), result = width(u8"ｈｅｌｌｏ", false);
            expect(cjk_result.has_value() == "has_value"_b && *cjk_result == 10_ull);
            expect(result.has_value() == "has_value"_b && *result == 10_ull);
        };
        "char16_t (cjk && not cjk)"_test = [] {
            auto cjk_result = width(u"ｈｅｌｌｏ"), result = width(u"ｈｅｌｌｏ", false);
            expect(cjk_result.has_value() == "has_value"_b && *cjk_result == 10_ull);
            expect(result.has_value() == "has_value"_b && *result == 10_ull);
        };
        "char32_t (cjk && not cjk)"_test = [] {
            auto cjk_result = width(U"ｈｅｌｌｏ"), result = width(U"ｈｅｌｌｏ", false);
            expect(cjk_result.has_value() == "has_value"_b && *cjk_result == 10_ull);
            expect(result.has_value() == "has_value"_b && *result == 10_ull);
        };
        "wchar_t (cjk && not cjk)"_test = [] {
            auto cjk_result = width(U"ｈｅｌｌｏ"), result = width(U"ｈｅｌｌｏ", false);
            expect(cjk_result.has_value() == "has_value"_b && *cjk_result == 10_ull);
            expect(result.has_value() == "has_value"_b && *result == 10_ull);
        };
    };

    R"(text: "" (empty string))"_test = [] {
        "char (cjk && not cjk)"_test = [] {
            auto cjk_result = width(""), result = width("", false);
            expect(cjk_result.has_value() == "has_value"_b && *cjk_result == 0_ull);
            expect(result.has_value() == "has_value"_b && *result == 0_ull);
        };
        "char8_t (cjk && not cjk)"_test = [] {
            auto cjk_result = width(u8""), result = width(u8"", false);
            expect(cjk_result.has_value() == "has_value"_b && *cjk_result == 0_ull);
            expect(result.has_value() == "has_value"_b && *result == 0_ull);
        };
        "char16_t (cjk && not cjk)"_test = [] {
            auto cjk_result = width(u""), result = width(u"", false);
            expect(cjk_result.has_value() == "has_value"_b && *cjk_result == 0_ull);
            expect(result.has_value() == "has_value"_b && *result == 0_ull);
        };
        "char32_t (cjk && not cjk)"_test = [] {
            auto cjk_result = width(U""), result = width(U"", false);
            expect(cjk_result.has_value() == "has_value"_b && *cjk_result == 0_ull);
            expect(result.has_value() == "has_value"_b && *result == 0_ull);
        };
        "wchar_t (cjk && not cjk)"_test = [] {
            auto cjk_result = width(U""), result = width(U"", false);
            expect(cjk_result.has_value() == "has_value"_b && *cjk_result == 0_ull);
            expect(result.has_value() == "has_value"_b && *result == 0_ull);
        };
    };

    R"(text: "\u2081\u2082\u2083\u2084")"_test = [] {
        "char (cjk && not cjk)"_test = [] {
            auto cjk_result = width("\u2081\u2082\u2083\u2084"),
                 result = width("\u2081\u2082\u2083\u2084", false);
            expect(cjk_result.has_value() == "has_value"_b && *cjk_result == 8_ull);
            expect(result.has_value() == "has_value"_b && *result == 4_ull);
        };
        "char8_t (cjk && not cjk)"_test = [] {
            auto cjk_result = width(u8"\u2081\u2082\u2083\u2084"),
                 result = width(u8"\u2081\u2082\u2083\u2084", false);
            expect(cjk_result.has_value() == "has_value"_b && *cjk_result == 8_ull);
            expect(result.has_value() == "has_value"_b && *result == 4_ull);
        };
        "char16_t (cjk && not cjk)"_test = [] {
            auto cjk_result = width(u"\u2081\u2082\u2083\u2084"),
                 result = width(u"\u2081\u2082\u2083\u2084", false);
            expect(cjk_result.has_value() == "has_value"_b && *cjk_result == 8_ull);
            expect(result.has_value() == "has_value"_b && *result == 4_ull);
        };
        "char32_t (cjk && not cjk)"_test = [] {
            auto cjk_result = width(U"\u2081\u2082\u2083\u2084"),
                 result = width(U"\u2081\u2082\u2083\u2084", false);
            expect(cjk_result.has_value() == "has_value"_b && *cjk_result == 8_ull);
            expect(result.has_value() == "has_value"_b && *result == 4_ull);
        };
        "wchar_t (cjk && not cjk)"_test = [] {
            auto cjk_result = width(U"\u2081\u2082\u2083\u2084"),
                 result = width(U"\u2081\u2082\u2083\u2084", false);
            expect(cjk_result.has_value() == "has_value"_b && *cjk_result == 8_ull);
            expect(result.has_value() == "has_value"_b && *result == 4_ull);
        };
    };

    R"(emoji: "👩")"_test = [] {
        "char (cjk && not cjk)"_test = [] {
            auto cjk_result = width("👩"), result = width("👩", false);
            expect(cjk_result.has_value() == "has_value"_b && *cjk_result == 2_ull);
            expect(result.has_value() == "has_value"_b && *result == 2_ull);
        };
        "char8_t (cjk && not cjk)"_test = [] {
            auto cjk_result = width(u8"👩"), result = width(u8"👩", false);
            expect(cjk_result.has_value() == "has_value"_b && *cjk_result == 2_ull);
            expect(result.has_value() == "has_value"_b && *result == 2_ull);
        };
        "char16_t (cjk && not cjk)"_test = [] {
            auto cjk_result = width(u"👩"), result = width(u"👩", false);
            expect(cjk_result.has_value() == "has_value"_b && *cjk_result == 2_ull);
            expect(result.has_value() == "has_value"_b && *result == 2_ull);
        };
        "char32_t (cjk && not cjk)"_test = [] {
            auto cjk_result = width(U"👩"), result = width(U"👩", false);
            expect(cjk_result.has_value() == "has_value"_b && *cjk_result == 2_ull);
            expect(result.has_value() == "has_value"_b && *result == 2_ull);
        };
        "wchar_t (cjk && not cjk)"_test = [] {
            auto cjk_result = width(U"👩"), result = width(U"👩", false);
            expect(cjk_result.has_value() == "has_value"_b && *cjk_result == 2_ull);
            expect(result.has_value() == "has_value"_b && *result == 2_ull);
        };
    };

    R"(emoji: "🔬")"_test = [] {
        "char (cjk && not cjk)"_test = [] {
            auto cjk_result = width("🔬"), result = width("🔬", false);
            expect(cjk_result.has_value() == "has_value"_b && *cjk_result == 2_ull);
            expect(result.has_value() == "has_value"_b && *result == 2_ull);
        };
        "char8_t (cjk && not cjk)"_test = [] {
            auto cjk_result = width(u8"🔬"), result = width(u8"🔬", false);
            expect(cjk_result.has_value() == "has_value"_b && *cjk_result == 2_ull);
            expect(result.has_value() == "has_value"_b && *result == 2_ull);
        };
        "char16_t (cjk && not cjk)"_test = [] {
            auto cjk_result = width(u"🔬"), result = width(u"🔬", false);
            expect(cjk_result.has_value() == "has_value"_b && *cjk_result == 2_ull);
            expect(result.has_value() == "has_value"_b && *result == 2_ull);
        };
        "char32_t (cjk && not cjk)"_test = [] {
            auto cjk_result = width(U"🔬"), result = width(U"🔬", false);
            expect(cjk_result.has_value() == "has_value"_b && *cjk_result == 2_ull);
            expect(result.has_value() == "has_value"_b && *result == 2_ull);
        };
        "wchar_t (cjk && not cjk)"_test = [] {
            auto cjk_result = width(U"🔬"), result = width(U"🔬", false);
            expect(cjk_result.has_value() == "has_value"_b && *cjk_result == 2_ull);
            expect(result.has_value() == "has_value"_b && *result == 2_ull);
        };
    };

    R"(emoji: "👩‍🔬")"_test = [] {
        "char (cjk && not cjk)"_test = [] {
            auto cjk_result = width("👩‍🔬"), result = width("👩‍🔬", false);
            expect(cjk_result.has_value() == "has_value"_b && *cjk_result == 4_ull);
            expect(result.has_value() == "has_value"_b && *result == 4_ull);
        };
        "char8_t (cjk && not cjk)"_test = [] {
            auto cjk_result = width(u8"👩‍🔬"), result = width(u8"👩‍🔬", false);
            expect(cjk_result.has_value() == "has_value"_b && *cjk_result == 4_ull);
            expect(result.has_value() == "has_value"_b && *result == 4_ull);
        };
        "char16_t (cjk && not cjk)"_test = [] {
            auto cjk_result = width(u"👩‍🔬"), result = width(u"👩‍🔬", false);
            expect(cjk_result.has_value() == "has_value"_b && *cjk_result == 4_ull);
            expect(result.has_value() == "has_value"_b && *result == 4_ull);
        };
        "char32_t (cjk && not cjk)"_test = [] {
            auto cjk_result = width(U"👩‍🔬"), result = width(U"👩‍🔬", false);
            expect(cjk_result.has_value() == "has_value"_b && *cjk_result == 4_ull);
            expect(result.has_value() == "has_value"_b && *result == 4_ull);
        };
        "wchar_t (cjk && not cjk)"_test = [] {
            auto cjk_result = width(U"👩‍🔬"), result = width(U"👩‍🔬", false);
            expect(cjk_result.has_value() == "has_value"_b && *cjk_result == 4_ull);
            expect(result.has_value() == "has_value"_b && *result == 4_ull);
        };
    };

    R"(char: U'ｈ')"_test = [] {
        auto cjk_result = width(U'ｈ'), result = width(U'ｈ', false);
        expect(cjk_result.has_value() == "has_value"_b && *cjk_result == 2_ull);
        expect(result.has_value() == "has_value"_b && *result == 2_ull);
    };

    R"(char: '\x00')"_test = [] {
        auto cjk_result = width('\x00'), result = width('\x00', false);
        expect(cjk_result.has_value() == "has_value"_b && *cjk_result == 0_ull);
        expect(result.has_value() == "has_value"_b && *result == 0_ull);
    };

    R"(char: '\x01')"_test = [] {
        auto cjk_result = width('\x01'), result = width('\x01', false);
        expect(cjk_result.has_value() == not "has_value"_b);
        expect(result.has_value() == not "has_value"_b);
    };

    R"(char: U'\u2081')"_test = [] {
        auto cjk_result = width(U'\u2081'), result = width(U'\u2081', false);
        expect(cjk_result.has_value() == "has_value"_b && *cjk_result == 2_ull);
        expect(result.has_value() == "has_value"_b && *result == 1_ull);
    };

    R"(char: '\x0A')"_test = [] {
        auto cjk_result = width('\x0A'), result = width('\x0A', false);
        expect(cjk_result.has_value() == not "has_value"_b);
        expect(result.has_value() == not "has_value"_b);
    };

    R"(char: 'w')"_test = [] {
        auto cjk_result = width('w'), result = width('w', false);
        expect(cjk_result.has_value() == "has_value"_b && *cjk_result == 1_ull);
        expect(result.has_value() == "has_value"_b && *result == 1_ull);
    };

    R"(char: U'\u00AD')"_test = [] {
        auto cjk_result = width(U'\u00AD'), result = width(U'\u00AD', false);
        expect(cjk_result.has_value() == "has_value"_b && *cjk_result == 1_ull);
        expect(result.has_value() == "has_value"_b && *result == 1_ull);
    };

    R"(char: U'\u1160')"_test = [] {
        auto cjk_result = width(U'\u1160'), result = width(U'\u1160', false);
        expect(cjk_result.has_value() == "has_value"_b && *cjk_result == 0_ull);
        expect(result.has_value() == "has_value"_b && *result == 0_ull);
    };

    R"(char: U'\u00A1')"_test = [] {
        auto cjk_result = width(U'\u00A1'), result = width(U'\u00A1', false);
        expect(cjk_result.has_value() == "has_value"_b && *cjk_result == 2_ull);
        expect(result.has_value() == "has_value"_b && *result == 1_ull);
    };

    R"(char: U'\u0300')"_test = [] {
        auto cjk_result = width(U'\u0300'), result = width(U'\u0300', false);
        expect(cjk_result.has_value() == "has_value"_b && *cjk_result == 0_ull);
        expect(result.has_value() == "has_value"_b && *result == 0_ull);
    };

    R"(char: U'\U0001F971')"_test = [] {
        auto cjk_result = width(U'\U0001F971'), result = width(U'\U0001F971', false);
        expect(cjk_result.has_value() == "has_value"_b && *cjk_result == 2_ull);
        expect(result.has_value() == "has_value"_b && *result == 2_ull);
    };
}
