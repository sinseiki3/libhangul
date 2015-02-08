#ifndef libhangul_hangulctype_addon_h
#define libhangul_hangulctype_addon_h

// 두벌식 바꿔놓기
inline ucschar choseong_compress_addon(ucschar a, ucschar b);

// 갈마들이
ucschar hangul_galmadeuli_shin_2003(ucschar c, bool conjoin);
ucschar hangul_galmadeuli_shin_2012(ucschar c, bool conjoin);
ucschar hangul_galmadeuli_3_2012(ucschar c, bool dummy);
ucschar hangul_galmadeuli_3_2014(ucschar c, bool conjoin);
ucschar hangul_galmadeuli_3_14_proposal(ucschar c, bool dummy);

// 확장 기호
ucschar hangul_ascii_to_symbol_shin(int ascii, int step, int dummy);
ucschar hangul_ascii_to_symbol_3_2011(int ascii, int step, int dummy);
ucschar hangul_ascii_to_symbol_3_2012(int ascii, int step, int dummy);
ucschar hangul_ascii_to_symbol_3_2011_yet(int ascii, int step, int press);
ucschar hangul_ascii_to_symbol_3_2012_yet(int ascii, int step, int press);
// 확장 옛한글
ucschar hangul_ascii_to_hanguel_3_yet(int ascii, int step, int press);

#endif /* libhangul_hangulctype_addon_h */
