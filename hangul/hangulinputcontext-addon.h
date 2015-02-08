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

#ifndef libhangul_hangulinputcontext_addon_h
#define libhangul_hangulinputcontext_addon_h
// hangulinputcontext.c 에 있는 함수들의 대부분이 static 라서
// 별도의 .c 가 아닌 .h 로 만들어서 
// hangulinputcontext.c 에 끼워넣기로 한다.

int
hangul_ic_get_extended_layout_index (HangulInputContext *hic)
{
    if (hic == NULL) {
        return 0;
    }

    return hic->extended_layout_index;
}

void
hangul_ic_set_extended_layout_mode (HangulInputContext *hic, bool enable)
{
    if (hic == NULL) {
        return;
    }

    if (hic->keyboard_addon != NULL) {
        if (hic->keyboard_addon->flag & HANGUL_KEYBOARD_FLAG_EXTENDED) {
            hic->extended_layout_enable = enable;
            return;
        }
    }
    hic->extended_layout_enable = FALSE;
}

void
hangul_ic_set_galmadeuli_method_mode (HangulInputContext *hic, bool enable)
{
    if (hic == NULL) {
        return;
    }

    if (hic->keyboard_addon != NULL) {
        if (hic->keyboard_addon->flag & HANGUL_KEYBOARD_FLAG_GALMADEULI) {
            hic->galmadeuli_method_enable = enable;
            return;
        }
    }
    hic->galmadeuli_method_enable = FALSE;
}

unsigned char
hangul_ic_get_layout_flags (HangulInputContext *hic)
{
    if (hic == NULL) {
        return 0;
    }

    if (hic->keyboard_addon != NULL) {
        return hic->keyboard_addon->flag;
    }

    return 0;
}



static bool
hangul_ic_process_jaso_shin_sebeol (HangulInputContext *hic, int ascii, ucschar ch)
{
    if (hic->extended_layout_enable) {
        if (hic->keyboard_addon != NULL) {
            if (hic->keyboard_addon->ext_key != NULL && hic->keyboard_addon->ext_value != NULL) {
                if (hic->keyboard_addon->ext_step != NULL) {
                    if (ascii == *(hic->keyboard_addon->ext_key+1) || ascii == *(hic->keyboard_addon->ext_key+2) || ascii == *(hic->keyboard_addon->ext_key+3)) {// 확장글쇠가 들어왔다
                        if (hic->buffer.choseong == *(hic->keyboard_addon->ext_value+0) && // 첫소리 0x110b (ㅇ) 이 있다
                                hic->buffer.jungseong == 0 &&   // 가윗소리가 없다
                                hic->extended_layout_index == 0) {// 확장모드가 아니다
                            if (hic->extended_layout_index == 0) {// 첫소리 0x110b (ㅇ) 이 있던 것을 지우고 뿌린다.
                                hic->buffer.choseong = 0;
                                hangul_ic_save_commit_string(hic);
                            }
                            // 신세벌식은 단계별 글쇠가 따로 있기 때문에 [1, 2, 3] 대신 [11, 12, 13] 을 쓴다.
                            // bool hangul_ic_backspace(HangulInputContext *hic)
                            if (ascii == *(hic->keyboard_addon->ext_key+1)) {
                                hic->buffer.choseong = *(hic->keyboard_addon->ext_step+0);
                                hic->extended_layout_index =  11;
                            } else if (ascii == *(hic->keyboard_addon->ext_key+2)) {
                                hic->buffer.choseong = *(hic->keyboard_addon->ext_step+1);
                                hic->extended_layout_index =  12;
                            } else if (ascii == *(hic->keyboard_addon->ext_key+3)) {
                                hic->buffer.choseong = *(hic->keyboard_addon->ext_step+2);
                                hic->extended_layout_index =  13;
                            } else {
                                hangul_buffer_clear(&hic->buffer);
                                hangul_ic_save_commit_string(hic);
                            }
                            hangul_ic_save_preedit_string(hic);
                            return true;
                        }
                    } 
                }

                if (hic->extended_layout_index >= 11 && hic->extended_layout_index <= 13) {
                    //index = [ #1, #2, #3 / 11, 12, 13 ]   // 확장 기호를 다룬다.
                    if (ch > 0) {
                        ucschar extended = 0;
                        if (hic->keyboard_addon->symbolFunc != NULL) {
                            extended = hic->keyboard_addon->symbolFunc(ascii, hic->extended_layout_index - 10, 0);
                        }

                        hangul_buffer_clear(&hic->buffer);//확장단계 표시 첫소리를 없앤다
                        hangul_ic_save_commit_string(hic);

                        if (extended) {// 확장기호가 있는 글쇠
                            hangul_ic_append_commit_string(hic, extended);
                        }
                        hangul_ic_save_preedit_string(hic);
                        return true;
                    } else {
                        hangul_ic_save_commit_string(hic);
                        return false;
                    }
                }
            }
        }
    }

    if (hangul_is_choseong(ch)) {
        if (hic->buffer.choseong == 0) {//첫소리 없고, 들어온 첫소리를 첫소리로 다룬다.
            if (!hangul_ic_push(hic, ch)) {
                if (!hangul_ic_push(hic, ch)) {
                    return false;
                }
            }
        } else {//첫소리 있고, 첫소리가 들어왔다.
            if (hic->buffer.jungseong == 0) {// 가윗소리가 없다
                // 첫소리 조합을 해보고 갈마들이로 간다
                ucschar choseong = 0;
                if (hangul_is_choseong(hangul_ic_peek(hic))) {
                    if (hic->keyboard_addon != NULL) {
                        if (hic->keyboard_addon->combination_addon != NULL) {
                            choseong = hangul_combination_combine(hic->keyboard_addon->combination_addon,
                                                                                        hic->buffer.choseong, ch);
                        }
                    }
                    if (choseong == 0) {
                        choseong = hangul_combination_combine(hic->keyboard->combination,
                                                                                        hic->buffer.choseong, ch);
                    }
                }
                if (hangul_is_choseong(choseong)) {
                    if (!hangul_ic_push(hic, choseong)) {
                        return false;
                    }
                } else {// 갈마들이
                    ucschar jungseong = 0;
                    if (hic->keyboard_addon != NULL) {
                        if (hic->keyboard_addon->galmadeuliFunc != NULL) {
                            jungseong = hic->keyboard_addon->galmadeuliFunc(ch, FALSE);
                        }
                    }
                    if (hangul_is_jungseong(jungseong)) {// 갈마들이 가윗소리 ㅜ, ㅗ, 아래아 가 겹홀소리에 쓰인다.
                        if (jungseong != 0x1174) {// 0x1174 (ㅢ) 는 뺀다.
                            hic->buffer.right_oua = jungseong;
                        }
                        if (!hangul_ic_push(hic, jungseong)) {
                            return false;
                        }
                    } else {//갈마들이 소리가 없으니 첫소리로 다룬다.
                        hangul_ic_save_commit_string(hic);
                        if (!hangul_ic_push(hic, ch)) {
                            return false;
                        }
                    }
                }
            } else {//가윗소리가 있으니 첫소리로
                hangul_ic_save_commit_string(hic);
                if (!hangul_ic_push(hic, ch)) {
                    return false;
                }
            }
        }
    } else if (hangul_is_jungseong(ch)) {
        if (hic->buffer.jungseong == 0) {//가윗소리가 없다.
            if (hic->buffer.jongseong == 0) {// 끝소리 없다. 첫소리가 있으나 없으나 가윗소리로
                if (hic->keyboard_addon != NULL && 
                        hic->keyboard_addon->moeum_key != NULL && 
                        (   ascii == *(hic->keyboard_addon->moeum_key+0) || 
                            ascii == *(hic->keyboard_addon->moeum_key+1)    )   ) {//shift+첫소리 [ᅟㅗ, ㅜ]
                    hic->buffer.right_oua = ch;
                }//shift+ㅁ [아래아] 는 홑홀소리
                if (!hangul_ic_push(hic, ch)) {
                    return false;
                }
            } else {// 끝소리 있다
                if (hic->buffer.choseong == 0) {//첫소리가 없다. 
                    if (hic->keyboard_addon != NULL && 
                            hic->keyboard_addon->moeum_key != NULL && 
                            (   ascii == *(hic->keyboard_addon->moeum_key+0) || 
                                ascii == *(hic->keyboard_addon->moeum_key+1)    )   ) {//shift+첫소리 [ㅗㅜ]
                        // 새로운 글자로
                        hangul_ic_save_commit_string(hic);
                        hic->buffer.right_oua = ch;
                        if (!hangul_ic_push(hic, ch)) {
                            return false;
                        }
                    } else { // 끝소리만 있다. 갈마들이로 가보자
                        //초성체에서 겹닿소리만 넣을 때는 끝소리를 아무거나 넣고 shift+끝글쇠[홀소리]로 넣는다.
                        ucschar jongseong = 0;
                        if (hic->keyboard_addon != NULL) {// conjoin
                            if (hic->keyboard_addon->galmadeuliFunc != NULL) {
                                jongseong = hic->keyboard_addon->galmadeuliFunc(ch, TRUE);// TRUE : 겹닿소리
                            }
                        }
                        if (hangul_is_jongseong(jongseong)) {// shift+글쇠에 겹받침이 있으면 끝소리로 다룬다. 초성체 겹닿소리
                            hangul_buffer_clear(&hic->buffer);
                            if (!hangul_ic_push(hic, jongseong)) {
                                return false;
                            }
                        } else {// 갈마들이 겹닿소리가 없다, 새로운 글자로
                            hangul_ic_save_commit_string(hic);
                            if (!hangul_ic_push(hic, ch)) {
                                return false;
                            }
                        }
                    }
                } else {// 첫소리, 끝소리가 있다. 새로운 글자로
                    //Shift + 글쇠인 가윗소리를 넣는다
                    hangul_ic_save_commit_string(hic);
                    if (!hangul_ic_push(hic, ch)) {
                        return false;
                    }               
                }
            }
        } else {// 가윗소리가 있다
            if (hic->buffer.jongseong == 0) {// 끝소리가 없으니
                if (hic->buffer.right_oua) {// 가윗소리 조합
                    if (hic->keyboard_addon != NULL && 
                            hic->keyboard_addon->moeum_key != NULL && 
                            (   ascii == *(hic->keyboard_addon->moeum_key+0) || 
                                ascii == *(hic->keyboard_addon->moeum_key+1)    )   ) {//shift+첫소리
                        hangul_ic_save_commit_string(hic);
                        hic->buffer.right_oua = ch;
                        if (!hangul_ic_push(hic, ch)) {
                            return false;
                        }
                    } else {// 첫소리 ㅇ 의 갈마들이 아래아만 겹홀소리로 조합할 수 있다.
                        //shift+ㅁ [아래아] 는 홑홀소리
                        // 홀소리 조합을 해보자
                        ucschar jungseong = 0;
                        if (hangul_is_jungseong(hangul_ic_peek(hic))) {
                            if (hic->keyboard_addon->combination_addon != NULL) {
                                jungseong = hangul_combination_combine(hic->keyboard_addon->combination_addon,
                                                                                                hic->buffer.jungseong, ch);
                            }
                            if (jungseong == 0) {
                                jungseong = hangul_combination_combine(hic->keyboard->combination,
                                                                                                hic->buffer.jungseong, ch);
                            }
                        }
                        if (hangul_is_jungseong(jungseong)) {// 조합된 가윗소리
                            if (!hangul_ic_push(hic, jungseong)) {
                                return false;
                            }
                        } else {// 조합이 되지 않으니 새로운 글자로
                            hangul_ic_save_commit_string(hic);
                            if (!hangul_ic_push(hic, ch)) {
                                return false;
                            }
                        }
                    }
                } else {// 조합이 되지 않는 가윗소리가 있으니, 갈마들이 겹받침으로 해보자
                    if (hic->keyboard_addon != NULL && 
                            hic->keyboard_addon->moeum_key != NULL && 
                            (   ascii == *(hic->keyboard_addon->moeum_key+0) || 
                                ascii == *(hic->keyboard_addon->moeum_key+1)    )   ) {//shift+첫소리
                        hangul_ic_save_commit_string(hic);
                        hic->buffer.right_oua = ch;
                        if (!hangul_ic_push(hic, ch)) {
                            return false;
                        }
                    } else {
                        ucschar jongseong = 0;
                        if (hic->keyboard_addon != NULL) {//겹받침
                            if (hic->keyboard_addon->galmadeuliFunc != NULL) {
                                jongseong = hic->keyboard_addon->galmadeuliFunc(ch, TRUE);// TRUE: 겹받침
                            }
                        }
                        if (hangul_is_jongseong(jongseong)) {// shift+끝소리에 겹받침이 있으면 겹받침으로 다룬다.
                            if (!hangul_ic_push(hic, jongseong)) {
                                return false;
                            }
                        } else {// shift+글쇠의 갈마들이 겹닿소리가 없으니, 새로운 글자로
                            hangul_ic_save_commit_string(hic);
                            if (!hangul_ic_push(hic, ch)) {
                                return false;
                            }
                        }
                    }
                }
            } else {// 가윗소리, 끝소리가 있다, 새로운 글자로
                hangul_ic_save_commit_string(hic);
                if (hic->keyboard_addon != NULL && 
                        hic->keyboard_addon->moeum_key != NULL && 
                        (   ascii == *(hic->keyboard_addon->moeum_key+0) || 
                            ascii == *(hic->keyboard_addon->moeum_key+1)    )   ) {//shift+첫소리
                    hic->buffer.right_oua = ch;
                }
                if (!hangul_ic_push(hic, ch)) {
                    return false;
                }
            }
        }
    } else if (hangul_is_jongseong(ch)) {
        if (hic->buffer.jungseong == 0) {// 가윗소리가 없다.
            if (hic->buffer.choseong == 0) {//첫소리가 없다.
                if (hic->buffer.jongseong == 0) {//끝소리가 없다.
                   if (!hangul_ic_push(hic, ch)) {
                        return false;
                    }
                } else {//끝소리가 있다. // 초성체를 위해
                    hangul_ic_save_commit_string(hic);
                    if (!hangul_ic_push(hic, ch)) {
                        return false;
                    }
                }
            } else {//첫소리가 있다.
                ucschar jungseong = 0;
                if (hic->keyboard_addon != NULL) {
                    if (hic->keyboard_addon->galmadeuliFunc != NULL) {
                        jungseong = hic->keyboard_addon->galmadeuliFunc(ch, FALSE); // FALSE : 홑소리
                    }
                }
                if (hangul_is_jungseong(jungseong)) {//가윗소리가 있는 글쇠는 가윗소리로.
                    if (!hangul_ic_push(hic, jungseong)) {
                        return false;
                    }
                } else {
                    if (!hangul_ic_push(hic, ch)) {
                        return false;
                    }
                }
            }
        } else {//가윗소리가 있다.
            if (hic->buffer.jongseong == 0) {//끝소리가 없다.
                // 먼저 끝소리를 가윗소리로 바꾸어 가윗소리 조합을 해본다.
                if (hangul_is_jungseong(hangul_ic_peek(hic)) && hic->buffer.right_oua) {
                    ucschar jungseong = 0;
                    ucschar jong_to_jung = 0;
                    if (hic->keyboard_addon != NULL) {
                        if (hic->keyboard_addon->galmadeuliFunc != NULL) {
                            jong_to_jung = hic->keyboard_addon->galmadeuliFunc(ch, FALSE);
                        }
                    }
                    if (jong_to_jung) {
                        if (hic->keyboard_addon->combination_addon != NULL) {
                            jungseong = hangul_combination_combine(hic->keyboard_addon->combination_addon,
                                                                                            hic->buffer.jungseong, jong_to_jung);
                        }
                        if (jungseong == 0) {
                            jungseong = hangul_combination_combine(hic->keyboard->combination,
                                                                                            hic->buffer.jungseong, jong_to_jung);
                        }
                    }
                    if (hangul_is_jungseong(jungseong)) {// 끝소리를 가윗소리로 바꾸어 가윗소리 조합이 되었다
                        if (!hangul_ic_push(hic, jungseong)) {
                            return false;
                        }
                    } else {
                        if (!hangul_ic_push(hic, ch)) {
                            return false;
                        }
                    }
                } else { // 끝소리를 가윗소리로 바꾸지 않고 끝소리로 다룬다
                    if (!hangul_ic_push(hic, ch)) {
                        return false;
                    }
                }
            } else {//끝소리가 있다.
                ucschar jongseong = 0;
                if (hangul_is_jongseong(hangul_ic_peek(hic))) {
                    if (hic->buffer.jongseong == ch) {//두 번 누를 때 겹받침으로 바꾼다.
                        if (hic->keyboard_addon != NULL) {
                            if (hic->keyboard_addon->galmadeuliFunc != NULL) {// conjoin
                                jongseong = hic->keyboard_addon->galmadeuliFunc(ch, TRUE);
                            }
                        }
                    }
                    if (jongseong == 0) {//끝소리가 다르거나 두 번 누를 때 겹받침으로 바꾸지 못하면 종성결합 규칙으로.
                        if (hic->keyboard_addon != NULL) {
                            if (hic->keyboard_addon->combination_addon != NULL) {
                                jongseong = hangul_combination_combine(hic->keyboard_addon->combination_addon,
                                                                                            hic->buffer.jongseong, ch);
                            }
                        }
                        if (jongseong == 0) {
                            jongseong = hangul_combination_combine(hic->keyboard->combination,
                                                                                            hic->buffer.jongseong, ch);
                        }
                    }
                }
                if (hangul_is_jongseong(jongseong)) { // 겹받침이 되었다
                    if (!hangul_ic_push(hic, jongseong)) {
                        return false;
                    }
                } else {
                    hangul_ic_save_commit_string(hic);
                    if (!hangul_ic_push(hic, ch)) {
                        return false;
                    }
                }
            }
        }
    } else if (ch > 0) {
        if (hic->keyboard_addon != NULL && 
                ( (hic->buffer.jungseong != 0 && hic->buffer.jongseong == 0) ||
                 (hic->buffer.choseong == 0 && hic->buffer.jungseong == 0 && hic->buffer.jongseong != 0) ) &&
              ascii == 'Z' && ch == 0x203B) {//※: 0x203B
            // 신세벌 2003 의 ㅁ (※) 의 윗글쇠에  홀소리가 없어서 shift + ㅁ = ㄻ (0x11b1) 은 여기서 다룬다.
            // 나머지는 hangul_shin_jungseong_to_conjoin_jongseong 에서 다룬다.
            ch = 0x11b1; /* ㄻ */
            if (!hangul_ic_push(hic, ch)) {
                return false;
            }
        } else {
            hangul_ic_save_commit_string(hic);
            hangul_ic_append_commit_string(hic, ch);
        }
    } else {
        hangul_ic_save_commit_string(hic);
        return false;
    }

    hangul_ic_save_preedit_string(hic);
    return true;
}


#endif /* libhangul_hangulinputcontext_addon_h */
