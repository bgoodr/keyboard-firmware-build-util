#include "keymap_common.h" 

/*
 * SpaceFN
 * http://geekhack.org/index.php?topic=51069.0
 */
const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap 0: Default Layer
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│ ESC │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │  -  │  =  │▒▒▒▒▒│BKSPC│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│ TAB │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │  [  │  ]  │  \  │█████│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│LCTRL│ FN2 │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │  '  │▒▒▒▒▒│ENTER│█████│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│LSHFT│▒▒▒▒▒│  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │▒▒▒▒▒│RSHFT│▒▒▒▒▒│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│CAPSL│L_GUI│L_ALT│█████│█████│█████Spc/Fn0█████│█████│█████│R_ALT│R_GUI│ APP │RCTRL│█████│
└─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
     */
    KEYMAP(
   ESC,    1,    2,    3,    4,    5,    6,    7,    8,    9,    0, MINS,  EQL,   NO, BSPC, \
   TAB,    Q,    W,    E,    R,    T,    Y,    U,    I,    O,    P, LBRC, RBRC, BSLS,       \
  LCTL,  FN2,    S,    D,    F,    G,    H,    J,    K,    L, SCLN, QUOT,   NO,  ENT,       \
  LSFT,   NO,    Z,    X,    C,    V,    B,    N,    M, COMM,  DOT, SLSH,   NO, RSFT,   NO, \
  CAPS, LGUI, LALT,                    FN0,                   RALT, RGUI,  APP, RCTL),

    /* Overlay 1: SpaceFN
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│  `  │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │▒▒▒▒▒│ Del │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│     │     │     │ Esc │     │     │     │Home │ Up  │ End │Pscr │Slck │Pause│ Ins │█████│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│     │     │     │     │     │     │PgUp │Left │Down │Right│     │     │▒▒▒▒▒│     │█████│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│     │▒▒▒▒▒│     │     │     │Space│PgDwn│  `  │  ~  │     │     │     │▒▒▒▒▒│     │▒▒▒▒▒│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│     │     │     │█████│█████│█████│     │█████│█████│█████│     │     │     │     │█████│
└─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
     */
    KEYMAP(
	 GRV,   F1,   F2,   F3,   F4,   F5,   F6,   F7,   F8,   F9,  F10,  F11,  F12, TRNS,  DEL, \
  TRNS, TRNS, TRNS,  ESC, TRNS, TRNS, TRNS, HOME,   UP,  END, PSCR, SLCK, PAUS,  INS,       \
	TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, PGUP, LEFT, DOWN, RGHT, TRNS, TRNS, TRNS, TRNS,       \
	TRNS, TRNS, TRNS, TRNS, TRNS,  SPC, PGDN,  GRV,  FN1, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
	TRNS, TRNS, TRNS,                   TRNS,                   TRNS, TRNS, TRNS, TRNS),
    /* Overlay 2: Mouse mode (Semicolon/App)
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│Grave│ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │▒▒▒▒▒│BkSpc│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│ Tab │     │     │     │     │     │ MwL │ MwD │ MwU │ MwR │     │     │     │     │█████│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│LCTRL│     │ Ac0 │ Ac1 │ Ac2 │     │ McL │ McD │ McU │ McR │ Mb3 │     │▒▒▒▒▒│Enter│█████│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│LSFHT│▒▒▒▒▒│     │     │     │     │     │ Mb2 │ Mb1 │ Mb4 │ Mb5 │     │▒▒▒▒▒│RSHFT│▒▒▒▒▒│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│LCTRL│L_GUI│L_ALT│█████│█████│█████│ Mb1 │█████│█████│█████│     │     │     │RCTRL│█████│
└─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
     * Mc: Mouse Cursor / Mb: Mouse Button / Mw: Mouse Wheel
     */
    KEYMAP(
  TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
   TAB, TRNS, TRNS, TRNS, TRNS, TRNS, WH_L, WH_D, WH_U, WH_R, TRNS, TRNS, TRNS, TRNS,       \
  LCTL, TRNS, ACL0, ACL1, ACL2, TRNS, MS_L, MS_D, MS_U, MS_R, BTN2, TRNS, TRNS,  ENT,       \
  LSFT, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, BTN3, BTN1, BTN4, BTN5, TRNS, TRNS, RSFT, TRNS, \
  LCTL, LGUI, LALT,                   BTN1,                   TRNS, TRNS, TRNS, RCTL),
 /*
  * Hack: For some reason not yet understood, on my machine, BTN3 shows up as
  * Button 2 in xev, and BTN2 shows up as Button 3 in xev. Swap them around in
  * the keymap above.
  */
};

/*
 * Fn action definition
 */
const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_TAP_KEY(1, KC_SPACE),    // Holding down FN0 switches to mouse keys layer, tapping FN0 produces a "Space"
    [1] = ACTION_MODS_KEY(MOD_LSFT, KC_GRV),    // FN1 acts as if shift-grv occurred, yielding a tilde.
    [2] = ACTION_LAYER_TAP_KEY(2, KC_A),        // Holding down FN2 switches to mouse keys layer, tapping FN2 produces an "A"
}; 
