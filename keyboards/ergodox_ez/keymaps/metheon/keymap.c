// clang-format off
#define LAYOUT_metheon(\
    L11, L12, L13, L14, L15, L16, R11, R12, R13, R14, R15, R16, \
    L21, L22, L23, L24, L25, L26, R21, R22, R23, R24, R25, R26, \
    L31, L32, L33, L34, L35, L36, R31, R32, R33, R34, R35, R36, \
    L41, L42, L43, L44, L45, L46, R41, R42, R43, R44, R45, R46, \
    E01, E02                                                    \
    )\
    LAYOUT_ergodox_pretty( \
    KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,   KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,  \
    L11,  L12,  L13,  L14,  L15,  L16,  L42,     R45,  R11,  R12,  R13,  R14,  R15,  R16,    \
    L21,  L22,  L23,  L24,  L25,  L26,                 R21,  R22,  R23,  R24,  R25,  R26,    \
    L31,  L32,  L33,  L34,  L35,  L36,  L41,     R46,  R31,  R32,  R33,  R34,  R35,  R36,    \
    KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                           R42,  R44,  KC_NO,KC_NO,KC_NO,  \
                                  KC_NO,KC_NO,   KC_NO,KC_NO,                                \
                                        KC_NO,   KC_NO,                                      \
                            L46,  L44,  KC_NO,   KC_NO,R43,  R41                             \
)
// clang-format on

#include "metheon.c"
