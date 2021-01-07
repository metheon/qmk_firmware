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
    //  .--------------------------------------------.                    .--------------------------------------------.
         KC_Q    ,KC_W    ,KC_F    ,KC_P    ,KC_G                         ,KC_J    ,KC_L    ,KC_U    ,KC_Y    ,KC_SCLN ,
    //  |--------------------------------------------|                    |--------------------------------------------|
         HOME_A  ,HOME_R  ,HOME_S ,HOME_T   ,KC_D                         ,KC_H    ,HOME_N  ,HOME_E  ,HOME_I  ,HOME_O  ,
    //  |--------------------------------------------|                    |--------------------------------------------|
         KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B                         ,KC_K    ,KC_M    ,KC_COMMA,KC_DOT  ,KC_SLSH ,
    //  '-------------------------+--------+---------+--------+  +--------+--------+--------+--------------------------'
                                   TAB_LWR ,SPC_EXT  ,ENT_RSE    ,DEL_RSE ,BSPC_EXT,ESC_LWR ,
    //                            '--------+---------+--------+  +--------+--------+--------'
    //  Encoders
    //  .--------+-------.
         BSE_E01 ,BSE_E02
    //  '--------+-------'
    ),
    [_LOWER] = LAYOUT_metheon(
    //  .--------------------------------------------.                    .--------------------------------------------.
         __NONE__,KC_9    ,KC_F8   ,KC_7    ,KC_F12                       ,KC_ASTR ,KC_7    ,KC_8    ,KC_9    ,KC_SLSH ,
    //  |--------------------------------------------|                    |--------------------------------------------|
         HOME_LP ,HOME_F6 ,HOME_F5,HOME_F4  ,KC_F11                       ,KC_PLUS ,HOME_4  ,HOME_5  ,HOME_6  ,HOME_MN ,
    //  |--------------------------------------------|                    |--------------------------------------------|
         KC_RPRN ,KC_F3   ,KC_F2   ,KC_F1   ,KC_F10                       ,KC_0    ,KC_1    ,KC_2    ,KC_3    ,KC_EQL  ,
    //  '-------------------------+--------+---------+--------+  +--------+--------+--------+--------------------------'
                                   _______ ,_______ ,_______     ,_______ ,_______ ,_______ ,
    //                            '--------+---------+--------+  +--------+--------+--------'
    //  Encoders
    //  .--------+-------.
         LWR_E01 ,LWR_E02
    //  '--------+-------'
    ),
    [_RAISE] = LAYOUT_metheon(
    //  .--------------------------------------------.                    .--------------------------------------------.
         KC_CIRC ,KC_AT   ,KC_HASH ,KC_DLR  ,KC_LCBR                      ,KC_RCBR ,DK_EUR  ,DK_PND  ,__NONE__,KC_BSLS ,
    //  |--------------------------------------------|                    |--------------------------------------------|
         DK_EE   ,DK_AE   ,DK_OE   ,DK_AA   ,KC_LPRN                      ,KC_RPRN ,KC_EQL  ,KC_EXLM ,KC_AMPR ,KC_PIPE ,
    //  |--------------------------------------------|                    |--------------------------------------------|
         KC_PERC ,KC_MINS ,KC_GRV  ,KC_QUOT ,KC_LBRC                      ,KC_RBRC ,KC_DQT  ,KC_TILD ,KC_UNDS ,KC_SLSH ,
    //  '-------------------------+--------+---------+--------+  +--------+--------+--------+--------------------------'
                                   _______ ,_______ ,_______     ,_______ ,_______ ,_______ ,
    //                            '--------+---------+--------+  +--------+--------+--------'
    //  Encoders
    //  .--------+-------.
         RSE_E01 ,RSE_E02
    //  '--------+-------'
    ),
    [_ADJUST] = LAYOUT_metheon(
    //  .--------------------------------------------.                    .--------------------------------------------.
         __NONE__,__NONE__,__NONE__,__NONE__,__NONE__                     ,__NONE__,KC_FLASH,KC_MAKE ,KC_VRSN ,__NONE__,
    //  |--------------------------------------------|                    |--------------------------------------------|
         KC_CAPS ,KC_MPRV ,KC_MPLY ,KC_MNXT ,__NONE__                     ,RGB_TOG ,RGB_MOD ,RGB_HUI ,RGB_SAI ,RGB_VAI ,
    //  |--------------------------------------------|                    |--------------------------------------------|
         __NONE__,KC_MUTE ,KC_VOLD ,KC_VOLU ,__NONE__                     ,__NONE__,RGB_RMOD,RGB_HUD ,RGB_SAD ,RGB_VAD ,
    //  '-------------------------+--------+---------+--------+  +--------+--------+--------+--------------------------'
                                   _______ ,RESET    ,_______    ,_______ ,RESET   ,_______ ,
    //                            '--------+---------+--------+  +--------+--------+--------'
    //  Encoders
    //  .--------+-------.
         ADJ_E01 ,ADJ_E02
    //  '--------+-------'
    ),
    [_EXTEND] = LAYOUT_metheon(
    //  .--------------------------------------------.                    .--------------------------------------------.
         __NONE__,__NONE__,__NONE__,__NONE__,__NONE__                     ,KC_PGUP ,KC_HOME ,KC_UP   ,KC_END  ,__NONE__,
    //  |--------------------------------------------|                    |--------------------------------------------|
         KC_LGUI ,KC_LALT ,KC_LSFT ,KC_LCTRL,KC_LEAD                      ,KC_PGDN ,KC_LEFT ,KC_DOWN ,KC_RGHT ,__NONE__,
    //  |--------------------------------------------|                    |--------------------------------------------|
         UNDO    ,CUT     ,COPY    ,REDO    ,PASTE                        ,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__,
    //  '-------------------------+--------+---------+--------+  +--------+--------+--------+--------------------------'
                                   _______ ,_______  ,_______    ,_______ ,_______ ,_______ ,
    //                            '--------+---------+--------+  +--------+--------+--------'
    //  Encoders
    //  .--------+-------.
         EXT_E01 ,EXT_E02
    //  '--------+-------'
    )
};
// clang-format on
