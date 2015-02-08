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

/** hangul.h 로... ***
 * 
typedef void   (*HangulOnTranslate)  (HangulInputContext*,
				      int,
				      ucschar*,
				      void*);
typedef bool   (*HangulOnTransition) (HangulInputContext*,
				      ucschar,
				      const ucschar*,
				      void*);

typedef struct _HangulCombinationItem HangulCombinationItem;
*
*/

struct _HangulKeyboard {
    int type;
    const char* id;
    const char* name;
    const ucschar* table;
    const HangulCombination* combination;
};

struct _HangulKeyboardAddon {
    const char *id;
    // 3beol
    const ucschar replace_it; // 바꿔 놓기 : 두벌식의 치환, 세벌식의 ] -> 아래아
    const unsigned char flag; // bit:00000000:0, 0, 0, 0, 왼/오른ㅗㅜ구분, 입력순서안따짐, 갈마들이, 확장배열
    const char *ext_key; // 확장 기호 배열로 바꾸는 글쇠
    const ucschar *ext_value; // ext_key 에 놓인 한글 낱소리의 유니코드 값
    ucschar (*symbolFunc)(int, int, int); // 기호 확장 함수
    const char *han_key; // 확장 한글 배열로 바꾸는 글쇠
    const ucschar *han_value; // han_key 에 놓인 한글 낱소리의 유니코드 값
    ucschar (*yethanguelFunc)(int, int, int); // 옛한글 확장 함수
    const ucschar *ext_step; // 확장 단계를 보여주는 한글 낱소리의 유니코드 값
    const char *moeum_key; // 겹홀소리에 쓰이는 ㅗ, ㅜ 가 놓여진 Qwerty 의 글쇠
    const ucschar *moeum_value; // 겹홀소리에 쓰이는 ㅗ, ㅜ 의 유니코드 값
    ucschar (*galmadeuliFunc)(ucschar, bool); // 갈마들이 함수
    const HangulCombination* combination_addon; // 기본 조합 외에 글판마다 더해진 조합
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

	// 종성 쉬프트를 쓰는 3-91 최종 순아래 글판에서 쓰인다 
    ucschar shift;
    // 신세벌식, 한글문와원 314 같은 왼/오른 ㅗㅜaraea 를 구분하는 글판에서 쓰인다
    ucschar right_oua;

    ucschar stack[12];
    int     index;
};

struct _HangulInputContext {
    int type;

    const HangulKeyboard*    keyboard;
    const HangulKeyboardAddon*    keyboard_addon;

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

    bool    extended_layout_enable;
    int     extended_layout_index;
    int     extended_layout_prevkey;
    bool    galmadeuli_method_enable;
};

#endif /* libhangul_hangulinputcontext_h */
