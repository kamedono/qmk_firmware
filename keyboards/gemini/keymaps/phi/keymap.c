#include QMK_KEYBOARD_H

#include "layer_numbers.h"
#include "rgb_matrix.h"         /* rgb_matrix_config */
#include "microwriter.h"

/* KEYCODE DEFINITIONS */

enum custom_keycodes {
    KC_MW_0 = SAFE_RANGE,
    KC_MW_1,
    KC_MW_2,
    KC_MW_3,
    KC_MW_4,
    KC_MW_5
};

#define KC_____ KC_TRNS
#define KC_XXXX KC_NO

#define KC_D_MOUS LT(MOUSE, KC_D)
#define KC_F_CUR  LT(CURSOR, KC_F)
#define KC_EN_RAI LT(RAISE, KC_ENT)
#define KC_L1_FN  LT(FUNCTION, KC_LANG1)
#define KC_L2_ALT LALT_T(KC_LANG2)
#define KC_ES_ALT LALT_T(KC_ESC)
#define KC_WEEL   MO(WHEEL)
#define KC_MOUSE  MO(MOUSE)
#define KC_MCRW   TO(MICROWRITER)
#define KC_BASE   TO(BASE)

#define KC_RST  RESET
#define KC_MUP  KC_MS_U
#define KC_MDN  KC_MS_D
#define KC_MLFT KC_MS_L
#define KC_MRGT KC_MS_R
#define KC_WUP  KC_WH_U
#define KC_WDN  KC_WH_D
#define KC_WLFT KC_WH_L
#define KC_WRGT KC_WH_R
#define KC_ACCL KC_MS_ACCEL2

#define KC_TOGG RGB_TOG
#define KC_MODE RGB_MOD
#define KC_H_UP RGB_HUI
#define KC_H_DN RGB_HUD
#define KC_S_UP RGB_SAI
#define KC_S_DN RGB_SAD
#define KC_V_UP RGB_VAI
#define KC_V_DN RGB_VAD

/* KEYMAPS */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[BASE] = LAYOUT_kc( \
//,-----------------------------------------. ,-----------------------------------------.
    JYEN , Q    , W    , E    , R    , T    ,   Y    , U    , I    , O    , P    , MINS , \
//|------+------+------+------+------+------| |------+------+------+------+------+------|
    LCTL , A    , S    ,D_MOUS, F_CUR, G    ,   H    , J    , K    , L    , SCLN , QUOT , \
//|------+------+------+------+------+------| |------+------+------+------+------+------|
    LSFT , Z    , X    , C    , V    , B    ,   B    , N    , M    , COMM , DOT  , SLSH , \
//`------+------+------+------+------+------| |------+------+------+------+------+------'
                               ES_ALT, SPC  ,   TAB  ,EN_RAI \
//                            `-------------' `-------------'
),

[RAISE] = LAYOUT_kc( \
//,-----------------------------------------. ,-----------------------------------------.
    BSPC , 1    , 2    , 3    , 4    , 5    ,   6    , 7    , 8    , 9    , 0    , EQL  , \
//|------+------+------+------+------+------| |------+------+------+------+------+------|
    ____ , ____ , ____ , LCBR , LPRN , LBRC ,   RBRC , RPRN , RCBR , ____ , PIPE , PLUS , \
//|------+------+------+------+------+------| |------+------+------+------+------+------|
    ____ , EXLM , AT   , HASH , DLR  , PERC ,   CIRC , AMPR , ASTR , ____ , ____ , BSLS , \
//`------+------+------+------+------+------| |------+------+------+------+------+------'
                               L2_ALT,L1_FN ,   MCRW , ____ \
//                            `-------------' `------------'
),

[FUNCTION] = LAYOUT_kc( \
//,-----------------------------------------. ,-----------------------------------------.
    ____ , F1   , F2   , F3   , F4   , F5   ,   F6   , F7   , F8   , F9   , PSCR , ____ , \
//|------+------+------+------+------+------| |------+------+------+------+------+------|
    ____ , TOGG , H_UP , S_UP , V_UP , LGUI ,   HOME , PGDN , PGUP , END  , ____ , ____ , \
//|------+------+------+------+------+------| |------+------+------+------+------+------|
    ____ , MODE , H_DN , S_DN , V_DN , ____ ,   ____ , ____ , ____ , ____ , ____ , ____ , \
//`------+------+------+------+------+------| |------+------+------+------+------+------'
                                RST  , ____ ,   ____ , ____ \
//                            `-------------' `------------'
),

[MOUSE] = LAYOUT_kc( \
//,-----------------------------------------. ,-----------------------------------------.
    ____ , ____ , ____ , ____ , ____ , ____ ,   ____ , ____ , ____ , ____ , ____ , ____ , \
//|------+------+------+------+------+------| |------+------+------+------+------+------|
    ____ , ____ , WEEL , ____ , ACCL , ____ ,   MLFT , MDN  , MUP  , MRGT , ____ , ____ , \
//|------+------+------+------+------+------| |------+------+------+------+------+------|
    ____ , ____ , ____ , ____ , ____ , ____ ,   ____ , ____ , ____ , ____ , ____ , ____ , \
//`------+------+------+------+------+------| |------+------+------+------+------+------'
                                BTN2 , BTN1 ,   ____ , ____ \
//                            `-------------' `------------'
),

[WHEEL] = LAYOUT_kc( \
//,-----------------------------------------. ,-----------------------------------------.
    ____ , ____ , ____ , ____ , ____ , ____ ,   ____ , ____ , ____ , ____ , ____ , ____ , \
//|------+------+------+------+------+------| |------+------+------+------+------+------|
    ____ , ____ , ____ , ____ , ACCL , ____ ,   WRGT , WUP  , WDN  , WLFT , ____ , ____ , \
//|------+------+------+------+------+------| |------+------+------+------+------+------|
    ____ , ____ , ____ , ____ , ____ , ____ ,   ____ , ____ , ____ , ____ , ____ , ____ , \
//`------+------+------+------+------+------| |------+------+------+------+------+------'
                                ____ , ____ ,   ____ , ____ \
//                            `-------------' `------------'
),

[CURSOR] = LAYOUT_kc( \
//,-----------------------------------------. ,-----------------------------------------.
    ____ , ____ , ____ , ____ , ____ , ____ ,   ____ , ____ , ____ , ____ , ____ , ____ , \
//|------+------+------+------+------+------| |------+------+------+------+------+------|
    ____ , ____ , ____ , MOUSE, ____ , ____ ,   LEFT , DOWN , UP   , RGHT , ____ , ____ , \
//|------+------+------+------+------+------| |------+------+------+------+------+------|
    ____ , ____ , ____ , ____ , ____ , ____ ,   ____ , ____ , ____ , ____ , ____ , ____ , \
//`------+------+------+------+------+------| |------+------+------+------+------+------'
                                ____ , ____ ,   ____ , ____ \
//                            `-------------' `------------'
),

[MICROWRITER] = LAYOUT_kc( \
//,-----------------------------------------. ,-----------------------------------------.
    ____ , ____ , ____ , ____ , ____ , ____ ,   ____ , ____ , ____ , ____ , ____ , ____ , \
//|------+------+------+------+------+------| |------+------+------+------+------+------|
    ____ , ____ , ____ , ____ , ____ , ____ ,   ____ , MW_2 , MW_3 , MW_4 , MW_5 , ____ , \
//|------+------+------+------+------+------| |------+------+------+------+------+------|
    ____ , ____ , ____ , ____ , ____ , ____ ,   ____ , ____ , ____ , ____ , ____ , ____ , \
//`------+------+------+------+------+------| |------+------+------+------+------+------'
                                ____ , BASE ,   MW_1 , MW_0 \
//                            `-------------' `------------'
),

};

int rotation = 0;

void matrix_scan_user (void) {
    static uint32_t last_layer_state = ~0;

    if (layer_state != last_layer_state) {
        if (LAYER_ON(MICROWRITER)) {
            rgb_matrix_sethsv_noeeprom(
                rgb_matrix_config.hsv.h + 60,
                rgb_matrix_config.hsv.s,
                rgb_matrix_config.hsv.v
            );
            rotation += 60;
        } else {
            rgb_matrix_sethsv_noeeprom(
                rgb_matrix_config.hsv.h - rotation,
                rgb_matrix_config.hsv.s,
                rgb_matrix_config.hsv.v
            );
            rotation = 0;
        }
        last_layer_state = layer_state;
    }
}

void keyboard_post_init_user () {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE);
    rgb_matrix_sethsv_noeeprom(20, 190, rgb_matrix_config.hsv.v);
    /* rgb_matrix_sethsv_noeeprom(128, 40, rgb_matrix_config.hsv.v); */
}

bool process_record_keymap (uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
      case KC_MW_0:
        return process_microwriter(MW_FUNCTION, record);
      case KC_MW_1:
        return process_microwriter(MW_THUMB, record);
      case KC_MW_2:
        return process_microwriter(MW_INDEX, record);
      case KC_MW_3:
        return process_microwriter(MW_MIDDLE, record);
      case KC_MW_4:
        return process_microwriter(MW_RING, record);
      case KC_MW_5:
        return process_microwriter(MW_PINKY, record);
    }
    return true;
}
