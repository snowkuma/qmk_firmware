#include QMK_KEYBOARD_H
#include "snowkuma.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT_wrapper(
  //,----------------------------------------------------.      ,----------------------------------------------------.
     _______, _________________COLEMAK_L1________________,       _________________COLEMAK_R1________________, KC__VOLUP,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
     _______, _________________COLEMAK_L2________________,       _________________COLEMAK_R2________________, KC__VOLDOWN,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
     _______, _________________COLEMAK_L3________________,       _________________COLEMAK_R3________________, KC__MUTE,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
                                ________MOD_LEFT_________,       ________MOD_RIGHT________
                                 //`---------------------'      `---------------------'
  ),

  [_NAV] = LAYOUT_wrapper(
  //,----------------------------------------------------.      ,----------------------------------------------------.
     _______, _________________NAV_L1____________________,       _________________NAV_R1____________________, _______,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
     _______, _________________NAV_L2____________________,       _________________NAV_R2____________________, _______,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
     _______, _________________NAV_L3____________________,       _________________NAV_L3____________________, _______,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
                                _______, DEL_SYM, _______,       _______, _______, _______
                                 //`---------------------'      `---------------------'
  ),

  [_SYMBOL] = LAYOUT_wrapper(
  //,----------------------------------------------------.      ,----------------------------------------------------.
     _______, _________________SYM_L1____________________,       _________________SYM_R1____________________, _______,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
     _______, _________________SYM_L2____________________,       _________________SYM_R2____________________, _______,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
     _______, _________________SYM_L3____________________,       _________________SYM_R3____________________, _______,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
                                _______, _______, _______,       _______, _______, _______
                                 //`---------------------'      `---------------------'
  ),

  [_NUMBER] = LAYOUT_wrapper(
  //,----------------------------------------------------.      ,----------------------------------------------------.
     _______, _________________NUM_L1____________________,       _________________NUM_R1____________________, _______,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
     _______, _________________NUM_L2____________________,       _________________NUM_R2____________________, _______,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
     _______, _________________NUM_L3____________________,       _________________NUM_R3____________________, _______,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
                                _______, _______, _______,       ________NUM_R4___________
                                 //`---------------------'      `---------------------'
  ),

  [_ARRANGE] = LAYOUT_wrapper(
  //,----------------------------------------------------.      ,----------------------------------------------------.
     _______, _________________ARR_L1____________________,       _________________ARR_R1____________________, _______,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
     _______, _________________ARR_L2____________________,       _________________ARR_R2____________________, _______,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
     _______, _________________ARR_L3____________________,       _________________ARR_R3____________________, _______,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
                                _______, _______, _______,       _______, _______, _______
                                 //`---------------------'      `---------------------'
  ),

  [_MOUSE] = LAYOUT_wrapper(
  //,----------------------------------------------------.      ,----------------------------------------------------.
     _______, _________________MOU_L1____________________,       _________________MOU_R1____________________, _______,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
     _______, _________________MOU_L2____________________,       _________________MOU_R2____________________, _______,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
     _______, _________________MOU_L3____________________,       _________________MOU_R3____________________, _______,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
                                _______, _______, _______,       _______, _______, _______
                                 //`---------------------'      `---------------------'
  ),
  
  [_THUMB] = LAYOUT_wrapper(
  //,----------------------------------------------------.      ,----------------------------------------------------.
     _______, _________________THU_L1____________________,       _________________THU_R1____________________, _______,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
     _______, _________________THU_L2____________________,       _________________THU_R2____________________, _______,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
     _______, _________________THU_L3____________________,       _________________THU_R3____________________, _______,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
                                _______, _______, _______,       _______, _______, _______
                                 //`---------------------'      `---------------------'
  ),
};