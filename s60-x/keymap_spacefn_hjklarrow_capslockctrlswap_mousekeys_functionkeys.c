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
│CAPSL│L_GUI│L_ALT│█████│█████│█████Spc/Fn0█████│█████│█████│R_ALT│ FN3 │ APP │RCTRL│█████│
└─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
     */
    KEYMAP(
   ESC,    1,    2,    3,    4,    5,    6,    7,    8,    9,    0, MINS,  EQL,   NO, BSPC, \
   TAB,    Q,    W,    E,    R,    T,    Y,    U,    I,    O,    P, LBRC, RBRC, BSLS,       \
  LCTL,  FN2,    S,    D,    F,    G,    H,    J,    K,    L,  FN6, QUOT,   NO,  ENT, \
  LSFT,   NO,    Z,    X,    C,    V,    B,    N,    M, COMM,  DOT, SLSH,   NO, RSFT,   NO, \
  CAPS, LGUI, LALT,                    FN0,                   RALT,  FN3,  APP, RCTL),

    /* Overlay 1: SpaceFN
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│  `  │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │▒▒▒▒▒│ Del │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│     │     │     │ Esc │     │     │     │Home │     │ End │Pscr │Slck │Pause│ Ins │█████│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│     │     │ F13 │PgDwn│PgUp │     │Left │Down │ Up  │Right│     │     │▒▒▒▒▒│     │█████│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│     │▒▒▒▒▒│     │     │     │Space│     │  `  │  ~  │     │     │     │▒▒▒▒▒│     │▒▒▒▒▒│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│     │     │     │█████│█████│█████│     │█████│█████│█████│     │     │     │     │█████│
└─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
     */
    KEYMAP(
	 GRV,   F1,   F2,   F3,   F4,   F5,   F6,   F7,   F8,   F9,  F10,  F11,  F12, TRNS,  DEL, \
  TRNS, TRNS, TRNS,  ESC, TRNS, TRNS, TRNS, HOME, TRNS,  END, PSCR, SLCK, PAUS,  INS,       \
	TRNS, TRNS,  F13, PGDN, PGUP, TRNS, LEFT, DOWN,   UP, RGHT, TRNS, TRNS, TRNS, TRNS,       \
	TRNS, TRNS, TRNS, TRNS, TRNS,  SPC, TRNS,  GRV,  FN1, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
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

    /* Keymap 3: Qwerty with swapped caps and control keys Layer
       This is mainly to allow a layout that treats "a" and spacebar like a regular keyboard, for gaming.
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│ ESC │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │  -  │  =  │▒▒▒▒▒│BKSPC│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│ TAB │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │  [  │  ]  │  \  │█████│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│LCTRL│  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │  '  │▒▒▒▒▒│ENTER│█████│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│LSHFT│▒▒▒▒▒│  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │▒▒▒▒▒│RSHFT│▒▒▒▒▒│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│CAPSL│L_GUI│L_ALT│█████│█████│█████│ SPC │█████│█████│█████│R_ALT│ FN3 │ APP │RCTRL│█████│
└─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
*/
    KEYMAP(
   ESC,    1,    2,    3,    4,    5,    6,    7,    8,    9,    0, MINS,  EQL,   NO, BSPC, \
   TAB,    Q,    W,    E,    R,    T,    Y,    U,    I,    O,    P, LBRC, RBRC, BSLS,       \
  LCTL,    A,    S,    D,    F,    G,    H,    J,    K,    L, SCLN, QUOT,   NO, ENT ,       \
  LSFT,   NO,    Z,    X,    C,    V,    B,    N,    M, COMM,  DOT, SLSH,   NO, RSFT,   NO, \
  CAPS, LGUI, LALT,                    SPC,                   RALT,  FN3,  APP, RCTL),

    /* Overlay 4: Layout selector
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│     │     │     │     │     │     │     │     │     │     │     │     │     │▒▒▒▒▒│     │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│     │ lq  │     │     │     │     │     │     │     │     │     │     │     │     │█████│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│     │     │     │ ld  │     │     │     │     │     │     │     │     │▒▒▒▒▒│     │█████│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│     │▒▒▒▒▒│     │     │     │     │     │     │     │     │     │     │▒▒▒▒▒│     │▒▒▒▒▒│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│     │     │     │█████│█████│█████│     │█████│█████│█████│     │ FN3 │     │     │█████│
└─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
     * Lq: set Qwerty layout
     * Ld: set SpaceFN layout
     */
    KEYMAP(
  TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
  TRNS,  FN4, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       \
	TRNS, TRNS, TRNS,  FN5, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       \
	TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
	TRNS, TRNS, TRNS,                   TRNS,                   TRNS, TRNS, TRNS, TRNS),
    /* Overlay 5: Extended function keys

       Emperically found bindings on Ubuntu:
         Physical key  C symbol:   keycode  xev reports:         
         ------------  ----------  -------  -------------------- 
         TAB           F13         191      XF86Tools
         Q             F14         192      XF67Launch5
         W             F15         193      XF67Launch6
         E             F16         194      XF67Launch7
         R             F17         195      XF67Launch8
         T             F18         196      XF67Launch9
         Y             F19         197      NoSymbol
         U             F20         198      XF86AudioMicMute
         I             F21         199      XF86TouchpadToggle
         O             F22         200      XF86TouchpadOn
         P             F23         201      XF86TouchpadOff
         [             F24         202      NoSymbol

┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│     │     │     │     │     │     │     │     │     │     │     │     │     │▒▒▒▒▒│     │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│ F13 │ F14 │ F15 │ F16 │ F17 │ F18 │ F19 │ F20 │ F21 │ F22 │ F23 │ F24 │     │     │█████│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│     │     |     |     |     |     |     |     |     |     |     |     │▒▒▒▒▒│     │█████│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│LSFHT│▒▒▒▒▒│     │     │     │     │     │     │     │     │     │     │▒▒▒▒▒│RSHFT│▒▒▒▒▒│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│LCTRL│L_GUI│L_ALT│█████│█████│█████│ Mb1 │█████│█████│█████│     │     │     │RCTRL│█████│
└─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
     */
    KEYMAP(
  TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
   F13,  F14,  F15,  F16,  F17,  F18,  F19,  F20,  F21,  F22,  F23,  F24, TRNS, TRNS, \
  TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,  TRNS, TRNS, TRNS,  ENT, \
	TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
	TRNS, TRNS, TRNS,                   TRNS,                   TRNS, TRNS, TRNS, TRNS),


    // KC_F25 - KC_F35 are not defined in tmk. They are defined in /usr/include/X11/keysymdef.h though:
#if 0
    KEYMAP(
  TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
   F13,  F14,  F15,  F16,  F17,  F18,  F19,  F20,  F21,  F22,  F23,  F24,  F25,  F26, \
  TRNS,  F27,  F28,  F29,  F30,  F31,  F32,  F33,  F34,  F35,  TRNS, TRNS, TRNS,  ENT, \
	TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
	TRNS, TRNS, TRNS,                   TRNS,                   TRNS, TRNS, TRNS, TRNS),
#endif

};

/*
 * Fn action definition
 */
const action_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_TAP_KEY(1, KC_SPACE),    // Holding down FN0 switches to spacefn layer, tapping FN0 produces a "Space"
    [1] = ACTION_MODS_KEY(MOD_LSFT, KC_GRV),    // FN1 acts as if shift-grv occurred, yielding a tilde.
    [2] = ACTION_LAYER_TAP_KEY(2, KC_A),        // Holding down FN2 switches to mouse keys layer, tapping FN2 produces an "A"
    [3] = ACTION_LAYER_MOMENTARY(4),            // Holding down FN3 switches to layout selector layer
    [4] = ACTION_DEFAULT_LAYER_SET(3),          // Switch to qwerty layout
    [5] = ACTION_DEFAULT_LAYER_SET(0),          // Switch to default layout
    [6] = ACTION_LAYER_TAP_KEY(5, KC_SCLN),     // Holding down FN6 switches to extended functions keys layer, tapping FN6 produces an ";"
}; 
