#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)

enum custom_keycodes {
  RGB_SLD = SAFE_RANGE, // can always be here
  EPRM,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox(KC_GRAVE,KC_1,KC_2,KC_3,KC_4,KC_5,KC_TRANSPARENT,KC_TAB,KC_SLASH,KC_COMMA,KC_DOT,KC_F,KC_Q,KC_LPRN,LCTL_T(KC_NO),KC_A,KC_O,KC_E,KC_I,KC_U,KC_LSHIFT,KC_Z,KC_X,KC_C,KC_V,KC_W,KC_LBRACKET,MO(1),KC_TRANSPARENT,KC_EQUAL,KC_QUOTE,KC_BSLASH,KC_LGUI,KC_LALT,KC_LCTRL,KC_SPACE,KC_ESCAPE,KC_TRANSPARENT,KC_TRANSPARENT,KC_6,KC_7,KC_8,KC_9,KC_0,KC_QUOTE,KC_RPRN,KC_M,KC_R,KC_D,KC_Y,KC_P,KC_MINUS,KC_G,KC_T,KC_K,KC_S,KC_N,RCTL_T(KC_NO),KC_RBRACKET,KC_B,KC_H,KC_J,KC_L,KC_SCOLON,KC_RSHIFT,KC_LANG1,KC_LANG2,KC_TRANSPARENT,KC_TRANSPARENT,MO(1),LALT(KC_NO),KC_RGUI,KC_TRANSPARENT,KC_TRANSPARENT,KC_BSPACE,KC_ENTER),

  [1] = LAYOUT_ergodox(KC_TRANSPARENT,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_TRANSPARENT,KC_TRANSPARENT,KC_F11,KC_F12,KC_F13,KC_F14,KC_F15,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_UP,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT,KC_WWW_BACK,KC_WWW_FORWARD,KC_TRANSPARENT,KC_TRANSPARENT,KC_LGUI,KC_TAB,KC_MS_BTN2,KC_MS_BTN1,KC_TRANSPARENT,RESET,KC_TRANSPARENT,KC_SPACE,KC_ESCAPE,LGUI(LSFT(KC_I)),KC_TRANSPARENT,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,KC_TRANSPARENT,KC_TRANSPARENT,KC_F16,KC_F17,KC_F18,KC_F19,KC_F20,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_UP,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_LEFT,KC_DOWN,KC_RIGHT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_BSPACE,KC_ENTER),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    case 1:
      ergodox_right_led_1_on();
      break;
    case 2:
      ergodox_right_led_2_on();
      break;
    case 3:
      ergodox_right_led_3_on();
      break;
    case 4:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      break;
    case 5:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      break;
    case 6:
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    case 7:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    default:
      break;
  }
  return state;
};
