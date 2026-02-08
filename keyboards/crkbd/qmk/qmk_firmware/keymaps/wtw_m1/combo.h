#define CASE_COMBO_TAP(combo, key) \
    case combo: \
        if (pressed) { \
            register_code16(key); \
        } else { \
            unregister_code16(key); \
        } \
        return;

const uint16_t PROGMEM combo_WE[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM combo_ER[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM combo_RT[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM combo_WR[] = {KC_W, KC_R, COMBO_END};
const uint16_t PROGMEM combo_WER[] = {KC_W, KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM combo_TG[] = {KC_T, KC_G, COMBO_END};
const uint16_t PROGMEM combo_GB[] = {KC_G, KC_B, COMBO_END};
const uint16_t PROGMEM combo_RF[] = {KC_R, KC_F, COMBO_END};

const uint16_t PROGMEM combo_FG[] = {KC_F, KC_G, COMBO_END};

const uint16_t PROGMEM combo_XC[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM combo_CV[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM combo_VB[] = {KC_V, KC_B, COMBO_END};



const uint16_t PROGMEM combo_YU[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM combo_UI[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM combo_IO[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM combo_UO[] = {KC_U, KC_O, COMBO_END};
const uint16_t PROGMEM combo_UIO[] = {KC_U, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM combo_YH[] = {KC_Y, KC_H, COMBO_END};
const uint16_t PROGMEM combo_HN[] = {KC_H, KC_N, COMBO_END};
const uint16_t PROGMEM combo_UJ[] = {KC_U, KC_J, COMBO_END};

const uint16_t PROGMEM combo_HJ[] = {KC_H, KC_J, COMBO_END};

const uint16_t PROGMEM combo_NM[] = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM combo_MCOMMA[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM combo_COMMADOT[] = {KC_COMM, KC_DOT, COMBO_END};

const uint16_t PROGMEM combo_SDF[] = {KC_S, KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM combo_JKL[] = {KC_J, KC_K, KC_L, COMBO_END};

enum combo_events {
    WE,
    ER,
    RT,
    WR,
    WER,
    TG,
    GB,
    RF,

    FG,

    XC,
    CV,
    VB,

    YU,
    UI,
    IO,
    UO,
    UIO,
    YH,
    HN,
    UJ,

    HJ,

    NM,
    MCOMMA,
    COMMADOT,

    SDF,
    JKL,
};

combo_t key_combos[] = {
    [WE] = COMBO_ACTION(combo_WE),
    [ER] = COMBO_ACTION(combo_ER),
    [RT] = COMBO_ACTION(combo_RT),
    [WR] = COMBO_ACTION(combo_WR),
    [WER] = COMBO_ACTION(combo_WER),
    [TG] = COMBO_ACTION(combo_TG),
    [GB] = COMBO_ACTION(combo_GB),
    [RF] = COMBO_ACTION(combo_RF),

    [FG] = COMBO_ACTION(combo_FG),

    [XC] = COMBO_ACTION(combo_XC),
    [CV] = COMBO_ACTION(combo_CV),
    [VB] = COMBO_ACTION(combo_VB),

    [YU] = COMBO_ACTION(combo_YU),
    [UI] = COMBO_ACTION(combo_UI),
    [IO] = COMBO_ACTION(combo_IO),
    [UO] = COMBO_ACTION(combo_UO),
    [UIO] = COMBO_ACTION(combo_UIO),
    [YH] = COMBO_ACTION(combo_YH),
    [HN] = COMBO_ACTION(combo_HN),
    [UJ] = COMBO_ACTION(combo_UJ),

    [HJ] = COMBO_ACTION(combo_HJ),

    [NM] = COMBO_ACTION(combo_NM),
    [MCOMMA] = COMBO_ACTION(combo_MCOMMA),
    [COMMADOT] = COMBO_ACTION(combo_COMMADOT),

    [SDF] = COMBO_ACTION(combo_SDF),
    [JKL] = COMBO_ACTION(combo_JKL),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
        CASE_COMBO_TAP(WE, KC_PLUS)
        CASE_COMBO_TAP(ER, KC_MINS)
        CASE_COMBO_TAP(RT, KC_LPRN)
        CASE_COMBO_TAP(WR, KC_UNDS)
        CASE_COMBO_TAP(WER, KC_EQL)
        CASE_COMBO_TAP(TG, KC_ASTR)
        CASE_COMBO_TAP(RF, KC_HASH)
        CASE_COMBO_TAP(GB, KC_EXLM)
        CASE_COMBO_TAP(CV, KC_BSLS)

        CASE_COMBO_TAP(FG, KC_LBRC)

        CASE_COMBO_TAP(VB, KC_LCBR)

        CASE_COMBO_TAP(YU, KC_RPRN)
        CASE_COMBO_TAP(UI, KC_QUOT)
        CASE_COMBO_TAP(IO, KC_DQUO)
        CASE_COMBO_TAP(UO, KC_GRV)
        CASE_COMBO_TAP(UIO, KC_TILD)
        CASE_COMBO_TAP(YH, KC_AMPR)
        CASE_COMBO_TAP(HN, KC_AT)
        CASE_COMBO_TAP(UJ, KC_DLR)
        CASE_COMBO_TAP(MCOMMA, KC_PIPE)

        CASE_COMBO_TAP(HJ, KC_RBRC)

        CASE_COMBO_TAP(NM, KC_RCBR)

        CASE_COMBO_TAP(SDF, LGUI(KC_SPC))
        CASE_COMBO_TAP(JKL, LGUI(KC_SPC))
    }
}
