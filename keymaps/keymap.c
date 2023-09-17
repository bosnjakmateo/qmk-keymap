#include QMK_KEYBOARD_H

enum layers {
   _BASE = 0,
   _EXT,
   _FNC,
   _SYM,
   _NUM,
   _SPE
};

// Layer aliases
#define EXT MO(_EXT)
#define FNC MO(_FNC)
#define SYM MO(_SYM)
#define NUM MO(_NUM)
#define SPE MO(_SPE)

// Mod key Aliases
#define EXT_TAB LT(EXT, KC_TAB)
#define SYM_ENT LT(SYM, KC_ENT)
#define FNC_SPC LT(FNC, KC_SPC)
#define NUM_BSP LT(NUM, KC_BSPC)

// Other Aliases
#define UNDO LGUI(KC_Z)
#define CUT LGUI(KC_X)
#define COPY LGUI(KC_C)
#define PASTE LGUI(KC_V)
#define GUI_TAB LGUI(KC_TAB)
#define HYP_GRV HYPR(KC_GRV)

// Hypers
#define HYP_1 HYPR(KC_1)
#define HYP_2 HYPR(KC_2)
#define HYP_3 HYPR(KC_3)
#define HYP_4 HYPR(KC_4)
#define HYP_5 HYPR(KC_5)

// Left-hand home row mods
#define CTL_A LCTL_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define GUI_D LGUI_T(KC_D)
#define SFT_F LSFT_T(KC_F)

// Right-hand home row mods
#define SFT_J RSFT_T(KC_J)
#define GUI_K RGUI_T(KC_K)
#define ALT_L LALT_T(KC_L)
#define CTL_SCLN RCTL_T(KC_SCLN)

// Combos
const uint16_t PROGMEM spe_combo[] = {LT(EXT, KC_SPC), LT(FNC, KC_TAB), COMBO_END};

combo_t key_combos[] = {
  COMBO(spe_combo, SPE),
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
    case CHROME:
        if (record->event.pressed) {
            openApplication("chr");
        }
        break;
    case IDEA:
        if (record->event.pressed) {
            openApplication("idea");
        }
        break;
    case SLACK:
        if (record->event.pressed) {
            openApplication("slack");
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [_BASE] = LAYOUT(
         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Z,    KC_U,    KC_I,    KC_O,    KC_P,
        CTL_A,   ALT_S,   GUI_D,   SFT_F,    KC_G,       KC_H,   SFT_J,   GUI_K,   ALT_L, CTL_SCLN,
         KC_Y,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_QUES,
                  LT(FNC, KC_TAB), LT(EXT, KC_SPC),      LT(SYM, KC_BSPC), LT(NUM, KC_ENT)
   ),
   [_EXT] = LAYOUT(
       KC_ESC, KC_PAUS,  KC_INS, GUI_TAB, HYP_GRV,    KC_PGUP, KC_HOME,   KC_UP,  KC_END, CW_TOGG,
      _______, _______, _______, _______, _______,    KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL,
         UNDO,     CUT,    COPY, KC_LGUI,   PASTE,     KC_ENT, KC_BSPC,  KC_TAB, _______, KC_PSCR,
                                 _______, _______,    _______, _______
   ),
   [_FNC] = LAYOUT(
      _______, KC_MRWD, KC_MPLY, KC_MFFD, _______,     KC_F12,   KC_F7,   KC_F8,   KC_F9, _______,
      _______, _______, _______, _______, _______,     KC_F11,   KC_F4,   KC_F5,   KC_F6, _______,
      _______, KC_VOLD, _______, KC_VOLU, _______,     KC_F10,   KC_F1,   KC_F2,   KC_F3, _______,
                                 _______, _______,    _______, _______
   ),
   [_SYM] = LAYOUT(
      KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,    KC_PEQL, KC_QUOT, KC_COLN, KC_SCLN, KC_PLUS,
      _______, _______, _______, _______, _______,    KC_ASTR, KC_LPRN, KC_LCBR, KC_LBRC, KC_MINS,
      _______, _______, KC_BSLS, KC_PIPE, KC_AMPR,    KC_PSLS, KC_RPRN, KC_RCBR, KC_RBRC, KC_UNDS,
                                 _______, _______,    _______, _______
   ),
   [_NUM] = LAYOUT(
      _______, _______, _______, _______, _______,    KC_PEQL,    KC_7,    KC_8,    KC_9, KC_PPLS,
      _______, _______, _______, _______, _______,    KC_PAST,    KC_4,    KC_5,    KC_6, KC_PMNS,
      _______, _______,  KC_TAB, KC_BSPC,  KC_ENT,       KC_0,    KC_1,    KC_2,    KC_3, KC_PSLS,
                                 _______, _______,    _______, _______
   ),
   [_SPE] = LAYOUT(
      _______, _______, _______, _______, _______,      HYP_1,   HYP_2,   HYP_3,   HYP_4,   HYP_5,
      _______, _______, _______, _______, _______,    _______,    IDEA,  CHROME,   SLACK, _______,
      _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,
                                 _______, _______,    _______, _______
   ),
};
