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
hangul_ic_process_jamo_dubeol (HangulInputContext *hic, ucschar ch)
{
    ucschar jong;
    ucschar combined = 0;

    // ch 가 한글자모가 아닐 경우, 조합하던 글자를 
    // commit_string 에 넣고 ch 를 뒤에 덧붙인다.
    if (!hangul_is_jamo(ch) && ch > 0) {
        hangul_ic_save_commit_string(hic);
        hangul_ic_append_commit_string(hic, ch);
        return true;
    }

    if (hic->buffer.jongseong) {// 끝소리가 있다
        if (hangul_is_choseong(ch)) {// 첫소리가 들어오면
            // 들어온 첫소리를 끝소리로 바꾸어서 있던 끝소리와 조합을 해본다.
            jong = hangul_ic_choseong_to_jongseong(hic, ch);
            if (hic->keyboard_addon != NULL) {
                if (hic->keyboard_addon->combination_addon != NULL) {
                    combined = hangul_combination_combine(hic->keyboard_addon->combination_addon,
                                                                                hic->buffer.jongseong, jong);
                }
            }
            if (combined == 0) {
                combined = hangul_combination_combine(hic->keyboard->combination,
                                                                                hic->buffer.jongseong, jong);
            }

            if (hangul_is_jongseong(combined)) {// 조합된 것이 끝소리면
                if (!hangul_ic_push(hic, combined)) {// 있던 끝소리 대신 넣는다
                    if (!hangul_ic_push(hic, ch)) {
                        return false;
                    }
                }
            } else {// 조합된 것이 끝소리가 아니면
                // 조합하던 글자를 commit_string 에 넣고
                // 첫소리 ch 를 넣어 글자조합을 새로 시작한다
                hangul_ic_save_commit_string(hic);
                if (!hangul_ic_push(hic, ch)) {
                    return false;
                }
            }
        } else if (hangul_is_jungseong(ch)) {// 가윗소리가 들어오면
            ucschar pop, peek;
            //stack 에서 마지막에 들어온 것 (끝소리) 을 빼낸다
            pop = hangul_ic_pop(hic);
            // 마지막 것을 빼낸 뒤의 것을 읽어온다
            peek = hangul_ic_peek(hic);
            // 끝소리 ㄺ 이 있었다면 peek : ㄹ, pop : ㄱ, 
            if (hangul_is_jongseong(peek)) {// 하나 빼낸 뒤의 것도 끝소리면
                // 끝소리를 앞의 것은 끝소리, 뒤의 것은 첫소리로 나누어 본다.
                // 끝소리 ㄺ 있었을 때, 나누어 진다면 끝소리 ㄱ 을 첫소리 ㄱ 으로 바꾸어 줄 것이다.
                ucschar choseong = hangul_jongseong_get_diff(peek,
                                                hic->buffer.jongseong);
                if (choseong == 0) {// 나누어지지 않는다면
                    hangul_ic_save_commit_string(hic);
                    if (!hangul_ic_push(hic, ch)) {
                        return false;
                    }
                } else {// 끝소리, 첫소리로 나누어 진다면
                    hic->buffer.jongseong = peek;
                    hangul_ic_save_commit_string(hic);
                    hangul_ic_push(hic, choseong);
                    if (!hangul_ic_push(hic, ch)) {
                        return false;
                    }
                }
            } else {// 하나 빼낸 뒤의 것이 끝소리가 아니면
                hic->buffer.jongseong = 0;
                hangul_ic_save_commit_string(hic);
                // 빼낸 끝소리 pop 을 첫소리로 바꾸어 넣는다
                hangul_ic_push(hic, hangul_jongseong_to_choseong(pop));
                if (!hangul_ic_push(hic, ch)) {
                    return false;
                }
            }
        } else {// 첫소리, 가윗소리는 앞에서 확인했으니 끝소리
            goto flush;
        }
    } else if (hic->buffer.jungseong) {// 끝소리 없이 가윗소리가 있다
        if (hangul_is_choseong(ch)) {// 첫소리가 들어왔다
            if (hic->buffer.choseong) {// 첫소리가 있다
                // 들어온 첫소리를 끝소리로 바꾼다
                jong = hangul_ic_choseong_to_jongseong(hic, ch);
                if (hangul_is_jongseong(jong)) {// 첫소리가 끝소리로 바뀌었다
                    if (!hangul_ic_push(hic, jong)) {
                        if (!hangul_ic_push(hic, ch)) {
                            return false;
                        }
                    }
                } else {// 첫소리가 끝소리로 바뀌지 않았다
                    hangul_ic_save_commit_string(hic);
                    if (!hangul_ic_push(hic, ch)) {
                        return false;
                    }
                }
            } else {// 첫소리가 없다
                if (!hangul_ic_push(hic, ch)) {
                    if (!hangul_ic_push(hic, ch)) {
                        return false;
                    }
                }
            }
        } else if (hangul_is_jungseong(ch)) {// 가윗소리가 들어왔다
            ucschar compress = 0;
            // 바꿔놓기를 위한 곳이다. <두벌 순아래>, < 북한 국규>
            // 첫소리 + 가윗소리 + 가윗소리 = 된소리 + 가윗소리
            if (hic->buffer.choseong) {// 첫소리가 있으면 된소리로 바꾸어 본다
                if (hic->keyboard_addon != NULL) {
                    if (hic->keyboard_addon->replace_it) {// 낱소리 바꿔놓기가 참이다
                        if (ch == hangul_ic_peek(hic)) {
                            //compress = choseong_compress(hic->buffer.choseong, hic->buffer.choseong);//좋은데, static 이네.
                            compress = choseong_compress_addon(hic->buffer.choseong, hic->buffer.choseong);
                        }
                    }
                }
            }

            if (compress) {// 첫소리가 된소리로 바뀌었다
                if (!hangul_ic_push(hic, compress)) {
                    return false;
                }
            } else {// 첫소리가 된소리로 바뀌지 않았다
                // 있던 가윗소리와 들어온 가윗소리를 하나로 만들어 본다
                if (hic->keyboard_addon != NULL) {
                    if (hic->keyboard_addon->combination_addon != NULL) {
                        combined = hangul_combination_combine(hic->keyboard_addon->combination_addon,
                                                                                    hic->buffer.jungseong, ch);
                    }
                }
                if (combined == 0) {
                    combined = hangul_combination_combine(hic->keyboard->combination,
                                                                                    hic->buffer.jungseong, ch);
                }

                if (hangul_is_jungseong(combined)) {// 가윗소리 둘이 하나가 되었다
                    if (!hangul_ic_push(hic, combined)) {
                        return false;
                    }
                } else {// 가윗소리 둘이 하나가 되지 못했다
                    hangul_ic_save_commit_string(hic);
                    if (!hangul_ic_push(hic, ch)) {
                        return false;
                    }
                }
            }
        } else { // 남은 것은 끝소리
            goto flush;
        }
    } else if (hic->buffer.choseong) {// 끝소리, 가윗소리 없이 첫소리가 있다
        if (hangul_is_choseong(ch)) {// 첫소리가 들어왔다
            // 있던 첫소리와 하나로 만들어 본다
            if (hic->keyboard_addon != NULL) {
                if (hic->keyboard_addon->combination_addon != NULL) {
                    combined = hangul_combination_combine(hic->keyboard_addon->combination_addon,
                                                                                hic->buffer.choseong, ch);
                }
            }
            if (combined == 0) {
                combined = hangul_combination_combine(hic->keyboard->combination,
                                                                                hic->buffer.choseong, ch);
            }

            if (!hangul_ic_push(hic, combined)) {// 첫소리 둘이 하나가 되었다
                if (!hangul_ic_push(hic, ch)) {// 첫소리 둘이 하나가 되지 못했으니 그냥 넣는다
                    return false;
                }
            }
        } else {// 나머지 가윗소리, 끝소리는 없으니 그냥 넣는다
            if (!hangul_ic_push(hic, ch)) {
                if (!hangul_ic_push(hic, ch)) {
                    return false;
                }
            }
        }
    } else {// 아무것도 없다. 그냥 넣는다
        if (!hangul_ic_push(hic, ch)) {
            return false;
        }
    }

    hangul_ic_save_preedit_string(hic);
    return true;

flush:
    hangul_ic_flush_internal(hic);
    return false;
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

static bool
hangul_ic_process_jaso_sebeol (HangulInputContext *hic, int ascii, ucschar ch)
{
    if (hic->extended_layout_enable) {
        if (hic->keyboard_addon != NULL) {
            if (hic->keyboard_addon->ext_key != NULL) {// 확장 기호 글쇠가 있다
                if (hic->keyboard_addon->ext_step != NULL) {// 확장 기호 단계가 있다
                    if (*(hic->keyboard_addon->ext_key+0) == '1') {// 기호 글쇠가 각각 다른 배열을 쓴다
                        if ((ascii == *(hic->keyboard_addon->ext_key+1) && hic->extended_layout_index < 3) || 
                                ascii == *(hic->keyboard_addon->ext_key+2)) {// 확장 기호 글쇠 누름
                            if (    hangul_buffer_is_empty(&(hic->buffer)) ||          // ( 아무것도 없거나
                                    hangul_buffer_has_jungseong(&(hic->buffer)) || // 가윗소리가 있거나
                                    (hic->extended_layout_index != 0 && hic->extended_layout_prevkey == ascii)    ) {// 확장모드 일 때 )
                                if (hic->extended_layout_index == 0) {// 있던 것을 뿌린다.
                                    if (hic->keyboard_addon->ext_value != NULL) {
                                        if (hic->buffer.right_oua) {// 가윗소리에 확장글쇠의 겹홀소리가 있으면 지워준다
                                            if (hic->buffer.jungseong ==  *(hic->keyboard_addon->ext_value+0) ||
                                                    hic->buffer.jungseong ==  *(hic->keyboard_addon->ext_value+1) ) {
                                                hic->buffer.jungseong = 0;
                                            }
                                        }
                                    }
                                    hangul_ic_save_commit_string(hic);
                                }
                                // 확장 단계를 올린다
                                hic->extended_layout_index += 1;
                                hic->extended_layout_prevkey = ascii;

                                switch (hic->extended_layout_index) {
                                    case 1 : 
                                                hic->buffer.choseong = *(hic->keyboard_addon->ext_step+0);
                                                break;
                                    case 2 : 
                                                hic->buffer.choseong = *(hic->keyboard_addon->ext_step+1);
                                                break;
                                    case 3 : 
                                                hic->buffer.choseong = *(hic->keyboard_addon->ext_step+2);
                                                break;
                                    case 4 : 
                                                hic->buffer.choseong = *(hic->keyboard_addon->ext_step+3);
                                                break;
                                    case 5 : 
                                                hic->buffer.choseong = *(hic->keyboard_addon->ext_step+4);
                                                break;
                                    default :
                                                hangul_buffer_clear(&hic->buffer);
                                                hangul_ic_save_commit_string(hic);
                                                break;
                                }
                                hangul_ic_save_preedit_string(hic);
                                return true;
                            }
                        } else if (hic->keyboard_addon->han_key != NULL) {// 확장 한글 글쇠가 있다
                            if (ascii == *(hic->keyboard_addon->han_key+0) || ascii == *(hic->keyboard_addon->han_key+1)) {// 확장 한글 글쇠 누름
                                // 여기는 한글조합에 쓰이기 때문에 있던 것을 뿌리지 않는다

                                if (hic->extended_layout_index == 0) {
                                    hic->extended_layout_prevkey = ascii;
                                } else if (hic->extended_layout_prevkey != ascii) {
                                    // 앞에서와 다른 한글확장 글쇠가 들어와서 조합을 끝낸다
                                    hangul_ic_save_commit_string(hic);
                                    return true;
                                }
                                    
                                // 확장 단계를 올린다
                                if (hic->extended_layout_index < 2) {
                                    hic->extended_layout_index += 1;
                                } else {
                                    hic->extended_layout_index = 0;
                                }

                                // 여기는 한글조합에 쓰이기 때문에 단계를 나타내지 않는다

                                hangul_ic_save_preedit_string(hic);
                                return true;
                            }
                        }
                    } else {// 기호 글쇠가 같은 배열을 쓴다
                        if (ascii == *(hic->keyboard_addon->ext_key+1) || 
                                ascii == *(hic->keyboard_addon->ext_key+2)) {// 확장 기호 글쇠 누름
                            if ( hangul_buffer_is_empty(&(hic->buffer)) ||          // ( 아무것도 없거나
                                    hangul_buffer_has_jungseong(&(hic->buffer)) || // 가윗소리가 있거나
                                    hic->extended_layout_index != 0 ) {                 // 확장모드 일 때 )
                                if ( hic->extended_layout_index < 2 ||
                                        (hic->extended_layout_index == 2 && // 확장단계가 2 일 때는
                                        hic->extended_layout_prevkey == ascii) ) {//앞에서와 같은 확장글쇠가 들어와야 한다
                                    if (hic->extended_layout_index == 0) {// 있던 것을 뿌린다.
                                        if (hic->keyboard_addon->ext_value != NULL) {
                                            if (hic->buffer.right_oua) {// 가윗소리에 확장글쇠의 겹홀소리가 있으면 지워준다
                                                if (hic->buffer.jungseong ==  *(hic->keyboard_addon->ext_value+0) ||
                                                        hic->buffer.jungseong ==  *(hic->keyboard_addon->ext_value+1) ) {
                                                    hic->buffer.jungseong = 0;
                                                }
                                            }
                                        }
                                        hangul_ic_save_commit_string(hic);
                                    }

                                    //앞에서와 다른 확장글쇠면 1단에서 바로 3단으로 뛴다.
                                    if (hic->extended_layout_index == 1 && hic->extended_layout_prevkey != ascii) {
                                        hic->extended_layout_index += 2;
                                    } else {
                                        hic->extended_layout_index += 1;
                                    }
                                    hic->extended_layout_prevkey = ascii;

                                    switch (hic->extended_layout_index) {
                                        case 1 : 
                                                    hic->buffer.choseong = *(hic->keyboard_addon->ext_step+0);
                                                    break;
                                        case 2 : 
                                                    hic->buffer.choseong = *(hic->keyboard_addon->ext_step+1);
                                                    break;
                                        case 3 : 
                                                    hic->buffer.choseong = *(hic->keyboard_addon->ext_step+2);
                                                    break;
                                        default :
                                                    hangul_buffer_clear(&hic->buffer);
                                                    hangul_ic_save_commit_string(hic);
                                                    break;
                                    }

                                    hangul_ic_save_preedit_string(hic);
                                    return true;
                                }
                            }
                        }
                    }
                }

                if (hic->extended_layout_index >= 1 && hic->extended_layout_index <= 5 ) {
                    //index = [ 1, 2, 3, 4, 5 ]   // 확장 기호를 다룬다.
                    if (ch > 0) {
                        ucschar extended = 0;
                        if (*(hic->keyboard_addon->ext_key+0) == '1') {// 기호 글쇠가 각각 다른 배열을 쓴다
                            if ( hic->keyboard_addon->han_key != NULL &&
                                    (hic->extended_layout_prevkey == *(hic->keyboard_addon->han_key+0) || 
                                    hic->extended_layout_prevkey == *(hic->keyboard_addon->han_key+1)) ) {// 한글 확장
                                if (hic->keyboard_addon->yethanguelFunc != NULL) {
                                    if (hic->extended_layout_prevkey == *(hic->keyboard_addon->han_key+0)) {// 앞한글
                                        extended = hic->keyboard_addon->yethanguelFunc(ascii, hic->extended_layout_index, 0);
                                    } else {// 뒷한글
                                        extended = hic->keyboard_addon->yethanguelFunc(ascii, hic->extended_layout_index, 1);
                                    }
                                }
                                // 한글확장에서는 버퍼 청소를 하지 않으니 여기서 확장단계를 없애준다
                                hic->extended_layout_index = 0;
                                if (extended) {
                                    ch = extended;
                                } else {// 참을 돌려줘야 값이 없는 글쇠를 눌렀을 때 [ 알파벳 ]이 들어가지 않는다
                                    hangul_ic_save_commit_string(hic);
                                    return true;
                                }
                            } else {// 기호 확장
                                if (hic->keyboard_addon->symbolFunc != NULL) {
                                    if (hic->extended_layout_prevkey == *(hic->keyboard_addon->ext_key+1)) {// 아랫기호
                                        extended = hic->keyboard_addon->symbolFunc(ascii, hic->extended_layout_index, 0);
                                    } else if (hic->extended_layout_prevkey == *(hic->keyboard_addon->ext_key+2)) {// 윗기호
                                        extended = hic->keyboard_addon->symbolFunc(ascii, hic->extended_layout_index, 1);
                                    }
                                }
                                hangul_buffer_clear(&hic->buffer);//확장단계 표시 첫소리를 없앤다
                                hangul_ic_save_commit_string(hic);
                                if (extended) {// 확장기호가 있는 글쇠
                                    hangul_ic_append_commit_string(hic, extended);
                                }
                                hangul_ic_save_preedit_string(hic);
                                return true;
                            }
                        } else {// // 기호 글쇠가 같은 배열을 쓴다
                            if (hic->keyboard_addon->symbolFunc != NULL) {
                                extended = hic->keyboard_addon->symbolFunc(ascii, hic->extended_layout_index, 0);
                            }

                            hangul_buffer_clear(&hic->buffer);//확장단계 표시 첫소리를 없앤다
                            hangul_ic_save_commit_string(hic);

                            if (extended) {// 확장기호가 있는 글쇠
                                hangul_ic_append_commit_string(hic, extended);
                            }
                            hangul_ic_save_preedit_string(hic);
                            return true;
                        }
                    } else {
                        hangul_ic_save_commit_string(hic);
                        return false;
                    }
                }
            }
        }
    }

    // 아래아
    if (ascii == '[') {
        //첫소리가 있고 끝소리가 없으며, 가윗소리가 없거나 아래아 일 때
        if (hic->buffer.choseong && hic->buffer.jongseong == 0) {
            if (hic->keyboard_addon != NULL) {
                if (hic->keyboard_addon->replace_it == 0x119e) {// [ 는 아래 아(ㆍ)로 구실한다
                    if (hic->buffer.jungseong == 0 || hic->buffer.jungseong == hic->keyboard_addon->replace_it) {
                        ch = hic->keyboard_addon->replace_it;// 아래아
                    }
                }
            }
        }
    }

    if (hangul_is_choseong(ch)) {// 첫소리가 들어왔다
        if (hic->buffer.choseong == 0) {// 첫소리가 없다
            if (!hangul_ic_push(hic, ch)) {
                if (!hangul_ic_push(hic, ch)) {
                    return false;
                }
            }
        } else {// 첫소리가 있다
            ucschar choseong = 0;
            bool combine = false;
            if ( (hic->buffer.choseong == ch) && 
                    ( (hic->keyboard_addon != NULL) && 
                        (hic->keyboard_addon->flag & HANGUL_KEYBOARD_FLAG_NOT_REPEAT_CHOSEONG) ) ) {
                combine = false;// 첫소리 연타 (ㄱ + ㄱ) 의 조합을 하지 않는다
            } else if (hangul_is_choseong(hangul_ic_peek(hic))) {
                // 바로 앞의 것이 첫소리면 하나로 만들어 본다
                combine = true;
            } else if ( (hic->keyboard_addon != NULL) && 
                    (hic->keyboard_addon->flag & HANGUL_KEYBOARD_FLAG_LOOSE_ORDER) ) {
                combine = true;
            }
            if (combine) {
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
            if (hangul_is_choseong(choseong)) {// 하나로 되었다
                if (!hangul_ic_push(hic, choseong)) {
                    if (!hangul_ic_push(hic, choseong)) {
                        return false;
                    }
                }
            } else {// 하나로 되지 못했다
                hangul_ic_save_commit_string(hic);
                if (!hangul_ic_push(hic, ch)) {
                    return false;
                }
            }
        }
    } else if (hangul_is_jungseong(ch)) {// 가윗소리가 들어왔다
        if (hic->buffer.jungseong == 0) {// 가윗소리가 없다
            if (hic->keyboard_addon != NULL) {
                // 겹홀소리에 쓰이는 ㅗ, ㅜ 가 들어왔다
                if (hic->keyboard_addon->moeum_key != NULL && 
                    hic->keyboard_addon->moeum_value != NULL &&
                    (   (ch == *(hic->keyboard_addon->moeum_value+0) && ascii == *(hic->keyboard_addon->moeum_key+0)) || 
                        (ch == *(hic->keyboard_addon->moeum_value+1) && ascii == *(hic->keyboard_addon->moeum_key+1))  ) ) {
                    hic->buffer.right_oua = ch;
                } else if (ascii == '[' && ch == hic->keyboard_addon->replace_it) {// [ 를 아래아로 바꾸었다
                    hic->buffer.right_oua = ch;
                }
            }
            if (!hangul_ic_push(hic, ch)) {
                if (!hangul_ic_push(hic, ch)) {
                    return false;
                }
            }
        } else {// 가윗소리가 있으니 먼저 가윗소리 조합을 해보고 안 되면 갈마들이로 간다
            ucschar jungseong = 0;
            bool combine = false;
            bool new_start = false;
            if (hic->keyboard_addon != NULL) {
                if (hic->keyboard_addon->flag & HANGUL_KEYBOARD_FLAG_RIGHT_OU) {
                    // 왼/오른 ㅗ, ㅜ 를 반드시 구분해야 하는 글판 (갈마들이 글판)
                    // 가윗소리가 있고 겹홀소리의 ㅗ, ㅜ 가 들어왔다
                    if ( hic->keyboard_addon->moeum_key != NULL && 
                            hic->keyboard_addon->moeum_value != NULL &&
                            (   (   ch == *(hic->keyboard_addon->moeum_value+0) && 
                                    ascii == *(hic->keyboard_addon->moeum_key+0)    ) || 
                                (   ch == *(hic->keyboard_addon->moeum_value+1) && 
                                    ascii == *(hic->keyboard_addon->moeum_key+1))   )   ) {
                        new_start = true;
                        combine = false;
                    } else if (hic->buffer.right_oua || (hic->buffer.choseong == 0)) {
                        combine = hangul_is_jungseong(hangul_ic_peek(hic));
                    } else {
                        combine = false;
                    }
                } else {
                    if (hic->keyboard_addon->flag & HANGUL_KEYBOARD_FLAG_LOOSE_ORDER) {
                        // 입력 순서를 따지지 않는다, 모아치기 2014
                        combine = true;
                    } else {
                        //가윗소리 조합은 바로 앞에서 홀소리를 넣었을 때만 한다.
                        combine = hangul_is_jungseong(hangul_ic_peek(hic));
                    }
                }
            } else {//가윗소리 조합은 바로 앞에서 홀소리를 넣었을 때만 한다.
                combine = hangul_is_jungseong(hangul_ic_peek(hic));
            }

            if (new_start) {// 새로운 글자를 시작한다
                // 왼/오른 ㅗㅜ 를 구분하는 글판에서 가윗소리가 있을 때 오른 ㅗㅜ 라면 새로운 글자가 된다
                hangul_ic_save_commit_string(hic);
                hic->buffer.right_oua = ch;
                if (!hangul_ic_push(hic, ch)) {
                    return false;
                }
            } else {
                if (combine) {// 가윗소리 조합이 된다면, 가윗소리 둘을 하나로 만들어 본다
                    if (hic->keyboard_addon != NULL) {
                        if (hic->keyboard_addon->combination_addon != NULL) {
                            jungseong = hangul_combination_combine(hic->keyboard_addon->combination_addon,
                                                                                        hic->buffer.jungseong, ch);
                        }
                    }
                    if (jungseong == 0) {
                        jungseong = hangul_combination_combine(hic->keyboard->combination,
                                                                                        hic->buffer.jungseong, ch);
                    }
                }
                if (hangul_is_jungseong(jungseong)) {// 둘이 하나가 되었다
                    if (!hangul_ic_push(hic, jungseong)) {
                        if (!hangul_ic_push(hic, jungseong)) {
                            return false;
                        }
                    }
                } else {// 둘이 하나가 되지 못했다. 갈마들이로 해보자
                    ucschar jung_jongseong = 0;
                    if (hic->galmadeuli_method_enable) {//  새로운 글자가 아니면 갈마들이를 해본다
                        if (hic->buffer.choseong) {// 첫소리, 가윗소리가 있다
                            if (hic->keyboard_addon != NULL) {
                                if (hic->keyboard_addon->galmadeuliFunc != NULL) {
                                    jung_jongseong = hic->keyboard_addon->galmadeuliFunc(ch, FALSE);
                                }
                            }
                        }
                    }
                    if (jung_jongseong) {// 갈마들이에 소리가 있다
                        if (hangul_is_jungseong(jung_jongseong)) {// 가윗소리다
                            // ㅣ+ㅐ, ㅐ+ㅐ
                            if (hangul_is_jungseong(hangul_ic_peek(hic)) && // 바로 앞에서 가윗소리를 눌렀다
                                    ( (hic->buffer.jungseong == 0x1175) || 
                                    (hic->buffer.jungseong == 0x1162) ) ) {// 같은 글쇠를 거듭눌렀다
                                if (!hangul_ic_push(hic, jung_jongseong)) {
                                    if (!hangul_ic_push(hic, jung_jongseong)) {
                                        return false;
                                    }
                                }
                            } else {// 가윗소리 조합이 안 되고 갈마들이 가윗소리로 바꾸지도 못 했다
                                hangul_ic_save_commit_string(hic);
                                if (!hangul_ic_push(hic, ch)) {
                                    if (!hangul_ic_push(hic, ch)) {
                                        return false;
                                    }
                                }
                            }
                        } else {// 갈마들이 끝소리다
                            if (hic->buffer.jongseong == 0) {
                                if (!hangul_ic_push(hic, jung_jongseong)) {
                                    if (!hangul_ic_push(hic, jung_jongseong)) {
                                        return false;
                                    }
                                }
                            } else {
                                ucschar jongseong = 0;
                                combine = false;
                                if ( (hic->buffer.jongseong == jung_jongseong) && 
                                        ( (hic->keyboard_addon != NULL) && 
                                            (hic->keyboard_addon->flag & HANGUL_KEYBOARD_FLAG_NOT_REPEAT_JONGSEONG) ) ) {
                                    combine = false;// 끝소리 연타 (ㄱ + ㄱ) 의 조합을 하지 않는다
                                } else if (hangul_is_jongseong(hangul_ic_peek(hic))) {
                                    combine = true;
                                } else if ( (hic->keyboard_addon != NULL) && 
                                        (hic->keyboard_addon->flag & HANGUL_KEYBOARD_FLAG_LOOSE_ORDER) ) {
                                    combine = true;
                                }
                                if (combine) {
                                    if (hic->keyboard_addon != NULL) {
                                        if (hic->keyboard_addon->combination_addon != NULL) {
                                            jongseong = hangul_combination_combine(hic->keyboard_addon->combination_addon,
                                                                                                        hic->buffer.jongseong, jung_jongseong);
                                        }
                                    }
                                    if (jongseong == 0) {
                                        jongseong = hangul_combination_combine(hic->keyboard->combination,
                                                                                                        hic->buffer.jongseong, jung_jongseong);
                                    }
                                    if ((jongseong == 0) && hic->galmadeuli_method_enable) {
                                        // 끝소리 조합이 안 되고 끝홑닿소리와 갈마들이 끝홑닿소리가 같으면, 갈마들이 연타 겹받침으로
                                        if (hic->buffer.jongseong == jung_jongseong) {
                                            if (hic->keyboard_addon != NULL) {
                                                if (hic->keyboard_addon->galmadeuliFunc != NULL) {
                                                    jongseong = hic->keyboard_addon->galmadeuliFunc(ch, TRUE);    // conjoin
                                                }
                                            }
                                        }
                                    }
                                }
                                if (hangul_is_jongseong(jongseong)) {// 하나가 되었다
                                    if (!hangul_ic_push(hic, jongseong)) {
                                        return false;
                                    }
                                } else {//끝겹닿소리가 안 되니 본래의 값인 가윗소리로 한다
                                    hangul_ic_save_commit_string(hic);
                                    if (!hangul_ic_push(hic, ch)) {
                                        return false;
                                    }
                                }
                            }
                        }
                    } else {// 가윗소리 조합도 안 되고 갈마들이 소리도 없으니 가윗소리로 한다
                        hangul_ic_save_commit_string(hic);
                        if (!hangul_ic_push(hic, ch)) {
                            return false;
                        }
                    }
                }
            }
        }
    } else if (hangul_is_jongseong(ch)) {// 끝소리가 들어왔다
        if (hic->buffer.jongseong == 0) {// 끝소리가 없다
            if (hic->buffer.jungseong == 0) {// 가윗소리가 없다
                if (!hangul_ic_push(hic, ch)) {
                    if (!hangul_ic_push(hic, ch)) {
                        return false;
                    }
                }
            } else {
                ucschar jongseong = 0;
                if (hic->galmadeuli_method_enable) {// 갈마들이를 켰을 때, shift+가윗소리=겹받침
                    if (hic->buffer.choseong) {// 첫소리, 가윗소리가 있다
                        // 갈마들이 겹받침으로.
                        if (hic->keyboard_addon != NULL) {
                            if (hic->keyboard_addon->galmadeuliFunc != NULL) {
                                jongseong = hic->keyboard_addon->galmadeuliFunc(ch, TRUE);    // conjoin
                            }
                        }
                    }
                }
                if (hangul_is_jongseong(jongseong)) {
                    if (!hangul_ic_push(hic, jongseong)) {
                        if (!hangul_ic_push(hic, jongseong)) {
                            return false;
                        }
                    }
                } else {
                    if (!hangul_ic_push(hic, ch)) {
                        if (!hangul_ic_push(hic, ch)) {
                            return false;
                        }
                    }
                }
            }
        } else {// 끝소리가 있으니 끝소리 조합을 먼저 해보자
            ucschar jongseong = 0;
            bool combine = false;
            // 바로 앞의 소리가 끝소리면, 끝소리 둘을 하나로 만들어 본다
            // 모아치기 2014 에서는 바로 앞에서 끝소리를 넣지 않았어도 끝소리가 있으면 조합해 본다
            if ( (hic->buffer.jongseong == ch) && 
                    ( (hic->keyboard_addon != NULL) && 
                        (hic->keyboard_addon->flag & HANGUL_KEYBOARD_FLAG_NOT_REPEAT_JONGSEONG) ) ) {
                combine = false;// 끝소리 연타 (ㄱ + ㄱ) 의 조합을 하지 않는다
            } else if (hangul_is_jongseong(hangul_ic_peek(hic))) {
                combine = true;
            } else if ( (hic->keyboard_addon != NULL) && 
                    (hic->keyboard_addon->flag & HANGUL_KEYBOARD_FLAG_LOOSE_ORDER) ) {
                combine = true;
            }

            if (combine) {
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
                if ((jongseong == 0) && hic->galmadeuli_method_enable) {
                    // 끝소리 조합이 안 되고 끝홑닿소리와들어온 끝홑닿소리가 같으면, 갈마들이 연타 겹받침으로
                    if (hic->buffer.jongseong == ch) {
                        if (hic->keyboard_addon != NULL) {
                            if (hic->keyboard_addon->galmadeuliFunc != NULL) {
                                jongseong = hic->keyboard_addon->galmadeuliFunc(ch, TRUE);    // conjoin
                            }
                        }
                    }
                }
            }

            if (hangul_is_jongseong(jongseong)) {// 겹받침이 되었다
                if (!hangul_ic_push(hic, jongseong)) {
                    if (!hangul_ic_push(hic, jongseong)) {
                        return false;
                    }
                }
            } else {// 안 되었다
                hangul_ic_save_commit_string(hic);
                if (!hangul_ic_push(hic, ch)) {
                    if (!hangul_ic_push(hic, ch)) {
                        return false;
                    }
                }
            }
        }
    } else if (ch > 0) {// 한글 자소가 아닌 것이 들어왔다
        hangul_ic_save_commit_string(hic);
        hangul_ic_append_commit_string(hic, ch);
    } else {// 이것은 뭣도 아닌 것이 들어왔네
        hangul_ic_save_commit_string(hic);
        return false;
    }

    hangul_ic_save_preedit_string(hic);
    return true;
}

static bool
hangul_ic_process_3finalsun (HangulInputContext *hic, int ascii, ucschar ch)
{
    #define SHKEY            0x11ff
    ucschar orig_ch = ch;

    if (ascii == '[') {//
        if (hangul_buffer_is_empty (&hic->buffer) == FALSE) {
            if (hic->buffer.shift == 0) {
                ch = SHKEY;
            }
        }
    }

    if (hangul_is_choseong(ch)) {
        if (hic->buffer.choseong == 0) {
            if (!hangul_ic_push(hic, ch)) {
                if (!hangul_ic_push(hic, ch)) {
                    return false;
                }
            }
        } else {
            ucschar choseong = 0;
            if (hangul_is_choseong(hangul_ic_peek(hic))) {
                choseong = hangul_combination_combine(hic->keyboard->combination,
                                                      hic->buffer.choseong, ch);
            }
            if (choseong) {
                if (!hangul_ic_push(hic, choseong)) {
                    if (!hangul_ic_push(hic, choseong)) {
                        return false;
                    }
                }
            } else {
                hangul_ic_save_commit_string(hic);
                if (!hangul_ic_push(hic, ch)) {
                    return false;
                }
            }
        }
    } else if (hangul_is_jungseong(ch)) {
		if (hic->buffer.jungseong == 0) {
            if (!hangul_ic_push(hic, ch)) {// 가윗소리가 없으면 들어온 가윗소리를 넣는다
                if (!hangul_ic_push(hic, ch)) {
                    return false;
                }
            }
			if (hic->buffer.jongseong == 0) {// 
				if (hic->buffer.shift) {
                    // 끝소리가 없고 종성시프트가 있다면 기윗소리에 놓인 겹받침을 넣는다
					ucschar jongseong = 0;
					jongseong = hangul_combination_combine(hic->keyboard->combination,
															   hic->buffer.shift, ch);
					if (jongseong) {
						hic->buffer.shift = 0;
						if (!hangul_ic_push(hic, jongseong)) {
							if (!hangul_ic_push(hic, jongseong)) {
								return false;
							}
						}
					}
				}
			}
        } else {// 들어온 가윗소리와 조합을 해본다
            ucschar jungseong = 0;
            jungseong = hangul_combination_combine(hic->keyboard->combination,
                                                       hic->buffer.jungseong, ch);
            if (jungseong) {
                if (!hangul_ic_push(hic, jungseong)) {
                    if (!hangul_ic_push(hic, jungseong)) {
                        return false;
                    }
                }
            } else {// 가윗소리 조합이 되지 않고 종성시프트가 있다면 가윗소리에 놓인 겹받침으로 바꿔본다
				if (hic->buffer.jongseong == 0) {// 
					if (hic->buffer.shift) {
						ucschar jongseong = 0;
						jongseong = hangul_combination_combine(hic->keyboard->combination,
																   hic->buffer.shift, ch);
						if (jongseong) {
							if (!hangul_ic_push(hic, jongseong)) {
								if (!hangul_ic_push(hic, jongseong)) {
									return false;
								}
							}
						} else {
							hangul_ic_save_commit_string(hic);
							if (!hangul_ic_push(hic, ch)) {
								if (!hangul_ic_push(hic, ch)) {
									return false;
								}
							}
						}
					}
				}
            }
        }
    } else if (hangul_is_jongseong(ch)) {
        if (ch == SHKEY) {// 종성시프트가 눌렸다면
            if (hic->buffer.jongseong == 0) {// 끝소리가 없을 때는 있는 가윗소리에 놓인 겹받침을 넣는다
                ucschar jongseong = 0;
                jongseong = hangul_combination_combine(hic->keyboard->combination,
                                                       ch, hic->buffer.jungseong);
                if (jongseong) {
                    if (!hangul_ic_push(hic, jongseong)) {
                        if (!hangul_ic_push(hic, jongseong)) {
                            return false;
                        }
                    }
                } else {
                    hic->buffer.shift = ch;
                }
            } else {// 끝소리가 있으면 겹받침으로 바꾼다
                ucschar jongseong = 0;
                jongseong = hangul_combination_combine(hic->keyboard->combination,
                                                           ch, hic->buffer.jongseong);
                if (jongseong) {
                    if (!hangul_ic_push(hic, jongseong)) {
                        if (!hangul_ic_push(hic, jongseong)) {
                            return false;
                        }
                    }
                } else {
                    hangul_ic_save_commit_string(hic);
                    hangul_ic_append_commit_string(hic, orig_ch);
                }
            }
        } else {
            if (hic->buffer.shift) {// 종성시프트가 있으면 끝소리는 겹받침이 된다
                if (hic->buffer.jongseong == 0) {
                    ucschar jongseong = 0;
                    jongseong = hangul_combination_combine(hic->keyboard->combination,
                                                           hic->buffer.shift, ch);
                    if (jongseong) {
                        if (!hangul_ic_push(hic, jongseong)) {
                            if (!hangul_ic_push(hic, jongseong)) {
                                return false;
                            }
                        }
                    } else {
                        hangul_ic_save_commit_string(hic);
                        if (!hangul_ic_push(hic, ch)) {
                            if (!hangul_ic_push(hic, ch)) {
                                return false;
                            }
                        }
                    }
                } else {
                    hangul_ic_save_commit_string(hic);
                    if (!hangul_ic_push(hic, ch)) {
                        if (!hangul_ic_push(hic, ch)) {
                            return false;
                        }
                    }
                }
            } else {
                if (hic->buffer.jongseong == 0) {
                    if (!hangul_ic_push(hic, ch)) {
                        if (!hangul_ic_push(hic, ch)) {
                            return false;
                        }
                    }
                } else {
                    ucschar jongseong = 0;
                    if (hangul_is_jongseong(hangul_ic_peek(hic))) {
                        jongseong = hangul_combination_combine(hic->keyboard->combination,
                                                               hic->buffer.jongseong, ch);
                    }
                    if (jongseong) {
                        if (!hangul_ic_push(hic, jongseong)) {
                            if (!hangul_ic_push(hic, jongseong)) {
                                return false;
                            }
                        }
                    } else {
                        hangul_ic_save_commit_string(hic);
                        if (!hangul_ic_push(hic, ch)) {
                            if (!hangul_ic_push(hic, ch)) {
                                return false;
                            }
                        }
                    }
                }
            }
        }
    } else if (ch > 0) {
        hangul_ic_save_commit_string(hic);
        hangul_ic_append_commit_string(hic, ch);
    } else {
        hangul_ic_save_commit_string(hic);
        return false;
    }

    hangul_ic_save_preedit_string(hic);
    return true;
}


#endif /* libhangul_hangulinputcontext_addon_h */
