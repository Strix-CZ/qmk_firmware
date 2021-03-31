#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"


#include "keymap_german.h"

#include "keymap_nordic.h"



enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
  cz_r_hacek,
  cz_i_carka,
  cz_s_hacek,
  cz_z_hacek,
  cz_t_hacek,
  cz_c_hacek,
  cz_y_carka,
  cz_u_krouzek,
  cz_n_hacek,
  cz_u_carka,
  cz_e_hacek,
  cz_d_hacek,
  cz_a_carka,
  cz_e_carka,
  cz_o_carka,
};

// příliš žluťoučký kůň úpěl ďábelské ódy
#define cz_lower_r_hacek   0x000159
#define cz_lower_i_carka   0x0000ED
#define cz_lower_s_hacek   0x000161
#define cz_lower_z_hacek   0x00017E
#define cz_lower_t_hacek   0x000165
#define cz_lower_c_hacek   0x00010D
#define cz_lower_y_carka   0x0000FD
#define cz_lower_u_krouzek 0x00016F
#define cz_lower_n_hacek   0x000148
#define cz_lower_u_carka   0x0000FA
#define cz_lower_e_hacek   0x00011B
#define cz_lower_d_hacek   0x00010F
#define cz_lower_a_carka   0x0000E1
#define cz_lower_e_carka   0x0000E9
#define cz_lower_o_carka   0x0000F3

#define cz_upper_i_carka   0x0000CD
#define cz_upper_y_carka   0x0000DD
#define cz_upper_u_carka   0x0000DA
#define cz_upper_a_carka   0x0000C1
#define cz_upper_e_carka   0x0000C9
#define cz_upper_o_carka   0x0000D3

#define layer_base 0
#define layer_cz 1
#define layer_f 2
#define layer_arrows 3
#define layer_mouse 4

volatile bool capsLockStatus = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [layer_base] = LAYOUT_ergodox(KC_ESCAPE,KC_1,KC_2,KC_3,KC_4,KC_5,KC_GRAVE,KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,KC_TRANSPARENT,TT(layer_arrows),SFT_T(KC_A),CTL_T(KC_S),ALT_T(KC_D),GUI_T(KC_F),KC_G,KC_TRANSPARENT,KC_Z,KC_X,KC_C,KC_V,KC_B,KC_ENTER,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_HOME,KC_END,KC_TRANSPARENT,KC_PSCREEN,KC_INSERT,KC_SPACE,KC_BSPACE,KC_DELETE,KC_6,KC_7,KC_8,KC_9,KC_0,KC_MINUS,KC_EQUAL,KC_TRANSPARENT,KC_Y,KC_U,KC_I,KC_O,KC_P,KC_BSLASH,KC_H,GUI_T(KC_J),ALGR_T(KC_K),RCTL_T(KC_L),RSFT_T(KC_SCOLON),KC_ENTER,LSFT(KC_LALT),KC_N,KC_M,KC_COMMA,KC_DOT,LT(layer_mouse,KC_SLASH),KC_TRANSPARENT,KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT,KC_TRANSPARENT,KC_APPLICATION,KC_TRANSPARENT,KC_TRANSPARENT,KC_CAPSLOCK,TT(layer_cz),TT(layer_f)),

  // ceska vrstva
  [layer_cz] =  LAYOUT_ergodox(

    KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
    KC_TRANSPARENT,cz_a_carka,cz_e_hacek,cz_e_carka,cz_r_hacek,cz_t_hacek,KC_TRANSPARENT,
    KC_TRANSPARENT,KC_RSHIFT,cz_s_hacek,cz_d_hacek,KC_TRANSPARENT,KC_TRANSPARENT,
    KC_TRANSPARENT,cz_z_hacek,KC_TRANSPARENT,cz_c_hacek,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
    KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,

    KC_TRANSPARENT,KC_TRANSPARENT,
    KC_TRANSPARENT,
    KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,


    KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
    KC_TRANSPARENT,cz_y_carka,cz_u_carka,cz_i_carka,cz_o_carka,KC_TRANSPARENT,KC_TRANSPARENT,
    KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_RSHIFT,KC_TRANSPARENT,
    KC_TRANSPARENT,cz_n_hacek,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,cz_u_krouzek,KC_TRANSPARENT,
    KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,

    KC_TRANSPARENT,KC_TRANSPARENT,
    KC_TRANSPARENT,
    KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),

  [layer_f] = LAYOUT_ergodox(KC_TRANSPARENT,KC_EXLM,KC_AT,KC_HASH,KC_DLR,KC_PERC,KC_GRAVE,KC_TRANSPARENT,KC_TRANSPARENT,KC_LPRN,KC_RPRN,KC_QUOTE,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_LCBR,KC_RCBR,KC_DQUO,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_LBRACKET,KC_RBRACKET,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_F1,KC_F2,KC_F3,KC_F4,KC_TRANSPARENT,KC_TRANSPARENT,KC_F5,KC_F6,KC_F7,KC_F8,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_F9,KC_F10,KC_F11,KC_F12,KC_TRANSPARENT,KC_HOME,KC_PGDOWN,KC_PGUP,KC_END,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,TO(layer_base)),

  [layer_arrows] = LAYOUT_ergodox(KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,TO(layer_base),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_PGDOWN,KC_PGUP,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_HOME,KC_PGDOWN,KC_PGUP,KC_END,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),

  [layer_mouse] = LAYOUT_ergodox(KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_UP,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_BTN1,KC_MS_BTN2,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_ACCEL2,KC_MS_ACCEL1,KC_MS_ACCEL0,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),

};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};

void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
  set_unicode_input_mode(UC_WINC);
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // Check for shift letter
  bool isShiftOn = ((keyboard_report->mods & MOD_BIT(KC_LSFT)) || (keyboard_report->mods & MOD_BIT(KC_RSFT))) ? true : false;
  bool isUpperCase = isShiftOn != capsLockStatus;
  int upperCaseOffset = isUpperCase ? -1 : 0;

  switch (keycode) {
     case EPRM:
      if (record->event.pressed) { eeconfig_init(); }
      return false; break;

    case VRSN:
      if (record->event.pressed) { SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION); }
      return false; break;

    #ifdef RGBLIGHT_ENABLE
    case RGB_SLD:
      if (record->event.pressed) { rgblight_mode(1); }
      return false; break;
    #endif

    // Czech characters
    case cz_r_hacek:
      if (record->event.pressed) {
        unicode_input_start(); register_hex(cz_lower_r_hacek + upperCaseOffset); unicode_input_finish();
      } return false; break;

    case cz_i_carka:
      if (record->event.pressed) {
        unicode_input_start(); register_hex(isUpperCase ? cz_upper_i_carka : cz_lower_i_carka); unicode_input_finish();
      } return false; break;

    case cz_s_hacek:
      if (record->event.pressed) {
        unicode_input_start(); register_hex(cz_lower_s_hacek + upperCaseOffset); unicode_input_finish();
      } return false; break;

    case cz_z_hacek:
      if (record->event.pressed) {
        unicode_input_start(); register_hex(cz_lower_z_hacek + upperCaseOffset); unicode_input_finish();
      } return false; break;

    case cz_t_hacek:
      if (record->event.pressed) {
        unicode_input_start(); register_hex(cz_lower_t_hacek + upperCaseOffset); unicode_input_finish();
      } return false; break;

    case cz_c_hacek:
      if (record->event.pressed) {
        unicode_input_start(); register_hex(cz_lower_c_hacek + upperCaseOffset); unicode_input_finish();
      } return false; break;

    case cz_y_carka:
      if (record->event.pressed) {
        unicode_input_start(); register_hex(isUpperCase ? cz_upper_y_carka : cz_lower_y_carka); unicode_input_finish();
      } return false; break;

    case cz_u_krouzek:
      if (record->event.pressed) {
        unicode_input_start(); register_hex(cz_lower_u_krouzek + upperCaseOffset); unicode_input_finish();
      } return false; break;

    case cz_n_hacek:
      if (record->event.pressed) {
        unicode_input_start(); register_hex(cz_lower_n_hacek + upperCaseOffset); unicode_input_finish();
      } return false; break;

    case cz_u_carka:
      if (record->event.pressed) {
        unicode_input_start(); register_hex(isUpperCase ? cz_upper_u_carka : cz_lower_u_carka); unicode_input_finish();
      } return false; break;

    case cz_e_hacek:
      if (record->event.pressed) {
        unicode_input_start(); register_hex(cz_lower_e_hacek + upperCaseOffset); unicode_input_finish();
      } return false; break;

    case cz_d_hacek:
      if (record->event.pressed) {
        unicode_input_start(); register_hex(cz_lower_d_hacek + upperCaseOffset); unicode_input_finish();
      } return false; break;

    case cz_a_carka:
      if (record->event.pressed) {
        unicode_input_start(); register_hex(isUpperCase ? cz_upper_a_carka : cz_lower_a_carka); unicode_input_finish();
      } return false; break;

    case cz_e_carka:
      if (record->event.pressed) {
        unicode_input_start(); register_hex(isUpperCase ? cz_upper_e_carka : cz_lower_e_carka); unicode_input_finish();
      } return false; break;

    case cz_o_carka:
      if (record->event.pressed) {
        unicode_input_start(); register_hex(isUpperCase ? cz_upper_o_carka : cz_lower_o_carka); unicode_input_finish();
      } return false; break;
  }
  return true;
}


void led_set_user(uint8_t usb_led) {
  if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
    capsLockStatus = true;
    ergodox_right_led_3_on();
  }
  else {
    capsLockStatus = false;
    ergodox_right_led_3_off();
  }
}


uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    switch (layer) {
      case 0: case 1:
        break;
      case 2:
        ergodox_right_led_1_on();
        break;
      case 3:
        ergodox_right_led_2_on();
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        break;
      default:
        break;
    }
    return state;

};
