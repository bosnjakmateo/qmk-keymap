#include QMK_KEYBOARD_H

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
const uint16_t PROGMEM spe_combo[] = {LT(EXT, KC_SPC), LT(FNC, KC_TAB), COMBO_END};
const uint16_t PROGMEM mus_combo[] = {LT(SYM, KC_ENT), LT(NUM, KC_BSPC), COMBO_END};

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
        SFT_A,   CTL_S,   ALT_D,   GUI_F,    KC_G,       KC_H,   GUI_J,   ALT_K,   CTL_L, SFT_SCLN,
         KC_Y,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_QUES,
                  LT(FNC, KC_TAB), LT(EXT, KC_SPC),      LT(SYM, KC_ENT),LT(NUM, KC_BSPC)
   ),
   [_EXT] = LAYOUT(
       KC_ESC, KC_PAUS,  KC_INS, GUI_TAB,   HYP_0,    KC_PGUP, KC_HOME,   KC_UP,  KC_END, CW_TOGG,
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
      KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_LBRC,    KC_RBRC, KC_PLUS, KC_ASTR, KC_SLSH, KC_PERC,
      LSFT_T(KC_AMPR), LCTL_T(KC_UNDS), LALT_T(KC_DQUO), LGUI_T(KC_QUOT), KC_LPRN,             KC_RPRN, KC_MINS, KC_LABK, KC_RABK, KC_SCLN,
      KC_PIPE, KC_TILD, KC_CIRC,  KC_GRV, KC_LCBR,    KC_RCBR,  KC_EQL, KC_COMM,  KC_DOT, KC_BSLS,
                                 _______, _______,    _______, _______
   ),
   [_NUM] = LAYOUT(
      _______, _______, _______, KC_PAST, KC_PPLS,    _______,    KC_7,    KC_8,    KC_9, _______,
      _______, _______, _______, LGUI_T(KC_PSLS), KC_PMNS,    _______,    KC_4,    KC_5,    KC_6, _______,
      _______, _______, KC_PEQL, KC_COMM,  KC_DOT,       KC_0,    KC_1,    KC_2,    KC_3, _______,
                                 _______, _______,    _______, _______
   ),
   [_SPE] = LAYOUT(
      _______, _______, _______, _______, _______,      HYP_1,   HYP_2,   HYP_3,   HYP_4,   HYP_5,
      _______, _______, _______, _______, _______,    _______,    IDEA,  CHROME,   SLACK, _______,
      _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,
                                 _______, _______,    _______, _______
   ),
   [_MUS] = LAYOUT(
      _______, _______, _______, _______, _______,    KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, _______,
      _______, KC_BTN1, KC_BTN3, KC_BTN2, _______,    KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, _______,
      _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,
                                 _______, _______,    _______, _______
   ),
};
