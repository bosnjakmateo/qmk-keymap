#include QMK_KEYBOARD_H
#include "oled.c"

enum layers {
   _BASE = 0,
   _EXT,
   _FNC,
   _SYM,
   _NUM,
   _SPE,
   _MUS
};

// Layer aliases
#define EXT MO(_EXT)
#define FNC MO(_FNC)
#define SYM MO(_SYM)
#define NUM MO(_NUM)
#define SPE MO(_SPE)
#define MUS MO(_MUS)

// Mod key Aliases
#define THUMB_1 LSFT_T(KC_TAB)
#define THUMB_2 LT(EXT, KC_SPC)
#define THUMB_3 LT(SYM, KC_ENT)
#define THUMB_4 LT(NUM, KC_BSPC)

// Other Aliases
#define UNDO LGUI(KC_Z)
#define CUT LGUI(KC_X)
#define COPY LGUI(KC_C)
#define PASTE LGUI(KC_V)
#define GUI_TAB LGUI(KC_TAB)

// Hypers
#define HYP_0 HYPR(KC_0)
#define HYP_1 HYPR(KC_1)
#define HYP_2 HYPR(KC_2)
#define HYP_3 HYPR(KC_3)
#define HYP_4 HYPR(KC_4)
#define HYP_5 HYPR(KC_5)

// Left-hand home row mods
#define SFT_A LSFT_T(KC_A)
#define CTL_S LCTL_T(KC_S)
#define ALT_D LALT_T(KC_D)
#define GUI_F LGUI_T(KC_F)

// Right-hand home row mods
#define GUI_J RGUI_T(KC_J)
#define ALT_K LALT_T(KC_K)
#define CTL_L RCTL_T(KC_L)
#define SFT_SCLN RSFT_T(KC_SCLN)

// Combos
const uint16_t PROGMEM spe_combo[] = {THUMB_1, THUMB_2, COMBO_END};
const uint16_t PROGMEM mus_combo[] = {THUMB_3, THUMB_4, COMBO_END};

combo_t key_combos[] = {
  COMBO(spe_combo, SPE),
  COMBO(mus_combo, MUS),
};

enum custom_keycodes {
    CHROME = SAFE_RANGE,
    IDEA,
    SLACK,
};

void openApplication(char* applicationName) {
    SEND_STRING(SS_DELAY(100));
    SEND_STRING(SS_DOWN(X_LGUI));
    SEND_STRING(SS_TAP(X_SPC));
    SEND_STRING(SS_UP(X_LGUI));
    SEND_STRING(SS_DELAY(50));
    SEND_STRING(applicationName);
    SEND_STRING(SS_DELAY(50));
    SEND_STRING(SS_TAP(X_ENT));
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case HYPR(KC_U):
        if (record->event.pressed) {
            openApplication("chr");
        }
        break;
    case HYPR(KC_I):
        if (record->event.pressed) {
            openApplication("idea");
        }
        break;
    case HYPR(KC_O):
        if (record->event.pressed) {
            openApplication("slack");
        }
        break;
    case LSFT_T(KC_AMPR):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_AMPR); // Send KC_DQUO on tap
                return false;        // Return false to ignore further processing of key
            }
            break;
    case LCTL_T(KC_UNDS):
        if (record->tap.count && record->event.pressed) {
            tap_code16(KC_UNDS); // Send KC_DQUO on tap
            return false;        // Return false to ignore further processing of key
        }
        break;
    case LALT_T(KC_DQUO):
        if (record->tap.count && record->event.pressed) {
            tap_code16(KC_DQUO); // Send KC_DQUO on tap
            return false;        // Return false to ignore further processing of key
        }
        break;
    case LGUI_T(KC_QUOT):
        if (record->tap.count && record->event.pressed) {
            tap_code16(KC_QUOT); // Send KC_DQUO on tap
            return false;        // Return false to ignore further processing of key
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [_BASE] = LAYOUT(
         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Z,    KC_U,    KC_I,    KC_O,    KC_P,
        SFT_A,   CTL_S,   ALT_D,   GUI_F,    KC_G,       KC_H,   GUI_J,   ALT_K,   CTL_L, SFT_SCLN,
         KC_Y,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_HYPR,
                                 THUMB_1, THUMB_2,    THUMB_3, THUMB_4
   ),
   [_EXT] = LAYOUT(
       KC_ESC, KC_MRWD,  KC_MPLY, KC_MFFD,   HYP_0,    KC_PGUP, KC_PGDN, KC_HOME,  KC_END, CW_TOGG,
      _______, KC_VOLD, _______, KC_VOLU, _______,    KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,  KC_DEL,
         UNDO,     CUT,    COPY,   PASTE, _______,    _______, _______, _______, _______, KC_PSCR,
                                 _______, _______,    _______, _______
   ),
   [_NUM] = LAYOUT(
      KC_F12,   KC_F7,   KC_F8,   KC_F9, _______,     _______, KC_7, KC_8, KC_9, _______,
      KC_F11,   KC_F4,   KC_F5,   KC_F6, _______,     _______, KC_4, KC_5, KC_6, KC_COMM,
      KC_F10,   KC_F1,   KC_F2,   KC_F3, _______,      KC_0, KC_1, KC_2, KC_3,    KC_DOT,
                                 _______, KC_LGUI,    _______, _______
   ),
   [_SYM] = LAYOUT(
      KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_LBRC,    KC_RBRC, KC_PLUS, KC_ASTR, KC_SLSH, KC_PERC,
      LSFT_T(KC_AMPR), LCTL_T(KC_UNDS), LALT_T(KC_DQUO), LGUI_T(KC_QUOT), KC_LPRN,    KC_RPRN, KC_MINS, KC_LABK, KC_RABK, KC_SCLN,
      KC_PIPE, KC_TILD, KC_CIRC,  KC_GRV, KC_LCBR,    KC_RCBR,  KC_EQL, KC_COMM,  KC_DOT, KC_BSLS,
                                 _______, _______,    _______, _______
   ),
   [_SPE] = LAYOUT(
      _______, _______, _______, _______, _______,      HYP_1,   HYP_2,   HYP_3,   HYP_4,   HYP_5,
      _______, _______, _______, _______, _______,    _______,    IDEA,  CHROME,   SLACK, _______,
      _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,
                                 _______, _______,    _______, _______
   ),
};