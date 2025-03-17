pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x6768
#define PRODUCT_ID      0x9002
#define DEVICE_VER      0x0001
#define MANUFACTURER    Condog9000
#define PRODUCT         W_Baxster
#define DESCRIPTION     Handwired 65% keyboard

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 15

/* key matrix pins */
#define MATRIX_ROW_PINS { B7, B6, B5, B4, B3 }
#define MATRIX_COL_PINS { B2, B1, B0, A6, A7, A8, A15, A13, A14, B12, B9, A0, B14, B13, B8 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* number of backlight levels */
//#define BACKLIGHT_PIN A3
//#define BACKLIGHT_PWM_DRIVER PWMD2
//#define BACKLIGHT_PWM_CHANNEL 4
//#define BACKLIGHT_PAL_MODE 1
//#define BACKLIGHT_LEVELS 30
//#define BACKLIGHT_BREATHING
//#define BREATHING_PERIOD 8

/*Lock LED Pins*/
//#define LED_NUM_LOCK_PIN	
#define LED_CAPS_LOCK_PIN A3
//#define LED_SCROLL_LOCK_PIN
//#define LED_PIN_ON_STATE 1

/* Rotary Encoder Things */
// #define ENCODER DIRECTION_FLIP
#define ENCODERS_PAD_A { A9, A2 }
#define ENCODERS_PAD_B { A10, A1 }
//#define ENCODER_RESOLUTION 4
//#define ENCODER_RESOLUTIONS { 4, 4 }

/* Taps (encoder tap_code) */
#define TAP_CODE_DELAY 10

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 3

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
//#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
//#define LOCKING_RESYNC_ENABLE

/* prevent stuck modifiers */
//#define PREVENT_STUCK_MODIFIER`

/* Audio */
#ifdef AUDIO_ENABLE
	#define AUDIO_PIN A5
	//#define Audio_PIN_ALT A4
	//#define AUDIO_PIN_ALT_AS_Negative
	#define AUDIO_DAC_SAMPLE_WAVEFORM_SINE
    //#define STARTUP_SONG SONG(THE_GRID)
	//#define AUDIO_DAC_SAMPLE_MAX 1024U  
	//#define AUDIO_ENABLE_TONE_MULTIPLEXING
	//#define AUDIO_TONE_MULTIPLEXING_RATE_DEFAULT 10
	//#define AUDIO_CLICKY
#endif