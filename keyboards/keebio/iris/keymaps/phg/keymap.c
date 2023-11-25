// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

/** X11 paste. */
#define SHF_INS SFT_T(KC_INS)

enum custom_layers {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
    /** NUM pads on both left and right half. */
    _NUMPAD,
};

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    NUM_ON,
    NUM_OFF,
    ADJUST,
};

/**
 * CAPS lock behavior rests on the assumtion that ``caps:swapescape`` is being
 * used in the X server. Hence we need to send ``ESC`` in order to toggle CAPS
 * locking.
 */
enum tap_handlers {
    /** Left shift CAPS lock double tap. */
    LCP = 0,
    /** Right shift CAPS lock double tap. */
    RCP = 1,
};

/**
 * - ``KC_APP`` is ``Menu`` in Xorg, to be mapped to the Compose key /
 *   ``Multi_key``.
 *
 * - ``KC_LGUI`` is the Windows key / ``Super_L`` in X.
 */

const uint16_t PROGMEM keymaps[] [MATRIX_ROWS] [MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     TD(LCP), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_HOME,          KC_APP,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, TD(RCP),
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    LOWER,   KC_LCTL, KC_LALT,                   KC_RALT, KC_SPC,  RAISE
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     QK_BOOT, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_DEL,  _______, KC_LEFT, KC_RGHT, KC_UP,   KC_LBRC,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PLUS, KC_PIPE,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     BL_STEP, _______, _______, _______, KC_DOWN, KC_LCBR, NUM_ON,           NUM_ON,  KC_RCBR, KC_P1,   KC_P2,   KC_P3,   KC_MINS, KC_CAPS,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, KC_DEL,                    KC_DEL,  SHF_INS, KC_P0
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_TOG, KC_EXLM, KC_UP,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_MOD, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGUP, KC_UNDS,                            KC_EQL,  KC_HOME, RGB_HUI, RGB_SAI, RGB_VAI, KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_CAPS, KC_MSTP, KC_MPLY, KC_VOLD, KC_PGDN, KC_MINS, KC_LPRN,          _______, KC_PLUS, KC_END,  RGB_HUD, RGB_SAD, RGB_VAD, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, SHF_INS, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_NUMPAD] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, KC_EQL,  KC_SLSH, KC_ASTR, KC_MINS,                            _______, KC_EQL,  KC_SLSH, KC_ASTR, KC_MINS, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_7,    KC_8,    KC_9,    KC_PLUS,                            _______, KC_7,    KC_8,    KC_9,    KC_PLUS, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_4,    KC_5,    KC_6,    KC_ENT,                             _______, KC_4,    KC_5,    KC_6,    KC_ENT,  _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_1,    KC_2,    KC_3,    KC_DEL,  NUM_OFF,          NUM_OFF, _______, KC_1,    KC_2,    KC_3,    KC_DEL,  _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_INS,  KC_LCTL, KC_LALT,                   KC_SPC,  KC_RALT, KC_INS
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

bool process_record_user (uint16_t keycode, keyrecord_t *record)
{
    switch (keycode) {
        default: {
            break;
        }
        case QWERTY: {
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        }
        case LOWER: {
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        }
        case RAISE: {
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        }
        case NUM_ON: {
            if (!record->event.pressed) {
                layer_on(_NUMPAD);
            }
            return false;
        }
        case NUM_OFF: {
            if (record->event.pressed) {
                layer_off(_NUMPAD);
            }
            return false;
        }
        case ADJUST: {
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
        }
    }

    return true;
}


tap_dance_action_t tap_dance_actions[] = {
    [LCP] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_ESC),
    [RCP] = ACTION_TAP_DANCE_DOUBLE(KC_RSFT, KC_ESC),
};

const uint8_t RGBLED_BREATHING_INTERVALS[] PROGMEM = { 5, 2, 5, 8 };

#ifdef RGBLIGHT_EFFECT_BREATHING
layer_state_t layer_state_set_user (layer_state_t state)
{
    switch (get_highest_layer(state)) {
        default:
            rgblight_disable();
            break;
        case _NUMPAD: {
            rgblight_enable();
            rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL);
            break;
        }
        case _LOWER: {
            rgblight_enable();
            rgblight_mode(RGBLIGHT_MODE_BREATHING);
            rgblight_sethsv_noeeprom (HSV_PURPLE);
            break;
        }
        case _RAISE: {
            rgblight_enable();
            rgblight_mode (RGBLIGHT_MODE_BREATHING);
            rgblight_sethsv_noeeprom (HSV_BLUE);
            break;
        }
    }

    return state;
}
#endif

