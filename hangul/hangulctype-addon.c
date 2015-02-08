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
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "hangul.h"

/**
 * @defgroup hangulctype 한글 글자 조작
 * 
 * @section hangulctype 한글 글자 조작
 * libhangul은 한글 각 글자를 구분하고 조작하는데 사용할 수 있는 몇가지 함수를
 * 제공한다.  libhangul의 글자 구분 함수의 인터페이스에서 글자의 기본 단위는
 * UCS4 코드값이다.
 */

/**
 * @file hangulctype.c
 */



ucschar
hangul_galmadeuli_shin_2003(ucschar c, bool conjoin)
{
    static const ucschar cho_to_jung[][1] = {
      {0x0000},  /* 0x1100  choseong kiyeok         */
      {0x0000},  /* 0x1101  choseong ssangkiyeok  */
      {0x0000},  /* 0x1102  choseong nieun           */
      {0x0000},  /* 0x1103  choseong tikeut          */
      {0x0000},  /* 0x1104  choseong ssangtikeut */
      {0x0000},  /* 0x1105  choseong rieul            */
      {0x1174},  /* 0x1106  choseong mieum           <ㅁ> */     /* <ㅢ> */
      {0x0000},  /* 0x1107  choseong pieup           */
      {0x0000},  /* 0x1108  choseong ssangpieup   */
      {0x0000},  /* 0x1109  choseong sios             */
      {0x0000},  /* 0x110a  choseong ssangsios     */
      {0x119e},  /* 0x110b  choseong ieung           <ㅇ> */      /* <ㆍ> araea */
      {0x0000},  /* 0x110c  choseong cieuc           */
      {0x0000},  /* 0x110d  choseong ssangcieuc  */
      {0x116e},  /* 0x110e  choseong chieuch          <ㅊ> */      /* <ㅜ> */
      {0x1169},  /* 0x110f  choseong khieukh         <ㅋ> */     /* <ㅗ> */
      {0x0000},  /* 0x1110  choseong thieuth       */
      {0x1169},  /* 0x1111  choseong phieuph            <ㅍ> */     /* <ㅗ> */
      {0x0000},  /* 0x1112  choseong hieuh         */
    };

    static const ucschar jong_to_jung[][1] = {
      {0x116d},  /* 0x11a8  jongseong kiyeok (ㄱ)        -> jungseong yo (ㅛ) */
      {0x0000},  /* 0x11a9  jongseong ssangkiyeok (ㄲ)   ->   */
      {0x0000},  /* 0x11aa  jongseong kiyeok-sios (ㄳ)   ->      */
      {0x1168},  /* 0x11ab  jongseong nieun (ㄴ)         -> jungseong ye (ㅖ)       */
      {0x0000},  /* 0x11ac  jongseong nieun-cieuc (ㄵ)   ->         */
      {0x0000},  /* 0x11ad  jongseong nieun-hieuh (ㄶ)   ->         */
      {0x1175},  /* 0x11ae  jongseong tikeut (ㄷ)        -> jungseong i  (ㅣ)      */
      {0x1163},  /* 0x11af  jongseong rieul (ㄹ)         ->  jungseong ya (ㅑ)       */
      {0x0000},  /* 0x11b0  jongseong rieul-kiyeok (ㄺ)  ->        */
      {0x0000},  /* 0x11b1  jongseong rieul-mieum (ㄻ)   ->        */
      {0x0000},  /* 0x11b2  jongseong rieul-pieup (ㄼ)   ->         */
      {0x0000},  /* 0x11b3  jongseong rieul-sios (ㄽ)    ->          */
      {0x0000},  /* 0x11b4  jongseong rieul-thieuth (ㄾ) ->       */
      {0x0000},  /* 0x11b5  jongseong rieul-phieuph (ㄿ) ->       */
      {0x0000},  /* 0x11b6  jongseong rieul-hieuh (ㅀ)   ->         */
      {0x119e},  /* 0x11b7  jongseong mieum  (ㅁ)        ->      jungseong araea (ᆞ)   */
      {0x1167},  /* 0x11b8  jongseong pieup  (ㅂ)        -> jungseong yeo (ㅕ)     */
      {0x0000},  /* 0x11b9  jongseong pieup-sios (ㅄ)    ->          */
      {0x1164},  /* 0x11ba  jongseong sios (ㅅ)          -> jungseong yae (ㅒ)        */
      {0x1161}, /* 0x11bb  jongseong ssangsios (ㅆ)     -> jungseong a (ㅏ)   */
      {0x1172},  /* 0x11bc  jongseong ieung (ㅇ)         -> jungseong yu  (ㅠ)      */
      {0x1173},  /* 0x11bd  jongseong cieuc (ㅈ)         -> jungseong eu  (ㅡ)      */
      {0x1166},  /* 0x11be  jongseong chieuch (ㅊ)       -> jungseong e  (ㅔ)    */
      {0x116e},  /* 0x11bf  jongseong khieukh (ㅋ)        -> jungseong u  (ㅜ)    */
      {0x1162},  /* 0x11c0  jongseong thieuth (ㅌ)       -> jungseong ae  (ㅐ)    */
      {0x1165},  /* 0x11c1  jongseong phieuph (ㅍ)       -> jungseong eo  (ㅓ)    */
      {0x1169},  /* 0x11c2  jongseong hieuh (ㅎ)         -> jungseong o   (ㅗ)     */
    };

    /*shin-2003 의 ㅁ 에는 홀소리가 없어서 첫소리, 가윗소리, 끝소리 조건에 걸리지 않기때문에 */
    /* ㄻ(0x11b1) 은 hangul_ic_process_jaso_shin_sebeol 의 한글 이외 처리부에서 따로 처리한다.*/
    static const ucschar jung_to_conjoin_jong[][1] = {// shift+글쇠=겹받침
    {0x0000},     /* 0x1161   ᅡ*/     /* <>  */
    {0x11b4},     /* 0x1162   ᅢ*/     /* <ㄾ> */
    {0x11b0},     /* 0x1163   ᅣ*/     /* <ㄺ> */
    {0x11b3},     /* 0x1164   ᅤ*/     /* <ㄽ> */
    {0x11b5},     /* 0x1165   ᅥ*/     /* <ㄿ> */
    {0x11aa},     /* 0x1166   ᅦ*/     /* <ㄳ>*/
    {0x11b2},     /* 0x1167   ᅧ*/     /* <ㄼ> */
    {0x11ad},     /* 0x1168   ᅨ*/     /* <ㄶ> */
    {0x11b6},     /* 0x1169   ᅩ*/     /* <ㅀ> */
    {0x0000},     /* 0x116a   ᅪ*/     /* <> */
    {0x0000},     /* 0x116b   ᅫ*/     /* <> */
    {0x0000},     /* 0x116c   ᅬ*/     /* <> */
    {0x11a9},     /* 0x116d   ᅭ*/     /* <ㄲ> */
    {0x0000},     /* 0x116e   ᅮ*/     /* <> */
    {0x0000},     /* 0x116f   ᅯ*/     /* <> */
    {0x0000},     /* 0x1170   ᅰ*/     /* <> */
    {0x0000},     /* 0x1171   ᅱ*/     /* <> */
    {0x11b9},     /* 0x1172   ᅲ*/     /* <ㅄ> */
    {0x0000},     /* 0x1173   ᅳ*/     /* <> */
    {0x0000},     /* 0x1174   ᅴ*/     /* <> */
    {0x11ac},     /* 0x1175   ᅵ*/     /* <ㄵ> */
    };

    static const ucschar jong_to_conjoin_jong[][1] = {// 끝소리 글쇠 두 번=겹받침
      {0x11a9},  /* 0x11a8 jongseong kiyeok (ㄱ)        -> jongseong ssangkiyeok (ㄲ)  */
      {0x0000},  /* 0x11a9 jongseong ssangkiyeok (ㄲ)   ->   */
      {0x0000},  /* 0x11aa jongseong kiyeok-sios (ㄳ)   ->      */
      {0x11ad},  /* 0x11ab jongseong nieun (ㄴ)        -> jongseong nieun-hieuh (ㄶ)   */
      {0x0000},  /* 0x11ac jongseong nieun-cieuc (ㄵ)  ->         */
      {0x0000},  /* 0x11ad jongseong nieun-hieuh (ㄶ)   ->         */
      {0x11ac},  /* 0x11ae jongseong tikeut (ㄷ)       ->  jongseong nieun-cieuc (ㄵ)      */
      {0x11b0},  /* 0x11af jongseong rieul (ㄹ)        ->  jongseong rieul-kiyeok (ㄺ)   */
      {0x0000},  /* 0x11b0 jongseong rieul-kiyeok (ㄺ)  ->        */
      {0x0000},  /* 0x11b1 jongseong rieul-mieum (ㄻ)  ->        */
      {0x0000},  /* 0x11b2 jongseong rieul-pieup (ㄼ)  ->         */
      {0x0000},  /* 0x11b3 jongseong rieul-sios (ㄽ)   ->          */
      {0x0000},  /* 0x11b4 jongseong rieul-thieuth (ㄾ) ->       */
      {0x0000},  /* 0x11b5 jongseong rieul-phieuph (ㄿ) ->       */
      {0x0000},  /* 0x11b6 jongseong rieul-hieuh (ㅀ)  ->         */
      {0x11b1},  /* 0x11b7 jongseong mieum (ㅁ)        ->  jongseong rieul-mieum (ㄻ)      */
      {0x11b2},  /* 0x11b8 jongseong pieup (ㅂ)        -> jongseong rieul-pieup (ㄼ)      */
      {0x0000},  /* 0x11b9 jongseong pieup-sios (ㅄ)   ->          */
      {0x11b3},  /* 0x11ba jongseong sios (ㅅ)         -> jongseong rieul-sios (ㄽ)         */
      {0x0000},  /* 0x11bb jongseong ssangsios (ㅆ)    ->          */
      {0x11b9},  /* 0x11bc jongseong ieung (ㅇ)        -> jongseong pieup-sios (ㅄ)        */
      {0x0000},  /* 0x11bd jongseong cieuc (ㅈ)        ->         */
      {0x11aa},  /* 0x11be jongseong chieuch (ㅊ)      -> jongseong kiyeok-sios (ㄳ)      */
      {0x0000},  /* 0x11bf jongseong khieukh (ㅋ)      ->            */
      {0x11b4},  /* 0x11c0 jongseong thieuth (ㅌ)      -> jongseong rieul-thieuth (ㄾ)      */
      {0x11b5},  /* 0x11c1 jongseong phieuph (ㅍ)      -> jongseong rieul-phieuph (ㄿ)      */
      {0x11b6},  /* 0x11c2 jongseong hieuh (ㅎ)         -> jongseong rieul-hieuh (ㅀ)        */
    };

    if (conjoin) {
        if (c >= 0x1161 && c <= 0x1175) {
            return jung_to_conjoin_jong[c - 0x1161][0];
        } else if (c >= 0x11a8 && c <= 0x11c2) {
            return jong_to_conjoin_jong[c - 0x11a8][0];
        } else {
            return 0;
        }
    } else {
        if (c >= 0x1100 && c <= 0x1112) {
            return cho_to_jung[c - 0x1100][0];
        } else if (c >= 0x11a8 && c <= 0x11c2) {
            return jong_to_jung[c - 0x11a8][0];
        } else {
            return 0;
        }
    }
}

ucschar
hangul_galmadeuli_shin_2012(ucschar c, bool conjoin)
{
    static const ucschar cho_to_jung[][1] = {
      {0x0000},  /* 0x1100  choseong kiyeok         */
      {0x0000},  /* 0x1101  choseong ssangkiyeok  */
      {0x0000},  /* 0x1102  choseong nieun           */
      {0x0000},  /* 0x1103  choseong tikeut          */
      {0x0000},  /* 0x1104  choseong ssangtikeut */
      {0x0000},  /* 0x1105  choseong rieul            */
      {0x1174},  /* 0x1106  choseong mieum           <ㅁ> */     /* <ㅢ> */
      {0x0000},  /* 0x1107  choseong pieup           */
      {0x0000},  /* 0x1108  choseong ssangpieup   */
      {0x0000},  /* 0x1109  choseong sios             */
      {0x0000},  /* 0x110a  choseong ssangsios     */
      {0x119e},  /* 0x110b  choseong ieung           <ㅇ> */      /* <ㆍ> araea */
      {0x0000},  /* 0x110c  choseong cieuc           */
      {0x0000},  /* 0x110d  choseong ssangcieuc  */
      {0x116e},  /* 0x110e  choseong chieuch          <ㅊ> */      /* <ㅜ> */
      {0x1169},  /* 0x110f  choseong khieukh         <ㅋ> */     /* <ㅗ> */
      {0x0000},  /* 0x1110  choseong thieuth       */
      {0x1169},  /* 0x1111  choseong phieuph            <ㅍ> */     /* <ㅗ> */
      {0x0000},  /* 0x1112  choseong hieuh         */
    };

    static const ucschar jong_to_jung[][1] = {
      {0x116d},  /* 0x11a8  jongseong kiyeok (ㄱ)        -> jungseong yo (ㅛ) */
      {0x0000},  /* 0x11a9  jongseong ssangkiyeok (ㄲ)   ->   */
      {0x0000},  /* 0x11aa  jongseong kiyeok-sios (ㄳ)   ->      */
      {0x1168},  /* 0x11ab  jongseong nieun (ㄴ)         -> jungseong ye (ㅖ)       */
      {0x0000},  /* 0x11ac  jongseong nieun-cieuc (ㄵ)   ->         */
      {0x0000},  /* 0x11ad  jongseong nieun-hieuh (ㄶ)   ->         */
      {0x1162},  /* 0x11ae  jongseong tikeut (ㄷ)        -> jungseong ae  (ㅐ)      */
      {0x1163},  /* 0x11af  jongseong rieul (ㄹ)         ->  jungseong ya (ㅑ)       */
      {0x0000},  /* 0x11b0  jongseong rieul-kiyeok (ㄺ)  ->        */
      {0x0000},  /* 0x11b1  jongseong rieul-mieum (ㄻ)   ->        */
      {0x0000},  /* 0x11b2  jongseong rieul-pieup (ㄼ)   ->         */
      {0x0000},  /* 0x11b3  jongseong rieul-sios (ㄽ)    ->          */
      {0x0000},  /* 0x11b4  jongseong rieul-thieuth (ㄾ) ->       */
      {0x0000},  /* 0x11b5  jongseong rieul-phieuph (ㄿ) ->       */
      {0x0000},  /* 0x11b6  jongseong rieul-hieuh (ㅀ)   ->         */
      {0x119e},  /* 0x11b7  jongseong mieum  (ㅁ)        ->      jungseong araea (ᆞ)   */
      {0x1167},  /* 0x11b8  jongseong pieup  (ㅂ)        -> jungseong yeo (ㅕ)     */
      {0x0000},  /* 0x11b9  jongseong pieup-sios (ㅄ)    ->          */
      {0x1164},  /* 0x11ba  jongseong sios (ㅅ)          -> jungseong yae (ㅒ)        */
      {0x1175}, /* 0x11bb  jongseong ssangsios (ㅆ)     -> jungseong i  (ㅣ)   */
      {0x1172},  /* 0x11bc  jongseong ieung (ㅇ)         -> jungseong yu  (ㅠ)      */
      {0x1173},  /* 0x11bd  jongseong cieuc (ㅈ)         -> jungseong eu  (ㅡ)      */
      {0x1161},  /* 0x11be  jongseong chieuch (ㅊ)       -> jungseong a (ㅏ)    */
      {0x1166},  /* 0x11bf  jongseong khieukh (ㅋ)        -> jungseong e  (ㅔ)    */
      {0x1165},  /* 0x11c0  jongseong thieuth (ㅌ)       -> jungseong eo  (ㅓ)    */
      {0x116e},  /* 0x11c1  jongseong phieuph (ㅍ)       -> jungseong u  (ㅜ)    */
      {0x1169},  /* 0x11c2  jongseong hieuh (ㅎ)         -> jungseong o   (ㅗ)     */
    };

    static const ucschar jung_to_conjoin_jong[][1] = {// shift+글쇠=겹받침
    {0x0000},     /* 0x1161   ᅡ*/     /* <>  */
    {0x0000},     /* 0x1162   ᅢ*/     /* <> */
    {0x11b0},     /* 0x1163   ᅣ*/     /* <ㄺ> */
    {0x11b3},     /* 0x1164   ᅤ*/     /* <ㄽ> */
    {0x11b4},     /* 0x1165   ᅥ*/     /* <ㄾ> */
    {0x11aa},     /* 0x1166   ᅦ*/     /* <ㄳ>*/
    {0x11b2},     /* 0x1167   ᅧ*/     /* <ㄼ> */
    {0x11ad},     /* 0x1168   ᅨ*/     /* <ㄶ> */
    {0x11b6},     /* 0x1169   ᅩ*/     /* <ㅀ> */
    {0x0000},     /* 0x116a   ᅪ*/     /* <> */
    {0x0000},     /* 0x116b   ᅫ*/     /* <> */
    {0x0000},     /* 0x116c   ᅬ*/     /* <> */
    {0x11a9},     /* 0x116d   ᅭ*/     /* <ㄲ> */
    {0x11b5},     /* 0x116e   ᅮ*/     /* <ㄿ> */
    {0x0000},     /* 0x116f   ᅯ*/     /* <> */
    {0x0000},     /* 0x1170   ᅰ*/     /* <> */
    {0x0000},     /* 0x1171   ᅱ*/     /* <> */
    {0x11b9},     /* 0x1172   ᅲ*/     /* <ㅄ> */
    {0x0000},     /* 0x1173   ᅳ*/     /* <> */
    {0x0000},     /* 0x1174   ᅴ*/     /* <> */
    {0x11ac},     /* 0x1175   ᅵ*/     /* <ㄵ> */
    {0x0000},     /* 0x1176   ᅶ*/ 
    {0x0000},    /* 0x1177    ᅷ*/
    {0x0000},     /* 0x1178   ᅸ*/
    {0x0000},     /* 0x1179   ᅹ */
    {0x0000},     /* 0x117a    ᅺ */
    {0x0000},     /* 0x117b    ᅻ */
    {0x0000},     /* 0x117c    ᅼ */
    {0x0000},     /* 0x117d    ᅽ  */
    {0x0000},     /* 0x117e    ᅾ */
    {0x0000},     /* 0x117f    ᅿ */
    {0x0000},     /* 0x1180    ᆀ */
    {0x0000},     /* 0x1181    ᆁ*/
    {0x0000},     /* 0x1182    ᆂ*/
    {0x0000},     /* 0x1183    ᆃ*/
    {0x0000},     /* 0x1184    ᆄ*/
    {0x0000},     /* 0x1185    ᆅ*/
    {0x0000},     /* 0x1186    ᆆ*/
    {0x0000},     /* 0x1187    ᆇ*/
    {0x0000},     /* 0x1188    ᆈ*/
    {0x0000},     /* 0x1189    ᆉ*/
    {0x0000},     /* 0x118a    ᆊ*/
    {0x0000},     /* 0x118b    ᆋ*/
    {0x0000},     /* 0x118c    ᆌ*/
    {0x0000},     /* 0x118d    ᆍ*/
    {0x0000},     /* 0x118e    ᆎ*/
    {0x0000},     /* 0x118f    ᆏ*/
    {0x0000},     /* 0x1190    ᆐ*/
    {0x0000},     /* 0x1191     ᆑ*/
    {0x0000},     /* 0x1192    ᆒ*/
    {0x0000},     /* 0x1193    ᆓ*/
    {0x0000},     /* 0x1194    ᆔ*/
    {0x0000},     /* 0x1195    ᆕ*/
    {0x0000},     /* 0x1196    ᆖ*/
    {0x0000},     /* 0x1197    ᆗ*/
    {0x0000},     /* 0x1198    ᆘ*/
    {0x0000},     /* 0x1199    ᆙ*/
    {0x0000},     /* 0x119a    ᆚ*/
    {0x0000},     /* 0x119b    ᆛ*/
    {0x0000},     /* 0x119c    ᆜ*/
    {0x0000},     /* 0x119d    ᆝ*/
    {0x11b1},     /* 0x119e     ᆞ araea*/    /* <ㄻ>  */
    {0x0000},     /* 0x119f    ᆟ*/
    {0x0000},     /* 0x11a0    ᆠ*/
    {0x0000},     /* 0x11a1    ᆡ*/
    {0x0000},     /* 0x11a2    ᆢ*/
    {0x0000},     /* 0x11a3    ᆣ*/
    {0x0000},     /* 0x11a4   ᆤ*/
    {0x0000},     /* 0x11a5    ᆥ*/
    {0x0000},     /* 0x11a6    ᆦ*/
    {0x0000},    /* 0x11a7    ᆧ*/
    };

    static const ucschar jong_to_conjoin_jong[][1] = {// 끝소리 글쇠 두 번=겹받침
      {0x11a9},  /* 0x11a8 jongseong kiyeok (ㄱ)        -> jongseong ssangkiyeok (ㄲ)  */
      {0x0000},  /* 0x11a9 jongseong ssangkiyeok (ㄲ)   ->   */
      {0x0000},  /* 0x11aa jongseong kiyeok-sios (ㄳ)   ->      */
      {0x11ad},  /* 0x11ab jongseong nieun (ㄴ)        -> jongseong nieun-hieuh (ㄶ)   */
      {0x0000},  /* 0x11ac jongseong nieun-cieuc (ㄵ)  ->         */
      {0x0000},  /* 0x11ad jongseong nieun-hieuh (ㄶ)   ->         */
      {0x0000},  /* 0x11ae jongseong tikeut (ㄷ)       ->        */
      {0x11b0},  /* 0x11af jongseong rieul (ㄹ)        ->  jongseong rieul-kiyeok (ㄺ)   */
      {0x0000},  /* 0x11b0 jongseong rieul-kiyeok (ㄺ)  ->        */
      {0x0000},  /* 0x11b1 jongseong rieul-mieum (ㄻ)  ->        */
      {0x0000},  /* 0x11b2 jongseong rieul-pieup (ㄼ)  ->         */
      {0x0000},  /* 0x11b3 jongseong rieul-sios (ㄽ)   ->          */
      {0x0000},  /* 0x11b4 jongseong rieul-thieuth (ㄾ) ->       */
      {0x0000},  /* 0x11b5 jongseong rieul-phieuph (ㄿ) ->       */
      {0x0000},  /* 0x11b6 jongseong rieul-hieuh (ㅀ)  ->         */
      {0x11b1},  /* 0x11b7 jongseong mieum (ㅁ)        ->  jongseong rieul-mieum (ㄻ)      */
      {0x11b2},  /* 0x11b8 jongseong pieup (ㅂ)        -> jongseong rieul-pieup (ㄼ)      */
      {0x0000},  /* 0x11b9 jongseong pieup-sios (ㅄ)   ->          */
      {0x11b3},  /* 0x11ba jongseong sios (ㅅ)         -> jongseong rieul-sios (ㄽ)         */
      {0x11ac},  /* 0x11bb jongseong ssangsios (ㅆ)    -> jongseong nieun-cieuc (ㄵ) */
      {0x11b9},  /* 0x11bc jongseong ieung (ㅇ)        -> jongseong pieup-sios (ㅄ)        */
      {0x0000},  /* 0x11bd jongseong cieuc (ㅈ)        ->         */
      {0x0000},  /* 0x11be jongseong chieuch (ㅊ)      ->       */
      {0x11aa},  /* 0x11bf jongseong khieukh (ㅋ)      ->  jongseong kiyeok-sios (ㄳ)   */
      {0x11b4},  /* 0x11c0 jongseong thieuth (ㅌ)      -> jongseong rieul-thieuth (ㄾ)      */
      {0x11b5},  /* 0x11c1 jongseong phieuph (ㅍ)      -> jongseong rieul-phieuph (ㄿ)      */
      {0x11b6},  /* 0x11c2 jongseong hieuh (ㅎ)         -> jongseong rieul-hieuh (ㅀ)        */
    };

    if (conjoin) {
        if (c >= 0x1161 && c <= 0x11a7) {
            return jung_to_conjoin_jong[c - 0x1161][0];
        } else if (c >= 0x11a8 && c <= 0x11c2) {
            return jong_to_conjoin_jong[c - 0x11a8][0];
        } else {
            return 0;
        }
    } else {
        if (c >= 0x1100 && c <= 0x1112) {
            return cho_to_jung[c - 0x1100][0];
        } else if (c >= 0x11a8 && c <= 0x11c2) {
            return jong_to_jung[c - 0x11a8][0];
        } else {
            return 0;
        }
    }
}



ucschar
hangul_ascii_to_symbol_shin(int ascii, int step, int dummy)
{/* 신세벌 글판 특수기호 확장 배열 */
    static unsigned short ext_table[][3] = {
    { 0x0000, 0x0000, 0x0000 }, // 0x21 !:
    { 0x0000, 0x0000, 0x0000 }, // 0x22 ":
    { 0x0000, 0x0000, 0x0000 }, // 0x23 #:
    { 0x0000, 0x0000, 0x0000 }, // 0x24 $:        
    { 0x0000, 0x0000, 0x0000 }, // 0x25 %:       
    { 0x0000, 0x0000, 0x0000 }, // 0x26 &:
    { 0x326B, 0x266A, 0x266C }, // 0x27 ':   ㉫/0x326B/♪/0x266A/♬/0x266C
    { 0x0000, 0x0000, 0x0000 }, // 0x28 (:
    { 0x0000, 0x0000, 0x0000 }, // 0x29 ):
    { 0x0000, 0x0000, 0x0000 }, // 0x2A *: 
    { 0x0000, 0x0000, 0x0000 }, // 0x2B +:
    { 0x3001, 0x3008, 0x300A }, // 0x2C ,:       、/0x3001/〈/0x3008/《/0x300A
    { 0x00B1, 0x2642, 0x2601 }, // 0x2D -:      ±/0x00B1/♂/0x2642/☁/0x2601
    { 0x3002, 0x3009, 0x300B }, // 0x2E .:      。/0x3002/〉/0x3009/》/0x300B
    { 0x326A, 0x203B, 0x2620 }, // 0x2F /:     ㉪/0x326A/※/0x203B/☠/0x2620
    { 0x00A7, 0x2469, 0x2473 }, // 0x30 0:     §/0x00A7/⑩/0x2469/⑳/0x2473
    { 0x03BC, 0x2460, 0x246A }, // 0x31 1:         μ/0x03BC/①/0x2460/⑪/0x246A
    { 0x00B2, 0x2461, 0x246B }, // 0x32 2:          ²/0x00B2/②/0x2461/⑫/0x246B
    { 0x00B3, 0x2462, 0x246C }, // 0x33 3:         ³/0x00B3/③/0x2462/⑬/0x246C
    { 0xFFE6, 0x2463, 0x246D }, // 0x34 4:       ￦/0xFFE6/④/0x2463/⑭/0x246D
    { 0xFFE5, 0x2464, 0x246E }, // 0x35 5:        ￥/0xFFE5/⑤/0x2464/⑮/0x246E
    { 0x321C, 0x2465, 0x246F }, // 0x36 6:       ㈜/0x321C/⑥/0x2465/⑯/0x246F
    { 0xFFE1, 0x2466, 0x2470 }, // 0x37 7:       ￡/0xFFE1/⑦/0x2466/⑰/0x2470
    { 0x20AC, 0x2467, 0x2471 }, // 0x38 8:        €/0x20AC/⑧/0x2467/⑱/0x2471
    { 0xFFE0, 0x2468, 0x2472 }, // 0x39 9:       ￠/0xFFE0/⑨/0x2468/⑲/0x2472
    { 0x0000, 0x0000, 0x0000 }, // 0x3A ::
    { 0x3265, 0x25BD, 0x25BC }, // 0x3B ;:     ㉥/0x3265/▽/0x25BD/▼/0x25BC
    { 0x0000, 0x0000, 0x0000 }, // 0x3C <:     
    { 0x2260, 0x2640, 0x2603 }, // 0x3D =:      ≠/0x2260/♀/0x2640/☃/0x2603
    { 0x0000, 0x0000, 0x0000 }, // 0x3E >:  
    { 0x0000, 0x0000, 0x0000 }, // 0x3F ?: 
    { 0x0000, 0x0000, 0x0000 }, // 0x40 @:       
    { 0x0000, 0x0000, 0x0000 }, // 0x41 A:        
    { 0x0000, 0x0000, 0x0000 }, // 0x42 B:        
    { 0x0000, 0x0000, 0x0000 }, // 0x43 C:        
    { 0x0000, 0x0000, 0x0000 }, // 0x44 D:        
    { 0x0000, 0x0000, 0x0000 }, // 0x45 E:
    { 0x0000, 0x0000, 0x0000 }, // 0x46 F:        
    { 0x0000, 0x0000, 0x0000 }, // 0x47 G:
    { 0x0000, 0x0000, 0x0000 }, // 0x48 H:
    { 0x0000, 0x0000, 0x0000 }, // 0x49 I:
    { 0x0000, 0x0000, 0x0000 }, // 0x4A J:
    { 0x0000, 0x0000, 0x0000 }, // 0x4B K:
    { 0x0000, 0x0000, 0x0000 }, // 0x4C L:
    { 0x0000, 0x0000, 0x0000 }, // 0x4D M:
    { 0x0000, 0x0000, 0x0000 }, // 0x4E N:
    { 0x0000, 0x0000, 0x0000 }, // 0x4F O:
    { 0x0000, 0x0000, 0x0000 }, // 0x50 P:
    { 0x0000, 0x0000, 0x0000 }, // 0x51 Q:
    { 0x0000, 0x0000, 0x0000 }, // 0x52 R:        
    { 0x0000, 0x0000, 0x0000 }, // 0x53 S:        
    { 0x0000, 0x0000, 0x0000 }, // 0x54 T:        
    { 0x0000, 0x0000, 0x0000 }, // 0x55 U:
    { 0x0000, 0x0000, 0x0000 }, // 0x56 V:
    { 0x0000, 0x0000, 0x0000 }, // 0x57 W:
    { 0x0000, 0x0000, 0x0000 }, // 0x58 X:        
    { 0x0000, 0x0000, 0x0000 }, // 0x59 Y:
    { 0x0000, 0x0000, 0x0000 }, // 0x5A Z:        
    { 0x3010, 0x3014, 0x2600 }, // 0x5B [:      【/0x3010/〔/0x3014/☀/0x2600
    { 0x2252, 0x00B6, 0x00A6 }, // 0x5C \:   ≒/0x2252/¶/0x00B6/¦/0x00A6
    { 0x3011, 0x3015, 0x2602 }, // 0x5D ]:      】/0x3011/〕/0x3015/☂/0x2602
    { 0x0000, 0x0000, 0x0000 }, // 0x5E ^:
    { 0x0000, 0x0000, 0x0000 }, // 0x5F _:
    { 0x2122, 0x00A9, 0x00AE }, // 0x60 `:    ™/0x2122/©/0x00A9/®/0x00AE
    { 0x25C7, 0x25C8, 0x25C6 }, // 0x61 a:      ◇/0x25C7/◈/0x25C8/◆/0x25C6
    { 0x00F7, 0x2030, 0x2031 }, // 0x62 b:        ÷/0x00F7/‰/0x2030/‱/0x2031
    { 0x00B0, 0x260E, 0x2668 }, // 0x63 c:       °/0x00B0/☎/0x260E/♨/0x2668
    { 0x25CB, 0x25C9, 0x25CF }, // 0x64 d:      ○/0x25CB/◉/0x25C9/●/0x25CF
    { 0x2199, 0x2190, 0x261C }, // 0x65 e:          ↙/0x2199/←/0x2190/☜/0x261C
    { 0x00B7, 0x25E6, 0x2022 }, // 0x66 f:      ·/0x00B7/◦/0x25E6/•/0x2022
    { 0x2026, 0x2015, 0xFFE3 }, // 0x67 g:       …/0x2026/―/0x2015/￣/0xFFE3
    { 0x3261, 0x3003, 0x2713 }, // 0x68 h:       ㉡/0x3261/〃/0x3003/✓/0x2713
    { 0x3264, 0x2103, 0x2109 }, // 0x69 i:       ㉤/0x3264/℃/0x2103/℉/0x2109 
    { 0x3267, 0x2018, 0x201C }, // 0x6A j:       ㉧/0x3267/‘/0x2018/“/0x201C
    { 0x3260, 0x2019, 0x201D }, // 0x6B k:      ㉠/0x3260/’/0x2019/”/0x201D
    { 0x3268, 0x25B3, 0x25B2 }, // 0x6C l:       ㉨/0x3268/△/0x25B3/▲/0x25B2
    { 0x326D, 0x300D, 0x300F }, // 0x6D m:   ㉭/0x326D/」/0x300D/』/0x300F
    { 0x3266, 0x300C, 0x300E }, // 0x6E n:    ㉦/0x3266/「/0x300C/『/0x300E
    { 0x3269, 0x25B7, 0x25B6 }, // 0x6F o:    ㉩/0x3269/▷/0x25B7/▶/0x25B6
    { 0x326C, 0x25C1, 0x25C0 }, // 0x70 p:   ㉬/0x326C/◁/0x25C1/◀/0x25C0
    { 0x2196, 0x2193, 0x261F }, // 0x71 q:       ↖/0x2196/↓/0x2193/☟/0x261F
    { 0x2198, 0x2192, 0x261E }, // 0x72 r:      ↘/0x2198/→/0x2192/☞/0x261E
    { 0x25A1, 0x25A3, 0x25A0 }, // 0x73 s:    □/0x25A1/▣/0x25A3/■/0x25A0
    { 0x02D0, 0x2194, 0x21C4 }, // 0x74 t:       ː/0x02D0/↔/0x2194/⇄/0x21C4
    { 0x3262, 0x327E, 0x327F }, // 0x75 u:     ㉢/0x3262/㉾/0x327E/㉿/0x327F
    { 0x00D7, 0x2715, 0x2702 }, // 0x76 v:    ×/0x00D7/✕/0x2715/✂/0x2702
    { 0x2197, 0x2191, 0x261D }, // 0x77 w:        ↗/0x2197/↑/0x2191/☝/0x261D
    { 0x2032, 0x2606, 0x2605 }, // 0x78 x:    ′/0x2032/☆/0x2606/★/0x2605
    { 0x3263, 0x2195, 0x21C5 }, // 0x79 y:    ㉣/0x3263/↕/0x2195/⇅/0x21C5
    { 0x2033, 0x2661, 0x2665 }, // 0x7A z:     ″/0x2033/♡/0x2661/♥/0x2665
    { 0x0000, 0x0000, 0x0000 }, // 0x7B {:
    { 0x0000, 0x0000, 0x0000 }, // 0x7C |:      
    { 0x0000, 0x0000, 0x0000 }, // 0x7D }:
    { 0x0000, 0x0000, 0x0000 }, // 0x7E ~:
    { 0x0000, 0x0000, 0x0000 }, // 0x7F delete    ///´/0x00B4/Ұ/0x04B0/☏/0x260F
    };

    if (ascii < 0x21 || ascii > 0x7F) {
        return 0;
    } else if (step < 1 || step > 3 ) {
        return 0;
    } else {
        return ext_table[ascii - 0x21][step - 1];
    }
}


