#include QMK_KEYBOARD_H

extern uint8_t is_master;

/* GLOBAL VARS */

#define BASE      0
#define RAISE     1
#define FUNCTION  2
#define GARAKE    3
#define GARARAISE 4
#define TENKEY    5
#define MOUSE     6
#define WHEEL     7

#define L_BASE      0
#define L_RAISE     (2 << (RAISE - 1))
#define L_FUNCTION  (2 << (FUNCTION - 1))
#define L_GARAKE    (2 << (GARAKE - 1))
#define L_GARARAISE (2 << (GARARAISE - 1))
#define L_TENKEY    (2 << (TENKEY - 1))
#define L_MOUSE     (2 << (MOUSE - 1))
#define L_WHEEL     (2 << (WHEEL - 1))

/* FEATURES */

#ifdef RGBLIGHT_ENABLE
#include "./rgb.c"
#endif
#ifdef TAP_DANCE_ENABLE
#include "dance.c"
#endif

/* KEYCODE DEFINITIONS */

enum custom_keycodes {
  KC_ACEL = SAFE_RANGE,
  KC_WEEL
};

#define KC_____ KC_TRNS
#define KC_XXXX KC_NO

#define KC_D_MOUS  LT(MOUSE, KC_D)
#define KC_L1_RAI  LT(RAISE, KC_LANG1)
#define KC_ESC_FN  LT(FUNCTION, KC_ESC)
#define KC_L2_ALT  LALT_T(KC_LANG2)
#define KC_BASE    TO(BASE)
#define KC_GARAKE  TG(GARAKE)
#define KC_TENKEY  TG(TENKEY)
#define KC_ALT_EN  LALT_T(KC_ENT)
#define KC_CTL_TB  LCTL_T(KC_TAB)

#ifdef TAP_DANCE_ENABLE
#define KC_GK1     TD(TD_GARAKE1)
#define KC_GK2     TD(TD_GARAKE2)
#define KC_GK3     TD(TD_GARAKE3)
#define KC_GK4     TD(TD_GARAKE4)
#define KC_GK5     TD(TD_GARAKE5)
#define KC_GK6     TD(TD_GARAKE6)
#define KC_GK7     TD(TD_GARAKE7)
#define KC_GK8     TD(TD_GARAKE8)
#define KC_GK9     TD(TD_GARAKE9)
#define KC_GK0_RA  TD(TD_GARAKE0_RAISE)
#define KC_CTL_L1  TD(TD_CTL_LANG1)
#define KC_SFT_L2  TD(TD_SFT_LANG2)
#else
#define KC_GK1     KC_1
#define KC_GK2     KC_2
#define KC_GK3     KC_3
#define KC_GK4     KC_4
#define KC_GK5     KC_5
#define KC_GK6     KC_6
#define KC_GK7     KC_7
#define KC_GK8     KC_8
#define KC_GK9     KC_9
#define KC_GK0_RA  LT(RAISE, KC_0)
#define KC_CTL_L1  LCTL_T(KC_LANG1)
#define KC_SFT_L2  LSFT_T(KC_LANG2)
#endif

#define KC_RST  RESET
#define KC_MUP  KC_MS_U
#define KC_MDN  KC_MS_D
#define KC_MLFT KC_MS_L
#define KC_MRGT KC_MS_R
#define KC_WUP  KC_WH_U
#define KC_WDN  KC_WH_D
#define KC_WLFT KC_WH_L
#define KC_WRGT KC_WH_R

/* KEYMAPS */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[BASE] = LAYOUT_kc( \
//,-----------------------------------------. ,-----------------------------------------.
    JYEN , Q    , W    , E    , R    , T    ,   Y    , U    , I    , O    , P    , MINS , \
//|------+------+------+------+------+------| |------+------+------+------+------+------|
    LCTL , A    , S    ,D_MOUS, F    , G    ,   H    , J    , K    , L    , SCLN , QUOT , \
//|------+------+------+------+------+------| |------+------+------+------+------+------|
    LSFT , Z    , X    , C    , V    , B    ,   B    , N    , M    , COMM , DOT  , SLSH , \
//`------+------+------+------+------+------| |------+------+------+------+------+------'
                        L2_ALT, SPC  ,ESC_FN,   TAB  , ENT  ,L1_RAI \
//                     `--------------------' `--------------------'
),

[RAISE] = LAYOUT_kc( \
//,-----------------------------------------. ,-----------------------------------------.
    BSPC , 1    , 2    , 3    , 4    , 5    ,   6    , 7    , 8    , 9    , 0    , EQL  , \
//|------+------+------+------+------+------| |------+------+------+------+------+------|
    ____ , ____ , BSLS , LCBR , LPRN , LBRC ,   RBRC , RPRN , RCBR , PIPE , UP   , PLUS , \
//|------+------+------+------+------+------| |------+------+------+------+------+------|
    ____ , EXLM , AT   , HASH , DLR  , PERC ,   CIRC , AMPR , ASTR , LEFT , DOWN , RGHT , \
//`------+------+------+------+------+------| |------+------+------+------+------+------'
                         ____ , ____ , RST  ,  GARAKE, ____ , XXXX  \
//                     `--------------------' `--------------------'
),

[FUNCTION] = LAYOUT_kc( \
//,-----------------------------------------. ,-----------------------------------------.
    ____ , F1   , F2   , F3   , F4   , F5   ,   F6   , F7   , F8   , F9   , PSCR , ____ , \
//|------+------+------+------+------+------| |------+------+------+------+------+------|
    ____ , ____ , ____ , ____ , ____ , LGUI ,   ____ , ____ , ____ , ____ , PGUP , ____ , \
//|------+------+------+------+------+------| |------+------+------+------+------+------|
    ____ , ____ , ____ , ____ , ____ , ____ ,   ____ , ____ , ____ , HOME , PGDN , END , \
//`------+------+------+------+------+------| |------+------+------+------+------+------'
                         ____ , ____ , XXXX ,   ____ , ____ , ____  \
//                     `--------------------' `--------------------'
),

[GARAKE] = LAYOUT_kc( \
//,-----------------------------------------. ,-----------------------------------------.
    ____ , ____ , ____ , ____ , ____ , ____ ,   ESC  , GK7  , GK8  , GK9  , BSPC , MINS , \
//|------+------+------+------+------+------| |------+------+------+------+------+------|
    ____ , ____ , ____ , ____ , ____ , ____ ,  CTL_TB, GK4  , GK5  , GK6  , SCLN , QUOT , \
//|------+------+------+------+------+------| |------+------+------+------+------+------|
    ____ , ____ , ____ , ____ , ____ , ____ ,   LSFT , GK1  , GK2  , GK3  , DOT  , SLSH , \
//`------+------+------+------+------+------| |------+------+------+------+------+------'
                         ____ , ____ , BASE ,   SPC  ,ALT_EN,GK0_RA\
//                     `--------------------' `--------------------'
),

[GARARAISE] = LAYOUT_kc( \
//,-----------------------------------------. ,-----------------------------------------.
    ____ , ____ , ____ , ____ , ____ , ____ ,  TENKEY, BTN1 , MUP  , BTN2 , ____ , EQL  , \
//|------+------+------+------+------+------| |------+------+------+------+------+------|
    ____ , ____ , ____ , ____ , ____ , ____ ,  CTL_L1, MLFT , MDN  , MRGT , UP   , PLUS , \
//|------+------+------+------+------+------| |------+------+------+------+------+------|
    ____ , ____ , ____ , ____ , ____ , ____ ,  SFT_L2, WUP  , WDN  , LEFT , DOWN , RGHT , \
//`------+------+------+------+------+------| |------+------+------+------+------+------'
                         ____ , ____ , ____ ,   ____ , ____ , XXXX  \
//                     `--------------------' `--------------------'
),

[TENKEY] = LAYOUT_kc( \
//,-----------------------------------------. ,-----------------------------------------.
    ____ , ____ , ____ , ____ , ____ , ____ ,   ____ , 7    , 8    , 9    , ____ , ____ , \
//|------+------+------+------+------+------| |------+------+------+------+------+------|
    ____ , ____ , ____ , ____ , ____ , ____ ,   ____ , 4    , 5    , 6    , ____ , ____ , \
//|------+------+------+------+------+------| |------+------+------+------+------+------|
    ____ , ____ , ____ , ____ , ____ , ____ ,   ____ , 1    , 2    , 3    , ____ , ____ , \
//`------+------+------+------+------+------| |------+------+------+------+------+------'
                         ____ , ____ , ____ ,   ____ , 0    , ____ \
//                     `--------------------' `--------------------'
),

[MOUSE] = LAYOUT_kc( \
//,-----------------------------------------. ,-----------------------------------------.
    ____ , ____ , ____ , ____ , ____ , ____ ,   ____ , ____ , ____ , ____ , ____ , ____ , \
//|------+------+------+------+------+------| |------+------+------+------+------+------|
    ____ , ____ , WEEL , ____ , ACEL , ____ ,   MLFT , MDN  , MUP  , MRGT , ____ , ____ , \
//|------+------+------+------+------+------| |------+------+------+------+------+------|
    ____ , ____ , ____ , ____ , BTN1 , BTN2 ,   ____ , ____ , ____ , ____ , ____ , ____ , \
//`------+------+------+------+------+------| |------+------+------+------+------+------'
                         ____ , ____ , ____ ,   ____ , ____ , ____  \
//                     `--------------------' `--------------------'
),

[WHEEL] = LAYOUT_kc( \
//,-----------------------------------------. ,-----------------------------------------.
    ____ , ____ , ____ , ____ , ____ , ____ ,   ____ , ____ , ____ , ____ , ____ , ____ , \
//|------+------+------+------+------+------| |------+------+------+------+------+------|
    ____ , ____ , ____ , ____ , ____ , ____ ,   WRGT , WUP  , WDN  , WLFT , ____ , ____ , \
//|------+------+------+------+------+------| |------+------+------+------+------+------|
    ____ , ____ , ____ , ____ , ____ , ____ ,   ____ , ____ , ____ , ____ , ____ , ____ , \
//`------+------+------+------+------+------| |------+------+------+------+------+------'
                         ____ , ____ , ____ ,   ____ , ____ , ____  \
//                     `--------------------' `--------------------'
),

};

/* USER TASKS */

void matrix_scan_user (void) {
  #ifdef RGBLIGHT_ENABLE
    rgb_update(false);
  #endif
}

void keybaord_post_init_user (void) {
  #ifdef RGBLIGHT_ENABLE
    rgb_update(false);
  #endif
}

extern uint8_t mk_time_to_max, mk_wheel_time_to_max, mk_max_speed, mk_wheel_max_speed, mk_delay, mk_interval;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  #ifdef RGBLIGHT_ENABLE
    rgb_process_record(keycode, record);
  #endif
    switch (keycode) {
     case KC_ACEL:
      if (record->event.pressed) {
        mk_max_speed = MOUSEKEY_ACL_MAX_SPEED;
        mk_wheel_max_speed = MOUSEKEY_ACL_WHEEL_MAX_SPEED;
        mk_time_to_max = 0;
        mk_wheel_time_to_max = 0;
      } else {
        mk_max_speed = MOUSEKEY_MAX_SPEED;
        mk_wheel_max_speed = MOUSEKEY_WHEEL_MAX_SPEED;
        mk_time_to_max = MOUSEKEY_TIME_TO_MAX;
        mk_wheel_time_to_max = MOUSEKEY_WHEEL_TIME_TO_MAX;
      }
      return false;
     case KC_WEEL:
      if (record->event.pressed) {
        mk_delay = MOUSEKEY_WHEEL_DELAY / 10;
        mk_interval = MOUSEKEY_WHEEL_INTERVAL;
        layer_on(WHEEL);
      } else {
        mk_delay = MOUSEKEY_DELAY / 10;
        mk_interval = MOUSEKEY_INTERVAL;
        layer_off(WHEEL);
      }
      return false;
    }
    return true;
}
