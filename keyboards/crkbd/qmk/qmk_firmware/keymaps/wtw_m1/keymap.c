#include QMK_KEYBOARD_H

#include "combo.h"
#include "sm_td.h"

enum layers {
    L_BASE = 0,
    L_NAV,
    L_MOUSE,
    L_BTN,
    L_NUM,
    L_FUN,
};

// Mod-Tap with smtd from https://github.com/stasmarkin/sm_td
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_smtd(keycode, record)) {
        return false;
    }
    return true;
}

smtd_resolution on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
    switch (keycode) {
        SMTD_MT(KC_A, KC_LEFT_GUI)
        SMTD_MT(KC_S, KC_LEFT_ALT)
        SMTD_MT(KC_D, KC_LEFT_CTRL)
        SMTD_MT(KC_F, KC_LSFT)

        SMTD_MT(KC_J, KC_LSFT)
        SMTD_MT(KC_K, KC_LEFT_CTRL)
        SMTD_MT(KC_L, KC_LEFT_ALT)
        SMTD_MT(KC_SEMICOLON, KC_LEFT_GUI)

        // SMTD_LT(KC_DEL, L_MEDIA, 1)
        SMTD_LT(KC_BSPC, L_NAV, 1)
        SMTD_LT(KC_TAB, L_MOUSE, 1)

        SMTD_LT(KC_ENT, L_NAV, 1)
        SMTD_LT(KC_SPC, L_NUM, 1)
        SMTD_LT(KC_ESC, L_FUN, 1)

        SMTD_LT(KC_Z, L_BTN, 1)
        SMTD_LT(KC_SLSH, L_BTN, 1)
    }

    return SMTD_RESOLUTION_UNHANDLED;
}

#ifdef LAYOUT_split_3x6_3_ex2
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_BASE] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
       KC_GRV,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, KC_COPY,    KC_VOLU,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_LBRC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G, KC_PSTE,    KC_VOLD,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
       KC_ESC,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RBRC,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                           KC_DEL, KC_BSPC,  KC_TAB,     KC_ENT,  KC_SPC,  KC_ESC
                                      //`--------------------------'  `--------------------------'

  ),

  [L_NAV] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_COPY,    KC_VOLU, KC_AGIN, KC_PSTE, KC_COPY,  KC_CUT, KC_UNDO, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, KC_PSTE,    KC_VOLD, KC_CAPS, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_INS, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    KC_ENT, KC_BSPC, KC_DEL
                                      //`--------------------------'  `--------------------------'
  ),
  [L_MOUSE] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_COPY,    KC_VOLU, KC_AGIN, KC_PSTE, KC_COPY,  KC_CUT, KC_UNDO, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, KC_PSTE,    KC_VOLD, XXXXXXX, MS_LEFT, MS_DOWN,   MS_UP, MS_RGHT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    MS_BTN2, MS_BTN1, MS_BTN3
                                      //`--------------------------'  `--------------------------'
  ),
  [L_BTN] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      XXXXXXX, KC_UNDO,  KC_CUT, KC_COPY, KC_PSTE, KC_AGIN, KC_COPY,    KC_VOLU, KC_AGIN, KC_PSTE, KC_COPY,  KC_CUT, KC_UNDO, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, KC_PSTE,    KC_VOLD, XXXXXXX, MS_LEFT, MS_DOWN,   MS_UP, MS_RGHT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_UNDO,  KC_CUT, KC_COPY, KC_PSTE, KC_AGIN,                      KC_AGIN, KC_PSTE, KC_COPY,  KC_CUT, KC_UNDO, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          MS_BTN3, MS_BTN1, MS_BTN2,    MS_BTN2, MS_BTN1, MS_BTN3
                                      //`--------------------------'  `--------------------------'
  ),
  [L_NUM] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      XXXXXXX, KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC, KC_COPY,    KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_SCLN,    KC_4,    KC_5,    KC_6,  KC_EQL, KC_PSTE,    KC_VOLD, XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX,  KC_GRV,    KC_1,    KC_2,    KC_3, KC_BSLS,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_DOT,    KC_0, KC_MINS,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [L_FUN] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      XXXXXXX,  KC_F12,   KC_F7,   KC_F8,   KC_F9, KC_PSCR, KC_COPY,    KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX,  KC_F11,   KC_F4,   KC_F5,   KC_F6, KC_SCRL, KC_PSTE,    KC_VOLD, XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX,  KC_F10,   KC_F1,   KC_F2,   KC_F3, KC_PAUS,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_APP,  KC_SPC, KC_TAB,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )
};
#else
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_GRV,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_LBRC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_ESC,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RBRC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_DEL, KC_BSPC,  KC_TAB,     KC_ENT,  KC_SPC,  KC_ESC
                                      //`--------------------------'  `--------------------------'
  ),

  [L_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_AGIN, KC_PSTE, KC_COPY,  KC_CUT, KC_UNDO, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                      KC_CAPS, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_INS, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    KC_ENT, KC_BSPC, KC_DEL
                                      //`--------------------------'  `--------------------------'
  ),

  [L_MOUSE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_AGIN, KC_PSTE, KC_COPY,  KC_CUT, KC_UNDO, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                      XXXXXXX, MS_LEFT, MS_DOWN,   MS_UP, MS_RGHT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    MS_BTN2, MS_BTN1, MS_BTN3
                                      //`--------------------------'  `--------------------------'
  ),

  [L_BTN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_UNDO,  KC_CUT, KC_COPY, KC_PSTE, KC_AGIN,                      KC_AGIN, KC_PSTE, KC_COPY,  KC_CUT, KC_UNDO, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                      XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_UNDO,  KC_CUT, KC_COPY, KC_PSTE, KC_AGIN,                      KC_AGIN, KC_PSTE, KC_COPY,  KC_CUT, KC_UNDO, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          MS_BTN3, MS_BTN1, MS_BTN2,    MS_BTN2, MS_BTN1, MS_BTN3
                                      //`--------------------------'  `--------------------------'
  ),

  [L_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_SCLN,    KC_4,    KC_5,    KC_6,  KC_EQL,                      XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,  KC_GRV,    KC_1,    KC_2,    KC_3, KC_BSLS,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_DOT,    KC_0, KC_MINS,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [L_FUN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,  KC_F12,   KC_F7,   KC_F8,   KC_F9, KC_PSCR,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,  KC_F11,   KC_F4,   KC_F5,   KC_F6, KC_SCRL,                      XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,  KC_F10,   KC_F1,   KC_F2,   KC_F3, KC_PAUS,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_APP,  KC_SPC, KC_TAB,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )
};
#endif

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [L_BASE] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(RGB_HUI, RGB_HUD), ENCODER_CCW_CW(RGB_VAI, RGB_VAD), ENCODER_CCW_CW(RGB_SAI, RGB_SAD), },
  [L_NAV] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(RGB_HUI, RGB_HUD), ENCODER_CCW_CW(RGB_VAI, RGB_VAD), ENCODER_CCW_CW(RGB_SAI, RGB_SAD), },
  [L_MOUSE] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(RGB_HUI, RGB_HUD), ENCODER_CCW_CW(RGB_VAI, RGB_VAD), ENCODER_CCW_CW(RGB_SAI, RGB_SAD), },
  [L_BTN] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(RGB_HUI, RGB_HUD), ENCODER_CCW_CW(RGB_VAI, RGB_VAD), ENCODER_CCW_CW(RGB_SAI, RGB_SAD), },
  [L_NUM] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(RGB_HUI, RGB_HUD), ENCODER_CCW_CW(RGB_VAI, RGB_VAD), ENCODER_CCW_CW(RGB_SAI, RGB_SAD), },
  [L_FUN] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(RGB_HUI, RGB_HUD), ENCODER_CCW_CW(RGB_VAI, RGB_VAD), ENCODER_CCW_CW(RGB_SAI, RGB_SAD), },
};
#endif
