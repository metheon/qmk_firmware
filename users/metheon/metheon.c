#include "metheon.h"

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
};

void matrix_scan_user(void) {
    matrix_scan_encoders();
    matrix_scan_leader();
}

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_metheon(
        KC_TAB  ,KC_Q    ,KC_W    ,KC_F    ,KC_P    ,KC_G    ,KC_J    ,KC_L    ,KC_U    ,KC_Y    ,KC_SCLN ,KC_BSPC ,
        KC_ESC  ,A_SFT   ,R_GUI   ,S_ALT   ,T_CTL   ,KC_D    ,KC_H    ,N_CTL   ,E_ALT   ,I_GUI   ,O_SFT   ,KC_QUOT ,
        XXXXXXX ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_K    ,KC_M    ,KC_COMMA,KC_DOT  ,KC_SLSH ,XXXXXXX ,
        KC_LEAD ,LOCK_PC ,XXXXXXX ,OSM_SFT ,LOWER   ,SPACE_FN,ENTER_FN,RAISE   ,NUMFUN  ,XXXXXXX ,DM_PLY1 ,DM_PLY2 ,
        BSE_E01 ,BSE_E02
    ),
    [_LOWER] = LAYOUT_metheon(
        KC_TILD ,KC_EXLM ,KC_AT   ,KC_HASH ,KC_DLR  ,KC_PERC ,KC_CIRC ,KC_AMPR ,KC_ASTR ,KC_LPRN ,KC_RPRN ,KC_DEL  ,
        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_UNDS ,KC_PLUS ,KC_LCBR ,KC_RCBR ,XXXXXXX ,
        _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,
        XXXXXXX ,XXXXXXX ,_______ ,_______ ,_______ ,KC_ENTER,KC_ENTER,_______ ,_______ ,_______ ,XXXXXXX ,XXXXXXX ,
        LWR_E01 ,LWR_E02
    ),
    [_RAISE] = LAYOUT_metheon(
        KC_GRV  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_DEL  ,
        KC_CAPS ,DK_EE   ,DK_AE   ,DK_OE   ,DK_AA   ,DK_EUR  ,DK_PND  ,KC_MINS ,KC_EQL  ,KC_LBRC ,KC_RBRC ,XXXXXXX ,
        _______ ,XXXXXXX ,XXXXXXX ,KC_PIPE ,KC_BSLS ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,_______ ,XXXXXXX ,_______ ,
        XXXXXXX ,XXXXXXX ,_______ ,_______ ,_______ ,KC_SPACE,KC_SPACE,_______ ,_______ ,_______ ,XXXXXXX ,XXXXXXX ,
        RSE_E01 ,RSE_E02
    ),
    [_ADJUST] = LAYOUT_metheon(
        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_VRSN ,KC_MAKE ,KC_FLASH,
        HIBRNT  ,XXXXXXX ,KC_MPRV ,KC_MPLY ,KC_MNXT ,XXXXXXX ,RGB_TOG ,RGB_MOD ,RGB_HUI ,RGB_SAI ,RGB_VAI ,XXXXXXX ,
        SLEEP   ,XXXXXXX ,KC_MUTE ,KC_VOLD ,KC_VOLU ,XXXXXXX ,XXXXXXX ,RGB_RMOD,RGB_HUD ,RGB_SAD ,RGB_VAD ,XXXXXXX ,
        XXXXXXX ,XXXXXXX ,_______ ,_______ ,_______ ,RESET   ,RESET   ,_______ ,_______ ,_______ ,XXXXXXX ,XXXXXXX ,
        ADJ_E01 ,ADJ_E02
    ),
    [_EXTEND] = LAYOUT_metheon(
        SPACES  ,XXXXXXX ,XXXXXXX ,LEFT_SPC,RGHT_SPC,FILES   ,KC_PGUP ,KC_HOME ,KC_UP   ,KC_END  ,XXXXXXX ,DEL_WRD ,
        WIN_MENU,KC_LSFT ,KC_LGUI ,KC_LALT ,KC_LCTRL,DESKTOP ,KC_PGDN ,KC_LEFT ,KC_DOWN ,KC_RGHT ,XXXXXXX ,XXXXXXX ,
        _______ ,UNDO    ,CUT     ,COPY    ,PASTE   ,REDO    ,FILES   ,PASTE_T ,COPY_T  ,XXXXXXX ,XXXXXXX ,_______ ,
        XXXXXXX ,DM_RSTP ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,_______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,DM_REC1 ,DM_REC2 ,
        EXT_E01 ,EXT_E02
    ),
    [_NUMFUN] = LAYOUT_metheon(
        XXXXXXX ,KC_F9   ,KC_F10  ,KC_F11  ,KC_F12  ,XXXXXXX ,KC_LPRN ,KC_7    ,KC_8    ,KC_9    ,KC_RPRN ,KC_BSPC ,
        _______ ,F5_SFT  ,F6_GUI  ,F7_ALT  ,F8_CTL  ,XXXXXXX ,PLUS_CTL,N4_ALT  ,N5_GUI  ,N6_SFT  ,KC_ASTR ,KC_COMMA,
        _______ ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,XXXXXXX ,KC_MINS ,KC_1    ,KC_2    ,KC_3    ,KC_SLSH ,KC_DOT  ,
        XXXXXXX ,XXXXXXX ,_______ ,_______ ,XXXXXXX ,KC_ENTER,KC_ENTER,KC_0    ,KC_0    ,KC_0    ,XXXXXXX ,XXXXXXX ,
        NUM_E01 ,NUM_E02
    )
};
// clang-format on
