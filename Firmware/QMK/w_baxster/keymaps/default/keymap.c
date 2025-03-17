#include QMK_KEYBOARD_H

enum custom_keycodes {
    TMPO_INC = SAFE_RANGE,
    TMPO_DEC,
    FUTURAMA,
    GRID,
    TWELVE,
};

#define _BL 0
#define _FL 1
#define _SL 2
#define _ML 3


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_BL] = LAYOUT( \
		KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_MPLY, \
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL, \
		KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_PGUP, \
		KC_LSFT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_PGDN, \
		KC_LCTL, KC_LGUI, KC_LALT, KC_BSLS, KC_LSFT, KC_BSPC, MO(2), KC_SPC, MO(1), KC_APP, KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RIGHT \
	),

	[_FL] = LAYOUT( \
		KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_NO, \
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_INS, \
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGUI(KC_L), KC_NO, KC_NO, KC_NO, KC_HOME, \
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_APP, KC_NO, KC_NO, KC_NO, KC_NO, LGUI(KC_UP), KC_END, \
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_TRNS, LCTL(LSFT(KC_ESC)), RCTL(RALT(KC_DEL)), LGUI(KC_LEFT), LGUI(KC_DOWN), LGUI(KC_RIGHT) \
	),

	[_SL] = LAYOUT( \
		MO(3), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, MU_TOG, \
		KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_NO, KC_NO, \
		KC_NO, KC_NO, LCTL(KC_S), KC_NO, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_UP, KC_DOWN, KC_RIGHT, KC_NO, KC_NO, KC_NO, \
		LGUI(LSFT(KC_S)), KC_TRNS, LCTL(KC_Z), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, \
		KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_ENT, KC_DEL, KC_NO, KC_TRNS, RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO \
	),

    [_ML] = LAYOUT( \
        KC_TRNS, FUTURAMA, GRID, TWELVE, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, AU_ON, \
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TMPO_INC, AU_OFF, \
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TMPO_DEC, KC_NO \
    )
};

/*
Encoder control
Default:
Enc 0: Volume up / down
Enc 1: Next Song / Previous Song
When on _SL
Enc 0: Disabled
Enc 1: Mouse Wheel up / down
*/
void encoder_update_user(uint8_t index, bool clockwise) {
    if (IS_LAYER_ON(_SL)){
        if (index == 0) {
            //if (clockwise) {
            //    ();
            //} else {
            //    ();
            //}
        } else if (index == 1) {
            if (clockwise) {
                (tap_code(KC_MS_WH_UP));
            } else {
                (tap_code(KC_MS_WH_DOWN));
            }
        }
    } else {
    	if (index == 0) {
            if (clockwise) {
            	tap_code(KC_VOLU);
            } else {
            	tap_code(KC_VOLD);
            }
        } else if (index == 1) {
            if (clockwise) {
                tap_code(KC_MNXT);
            } else {
                tap_code(KC_MPRV);
            }
        }
    }
}

#ifdef AUDIO_ENABLE
float futurama[][2] = SONG(FUTURAMA_THEME);
float grid[][2] = SONG(THE_GRID);
float twelvefiftyone[][2] = SONG(TWELVE_FIFTY_ONE);
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TMPO_INC:
            if (record->event.pressed) {
                #ifdef AUDIO_ENABLE
                    void audio_increase_tempo(uint8_t tempo_change);
                #endif
            }
            break;
        case TMPO_DEC:
            if (record->event.pressed) {
                #ifdef AUDIO_ENABLE
                    void aduio_decrease_tempo(uint8_t tempo_change);
                #endif
            }
            break;
        case FUTURAMA:
            if (record->event.pressed) {
                //when keycode FUTURAMA is pressed
                #ifdef AUDIO_ENABLE
                    PLAY_SONG(futurama);
                #endif
            } else {
                //when keycode FUTURAMA is released
            }
            break;
        case GRID:
            if (record->event.pressed) {
                #ifdef AUDIO_ENABLE
                    PLAY_SONG(grid);
                #endif
            }
            break;
        case TWELVE:
            if (record->event.pressed) {
                #ifdef AUDIO_ENABLE
                    PLAY_SONG(twelvefiftyone);
                #endif
            }
            break;
        }
    return true;
};