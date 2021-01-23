#include "metheon.h"

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _EXTEND, _SYMBOLS, _ADJUST);
    state = update_tri_layer_state(state, _NUMPAD, _FUNPAD , _MAGNET);
    return state;
};

void matrix_scan_user(void) {
    matrix_scan_encoders();
    matrix_scan_leader();
}

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_metheon(
    //  .--------------------------------------------.                    .--------------------------------------------.
         KC_Q    ,KC_W    ,KC_F    ,KC_P    ,KC_B                         ,KC_J    ,KC_L    ,KC_U    ,KC_Y    ,KC_QUOT ,
    //  |--------------------------------------------|                    |--------------------------------------------|
         HOME_A  ,HOME_R  ,HOME_S ,HOME_T   ,KC_G                         ,KC_M    ,HOME_N  ,HOME_E  ,HOME_I  ,HOME_O  ,
    //  |--------------------------------------------|                    |--------------------------------------------|
         KC_Z    ,KC_X    ,KC_C    ,KC_D    ,KC_V                         ,KC_K    ,KC_H    ,KC_COMMA,KC_DOT  ,KC_SLSH ,
    //  '-------------------------+--------+---------+--------+  +--------+--------+--------+--------------------------'
                                   BSE_E01 ,SPC_EXT  ,ENT_NUM    ,DEL_FUN ,BSPC_SYM,BSE_E02
    //                            '--------+---------+--------+  +--------+--------+--------'
    ),
    [_NUMPAD] = LAYOUT_metheon(
    //  .--------------------------------------------.                    .--------------------------------------------.
         __NONE__,__NONE__,__NONE__,__NONE__,__NONE__                     ,KC_EQL  ,KC_7    ,KC_8    ,KC_9    ,KC_ASTR ,
    //  |--------------------------------------------|                    |--------------------------------------------|
         KC_LGUI ,KC_LALT ,KC_LSFT ,KC_LCTRL,__NONE__                     ,KC_PLUS ,KC_4    ,KC_5    ,KC_6    ,KC_0    ,
    //  |--------------------------------------------|                    |--------------------------------------------|
         __NONE__,__NONE__,__NONE__,__NONE__,__NONE__                     ,KC_MINS ,KC_1    ,KC_2    ,KC_3    ,KC_SLSH ,
    //  '-------------------------+--------+---------+--------+  +--------+--------+--------+--------------------------'
                                   NUM_E01 ,________ ,________   ,________,________,NUM_E02
    //                            '--------+---------+--------+  +--------+--------+--------'
    ),
    [_SYMBOLS] = LAYOUT_metheon(
    //  .--------------------------------------------.                    .--------------------------------------------.
         KC_GRV  ,KC_CIRC ,KC_HASH ,KC_TILD ,KC_LCBR                      ,KC_RCBR ,KC_DLR  ,KC_EUR  ,KC_PND  ,__NONE__,
    //  |--------------------------------------------|                    |--------------------------------------------|
         KC_AT   ,KC_AE   ,KC_OE   ,KC_AA   ,KC_LPRN                      ,KC_RPRN ,KC_EQL  ,KC_EXLM ,KC_AMPR ,KC_PIPE ,
    //  |--------------------------------------------|                    |--------------------------------------------|
         KC_UNDS ,KC_MINS ,KC_COLN ,KC_SCLN ,KC_LBRC                       ,KC_RBRC ,__NONE__,__NONE__,KC_PERC ,KC_BSLS ,
    //  '-------------------------+--------+---------+--------+  +--------+--------+--------+--------------------------'
                                   SYM_E01 ,________ ,________   ,________,________,SYM_E02
    //                            '--------+---------+--------+  +--------+--------+--------'
    ),
    [_EXTEND] = LAYOUT_metheon(
    //  .--------+--------+--------+--------+--------.                    .--------------------------------------------.
         KC_ESC  ,__NONE__,__NONE__,__NONE__,__NONE__                     ,KC_PGUP ,KC_HOME ,KC_UP   ,KC_END  ,__NONE__,
    //  |--------------------------------------------|                    |--------------------------------------------|
         KC_LGUI ,KC_LALT ,KC_LSFT ,KC_LCTRL,KC_LEAD                      ,KC_PGDN ,KC_LEFT ,KC_DOWN ,KC_RGHT ,__NONE__,
    //  |--------------------------------------------|                    |--------------------------------------------|
         UNDO    ,CUT     ,COPY    ,PASTE   ,PASTE                        ,__NONE__,KC_STAB ,KC_TAB  ,__NONE__,__NONE__,
    //  '--------+--------+--------+--------+--------+--------+  +--------+--------+--------+--------+--------+--------'
                                   EXT_E01  ,________ ,________  ,ESC_FUN ,TAB_SYM ,EXT_E02
    //                            '--------+---------+--------+  +--------+--------+--------'
    ),
    [_FUNPAD] = LAYOUT_metheon(
    //  .--------------------------------------------.                    .--------------------------------------------.
         KC_F9   ,KC_F10  ,KC_F11  ,KC_F12  ,__NONE__                     ,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__,
    //  |--------------------------------------------|                    |--------------------------------------------|
         KC_F5   ,KC_F6   ,KC_F7   ,KC_F8   ,__NONE__                     ,__NONE__,KC_LCTRL,KC_LSFT ,KC_LALT ,KC_LGUI ,
    //  |--------------------------------------------|                    |--------------------------------------------|
         KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,__NONE__                     ,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__,
    //  '-------------------------+--------+---------+--------+  +--------+--------+--------+--------------------------'
                                   FUN_E01 ,________ ,________   ,________,________,FUN_E02
    //                            '--------+---------+--------+  +--------+--------+--------'
    ),
    [_ADJUST] = LAYOUT_metheon(
    //  .--------------------------------------------.                    .--------------------------------------------.
         __NONE__,__NONE__,WHICH_OS,CG_TOGG ,__NONE__                     ,__NONE__,KC_FLASH,KC_MAKE ,KC_VRSN ,__NONE__,
    //  |--------------------------------------------|                    |--------------------------------------------|
         KC_CAPS ,KC_MPRV ,KC_MPLY ,KC_MNXT ,__NONE__                     ,RGB_TOG ,RGB_MOD ,RGB_HUI ,RGB_SAI ,RGB_VAI ,
    //  |--------------------------------------------|                    |--------------------------------------------|
         __NONE__,KC_MUTE ,KC_VOLD ,KC_VOLU ,__NONE__                     ,__NONE__,RGB_RMOD,RGB_HUD ,RGB_SAD ,RGB_VAD ,
    //  '-------------------------+--------+---------+--------+  +--------+--------+--------+--------------------------'
                                   ADJ_E01 ,________ ,RESET      ,RESET   ,________,ADJ_E02
    //                            '--------+---------+--------+  +--------+--------+--------'
    ),
    [_MAGNET] = LAYOUT_metheon(
    //  .--------------------------------------------.                    .--------------------------------------------.
         __NONE__,MG_UL_QD,MG_UP_HF,MG_UR_QD,__NONE__                     ,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__,
    //  |--------------------------------------------|                    |--------------------------------------------|
         __NONE__,MG_LF_HF,MG_FSCR ,MG_RT_HF,__NONE__                     ,________,MG_LF_TD,MG_MD_TD,MG_RT_TD,__NONE__,
    //  |--------------------------------------------|                    |--------------------------------------------|
         __NONE__,MG_BL_QD,MG_BT_HF,MG_BR_QD,__NONE__                     ,__NONE__,MG_L2_TD,MG_R2_TD,__NONE__,__NONE__,
    //  '-------------------------+--------+---------+--------+  +--------+--------+--------+--------------------------'
                                   MAG_E01 ,________ ,________   ,________,________,MAG_E02
    //                            '--------+---------+--------+  +--------+--------+--------'
    )
};
// clang-format on
