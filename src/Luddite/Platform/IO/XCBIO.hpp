#pragma once
#include "Luddite/Core/pch.hpp"

#ifdef LD_PLATFORM_LINUX
#include "xkbcommon/xkbcommon-keysyms.h"

namespace Luddite
{
enum class Keys : uint32_t
{
        A = XKB_KEY_a,
        B = XKB_KEY_b,
        C = XKB_KEY_c,
        D = XKB_KEY_d,
        E = XKB_KEY_e,
        F = XKB_KEY_f,
        G = XKB_KEY_g,
        H = XKB_KEY_h,
        I = XKB_KEY_i,
        J = XKB_KEY_j,
        K = XKB_KEY_k,
        L = XKB_KEY_l,
        M = XKB_KEY_m,
        N = XKB_KEY_n,
        O = XKB_KEY_o,
        P = XKB_KEY_p,
        Q = XKB_KEY_q,
        R = XKB_KEY_r,
        S = XKB_KEY_s,
        T = XKB_KEY_t,
        U = XKB_KEY_u,
        V = XKB_KEY_v,
        W = XKB_KEY_w,
        X = XKB_KEY_x,
        Y = XKB_KEY_y,
        Z = XKB_KEY_z,
        Zero = XKB_KEY_0,
        One = XKB_KEY_1,
        Two = XKB_KEY_2,
        Three = XKB_KEY_3,
        Four = XKB_KEY_4,
        Five = XKB_KEY_5,
        Six = XKB_KEY_6,
        Seven = XKB_KEY_7,
        Eight = XKB_KEY_8,
        Nine = XKB_KEY_9,
        Space = XKB_KEY_space,
        Exclamation = XKB_KEY_exclam,
        Quotedbl = XKB_KEY_quotedbl,
        Numbersign = XKB_KEY_numbersign,
        Dollar = XKB_KEY_dollar,
        Percent = XKB_KEY_percent,
        Ampersand = XKB_KEY_ampersand,
        Apostrophe = XKB_KEY_apostrophe,
        ParenthesisLeft = XKB_KEY_parenleft,
        ParenthesisRight = XKB_KEY_parenright,
        Asterisk = XKB_KEY_asterisk,
        Plus = XKB_KEY_plus,
        Comma = XKB_KEY_comma,
        Minus = XKB_KEY_minus,
        Period = XKB_KEY_period,
        Slash = XKB_KEY_slash,
        Colon = XKB_KEY_colon,
        Semicolon = XKB_KEY_semicolon,
        Less = XKB_KEY_less,
        Equal = XKB_KEY_equal,
        Greater = XKB_KEY_greater,
        QuestionMark = XKB_KEY_question,
        At = XKB_KEY_at,
        BracketLeft = XKB_KEY_bracketleft,
        BracketRight = XKB_KEY_bracketright,
        Backslash = XKB_KEY_backslash,
        Asciicircum = XKB_KEY_asciicircum,
        Underscore = XKB_KEY_underscore,
        Grave = XKB_KEY_grave,
        BraceLeft = XKB_KEY_braceleft,
        BraceRight = XKB_KEY_braceright,
        Bar = XKB_KEY_bar,
        Asciitilde = XKB_KEY_asciitilde,

        // Modifiers
        ShiftLeft = XKB_KEY_Shift_L,
        ShiftRight = XKB_KEY_Shift_R,
        ControlLeft = XKB_KEY_Control_L,
        ControlRight = XKB_KEY_Control_R,
        CapsLock = XKB_KEY_Caps_Lock,
        ShiftLock = XKB_KEY_Shift_Lock,
        MetaLeft = XKB_KEY_Meta_L,
        MetaRight = XKB_KEY_Meta_R,
        AltLeft = XKB_KEY_Alt_L,
        AltRight = XKB_KEY_Alt_R,
        SuperLeft = XKB_KEY_Super_L,
        SuperRight = XKB_KEY_Super_R,
        HyperLeft = XKB_KEY_Hyper_L,
        HyperRight = XKB_KEY_Hyper_R,

        //Functions
        F1 = XKB_KEY_F1,
        F2 = XKB_KEY_F2,
        F3 = XKB_KEY_F3,
        F4 = XKB_KEY_F4,
        F5 = XKB_KEY_F5,
        F6 = XKB_KEY_F6,
        F7 = XKB_KEY_F7,
        F8 = XKB_KEY_F8,
        F9 = XKB_KEY_F9,
        F10 = XKB_KEY_F10,
        F11 = XKB_KEY_F11,
        F12 = XKB_KEY_F12,
        F13 = XKB_KEY_F13,
        F14 = XKB_KEY_F14,
        F15 = XKB_KEY_F15,
        F16 = XKB_KEY_F16,
        F17 = XKB_KEY_F17,
        F18 = XKB_KEY_F18,
        F19 = XKB_KEY_F19,
        F20 = XKB_KEY_F20,
        F21 = XKB_KEY_F21,
        F22 = XKB_KEY_F22,
        F23 = XKB_KEY_F23,
        F24 = XKB_KEY_F24,
        F25 = XKB_KEY_F25,
        F26 = XKB_KEY_F26,
        F27 = XKB_KEY_F27,
        F28 = XKB_KEY_F28,
        F29 = XKB_KEY_F29,
        F30 = XKB_KEY_F30,
        F31 = XKB_KEY_F31,
        F32 = XKB_KEY_F32,
        F33 = XKB_KEY_F33,
        F34 = XKB_KEY_F34,
        F35 = XKB_KEY_F35,
};
}

#endif //LD_PLATFORM_LINUX
