/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*                                   _
 *  ___   _ __     ___   __      __ | | __  _   _   _ __ ___     __ _
 * / __| | '_ \   / _ \  \ \ /\ / / | |/ / | | | | | '_ ` _ \   / _` |
 * \__ \ | | | | | (_) |  \ V  V /  |   <  | |_| | | | | | | | | (_| |
 * |___/ |_| |_|  \___/    \_/\_/   |_|\_\  \__,_| |_| |_| |_|  \__,_|
 *
 * https://github.com/snowkuma
 *
 * Colemak is the default layer and I'll add some notes for other changes as I 
 * go along.
 * 
 * version 0.1
*/

#include "planck.h"
#include "action_layer.h"
#include "muse.h"
#include "custom_keycodes.h"
#include "canned_responses.h"

#define Colemak = 0
extern keymap_config_t keymap_config;

enum planck_layers {
  _COLEMAK = 0,
  _NUMBER,
  _SYMBOL,
  _NAV,
  _THUMB,
  _MOUSE,
  _FUNCTION
};

enum planck_keycodes {
  COLEMAK = SAFE_RANGE,
  PLOVER,
  EXT_PLV,
  EMAIL,
  ITERM,
  LESSON,
  TYPE_FU,
  VS_CODE  
};

enum unicode_names {
  GBP,
  EURO,
  SNEK
}

const uint32_t PROGMEM unicode_map[] = {
  [GBP] = 0x1C2A0, // £
  [EURO] = 0x120AC, // €    
  [SNEK] = 0x1F40D, // 🐍
}
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* COLEMAK
 *
 * Base layer
 * ,-----------------------------------------------------------------------------------------------------------.
 * | Q_CTL  | W_ALT  | F_CMD  |   f    |   g    |        |        |   j    |   l    | U_CMD  | Y_ALT  | SC_CTL |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |   a    |   r    |   s    | t_sft  |   d    |  caps  |        |   h    | n_sft  |   e    |   i    |   o    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |   z    |   x    |   c    |   v    |   b    |        |        |   k    |   m    |   ,    |   .    |   '    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |  Esc   |  BkSp  |  Sft   |   Tab  | Space  | Enter  |        |        |
 * |        |        |        |  Num   | Regex  |        |  Edit  |  Nav   | Mouse  |        |        |        |
 * `--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
 * Left Shift Layer
 * ,-----------------------------------------------------------------------------------------------------------.
 * | QU_ALT | WU_ALT | FU_CMD |   F    |   G    |        |        |   J    |   L    | UU_CMD | YU_CMD |CLNU_CMD|
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |   A    |   R    |   S    |  fn()  |   D    |  caps  |        |   H    |   N    |   E    |   I    |   O    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |   Z    |   X    |   C    |   V    |   B    |        |        |   K    |   M    |   <    |   >    |   "    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |  Esc   |  Del   |  Sft   |Sft_Tab | Space  | Enter  |        |        |
 * |        |        |        |  Num   | Regex  |        |  Edit  |  Nav   | Mouse  |        |        |        |
 * `--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
 * Right Shift Layer
 * ,-----------------------------------------------------------------------------------------------------------.
 * | QU_ALT | WU_ALT | FU_CMD |   F    |   G    |        |        |   J    |   L    | UU_CMD | YU_CMD |CLNU_CMD|
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |   A    |   R    |   S    | TU_SFT |   D    |  caps  |        |   H    |  fn()  |   E    |   I    |   O    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |   Z    |   X    |   C    |   V    |   B    |        |        |   K    |   M    |   <    |   >    |   "    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |  Esc   |  Del   |  Sft   |Sft_Tab | Space  | Enter  |        |        |
 * |        |        |        |  Num   | Regex  |        |  Edit  |  Nav   | Mouse  |        |        |        |
 * `--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
 * Regex layer
 * ,-----------------------------------------------------------------------------------------------------------.
 * |   !    |   @    |   #    |   -    |   &    |        |        |   *    |   [    |   ^    |    ]   |   :    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |   £    |   <    |   %    |   >    |   ~    |        |        |   ?    |   (    |   $    |    )   |   /    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |   €    |   +    |   =    |   _    |   `    |        |        |   |    |   {    |   #    |    }   |   \    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |  Esc   |   f()  |  Sft   |  Tab   | Space  | Enter  |        |        |
 * |        |        |        |  Num   |  Regex |        | Edit   |  Nav   | Mouse  |        |        |        |
 * `--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
 *
 * Nav Layer
 * ,-----------------------------------------------------------------------------------------------------------.
 * |  Ctrl  |  Alt   |  GUI   |        |        |        |        |        | Home   |   Up   |  End   | PgUp   |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |  Sft   |        |        |        |        | Left   |  Down  | Right  | PgDn   |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |  Esc   |   f()  |  Sft   |  Tab   |   f()  | Enter  |        |        |
 * |        |        |        |  Num   |  Regex |        |  Edit  |  Nav   | Mouse  |        |        |        |
 * `--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
 *
 * Mouse Layer
 * ,-----------------------------------------------------------------------------------------------------------.
 * |  Ctrl  |  Alt   |  GUI   |        |        |        |        |        | Home   |   Up   |  End   | ScUp   |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |  Btn3  |  Btn2  |  Btn1  |  Sft   |        |        |        |        | Left   |  Down  | Right  | ScDn   |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |  Esc   |   Tab  |  Sft   |  Tab   | Space  |  f()   |        |        |
 * |        |        |        |  Num   |  Regex |        |  Edit  |  Nav   | Mouse  |        |        |        |
 * `--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
 *
 * Number Layer
 * ,-----------------------------------------------------------------------------------------------------------.
 * |   1    |   2    |    3   |   4    |    5   |        |        |    6   |   7    |   8    |   9    |   0    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |   4    |   5    |   6    |   .    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |   -    |   +    |        |        |        |        |        |        |   1    |   2    |   3    |   ,    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |  f()   |   Tab  |  Sft   |  Tab   | Space  | Enter  |        |        |
 * |        |        |        |  Num   |  Regex |        |  Edit  |  Nav   | Mouse  |        |        |        |
 * `--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
 */
[_COLEMAK] = LAYOUT_planck_grid(
    Q_CTL,   W_ALT,   F_CMD,   KC_P,    KC_G,    ___x___, ___x___, KC_J,    KC_L,    U_CMD,   Y_ALT,   SC_CTL,
    ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___,	
    ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___,	
    ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___,
),

/* SYMBOL
 * ,-----------------------------------------------------------------------------------------------------------.
 * |  Tab   |   q    |   w    |   f    |   f    |   g    |        |   j    |   l    |   u    |   y    |   ;    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |  Ctrl  |   a    |   r    |   s    |   t    |   d    |        |   h    |   n    |   e    |   i    |   o    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |   z    |   x    |   c    |   v    |   b    |        |   k    |   m    |   ,    |   .    |   '    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |  Num   |        |        |        |  Esc   |  Bksp  | Shift  | Space  |  Enter |        |        |        |
 * |        |        |        |        |  Num   |  Sym   |        |  Nav   |  Thumb |        |        |        |
 * `--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
 */
[_SYMBOL] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    ___x___, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
    KC_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    ___x___, KC_H,    KC_N,    KC_E,    KC_I,    KC_O,
    ___x___, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    ___x___, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_QOUT,
    NUM,     ___x___, ___x___, ___x___, ESC_NUM, BSP_SYM, KC_LSFT, SPC_NAV, ENT_THU, ___x___, ___x___, ___x___
),

/* NUMBER
 * ,-----------------------------------------------------------------------------------------------------------.
 * |  Tab   |   q    |   w    |   f    |   f    |   g    |        |   j    |   l    |   u    |   y    |   ;    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |  Ctrl  |   a    |   r    |   s    |   t    |   d    |        |   h    |   n    |   e    |   i    |   o    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |   z    |   x    |   c    |   v    |   b    |        |   k    |   m    |   ,    |   .    |   '    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |  Num   |        |        |        |  Esc   |  Bksp  | Shift  | Space  |  Enter |        |        |        |
 * |        |        |        |        |  Num   |  Sym   |        |  Nav   |  Thumb |        |        |        |
 * `--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
 */
[_NUMBER] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    ___x___, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
    KC_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    ___x___, KC_H,    KC_N,    KC_E,    KC_I,    KC_O,
    ___x___, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    ___x___, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_QOUT,
    NUM,     ___x___, ___x___, ___x___, ESC_NUM, BSP_SYM, KC_LSFT, SPC_NAV, ENT_THU, ___x___, ___x___, ___x___
),

/* NAV
 * ,-----------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |   UP   |        | PgUp   |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |  LEFT  |  DOWN  | RIGHT  | PgDn   |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |  Num   |        |        |        |  Esc   |  Bksp  | Shift  | Space  |  Enter |        |        |        |
 * |        |        |        |        |  Num   |  Sym   |        |  Nav   |  Thumb |        |        |        |
 * `--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
 */
[_NAV] = LAYOUT_planck_grid(
    ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___,            
    ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___,            
    ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___,            
    NUM,     ___x___, ___x___, ___x___, ESC_NUM, BSP_SYM, KC_LSFT, SPC_NAV, ENT_THU, ___x___, ___x___, ___x___
)

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          PORTE &= ~(1<<6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          PORTE |= (1<<6);
        #endif
      }
      return false;
      break;
    case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_PLOVER);
      }
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
}

void dip_update(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if (active) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_song);
        #endif
        layer_on(_ADJUST);
      } else {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_ADJUST);
      }
      break;
    case 1:
      if (active) {
        muse_mode = true;
      } else {
        muse_mode = false;
        #ifdef AUDIO_ENABLE
          stop_all_notes();
        #endif
      }
   }
}

void matrix_scan_user(void) {
  #ifdef AUDIO_ENABLE
    if (muse_mode) {
      if (muse_counter == 0) {
        uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
        if (muse_note != last_muse_note) {
          stop_note(compute_freq_for_midi_note(last_muse_note));
          play_note(compute_freq_for_midi_note(muse_note), 0xF);
          last_muse_note = muse_note;
        }
      }
      muse_counter = (muse_counter + 1) % muse_tempo;
    }
  #endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
