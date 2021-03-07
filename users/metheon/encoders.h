#include "metheon.h"

// Encoder tap functions
#define BSE_E01             KC_NO
#define BSE_E02             KC_MUTE

#define LWR_E01             KC_NO
#define LWR_E02             KC_NO

#define RSE_E01             LGUI(KC_W) // close tab
#define RSE_E02             KC_NO

#define EXT_E01             KC_NO
#define EXT_E02             KC_MPLY

#define ADJ_E01             KC_NO
#define ADJ_E02             KC_NO

// Required for cmd-tab function
void matrix_scan_encoders(void);
