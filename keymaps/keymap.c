#include QMK_KEYBOARD_H

enum layers {
   _BASE = 0,
   _EXT,
   _FNC,
   _SYM,
   _NUM,
};

// Layer aliases
#define EXT MO(_EXT)
#define FNC MO(_FNC)
#define SYM MO(_SYM)
#define NUM MO(_NUM)

// Mod key Aliases
#define SFT_SPC LSFT(KC_SPC)

// Oneshot Aliases
#define OS_SFT OSM(MOD_LSFT)
#define OS_CTL OSM(MOD_LCTL)
#define OS_ALT OSM(MOD_LALT)
#define OS_GUI OSM(MOD_LGUI)
#define OS_RALT OSM(MOD_RALT)

// Other Aliases
#define UNDO LGUI(KC_Z)
#define CUT LGUI(KC_X)
#define COPY LGUI(KC_C)
#define PASTE LGUI(KC_V)
#define GUI_TAB LGUI(KC_TAB)
#define GUI_GRV LGUI(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [_BASE] = LAYOUT(
         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Z,    KC_U,    KC_I,    KC_O,    KC_P,
         KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, XXXXXXX,
         KC_Y,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, XXXXXXX,
                                     EXT, SFT_SPC,     KC_ENT,     SYM
   ),
   [_EXT] = LAYOUT(
       KC_ESC, KC_PAUS,  KC_INS, GUI_TAB, GUI_GRV,    KC_PGUP, KC_HOME,   KC_UP,  KC_END, KC_CAPS,
       OS_SFT,  OS_CTL,  OS_ALT,  OS_GUI, OS_RALT,    KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL,
         UNDO,     CUT,    COPY, KC_LGUI,   PASTE,     KC_ENT, KC_BSPC,  KC_TAB, XXXXXXX, KC_PSCR,
                                 XXXXXXX, XXXXXXX,     KC_ENT,     FNC
   ),
   [_FNC] = LAYOUT(
      XXXXXXX, KC_MRWD, KC_MPLY, KC_MFFD, XXXXXXX,     KC_F12,   KC_F7,   KC_F8,   KC_F9, XXXXXXX,
      _______, _______, _______, _______, XXXXXXX,     KC_F11,   KC_F4,   KC_F5,   KC_F6, XXXXXXX,
      XXXXXXX, KC_VOLD, XXXXXXX, KC_VOLU, XXXXXXX,     KC_F10,   KC_F1,   KC_F2,   KC_F3, XXXXXXX,
                                 XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX
   ),
   [_SYM] = LAYOUT(
      KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,    KC_PEQL, KC_QUOT, KC_COLN, KC_SCLN, KC_PLUS,
      _______, _______, _______, _______, KC_RALT,    KC_ASTR, KC_LPRN, KC_LCBR, KC_LBRC, KC_MINS,
      XXXXXXX, XXXXXXX, KC_BSLS, KC_PIPE, KC_AMPR,    KC_PSLS, KC_RPRN, KC_RCBR, KC_RBRC, KC_UNDS,
                                     FNC,     NUM,    XXXXXXX, XXXXXXX
   ),
   [_NUM] = LAYOUT(
      _______, _______, _______, _______, _______,    KC_PEQL,   KC_P7,   KC_P8,   KC_P9, KC_PPLS,
      _______, _______, _______, _______, _______,    KC_PAST,   KC_P4,   KC_P5,   KC_P6, KC_PMNS,
      _______, _______,  KC_TAB, KC_BSPC,  KC_ENT,      KC_P0,   KC_P1,   KC_P2,   KC_P3, KC_PSLS,
                                 XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX
   ),
};
