// Copyright 2026 Henrique Picanço
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "gpio.h"

#include "henrique.h"

enum layers {
    BASE,
    GAME,
    FN,
    SYSTEM,
    KNOB
};

enum custom_keycodes {
    MC_KNOB = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
        KC_CAPS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_F13,   MC_KNOB,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_HOME,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_ENT,   KC_PGUP,
        KC_ESC,   MT_A,     MT_S,     MT_D,     MT_F,     KC_G,     KC_H,     MT_J,     MT_K,     MT_L,     MT_SCLN,  KC_QUOT,  KC_BSLS,            KC_PGDN,
        KC_LSFT,  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        KC_LCTL,  KC_LGUI,  KC_LALT,                           KC_SPC,                            KC_RALT,  MO(2),              KC_LEFT,  KC_DOWN,  KC_RGHT
        ),

    [GAME] = LAYOUT(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_F13,   MC_KNOB,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_HOME,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_ENT,   KC_PGUP,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_BSLS,            KC_PGDN,
        KC_LSFT,  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        KC_LCTL,  KC_LGUI,  KC_LALT,                           KC_SPC,                            KC_RALT,  MO(2),              KC_LEFT,  KC_DOWN,  KC_RGHT
        ),

    [FN] = LAYOUT(
        _______,  KC_MYCM,  KC_WHOM,  KC_MAIL,  KC_CALC,  KC_MSEL,  KC_MSTP,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_SCRL,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_DEL,   KC_PSCR,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RM_PREV,  _______,  KC_INS,   _______,  KC_PAUSE,
        _______,  _______,  _______,  _______,  _______,  TG(1),    _______,  _______,  _______,  RM_TOGG,  _______,  _______,  _______,            KC_END,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  RM_NEXT,  _______,  _______,  _______,  _______,  MO(3),    RM_VALU,
        _______,  GU_TOGG,  _______,                            EE_CLR,                           KC_RALT,  _______,            RM_SPDD,  RM_VALD,  RM_SPDU
        ),

    [SYSTEM] = LAYOUT(
        QK_BOOT,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,                            _______,                          _______,  _______,            _______,  _______,  _______
        ),

    [KNOB] = LAYOUT(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  MC_KNOB,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,                            _______,                          _______,  _______,            _______,  _______,  _______
        ),
};

// Custom KNOB behaivior: Long press (200m), knob controls RGB.
uint16_t knob_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case MC_KNOB:
            if (record->event.pressed) {
                knob_timer = timer_read();
            } else {
                if (timer_elapsed(knob_timer) >= 300) {
                    layer_invert(KNOB);
                } else {
                    if(IS_LAYER_ON(KNOB)) {
                        rgb_matrix_toggle();
                    } else {
                        tap_code(KC_MUTE);
                    }
                }
            }
        return false;
    }
    return true;
}

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [BASE]   = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [GAME]   = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [FN]     = { ENCODER_CCW_CW(_______, _______) },
    [SYSTEM] = { ENCODER_CCW_CW(_______, _______) },
    [KNOB]   = { ENCODER_CCW_CW(RM_SPDD, RM_SPDU) },
};
#endif

void keyboard_post_init_user(void) {
    gpio_set_pin_output(LED_GAME_PIN);
    gpio_set_pin_output(LED_WIN_LOCK_PIN);

    gpio_write_pin_high(LED_GAME_PIN);

    if (keymap_config.no_gui) {
        gpio_write_pin_low(LED_WIN_LOCK_PIN);
    } else {
        gpio_write_pin_high(LED_WIN_LOCK_PIN);
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    if (layer_state_cmp(state, GAME)) {
        gpio_write_pin_low(LED_GAME_PIN);
    } else {
        gpio_write_pin_high(LED_GAME_PIN);
    }

    return state;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case GU_TOGG:
            if (!record->event.pressed) {
                if (keymap_config.no_gui) {
                    gpio_write_pin_low(LED_WIN_LOCK_PIN);
                } else {
                    gpio_write_pin_high(LED_WIN_LOCK_PIN);
                }
            }
        break;
    }
}

// clang-format on

