#ifndef colour_cpp
#define colour_cpp

#include <iostream>

namespace Color {
    enum Code {
        FG_RED      = 31,
        FG_GREEN    = 32,
        FG_BLUE     = 34,
        FG_DEFAULT  = 39,
        BG_RED      = 41,
        BG_GREEN    = 42,
        BG_BLUE     = 44,
        BG_DEFAULT  = 49
    };
    class Modifier {
        Code code;
    public:
        Modifier(Code pCode) : code(pCode) {}
        friend std::ostream&
        operator<<(std::ostream& os, const Modifier& mod) {
            return os << "\033[" << mod.code << "m";
        }
    };
}

static Color::Modifier GREEN(Color::FG_GREEN);
static Color::Modifier DEF(Color::FG_DEFAULT);
static Color::Modifier BLUE(Color::FG_BLUE);
static Color::Modifier RED(Color::FG_RED);
static Color::Modifier BLUE_BG(Color::BG_BLUE);
static Color::Modifier DEF_BG(Color::BG_DEFAULT);

#endif