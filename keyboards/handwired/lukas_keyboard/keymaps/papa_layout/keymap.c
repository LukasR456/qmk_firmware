/* Copyright 2021 Lukas Rosenbach
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

#include QMK_KEYBOARD_H
#include "keymap_german.h"

extern keymap_config_t keymap_config;
extern rgblight_config_t rgblight_config;

#define _TYPE 0
#define _MODI 1
#define _SYMB 2
#define _NAVI 3
#define _NUMB 4
#define _MACR 5
#define _CONF 6

enum custom_keycodes {
  TYPE = SAFE_RANGE,
  MODI,
  SYMB,
  NAVI,
  NUMB,
  MACR,
  CONF,
};

/*void keyboard_post_init_user(void) {
  layer_on(_MODI); //Turn modifiers layer on
}*/

// Shortcut to make keymap more readable
#define KC_STAB S(KC_TAB)
#define KC_UNDO C(DE_Z)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

   //Typing
  [_TYPE] = LAYOUT(
  //┌────────┬────────┬────────┬──────────┬────────┬────────┐                                                       ┌────────┬────────┬──────────┬────────┬────────┬────────┐
     DE_CIRC ,DE_1    ,DE_2    ,DE_3      ,DE_4    ,DE_5    ,                                                        DE_6    ,DE_7    ,DE_8      ,DE_9    ,DE_0    ,DE_SS   ,
  //├────────┼────────┼────────┼──────────┼────────┼────────┤                                                       ├────────┼────────┼──────────┼────────┼────────┼────────┤
     KC_TAB  ,DE_Q    ,DE_W    ,DE_E      ,DE_R    ,DE_T    ,                                                        DE_Z    ,DE_U    ,DE_I      ,DE_O    ,DE_P    ,DE_UDIA ,
  //├────────┼────────┼────────┼──────────┼────────┼────────┼───────────┬───────────┐       ┌───────────┬───────────┼────────┼────────┼──────────┼────────┼────────┼────────┤
     KC_ESC  ,DE_A    ,DE_S    ,DE_D      ,DE_F    ,DE_G    ,XXXXXXX    ,XXXXXXX    ,        TG(_NUMB)  ,KC_MUTE    ,DE_H    ,DE_J    ,DE_K      ,DE_L    ,DE_ODIA ,DE_ADIA ,
  //├────────┼────────┼────────┼──────────┼────────┼────────┼───────────┼───────────┤       ├───────────┼───────────┼────────┼────────┼──────────┼────────┼────────┼────────┤
     KC_LSFT ,DE_Y    ,DE_X    ,DE_C      ,DE_V    ,DE_B    ,MO(_NAVI)  ,MO(_MACR)  ,        MO(_MACR)  ,MO(_NAVI)  ,DE_N    ,DE_M    ,DE_COMM   ,DE_DOT  ,DE_MINS ,KC_RSFT ,
  //├────────┼────────┼────────┼──────────┼────┬───┴────┬───┼───────────┼───────────┤       ├───────────┼───────────┼───┬────┴────┬───┼──────────┼────────┼────────┼────────┤
     KC_LCTL ,KC_LALT ,KC_LWIN ,MO(_CONF) ,     MO(_SYMB),   KC_SPC     ,KC_DEL     ,        KC_ENT     ,KC_BSPC    ,    MO(_SYMB),    MO(_CONF) ,KC_RWIN ,KC_RALT ,KC_RCTL
  //└────────┴────────┴────────┴──────────┘    └────────┘   └───────────┴───────────┘       └───────────┴───────────┘   └─────────┘   └──────────┴────────┴────────┴────────┘
  ),

  //Typing
  [_MODI] = LAYOUT(
  //┌────────────────┬────────────────┬────────────────┬────────────────┬────────────────┬────────┐                                                   ┌────────┬────────────────┬────────────────┬────────────────┬────────────────┬────────────────┐
     _______         ,_______         ,_______         ,_______         ,_______         ,_______ ,                                                    _______ ,_______         ,_______         ,_______         ,_______         ,_______         ,
  //├────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼────────┤                                                   ├────────┼────────────────┼────────────────┼────────────────┼────────────────┼────────────────┤
     _______         ,_______         ,_______         ,_______         ,_______         ,_______ ,                                                    _______ ,_______         ,_______         ,_______         ,_______         ,_______         ,
  //├────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼────────┼──────────┬──────────┐       ┌──────────┬──────────┼────────┼────────────────┼────────────────┼────────────────┼────────────────┼────────────────┤
     HYPR_T(KC_ESC)  ,LSFT_T(DE_A)    ,LCTL_T(DE_S)    ,LALT_T(DE_D)    ,LGUI_T(DE_F)    ,_______ ,_______   ,_______   ,        _______   ,_______   ,_______ ,RGUI_T(DE_J)    ,RALT_T(DE_K)    ,RCTL_T(DE_L)    ,RSFT_T(DE_ODIA) ,HYPR_T(DE_ADIA) ,
  //├────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼────────┼──────────┼──────────┤       ├──────────┼──────────┼────────┼────────────────┼────────────────┼────────────────┼────────────────┼────────────────┤
     _______         ,_______         ,_______         ,_______         ,_______         ,_______ ,_______   ,_______   ,        _______   ,_______   ,_______ ,_______         ,_______         ,_______         ,_______         ,_______         ,
  //├────────────────┼────────────────┼────────────────┼────────────────┼───────┬────────┴───┬────┼──────────┼──────────┤       ├──────────┼──────────┼─────┬──┴─────────┬──────┼────────────────┼────────────────┼────────────────┼────────────────┤
     _______         ,_______         ,_______         ,_______         ,        _______     ,     _______   ,_______   ,        _______   ,_______   ,      _______     ,       _______         ,_______         ,_______         ,_______
  //└────────────────┴────────────────┴────────────────┴────────────────┘       └────────────┘    └──────────┴──────────┘       └──────────┴──────────┘     └────────────┘      └────────────────┴────────────────┴────────────────┴────────────────┘
  ),

   //Symbols
  [_SYMB] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                                            _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                           ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,DE_UNDS ,DE_LBRC ,DE_RBRC ,DE_CIRC ,                                            DE_EXLM ,DE_LABK ,DE_RABK ,DE_EQL  ,DE_AMPR ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┬────────┐       ┌────────┬────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,DE_BSLS ,DE_SLSH ,DE_LCBR ,DE_RCBR ,DE_ASTR ,_______ ,_______ ,        _______ ,_______ ,DE_QUES ,DE_LPRN ,DE_RPRN ,DE_MINS ,DE_COLN ,DE_AT   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,DE_HASH ,DE_DLR  ,DE_PIPE ,DE_TILD ,DE_GRV  ,_______ ,_______ ,        _______ ,_______ ,DE_PLUS ,DE_PERC ,DE_DQUO ,DE_QUOT ,DE_SCLN ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    _______ ,     _______ ,_______ ,_______ ,_______
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

   //Navigation
  [_NAVI] = LAYOUT(
  //┌────────┬────────┬──────────────┬────────┬────────────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F1   ,KC_F2   ,KC_F3         ,KC_F4   ,KC_F5           ,KC_F6   ,                                            KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,KC_F12  ,
  //├────────┼────────┼──────────────┼────────┼────────────────┼────────┤                                           ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_PGUP ,LCTL(KC_LEFT) ,KC_UP   ,LCTL(KC_RIGHT)  ,KC_PGDN ,                                            _______ ,KC_WH_D ,KC_MS_U ,KC_WH_U ,_______ ,_______ ,
  //├────────┼────────┼──────────────┼────────┼────────────────┼────────┼────────┬────────┐       ┌────────┬────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_HOME ,KC_LEFT       ,KC_DOWN ,KC_RIGHT        ,KC_END  ,_______ ,_______ ,        _______ ,_______ ,KC_BTN1 ,KC_MS_L ,KC_MS_D ,KC_MS_R ,KC_BTN2 ,_______ ,
  //├────────┼────────┼──────────────┼────────┼────────────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_STAB ,LCTL(KC_BSPC) ,KC_SPC  ,LCTL(KC_DEL)    ,KC_UNDO ,_______ ,_______ ,        _______ ,_______ ,_______ ,KC_WH_L ,KC_BTN1 ,KC_WH_R ,_______ ,_______ ,
  //├────────┼────────┼──────────────┼────────┼────┬───────────┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______       ,_______ ,     _______         ,    _______ ,_______ ,        _______ ,_______ ,    _______ ,     _______ ,_______ ,_______ ,_______
  //└────────┴────────┴──────────────┴────────┘    └────────────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

   //Numblock
  [_NUMB] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                                            _______ ,KC_NUM  ,KC_PSLS ,KC_PAST ,KC_PMNS ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                           ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_F12  ,KC_F11  ,KC_F10  ,KC_F9   ,_______ ,                                            _______ ,KC_P7   ,KC_P8   ,KC_P9   ,KC_PPLS ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┬────────┐       ┌────────┬────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_F8   ,KC_F7   ,KC_F6   ,KC_F5   ,_______ ,_______ ,_______ ,        _______ ,_______ ,_______ ,KC_P4   ,KC_P5   ,KC_P6   ,KC_PPLS ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_F4   ,KC_F3   ,KC_F2   ,KC_F1   ,_______ ,_______ ,_______ ,        _______ ,_______ ,_______ ,KC_P1   ,KC_P2   ,KC_P3   ,KC_PENT ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    _______ ,     KC_P0   ,KC_PDOT ,KC_PENT ,_______
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

   //Macros
  [_MACR] = LAYOUT(
  //┌────────┬───────────┬───────────┬───────────┬───────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______    ,_______    ,_______    ,_______    ,_______ ,                                            _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼───────────┼───────────┼───────────┼───────────┼────────┤                                           ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______    ,_______    ,_______    ,_______    ,_______ ,                                            _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼───────────┼───────────┼───────────┼───────────┼────────┼────────┬────────┐       ┌────────┬────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,LCTL(DE_S) ,LCTL(DE_Z) ,_______    ,_______    ,_______ ,_______ ,_______ ,        _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼───────────┼───────────┼───────────┼───────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______    ,LCTL(DE_X) ,LCTL(DE_C) ,LCTL(DE_V) ,_______ ,_______ ,_______ ,        _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼───────────┼───────────┼───────────┼─────┬─────┴──┬─────┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______    ,_______    ,_______ ,         _______ ,      _______ ,_______ ,        _______ ,_______ ,    _______ ,     _______ ,_______ ,_______ ,_______
  //└────────┴───────────┴───────────┴───────────┘     └────────┘     └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),


   //Configuration and RGB
  [_CONF] = LAYOUT(
  //┌────────┬──────────┬──────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QK_BOOT ,_______   ,_______   ,_______ ,_______ ,_______ ,                                            _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼──────────┼──────────┼────────┼────────┼────────┤                                           ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,TG(_MODI) ,_______   ,_______ ,_______ ,_______ ,                                            _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼──────────┼──────────┼────────┼────────┼────────┼────────┬────────┐       ┌────────┬────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______   ,_______   ,_______ ,_______ ,_______ ,_______ ,_______ ,        _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼──────────┼──────────┼────────┼────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,RGB_TOG   ,RGB_MOD   ,RGB_VAI ,RGB_HUI ,RGB_SAI ,_______ ,_______ ,        _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼──────────┼──────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______   ,_______   ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    _______ ,     _______ ,_______ ,_______ ,_______
  //└────────┴──────────┴──────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

};

//Rotary encoders callback
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { // Encoder 1
        if (clockwise) {
            //redo
            register_mods(KC_LCTL);
            register_mods(KC_LSFT);
            tap_code(DE_Z);
            unregister_mods(KC_LCTL);
            unregister_mods(KC_LSFT);
        } else {
            // Undo
            register_mods(KC_LCTL);
            tap_code(DE_Z);
            unregister_mods(KC_LCTL);
        }
    } else if (index == 1) { // Encoder 2
        if (clockwise) {

        } else {

        }
    } else if (index == 2) { // Encoder 3
        if (clockwise) {
            tap_code(KC_AUDIO_VOL_UP);
        } else {
            tap_code(KC_AUDIO_VOL_DOWN);
        }
    } else if (index == 3) { // Encoder 4
        if (clockwise) {

        } else {

        }
    }
    return false;
}
