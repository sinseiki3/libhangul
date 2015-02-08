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

#ifndef libhangul_hangulinputcontext_h
#define libhangul_hangulinputcontext_h

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#define HANGUL_KEYBOARD_TABLE_SIZE 0x80

typedef void   (*HangulOnTranslate)  (HangulInputContext*,
				      int,
				      ucschar*,
				      void*);
typedef bool   (*HangulOnTransition) (HangulInputContext*,
				      ucschar,
				      const ucschar*,
				      void*);

typedef struct _HangulCombinationItem HangulCombinationItem;

struct _HangulKeyboard {
    int type;
    const char* id;
    const char* name;
    const ucschar* table;
    const HangulCombination* combination;
};

struct _HangulCombinationItem {
    uint32_t key;
    ucschar code;
};

struct _HangulCombination {
    int size;
    HangulCombinationItem *table;
};

struct _HangulBuffer {
    ucschar choseong;
    ucschar jungseong;
    ucschar jongseong;

    ucschar stack[12];
    int     index;
};

struct _HangulInputContext {
    int type;

    const HangulKeyboard*    keyboard;

    HangulBuffer buffer;
    int output_mode;

    ucschar preedit_string[64];
    ucschar commit_string[64];
    ucschar flushed_string[64];

    HangulOnTranslate   on_translate;
    void*               on_translate_data;

    HangulOnTransition  on_transition;
    void*               on_transition_data;

    unsigned int use_jamo_mode_only : 1;
};

#endif /* libhangul_hangulinputcontext_h */
