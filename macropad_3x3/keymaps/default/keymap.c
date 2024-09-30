// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#define _l1 0
#define _l2 1
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_l1] = LAYOUT_3x3(   
      RCS(KC_ESC),  TG(1),      KC_MUTE,    
      KC_WHOM,      KC_MAIL,    KC_MYCM,    
      LCTL(KC_C),   LCTL(KC_V), KC_CALC),
    
    [_l2] = LAYOUT_3x3(
      RCS(KC_ESC),  KC_TRNS,        KC_NO,
      RCS(KC_N),    LCA(KC_Z),      MEH(KC_W),
      LCTL(KC_LBRC),LCTL(KC_RBRC),  LCTL(KC_0))

};

bool encoder_update_kb(uint8_t index, bool clockwise) {
  if (!encoder_update_user(index, clockwise)) return false;

  switch(get_highest_layer(layer_state)) {
    case _l1:        //if you're on layer 0
        if (index == 0) {
            if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
        }
        break;
    case _l2:        //if you're on layer 1
        if (index == 0) {
            if (clockwise) {
            tap_code(MS_WHLR);
        } else {
            tap_code(MS_WHLL);
        }
        }
        break;
  }

  return true;
}

void keyboard_pre_init_user(void) {
setPinOutput(B6);  
}
layer_state_t layer_state_set_user(layer_state_t state) {
    if(IS_LAYER_ON_STATE(state, 1)) { 
        writePinHigh(B6); 
    } 
    else { 
        writePinLow(B6);
    } 
return state; 
}