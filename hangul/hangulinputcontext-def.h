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

static const HangulCombination hangul_combination_default = {
    N_ELEMENTS(hangul_combination_table_default),
    (HangulCombinationItem*)hangul_combination_table_default
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
    N_("Dubeolsik"), 
    (ucschar*)hangul_keyboard_table_2,
    &hangul_combination_default
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
    &hangul_combination_default
};

static const HangulKeyboard hangul_keyboard_390 = {
    HANGUL_KEYBOARD_TYPE_JASO,
    "39",
    N_("Sebeolsik 390"),
    (ucschar*)hangul_keyboard_table_390,
    &hangul_combination_default
};

static const HangulKeyboard hangul_keyboard_3final = {
    HANGUL_KEYBOARD_TYPE_JASO,
    "3f",
    N_("Sebeolsik Final"),
    (ucschar*)hangul_keyboard_table_3final,
    &hangul_combination_default
};

static const HangulKeyboard hangul_keyboard_3sun = {
    HANGUL_KEYBOARD_TYPE_JASO,
    "3s",
    N_("Sebeolsik Noshift"),
    (ucschar*)hangul_keyboard_table_3sun,
    &hangul_combination_default
};

static const HangulKeyboard hangul_keyboard_3yet = {
    HANGUL_KEYBOARD_TYPE_JASO,
    "3y",
    N_("Sebeolsik Yetgeul"),
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

static const HangulKeyboard* hangul_keyboards[] = {
    &hangul_keyboard_2,
    &hangul_keyboard_2y,
    &hangul_keyboard_390,
    &hangul_keyboard_3final,
    &hangul_keyboard_3sun,
    &hangul_keyboard_3yet,
    &hangul_keyboard_32,
    &hangul_keyboard_romaja,
    &hangul_keyboard_ahn,
};


static void    hangul_buffer_push(HangulBuffer *buffer, ucschar ch);
static ucschar hangul_buffer_pop (HangulBuffer *buffer);
static ucschar hangul_buffer_peek(HangulBuffer *buffer);

static void    hangul_buffer_clear(HangulBuffer *buffer);
static int     hangul_buffer_get_string(HangulBuffer *buffer, ucschar*buf, int buflen);
static int     hangul_buffer_get_jamo_string(HangulBuffer *buffer, ucschar *buf, int buflen);

static void    hangul_ic_flush_internal(HangulInputContext *hic);

#endif /* libhangul_hangulinputcontext_def_h */
