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

static const HangulCombination hangul_combination_romaja = {
    N_ELEMENTS(hangul_combination_table_romaja),
    (HangulCombinationItem*)hangul_combination_table_romaja
};

static const HangulCombination hangul_combination_full = {
    N_ELEMENTS(hangul_combination_table_full),
    (HangulCombinationItem*)hangul_combination_table_full
};

static const HangulCombination hangul_combination_ahn = {
    N_ELEMENTS(hangul_combination_table_ahn),
    (HangulCombinationItem*)hangul_combination_table_ahn
};


static const HangulKeyboard hangul_keyboard_2 = {
    HANGUL_KEYBOARD_TYPE_JAMO,
    "2", 
    N_("Dubeolsik KSX 5002"), 
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

static const HangulKeyboard hangul_keyboard_32 = {
    HANGUL_KEYBOARD_TYPE_JASO,
    "32",
    N_("Sebeolsik Dubeol Layout"),
    (ucschar*)hangul_keyboard_table_32,
    &hangul_combination_default_2
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
    &hangul_keyboard_2y,
    &hangul_keyboard_3_90,
    &hangul_keyboard_3_91_final,
    &hangul_keyboard_3_93_yet,
    &hangul_keyboard_32,
    &hangul_keyboard_romaja,
    &hangul_keyboard_ahn,
    &hangul_keyboard_3sun_1990,
    &hangul_keyboard_3shin_2003,
    &hangul_keyboard_3shin_2012,
};

// 세벌식 확장모드 글쇠
static const char sebeol_3shin_ext_key[4] = {'j', 'k', 'l', ';'};   // j + [ k, l, ;]
static const ucschar sebeol_3shin_ext_value[1] = {0x110b};   // 첫소리 ㅇ [j]
// 세벌식 확장단계 표시
static const ucschar sebeol_3_ext_step[5] = {0x2460, 0x2461, 0x2462, 0x2463, 0x2464};// ①, ②, ③, ④, ⑤
// 세벌식 겹홀소리 글쇠
static const char sebeol_3_moeum_key[2] = {'/', '9'};  // ㅗ, ㅜ  // 공병우 계열
static const char sebeol_3shin_moeum_key[2] = {'O', 'P'};  // ㅗ, ㅜ  // 신광조 계열
static const ucschar sebeol_3_moeum_value[2] = {0x1169, 0x116e};  // ㅗ, ㅜ 


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
    &hangul_keyboard_addon_3_90,
    &hangul_keyboard_addon_3_91,
    &hangul_keyboard_addon_3_93_yet,
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
static bool hangul_ic_process_jaso_shin_sebeol (HangulInputContext *hic, int ascii, ucschar ch);
/************/

static const HangulKeyboard* hangul_ic_get_keyboard_by_id(const char* id);
/*** 3beol ***/
static const HangulKeyboardAddon* hangul_ic_get_keyboard_addon_by_id(const char* id);
static unsigned int hangul_ic_get_n_keyboard_addons(void);
/************/

static void    hangul_ic_flush_internal(HangulInputContext *hic);

#endif /* libhangul_hangulinputcontext_def_h */
