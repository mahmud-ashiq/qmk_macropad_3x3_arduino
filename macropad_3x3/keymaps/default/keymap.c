// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#define _l1 0
#define _l2 1
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_l1] = LAYOUT_3x3(   
        KC_BRID, KC_BRIU, KC_MUTE, 
        KC_CAPS, KC_SCRL, KC_PSCR, 
        KC_CALC, KC_MYCM, OSL(1)),
    
    [_l2] = LAYOUT_3x3(
        KC_VOLD, KC_VOLU, KC_MUTE, 
        KC_CAPS, KC_SCRL, KC_PSCR, 
        KC_CALC, KC_MYCM, OSL(1))
    

};

/*bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { 
        if (clockwise) {
            tap_code(KC_AUDIO_VOL_UP);
        } else {
            tap_code(KC_AUDIO_VOL_DOWN);
        }
    }
    return false;
}*/

bool encoder_update_kb(uint8_t index, bool clockwise) {
  if (!encoder_update_user(index, clockwise)) return false;

  switch(get_highest_layer(layer_state)) {
    case _l1:        //if you're on layer 0
        if (index == 0) {
            if (clockwise) {
            tap_code(KC_AUDIO_VOL_UP);
        } else {
            tap_code(KC_AUDIO_VOL_DOWN);
        }
        }
        break;
    case _l2:        //if you're on layer 1
        if (index == 0) {
            if (clockwise) {
            tap_code(KC_BRIU);
        } else {
            tap_code(KC_BRID);
        }
        }
        break;
  }

  return true;
}

void keyboard_pre_init_user(void) {
setPinOutput(B6);  
setPinOutput(B2);  
}

layer_state_t layer_state_set_user(layer_state_t state) {
    if(IS_LAYER_ON_STATE(state, 0)) { 
        writePinHigh(B6); 
    } 
    else { 
        writePinLow(B6);
    } 
    if(IS_LAYER_ON_STATE(state, 1)) { 
        writePinHigh(B2); 
    } 
    else { 
        writePinLow(B2); 
    } 
return state; 
}