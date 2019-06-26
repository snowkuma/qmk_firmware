// These definitions are for convenience.
// It is not wise to put sensitive information here such as passwords
// as anyone with access to your keyboard will be able to use them!

// magnet keycodes
#define M_LEFT LCA(KC_LEFT)
#define M_TOP LCA(KC_UP)
#define M_BOTT LCA(KC_DOWN)
#define M_RGHT LCA(KC_RGHT)

#define M_TOPL LCA(KC_U)
#define M_TOPR LCA(KC_I)
#define M_BOTL LCA(KC_J)
#define M_BOTR LCA(KC_K)

#define M_L13 LCA(KC_D)
#define M_L23 LCA(KC_E)
#define M_C13 LCA(KC_F)
#define M_R23 LCA(KC_T)
#define M_R13 LCA(KC_G)

#define M_NEXT LCAG(KC_RGHT)
#define M_PREV LCAG(KC_LEFT)

#define M_MAX LCA(KC_ENT)
#define M_CEN LCA(KC_C)
#define M_REST LCA(KC_BSPC)

// Shortcuts
#define INPUT_L LCAG(KC_SPC)
#define TXT_PLS LGUI(KC_PLUS)
#define TXT_MIN LGUI(KC_MINS)
 
// Convenience Keycodes
#define ___x___ KC_NO
#define ___f___ KC_TRNS

// Special Layer keycodes
#define ESC_NUM LT(_NUMBER, KC_ESC)
#define BSP_REG LT(_REGEX, KC_BSPC)
#define MIN_ARR LT(_ARRANGE, KC_MINS)
#define TAB_SFT LSFT_T(KC_TAB)
#define SPC_SYM LT(_SYMBOL, KC_SPC)
#define ENT_THU LT(_THUMB, KC_ENT)

#define FUN_L MO(_FUNCTION)
// HOMEROW SHIFT
#define T_SFT LSFT_T(KC_T)
#define N_SFT RSFT_T(KC_N)
#define A_SFT LSFT_T(S(KC_A))

// Special Characters
#define GBP LALT(KC_3)
#define EURO LALT(S(KC_2))

// Modifier tap holds
#define Q_CTL LCTL_T(KC_Q)
#define W_ALT LALT_T(KC_W)
#define F_GUI LGUI_T(KC_F)
#define U_GUI LGUI_T(KC_U)
#define Y_ALT LALT_T(KC_Y)
#define SCL_CTL LCTL_T(KC_SCLN)

#define GT_SFT LSFT_T(KC_GT)

#define F_ALT LALT_T(KC_F)
#define E_GUI LGUI_T(KC_E)
#define YEN 0x00A5
#define YEN_CTL LCTL_T(UC(YEN))
