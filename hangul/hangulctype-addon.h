#ifndef libhangul_hangulctype_addon_h
#define libhangul_hangulctype_addon_h

// 갈마들이
ucschar hangul_galmadeuli_shin_2003(ucschar c, bool conjoin);
ucschar hangul_galmadeuli_shin_2012(ucschar c, bool conjoin);

// 확장 기호
ucschar hangul_ascii_to_symbol_shin(int ascii, int step, int dummy);

#endif /* libhangul_hangulctype_addon_h */
