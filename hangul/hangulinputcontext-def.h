/* vim:set et sts=4 sw=4 fileencoding=utf-8: */
/* libhangul
 * Copyright (C) 2004 - 2009 Choe Hwanjin
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef libhangul_hangulinputcontext_def_h
#define libhangul_hangulinputcontext_def_h

static const HangulCombination hangul_combination_default_2 = {
    N_ELEMENTS(hangul_combination_table_default_2),
    (HangulCombinationItem*)hangul_combination_table_default_2
};

static const HangulCombination hangul_combination_default_3 = {
    N_ELEMENTS(hangul_combination_table_default_3),
    (HangulCombinationItem*)hangul_combination_table_default_3
};

static const HangulCombination hangul_combination_full = {
    N_ELEMENTS(hangul_combination_table_full),
    (HangulCombinationItem*)hangul_combination_table_full
};

static const HangulCombination hangul_combination_romaja = {
    N_ELEMENTS(hangul_combination_table_romaja),
    (HangulCombinationItem*)hangul_combination_table_romaja
};

static const HangulCombination hangul_combination_ahn = {
    N_ELEMENTS(hangul_combination_table_ahn),
    (HangulCombinationItem*)hangul_combination_table_ahn
};

static const HangulCombination hangul_combination_3moachigi_2014 = {
    N_ELEMENTS(hangul_combination_table_3moachigi_2014),
    (HangulCombinationItem*)hangul_combination_table_3moachigi_2014
};

static const HangulCombination hangul_combination_3_91_noshift = {
    N_ELEMENTS(hangul_combination_table_3_91_noshift),
    (HangulCombinationItem*)hangul_combination_table_3_91_noshift
};


static const HangulKeyboard hangul_keyboard_2 = {
    HANGUL_KEYBOARD_TYPE_JAMO,
    "2", 
    N_("Dubeolsik KSX 5002"), 
    (ucschar*)hangul_keyboard_table_2,
    &hangul_combination_default_2
};

static const HangulKeyboard hangul_keyboard_2noshift = {
    HANGUL_KEYBOARD_TYPE_JAMO,
    "2noshift", 
    N_("Dubeolsik Noshift"), 
    (ucschar*)hangul_keyboard_table_2,
    &hangul_combination_default_2
};

static const HangulKeyboard hangul_keyboard_2y = {
    HANGUL_KEYBOARD_TYPE_JAMO,
    "2y", 
    N_("Dubeolsik Yetgeul"), 
    (ucschar*)hangul_keyboard_table_2y,
    &hangul_combination_full
};

static const HangulKeyboard hangul_keyboard_2north9256 = {
    HANGUL_KEYBOARD_TYPE_JAMO,
    "2n9256", 
    N_("Dubeolsik North 9256"), 
    (ucschar*)hangul_keyboard_table_2north9256,
    &hangul_combination_default_2
};

static const HangulKeyboard hangul_keyboard_32 = {
    HANGUL_KEYBOARD_TYPE_JASO,
    "32",
    N_("Sebeolsik Dubeol Layout"),
    (ucschar*)hangul_keyboard_table_32,
    &hangul_combination_default_2
};

static const HangulKeyboard hangul_keyboard_3_89 = {
    HANGUL_KEYBOARD_TYPE_JASO,
    "3-89",
    N_("Sebeolsik 3-89"),
    (ucschar*)hangul_keyboard_table_3_89,
    &hangul_combination_default_3
};

static const HangulKeyboard hangul_keyboard_3_90 = {
    HANGUL_KEYBOARD_TYPE_JASO,
    "3-90",
    N_("Sebeolsik 3-90"),
    (ucschar*)hangul_keyboard_table_390,
    &hangul_combination_default_3
};

static const HangulKeyboard hangul_keyboard_3_91_final = {
    HANGUL_KEYBOARD_TYPE_JASO,
    "3-91",
    N_("Sebeolsik 3-91 Final"),
    (ucschar*)hangul_keyboard_table_3final,
    &hangul_combination_default_3
};

static const HangulKeyboard hangul_keyboard_3_91_final_noshift = {
    HANGUL_KEYBOARD_TYPE_3FINALSUN,
    "3-91-noshift",
    N_("Sebeolsik 3-91 Final Noshift"),
    (ucschar*)hangul_keyboard_table_3_91_final_noshift,
    &hangul_combination_3_91_noshift
};

static const HangulKeyboard hangul_keyboard_3sun_1990 = {
    HANGUL_KEYBOARD_TYPE_JASO,
    "3sun-1990",
    N_("Sebeolsik Noshift 1990"),
    (ucschar*)hangul_keyboard_table_3sun,
    &hangul_combination_default_3
};

static const HangulKeyboard hangul_keyboard_3_93_yet = {
    HANGUL_KEYBOARD_TYPE_JASO,
    "3-93-yet",
    N_("Sebeolsik 3-93 Yetgeul"),
    (ucschar*)hangul_keyboard_table_3yet,
    &hangul_combination_full
};

static const HangulKeyboard hangul_keyboard_romaja = {
    HANGUL_KEYBOARD_TYPE_ROMAJA,
    "ro",
    N_("Romaja"),
    (ucschar*)hangul_keyboard_table_romaja,
    &hangul_combination_romaja
};

static const HangulKeyboard hangul_keyboard_ahn = {
    HANGUL_KEYBOARD_TYPE_JASO,
    "ahn",
    N_("Ahnmatae"),
    (ucschar*)hangul_keyboard_table_ahn,
    &hangul_combination_ahn
};

static const HangulKeyboard hangul_keyboard_3ahnmatae = {
    HANGUL_KEYBOARD_TYPE_JASO,
    "3ahn",
    N_("Sebeolsik 3Ahnmatae"),
    (ucschar*)hangul_keyboard_table_3ahnmatae,
    &hangul_combination_ahn
};

static const HangulKeyboard hangul_keyboard_3_2011 = {
    HANGUL_KEYBOARD_TYPE_JASO,
    "3-2011",
    N_("Sebeolsik 3-2011"),
    (ucschar*)hangul_keyboard_table_3_2011,
    &hangul_combination_default_3
};

static const HangulKeyboard hangul_keyboard_3_2011_yet = {
    HANGUL_KEYBOARD_TYPE_JASO,
    "3-2011-yet",
    N_("Sebeolsik 3-2011 Yetgeul"),
    (ucschar*)hangul_keyboard_table_3_2011,
    &hangul_combination_full
};

static const HangulKeyboard hangul_keyboard_3_2012 = {
    HANGUL_KEYBOARD_TYPE_JASO,
    "3-2012",
    N_("Sebeolsik 3-2012"),
    (ucschar*)hangul_keyboard_table_3_2012,
    &hangul_combination_default_3
};

static const HangulKeyboard hangul_keyboard_3_2012_yet = {
    HANGUL_KEYBOARD_TYPE_JASO,
    "3-2012-yet",
    N_("Sebeolsik 3-2012 Yetgeul"),
    (ucschar*)hangul_keyboard_table_3_2012,
    &hangul_combination_full
};

static const HangulKeyboard hangul_keyboard_3_2014 = {
    HANGUL_KEYBOARD_TYPE_JASO,
    "3-2014",
    N_("Sebeolsik 3-2014"),
    (ucschar*)hangul_keyboard_table_3_2014,
    &hangul_combination_default_3
};

static const HangulKeyboard hangul_keyboard_3_2014_yet = {
    HANGUL_KEYBOARD_TYPE_JASO,
    "3-2014-yet",
    N_("Sebeolsik 3-2014 Yetguel"),
    (ucschar*)hangul_keyboard_table_3_2014,
    &hangul_combination_full
};

static const HangulKeyboard hangul_keyboard_3_2015 = {
    HANGUL_KEYBOARD_TYPE_JASO,
    "3-2015",
    N_("Sebeolsik 3-2015"),
    (ucschar*)hangul_keyboard_table_3_2015,
    &hangul_combination_default_3
};
 
static const HangulKeyboard hangul_keyboard_3_2015_yet = {
    HANGUL_KEYBOARD_TYPE_JASO,
    "3-2015-yet",
    N_("Sebeolsik 3-2015 Yetgeul"),
    (ucschar*)hangul_keyboard_table_3_2015_yet,
    &hangul_combination_full
};

static const HangulKeyboard hangul_keyboard_3_2015_patal = {
    HANGUL_KEYBOARD_TYPE_JASO,
    "3-2015-patal",
    N_("Sebeolsik 3-2015P"),
    (ucschar*)hangul_keyboard_table_3_2015_patal,
    &hangul_combination_default_3
};

static const HangulKeyboard hangul_keyboard_3_2015_patal_yet = {
    HANGUL_KEYBOARD_TYPE_JASO,
    "3-2015-patal-yet",
    N_("Sebeolsik 3-2015P Yetguel"),
    (ucschar*)hangul_keyboard_table_3_2015_patal,
    &hangul_combination_full
};

static const HangulKeyboard hangul_keyboard_3_14_proposal = {
    HANGUL_KEYBOARD_TYPE_JASO,
    "3-14-proposal",
    N_("Sebeolsik 3-14 Proposal"),
    (ucschar*)hangul_keyboard_table_3_14_proposal,
    &hangul_combination_default_3
};

static const HangulKeyboard hangul_keyboard_3moachigi_2014 = {
    HANGUL_KEYBOARD_TYPE_JASO,
    "3moachigi-2014",
    N_("Sebeolsik Moachigi 2014"),
    (ucschar*)hangul_keyboard_table_3moachigi_2014,
    &hangul_combination_3moachigi_2014
};

static const HangulKeyboard hangul_keyboard_3sun_2014 = {
    HANGUL_KEYBOARD_TYPE_JASO,
    "3sun-2014",
    N_("Sebeolsik Noshift 2014"),
    (ucschar*)hangul_keyboard_table_3sun_2014,
    &hangul_combination_default_3
};

static const HangulKeyboard hangul_keyboard_3gimguk_38a_yet = {
    HANGUL_KEYBOARD_TYPE_JASO,
    "3gimguk-38a-yet",
    N_("Sebeolsik 3Gimguk-38A Yetgeul"),
    (ucschar*)hangul_keyboard_table_3gimguk_38A_yet,
    &hangul_combination_full
};

static const HangulKeyboard hangul_keyboard_3shin_2003 = {
    HANGUL_KEYBOARD_TYPE_JASO_SHIN,
    "3shin-2003",
    N_("Sebeolsik Shin 2003"),
    (ucschar*)hangul_keyboard_table_3shin_2003,
    &hangul_combination_default_3
};

static const HangulKeyboard hangul_keyboard_3shin_2012 = {
    HANGUL_KEYBOARD_TYPE_JASO_SHIN,
    "3shin-2012",
    N_("Sebeolsik Shin 2012"),
    (ucschar*)hangul_keyboard_table_3shin_2012,
    &hangul_combination_default_3
};


static const HangulKeyboard* hangul_keyboards[] = {
    &hangul_keyboard_2,
    &hangul_keyboard_2noshift,
    &hangul_keyboard_2y,
    &hangul_keyboard_2north9256,
    &hangul_keyboard_3_89,
    &hangul_keyboard_3_90,
    &hangul_keyboard_3_91_final,
    &hangul_keyboard_3_91_final_noshift,
    &hangul_keyboard_3_93_yet,
    &hangul_keyboard_32,
    &hangul_keyboard_romaja,
    &hangul_keyboard_ahn,
    &hangul_keyboard_3ahnmatae,
    &hangul_keyboard_3_2011,
    &hangul_keyboard_3_2011_yet,
    &hangul_keyboard_3_2012,
    &hangul_keyboard_3_2012_yet,
    &hangul_keyboard_3_2014,
    &hangul_keyboard_3_2014_yet,
    &hangul_keyboard_3_2015,
    &hangul_keyboard_3_2015_yet,
    &hangul_keyboard_3_2015_patal,
    &hangul_keyboard_3_2015_patal_yet,
    &hangul_keyboard_3_14_proposal,
    &hangul_keyboard_3moachigi_2014,
    &hangul_keyboard_3sun_1990,
    &hangul_keyboard_3sun_2014,
    &hangul_keyboard_3gimguk_38a_yet,
    &hangul_keyboard_3shin_2003,
    &hangul_keyboard_3shin_2012,
};

// 세벌식 확장모드 글쇠
static const char sebeol_3_ext_key[3] = {'0', 'v', '8'};    //0:같은 기호 배열을 쓴다 // ㅗ, ㅜ
static const ucschar sebeol_3_ext_value[2] = {0x1169, 0x116e};  // ㅗ, ㅜ 
static const char sebeol_3yet_ext_key[3] = {'1', '/', '9'};  //1:다른 기호 배열을 쓴다// ㅗ, ㅜ
static const char sebeol_3shin_ext_key[4] = {'j', 'k', 'l', ';'};   // j + [ k, l, ;]
static const ucschar sebeol_3shin_ext_value[1] = {0x110b};   // 첫소리 ㅇ [j]
// 세벌식 옛한글
static const char sebeol_3yet_han_key[2] = {'7', '8'};  // ㅖ, ㅢ  // 공병우 계열
static const ucschar sebeol_3yet_han_value[2] = {0x1168, 0x1174};  // ㅖ, ㅢ  // 공병우 계열
// 세벌식 확장단계 표시
static const ucschar sebeol_3_ext_step[5] = {0x2460, 0x2461, 0x2462, 0x2463, 0x2464};// ①, ②, ③, ④, ⑤
// 세벌식 겹홀소리 글쇠
static const char sebeol_3_moeum_key[2] = {'/', '9'};  // ㅗ, ㅜ  // 공병우 계열
static const char sebeol_3shin_moeum_key[2] = {'O', 'P'};  // ㅗ, ㅜ  // 신광조 계열
static const char sebeol_3moachigi_moeum_key[2] = {'\'', 'p'}; // ㅗ, ㅜ  // 신세기 계열
static const ucschar sebeol_3_moeum_value[2] = {0x1169, 0x116e};  // ㅗ, ㅜ 


static const HangulCombination hangul_combination_3_2014 = {
    N_ELEMENTS(hangul_combination_table_3_3_2014),
    (HangulCombinationItem*)hangul_combination_table_3_3_2014
};

static const HangulCombination hangul_combination_3_2015 = {
    N_ELEMENTS(hangul_combination_table_3_3_2015),
    (HangulCombinationItem*)hangul_combination_table_3_3_2015
};
 
static const HangulCombination hangul_combination_3_2015_yet = {
    N_ELEMENTS(hangul_combination_table_full_3_2015_yet),
    (HangulCombinationItem*)hangul_combination_table_full_3_2015_yet
};

static const HangulCombination hangul_combination_3_2015_patal = {
    N_ELEMENTS(hangul_combination_table_3_3_2015_patal),
    (HangulCombinationItem*)hangul_combination_table_3_3_2015_patal
};

static const HangulCombination hangul_combination_3_14_proposal = {
    N_ELEMENTS(hangul_combination_table_3_3_14_proposal),
    (HangulCombinationItem*)hangul_combination_table_3_3_14_proposal
};

static const HangulCombination hangul_combination_3sun_2014 = {
    N_ELEMENTS(hangul_combination_table_3_3sun_2014),
    (HangulCombinationItem*)hangul_combination_table_3_3sun_2014
};

static const HangulCombination hangul_combination_3gimguk_38a_yet = {
    N_ELEMENTS(hangul_combination_table_full_3gimguk_38A_yet),
    (HangulCombinationItem*)hangul_combination_table_full_3gimguk_38A_yet
};


static const HangulKeyboardAddon hangul_keyboard_addon_2noshift = {
    "2noshift", // id
    0x0001, // replace_it // ucschar // 0x0000 : FALSE , else : TRUE
    0x00, // flag
    NULL, // ext_key
    NULL, // ext_value
    NULL, // (*symbolFunc)(int, int, int)
    NULL, // han_key
    NULL, // han_value
    NULL, // (*yethanguelFunc)(int, int, int)
    NULL, // ext_step
    NULL, // moeum_key
    NULL, // moeum_value
    NULL, // (*galmadeuliFunc)(ucschar, bool)
    NULL // combination_addon
};

static const HangulKeyboardAddon hangul_keyboard_addon_2north9256 = {
    "2n9256", // id
    0x0001, // replace_it // ucschar // 0x0000 : FALSE , else : TRUE
    0x00, // flag
    NULL, // ext_key
    NULL, // ext_value
    NULL, // (*symbolFunc)(int, int, int)
    NULL, // han_key
    NULL, // han_value
    NULL, // (*yethanguelFunc)(int, int, int)
    NULL, // ext_step
    NULL, // moeum_key
    NULL, // moeum_value
    NULL, // (*galmadeuliFunc)(ucschar, bool)
    NULL // combination_addon
};

static const HangulKeyboardAddon hangul_keyboard_addon_3_90 = {
    "3-90", // id
    0x119e, // replace_it // 아래아
    0x00, // flag
    NULL, // ext_key
    NULL, // ext_value
    NULL, // (*symbolFunc)(int, int, int)
    NULL, // han_key
    NULL, // han_value
    NULL, // (*yethanguelFunc)(int, int, int)
    NULL, // ext_step
    sebeol_3_moeum_key, // moeum_key
    sebeol_3_moeum_value, // moeum_value
    NULL, // (*galmadeuliFunc)(ucschar, bool)
    NULL // combination_addon
};

static const HangulKeyboardAddon hangul_keyboard_addon_3_91 = {
    "3-91", // id
    0x119e, // replace_it // 아래아
    0x00, // flag
    NULL, // ext_key
    NULL, // ext_value
    NULL, // (*symbolFunc)(int, int, int)
    NULL, // han_key
    NULL, // han_value
    NULL, // (*yethanguelFunc)(int, int, int)
    NULL, // ext_step
    sebeol_3_moeum_key, // moeum_key
    sebeol_3_moeum_value, // moeum_value
    NULL, // (*galmadeuliFunc)(ucschar, bool)
    NULL // combination_addon
};

static const HangulKeyboardAddon hangul_keyboard_addon_3_93_yet = {
    "3-93-yet", // id
    0x0000, // replace_it // FALSE
    0x00, // flag
    NULL, // ext_key
    NULL, // ext_value
    NULL, // (*symbolFunc)(int, int, int)
    NULL, // han_key
    NULL, // han_value
    NULL, // (*yethanguelFunc)(int, int, int)
    NULL, // ext_step
    sebeol_3_moeum_key, // moeum_key
    sebeol_3_moeum_value, // moeum_value
    NULL, // (*galmadeuliFunc)(ucschar, bool)
    NULL // combination_addon
};

static const HangulKeyboardAddon hangul_keyboard_addon_3_2011 = {
    "3-2011", // id
    0x119e, // replace_it // 아래아
    0x01, // flag
    sebeol_3_ext_key, // ext_key
    NULL, // ext_value
    &hangul_ascii_to_symbol_3_2011, // (*symbolFunc)(int, int, int)
    NULL, // han_key
    NULL, // han_value
    NULL, // (*yethanguelFunc)(int, int, int)
    sebeol_3_ext_step, // ext_step
    sebeol_3_moeum_key, // moeum_key
    sebeol_3_moeum_value, // moeum_value
    NULL, // (*galmadeuliFunc)(ucschar, bool)
    NULL // combination_addon
};

static const HangulKeyboardAddon hangul_keyboard_addon_3_2011_yet = {
    "3-2011-yet", // id
    0x119e, // replace_it // 아래아
    0x01, // flag
    sebeol_3yet_ext_key, // ext_key
    NULL, // ext_value
    &hangul_ascii_to_symbol_3_2011_yet, // (*symbolFunc)(int, int, int)
    sebeol_3yet_han_key, // han_key
    NULL, // han_value
    &hangul_ascii_to_hanguel_3_yet, // (*yethanguelFunc)(int, int, int)
    sebeol_3_ext_step, // ext_step
    sebeol_3_moeum_key, // moeum_key
    sebeol_3_moeum_value, // moeum_value
    NULL, // (*galmadeuliFunc)(ucschar, bool)
    NULL // combination_addon
};

static const HangulKeyboardAddon hangul_keyboard_addon_3_2012 = {
    "3-2012", // id
    0x119e, // replace_it // 아래아
    0x01, // flag
    sebeol_3_ext_key, // ext_key
    NULL, // ext_value
    &hangul_ascii_to_symbol_3_2012, // (*symbolFunc)(int, int, int)
    NULL, // han_key
    NULL, // han_value
    NULL, // (*yethanguelFunc)(int, int, int)
    sebeol_3_ext_step, // ext_step
    sebeol_3_moeum_key, // moeum_key
    sebeol_3_moeum_value, // moeum_value
    NULL, // (*galmadeuliFunc)(ucschar, bool)
    NULL // combination_addon
};

static const HangulKeyboardAddon hangul_keyboard_addon_3_2012_yet = {
    "3-2012-yet", // id
    0x119e, // replace_it // 아래아
    0x01, // flag
    sebeol_3yet_ext_key, // ext_key
    NULL, // ext_value
    &hangul_ascii_to_symbol_3_2012_yet, // (*symbolFunc)(int, int, int)
    sebeol_3yet_han_key, // han_key
    NULL, // han_value
    &hangul_ascii_to_hanguel_3_yet, // (*yethanguelFunc)(int, int, int)
    sebeol_3_ext_step, // ext_step
    sebeol_3_moeum_key, // moeum_key
    sebeol_3_moeum_value, // moeum_value
    NULL, // (*galmadeuliFunc)(ucschar, bool)
    NULL // combination_addon
};

static const HangulKeyboardAddon hangul_keyboard_addon_3_2014 = {
    "3-2014", // id
    0x119e, // replace_it // 아래아
    0x0b, // flag
    sebeol_3yet_ext_key, // ext_key
    sebeol_3_ext_value, // ext_value
    &hangul_ascii_to_symbol_3_2012_yet, // (*symbolFunc)(int, int, int)
    NULL, // han_key
    NULL, // han_value
    NULL, // (*yethanguelFunc)(int, int, int)
    sebeol_3_ext_step, // ext_step
    sebeol_3_moeum_key, // moeum_key
    sebeol_3_moeum_value, // moeum_value
    &hangul_galmadeuli_3_2014, // (*galmadeuliFunc)(ucschar, bool)
    &hangul_combination_3_2014 // combination_addon
};

static const HangulKeyboardAddon hangul_keyboard_addon_3_2014_yet = {
    "3-2014-yet", // id
    0x119e, // replace_it // 아래아
    0x01, // flag
    sebeol_3yet_ext_key, // ext_key
    sebeol_3_ext_value, // ext_value
    &hangul_ascii_to_symbol_3_2012_yet, // (*symbolFunc)(int, int, int)
    sebeol_3yet_han_key, // han_key
    NULL, // han_value
    &hangul_ascii_to_hanguel_3_yet, // (*yethanguelFunc)(int, int, int)
    sebeol_3_ext_step, // ext_step
    sebeol_3_moeum_key, // moeum_key
    sebeol_3_moeum_value, // moeum_value
    NULL, // (*galmadeuliFunc)(ucschar, bool)
    NULL // combination_addon
};

static const HangulKeyboardAddon hangul_keyboard_addon_3_2015 = {
    "3-2015", // id
    0x0000, // replace_it // 아래아
    0x3a, // flag
    NULL, // ext_key
    NULL, // ext_value
    NULL, // (*symbolFunc)(int, int, int)
    NULL, // han_key
    NULL, // han_value
    NULL, // (*yethanguelFunc)(int, int, int)
    NULL, // ext_step
    sebeol_3_moeum_key, // moeum_key
    sebeol_3_moeum_value, // moeum_value
    &hangul_galmadeuli_3_2015, // (*galmadeuliFunc)(ucschar, bool)
    &hangul_combination_3_2015 // combination_addon
};
 
static const HangulKeyboardAddon hangul_keyboard_addon_3_2015_yet = {
    "3-2015-yet", // id
    0x0000, // replace_it // FALSE
    0x00, // flag
    NULL, // ext_key
    NULL, // ext_value
    NULL, // (*symbolFunc)(int, int, int)
    NULL, // han_key
    NULL, // han_value
    NULL, // (*yethanguelFunc)(int, int, int)
    NULL, // ext_step
    sebeol_3_moeum_key, // moeum_key
    sebeol_3_moeum_value, // moeum_value
    NULL, // (*galmadeuliFunc)(ucschar, bool)
    &hangul_combination_3_2015_yet // combination_addon
};

static const HangulKeyboardAddon hangul_keyboard_addon_3_2015_patal = {
    "3-2015-patal", // id
    0x119e, // replace_it // 아래아
    0x0b, // flag
    sebeol_3yet_ext_key, // ext_key
    sebeol_3_ext_value, // ext_value
    &hangul_ascii_to_symbol_3_2012_yet, // (*symbolFunc)(int, int, int)
    NULL, // han_key
    NULL, // han_value
    NULL, // (*yethanguelFunc)(int, int, int)
    sebeol_3_ext_step, // ext_step
    sebeol_3_moeum_key, // moeum_key
    sebeol_3_moeum_value, // moeum_value
    &hangul_galmadeuli_3_2015_patal, // (*galmadeuliFunc)(ucschar, bool)
    &hangul_combination_3_2015_patal // combination_addon
};

static const HangulKeyboardAddon hangul_keyboard_addon_3_2015_patal_yet = {
    "3-2015-patal-yet", // id
    0x119e, // replace_it // 아래아
    0x01, // flag
    sebeol_3yet_ext_key, // ext_key
    sebeol_3_ext_value, // ext_value
    &hangul_ascii_to_symbol_3_2012_yet, // (*symbolFunc)(int, int, int)
    sebeol_3yet_han_key, // han_key
    NULL, // han_value
    &hangul_ascii_to_hanguel_3_yet, // (*yethanguelFunc)(int, int, int)
    sebeol_3_ext_step, // ext_step
    sebeol_3_moeum_key, // moeum_key
    sebeol_3_moeum_value, // moeum_value
    NULL, // (*galmadeuliFunc)(ucschar, bool)
    NULL // combination_addon
};

static const HangulKeyboardAddon hangul_keyboard_addon_3_14_proposal = {
    "3-14-proposal", // id
    0x0000, // replace_it // FALSE
    0x0a, // flag
    NULL, // ext_key
    NULL, // ext_value
    NULL, // (*symbolFunc)(int, int, int)
    NULL, // han_key
    NULL, // han_value
    NULL, // (*yethanguelFunc)(int, int, int)
    NULL, // ext_step
    sebeol_3_moeum_key, // moeum_key
    sebeol_3_moeum_value, // moeum_value
    &hangul_galmadeuli_3_14_proposal, // (*galmadeuliFunc)(ucschar, bool)
    &hangul_combination_3_14_proposal // combination_addon
};

static const HangulKeyboardAddon hangul_keyboard_addon_3moachigi_2014 = {
    "3moachigi-2014", // id
    0x0000, // replace_it // FALSE
    0x04, // flag
    NULL, // ext_key
    NULL, // ext_value
    NULL, // (*symbolFunc)(int, int, int)
    NULL, // han_key
    NULL, // han_value
    NULL, // (*yethanguelFunc)(int, int, int)
    NULL, // ext_step
    sebeol_3moachigi_moeum_key, // moeum_key
    sebeol_3_moeum_value, // moeum_value
    NULL, // (*galmadeuliFunc)(ucschar, bool)
    NULL // combination_addon
};

static const HangulKeyboardAddon hangul_keyboard_addon_3sun_2014 = {
    "3sun-2014", // id
    0x0000, // replace_it // FALSE
    0x00, // flag
    NULL, // ext_key
    NULL, // ext_value
    NULL, // (*symbolFunc)(int, int, int)
    NULL, // han_key
    NULL, // han_value
    NULL, // (*yethanguelFunc)(int, int, int)
    NULL, // ext_step
    sebeol_3_moeum_key, // moeum_key
    sebeol_3_moeum_value, // moeum_value
    NULL, // (*galmadeuliFunc)(ucschar, bool)
    &hangul_combination_3sun_2014 // combination_addon
};

static const HangulKeyboardAddon hangul_keyboard_addon_3gimguk_38a_yet = {
    "3gimguk-38a-yet", // id
    0x0000, // replace_it // FALSE
    0x00, // flag
    NULL, // ext_key
    NULL, // ext_value
    NULL, // (*symbolFunc)(int, int, int)
    NULL, // han_key
    NULL, // han_value
    NULL, // (*yethanguelFunc)(int, int, int)
    NULL, // ext_step
    NULL, // moeum_key
    NULL, // moeum_value
    NULL, // (*galmadeuliFunc)(ucschar, bool)
    &hangul_combination_3gimguk_38a_yet // combination_addon
};

static const HangulKeyboardAddon hangul_keyboard_addon_3shin_2003 = {
    "3shin-2003", // id
    0x0000, // replace_it // FALSE
    0x09, // flag // 갈마들이는 필수 기능이라 꺼지면 안된다
    sebeol_3shin_ext_key, // ext_key
    sebeol_3shin_ext_value, // ext_value
    &hangul_ascii_to_symbol_shin, // (*symbolFunc)(int, int, int)
    NULL, // han_key
    NULL, // han_value
    NULL, // (*yethanguelFunc)(int, int, int)
    sebeol_3_ext_step, // ext_step
    sebeol_3shin_moeum_key, // moeum_key
    sebeol_3_moeum_value, // moeum_value
    &hangul_galmadeuli_shin_2003, // (*galmadeuliFunc)(ucschar, bool)
    NULL // combination_addon
};

static const HangulKeyboardAddon hangul_keyboard_addon_3shin_2012 = {
    "3shin-2012", // id
    0x0000, // replace_it // FALSE
    0x09, // flag // 갈마들이는 필수 기능이라 꺼지면 안된다
    sebeol_3shin_ext_key, // ext_key
    sebeol_3shin_ext_value, // ext_value
    &hangul_ascii_to_symbol_shin, // (*symbolFunc)(int, int, int)
    NULL, // han_key
    NULL, // han_value
    NULL, // (*yethanguelFunc)(int, int, int)
    sebeol_3_ext_step, // ext_step
    sebeol_3shin_moeum_key, // moeum_key
    sebeol_3_moeum_value, // moeum_value
    &hangul_galmadeuli_shin_2012, // (*galmadeuliFunc)(ucschar, bool)
    NULL // combination_addon
};


static const HangulKeyboardAddon* hangul_keyboard_addons[] = {
    &hangul_keyboard_addon_2noshift,
    &hangul_keyboard_addon_2north9256,
    &hangul_keyboard_addon_3_90,
    &hangul_keyboard_addon_3_91,
    &hangul_keyboard_addon_3_93_yet,
    &hangul_keyboard_addon_3_2011,
    &hangul_keyboard_addon_3_2011_yet,
    &hangul_keyboard_addon_3_2012,
    &hangul_keyboard_addon_3_2012_yet,
    &hangul_keyboard_addon_3_2014,
    &hangul_keyboard_addon_3_2014_yet,
    &hangul_keyboard_addon_3_2015,
    &hangul_keyboard_addon_3_2015_yet,
    &hangul_keyboard_addon_3_2015_patal,
    &hangul_keyboard_addon_3_2015_patal_yet,
    &hangul_keyboard_addon_3_14_proposal,
    &hangul_keyboard_addon_3moachigi_2014,
    &hangul_keyboard_addon_3sun_2014,
    &hangul_keyboard_addon_3gimguk_38a_yet,
    &hangul_keyboard_addon_3shin_2003,
    &hangul_keyboard_addon_3shin_2012,
};


/* keyboard */
static ucschar hangul_keyboard_get_value(const HangulKeyboard *keyboard, int key);
static int hangul_keyboard_get_type(const HangulKeyboard *keyboard);

/* combination */
static uint32_t hangul_combination_make_key(ucschar first, ucschar second);
static int hangul_combination_cmp(const void* p1, const void* p2);
ucschar hangul_combination_combine(const HangulCombination* combination,
			   ucschar first, ucschar second);

/* buffer */
static bool hangul_buffer_is_empty(HangulBuffer *buffer);
static bool hangul_buffer_has_choseong(HangulBuffer *buffer);
static bool hangul_buffer_has_jungseong(HangulBuffer *buffer);
static bool hangul_buffer_has_jongseong(HangulBuffer *buffer);

static void    hangul_buffer_push(HangulBuffer *buffer, ucschar ch);
static ucschar hangul_buffer_pop (HangulBuffer *buffer);
static ucschar hangul_buffer_peek(HangulBuffer *buffer);

static void    hangul_buffer_clear(HangulBuffer *buffer);
static int     hangul_buffer_get_string(HangulBuffer *buffer, ucschar*buf, int buflen);
static int     hangul_buffer_get_jamo_string(HangulBuffer *buffer, ucschar *buf, int buflen);
static int     hangul_jaso_to_string(ucschar cho, ucschar jung, ucschar jong,
		      ucschar *buf, int len);

static bool hangul_buffer_backspace(HangulBuffer *buffer);

/* input context */
static inline bool hangul_ic_push(HangulInputContext *hic, ucschar c);
static inline ucschar hangul_ic_pop(HangulInputContext *hic);
static inline ucschar hangul_ic_peek(HangulInputContext *hic);

static inline void hangul_ic_save_preedit_string(HangulInputContext *hic);
static inline void hangul_ic_append_commit_string(HangulInputContext *hic, ucschar ch);
static inline void hangul_ic_save_commit_string(HangulInputContext *hic);

static ucschar hangul_ic_choseong_to_jongseong(HangulInputContext* hic, ucschar cho);

static bool hangul_ic_process_jamo(HangulInputContext *hic, ucschar ch);
static bool hangul_ic_process_jaso(HangulInputContext *hic, ucschar ch);
static bool hangul_ic_process_romaja(HangulInputContext *hic, int ascii, ucschar ch);

/*** 3beol ***/
static bool hangul_ic_process_jamo_dubeol (HangulInputContext *hic, ucschar ch);
static bool hangul_ic_process_jaso_shin_sebeol (HangulInputContext *hic, int ascii, ucschar ch);
static bool hangul_ic_process_jaso_sebeol (HangulInputContext *hic, int ascii, ucschar ch);
static bool hangul_ic_process_3finalsun(HangulInputContext *hic, int ascii, ucschar ch);
/************/

static const HangulKeyboard* hangul_ic_get_keyboard_by_id(const char* id);
/*** 3beol ***/
static const HangulKeyboardAddon* hangul_ic_get_keyboard_addon_by_id(const char* id);
static unsigned int hangul_ic_get_n_keyboard_addons(void);
/************/

static void    hangul_ic_flush_internal(HangulInputContext *hic);

#endif /* libhangul_hangulinputcontext_def_h */
