#include "metheon.h"

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _LOWER, _EXTEND, _MAGNET);
    state = update_tri_layer_state(state, _EXTEND, _RAISE, _FUNPAD);
    state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    return state;
};

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_A:
        case HOME_R:
        case HOME_S:
        case HOME_T:
        case HOME_N:
        case HOME_E:
        case HOME_I:
        case HOME_O:
            return true;
        default:
            return false;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_A:
        case HOME_R:
        case HOME_S:
        case HOME_T:
        case HOME_N:
        case HOME_E:
        case HOME_I:
        case HOME_O:
            return TAPPING_TERM - 100; // 400-100=300
        case SPC_EXT:
        case ENT_EXT:
            return TAPPING_TERM - 225; // 400-225=175
        default:
            return TAPPING_TERM;       // 400
    }
}

void matrix_scan_user(void) {
    matrix_scan_encoders();
    matrix_scan_window_tab();
}

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_metheon(
    //  .--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------.
         KC_TAB  ,KC_Q    ,KC_W    ,KC_F    ,KC_P    ,KC_B    ,KC_J    ,KC_L    ,KC_U    ,KC_Y    ,KC_SCLN ,KC_BSPC ,
    //  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         KC_ESC  ,HOME_A  ,HOME_R  ,HOME_S ,HOME_T   ,KC_G    ,KC_M    ,HOME_N  ,HOME_E  ,HOME_I  ,HOME_O  ,KC_QUOT ,
    //  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         SHIFT   ,KC_Z    ,KC_X    ,KC_C    ,KC_D    ,KC_V    ,KC_K    ,KC_H    ,KC_COMMA,KC_DOT  ,KC_SLSH ,SHIFT   ,
    //  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         LOCK    ,SEARCH  ,__NONE__,FUNPAD  ,LWR_SFT ,SPC_EXT ,ENT_EXT ,RSE_SFT ,MAGNET  ,__NONE__,SECRETS ,__NONE__
    //  '--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
    ),
    [_LOWER] = LAYOUT_metheon(
    //  .--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------.
         KC_TAB  ,KC_SLSH ,KC_ASTR ,KC_MINS ,KC_PLUS ,KC_EQL  ,KC_PERC ,KC_7    ,KC_8    ,KC_9    ,__NONE__,KC_BSPC ,
    //  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         __NONE__,KC_LGUI ,KC_LALT ,KC_LSFT ,KC_LCTRL,KC_LPRN ,KC_RPRN ,KC_4    ,KC_5    ,KC_6    ,KC_0    ,__NONE__,
    //  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         __NONE__,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__,KC_1    ,KC_2    ,KC_3    ,__NONE__,__NONE__,
    //  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         __NONE__,__NONE__,__NONE__,__NONE__,________,ENT_EXT ,ENT_EXT ,________,KC_COMMA,KC_DOT  ,__NONE__,__NONE__
    //  '--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
    ),
    [_RAISE] = LAYOUT_metheon(
    //  .--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------.
         __NONE__,KC_GRV  ,KC_CIRC ,KC_HASH ,KC_TILD ,KC_LCBR ,KC_RCBR ,KC_DLR  ,KC_EUR  ,KC_PND  ,__NONE__,__NONE__,
    //  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         __NONE__,KC_AT   ,KC_AE   ,KC_OE   ,KC_AA   ,KC_LPRN ,KC_RPRN ,KC_EQL  ,KC_EXLM ,KC_AMPR ,KC_PIPE ,__NONE__,
    //  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         __NONE__,KC_BSLS ,KC_PERC ,KC_UNDS ,KC_MINS ,KC_LBRC ,KC_RBRC ,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__,
    //  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         __NONE__,__NONE__,__NONE__,__NONE__,________,SPC_EXT ,SPC_EXT ,________,__NONE__,__NONE__,__NONE__,__NONE__
    //  '--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
    ),
    [_EXTEND] = LAYOUT_metheon(
    //  .--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------.
         __NONE__,PREV_TAB,NEXT_TAB,PREV_WIN,NEXT_WIN,__NONE__,KC_PGUP ,KC_HOME ,KC_UP   ,KC_END  ,__NONE__,KC_DEL  ,
    //  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         __NONE__,KC_LGUI ,KC_LALT ,KC_LSFT ,KC_LCTRL,__NONE__,KC_PGDN ,KC_LEFT ,KC_DOWN ,KC_RGHT ,KC_ENTER,__NONE__,
    //  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         __NONE__,UNDO    ,CUT     ,COPY     ,TEXT_MOD,PASTE  ,OVERVIEW,PRV_DSKT,NXT_DSKT,__NONE__,__NONE__,__NONE__,
    //  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         IJ_RNAME,IJ_TERM ,__NONE__,__NONE__,________,________,________,________,__NONE__,__NONE__,__NONE__,__NONE__
    //  '--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
    ),
    [_FUNPAD] = LAYOUT_metheon(
    //  .--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------.
         __NONE__,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__,KC_F7   ,KC_F8   ,KC_F9   ,KC_F12  ,__NONE__,
    //  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         __NONE__,KC_LGUI ,KC_LALT ,KC_LSFT ,KC_LCTRL,__NONE__,__NONE__,KC_F4   ,KC_F5   ,KC_F6   ,KC_F10  ,__NONE__,
    //  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         __NONE__,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__,KC_F1   ,KC_F2   ,KC_F3   ,KC_F11  ,__NONE__,
    //  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         __NONE__,__NONE__,__NONE__,__NONE__,________,________,________,________,__NONE__,__NONE__,__NONE__,__NONE__
    //  '--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
    ),
    [_ADJUST] = LAYOUT_metheon(
    //  .--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------.
         __NONE__,RESET   ,__NONE__,WHICH_OS,CG_TOGG ,__NONE__,TO_BL3  ,KC_FLASH,KC_MAKE ,KC_VRSN ,__NONE__,__NONE__,
    //  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         __NONE__,KC_CAPS ,KC_MPRV ,KC_MPLY ,KC_MNXT ,__NONE__,RGB_TOG ,RGB_MOD ,RGB_HUI ,RGB_SAI ,RGB_VAI ,__NONE__,
    //  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         __NONE__,__NONE__,KC_MUTE ,KC_VOLD ,KC_VOLU ,__NONE__,__NONE__,RGB_RMOD,RGB_HUD ,RGB_SAD ,RGB_VAD ,__NONE__,
    //  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         __NONE__,__NONE__,__NONE__,__NONE__,________,________,________,________,__NONE__,__NONE__,__NONE__,__NONE__
    //  '--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
    ),
    [_MAGNET] = LAYOUT_metheon(
    //  .--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------.
         __NONE__,__NONE__,MG_UL_QD,MG_UP_HF,MG_UR_QD,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__,
    //  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         __NONE__,__NONE__,MG_LF_HF,MG_FSCR ,MG_RT_HF,__NONE__,________,MG_LF_TD,MG_MD_TD,MG_RT_TD,__NONE__,__NONE__,
    //  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         __NONE__,__NONE__,MG_BL_QD,MG_BT_HF,MG_BR_QD,__NONE__,__NONE__,MG_L2_TD,MG_R2_TD,__NONE__,__NONE__,__NONE__,
    //  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         __NONE__,__NONE__,__NONE__,__NONE__,________,________,________,________,__NONE__,__NONE__,__NONE__,__NONE__
    //  '--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
    ),
    [_SECRETS] = LAYOUT_metheon(
    //  .--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------.
         __NONE__,SECRET00,SECRET01,SECRET02,SECRET03,SECRET04,SECRET05,SECRET06,SECRET07,SECRET08,SECRET09,__NONE__,
    //  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         __NONE__,SECRET10,SECRET11,SECRET12,SECRET13,SECRET14,SECRET15,SECRET16,SECRET17,SECRET18,SECRET19,__NONE__,
    //  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         __NONE__,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__,
    //  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         __NONE__,__NONE__,__NONE__,__NONE__,________,________,________,________,__NONE__,__NONE__,__NONE__,__NONE__
    //  '--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
    ),
    [_BL3_BSE] = LAYOUT_metheon(
    //  .--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------.
         __NONE__,KC_F    ,KC_Q    ,BL3_W   ,KC_E    ,KC_R    ,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__,
    //  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         __NONE__,KC_LCTL ,BL3_A   ,BL3_S   ,BL3_D   ,KC_G    ,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__,
    //  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         __NONE__,KC_LSFT ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__,
    //  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         __NONE__,__NONE__,__NONE__,__NONE__,KC_V    ,BL3_SPC ,BL3_SPC ,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__
    //  '--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
    ),
    [_BL3_UPR] = LAYOUT_metheon(
    //  .--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------.
         __NONE__,KC_TAB  ,KC_LBRC ,________,KC_RBRC ,KC_C    ,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__,
    //  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         __NONE__,KC_ESC  ,________,________,________,KC_X    ,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__,
    //  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         __NONE__,________,KC_M    ,KC_I    ,KC_L    ,KC_K    ,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__,
    //  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         __NONE__,__NONE__,__NONE__,__NONE__,__NONE__,TO_BASE ,TO_BASE ,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__
    //  '--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
    )
};
// clang-format on

