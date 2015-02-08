#ifndef libhangul_hangulkeyboard_h
#define libhangul_hangulkeyboard_h

static const ucschar hangul_keyboard_table_2[] = {
    0x0000,     /* 0x00 null                                         */
    0x0000,     /* 0x01 start of heading                             */
    0x0000,     /* 0x02 start of text                                */
    0x0000,     /* 0x03 end of text                                  */
    0x0000,     /* 0x04 end of transmission                          */
    0x0000,     /* 0x05 enquiry                                      */
    0x0000,     /* 0x06 acknowledge                                  */
    0x0000,     /* 0x07 bell                                         */
    0x0000,     /* 0x08 backspace                                    */
    0x0000,     /* 0x09 character tabulation                         */
    0x0000,     /* 0x0A line feed (lf)                               */
    0x0000,     /* 0x0B line tabulation                              */
    0x0000,     /* 0x0C form feed (ff)                               */
    0x0000,     /* 0x0D carriage return (cr)                         */
    0x0000,     /* 0x0E shift out                                    */
    0x0000,     /* 0x0F shift in                                     */
    0x0000,     /* 0x10 data link escape                             */
    0x0000,     /* 0x11 device control one                           */
    0x0000,     /* 0x12 device control two                           */
    0x0000,     /* 0x13 device control three                         */
    0x0000,     /* 0x14 device control four                          */
    0x0000,     /* 0x15 negative acknowledge                         */
    0x0000,     /* 0x16 synchronous idle                             */
    0x0000,     /* 0x17 end of transmission block                    */
    0x0000,     /* 0x18 cancel                                       */
    0x0000,     /* 0x19 end of medium                                */
    0x0000,     /* 0x1A substitute                                   */
    0x0000,     /* 0x1B escape                                       */
    0x0000,     /* 0x1C information separator four                   */
    0x0000,     /* 0x1D information separator three                  */
    0x0000,     /* 0x1E information separator two                    */
    0x0000,     /* 0x1F information separator one                    */
    0x0000,     /* 0x20 space                                        */
    0x0021,     /* 0x21 exclam:       exclamation mark               */
    0x0022,     /* 0x22 quotedbl:     quotation mark                 */
    0x0023,     /* 0x23 numbersign:   number sign                    */
    0x0024,     /* 0x24 dollar:       dollar sign                    */
    0x0025,     /* 0x25 percent:      percent sign                   */
    0x0026,     /* 0x26 ampersand:    ampersand                      */
    0x0027,     /* 0x27 apostrophe:   apostrophe                     */
    0x0028,     /* 0x28 parenleft:    left parenthesis               */
    0x0029,     /* 0x29 parenright:   right parenthesis              */
    0x002a,     /* 0x2A asterisk:     asterisk                       */
    0x002b,     /* 0x2B plus:         plus sign                      */
    0x002c,     /* 0x2C comma:        comma                          */
    0x002d,     /* 0x2D minus:        minus sign                     */
    0x002e,     /* 0x2E period:       period                         */
    0x002f,     /* 0x2F slash:        slash                          */
    0x0030,     /* 0x30 0:            0                              */
    0x0031,     /* 0x31 1:            1                              */
    0x0032,     /* 0x32 2:            2                              */
    0x0033,     /* 0x33 3:            3                              */
    0x0034,     /* 0x34 4:            4                              */
    0x0035,     /* 0x35 5:            5                              */
    0x0036,     /* 0x36 6:            6                              */
    0x0037,     /* 0x37 7:            7                              */
    0x0038,     /* 0x38 8:            8                              */
    0x0039,     /* 0x39 9:            9                              */
    0x003a,     /* 0x3A colon:        colon                          */
    0x003b,     /* 0x3B semicolon:    semicolon                      */
    0x003c,     /* 0x3C less:         less-than sign                 */
    0x003d,     /* 0x3D equal:        equals sign                    */
    0x003e,     /* 0x3E greater:      greater-than sign              */
    0x003f,     /* 0x3F question:     question mark                  */
    0x0040,     /* 0x40 at:           commercial at                  */
    0x1106,     /* 0x41 A:            choseong mieum                 */
    0x1172,     /* 0x42 B:            jungseong yu                   */
    0x110e,     /* 0x43 C:            choseong chieuch               */
    0x110b,     /* 0x44 D:            choseong ieung                 */
    0x1104,     /* 0x45 E:            choseong ssangtikeut           */
    0x1105,     /* 0x46 F:            choseong rieul                 */
    0x1112,     /* 0x47 G:            choseong hieuh                 */
    0x1169,     /* 0x48 H:            jungseong o                    */
    0x1163,     /* 0x49 I:            jungseong ya                   */
    0x1165,     /* 0x4A J:            jungseong eo                   */
    0x1161,     /* 0x4B K:            jungseong a                    */
    0x1175,     /* 0x4C L:            jungseong i                    */
    0x1173,     /* 0x4D M:            jungseong eu                   */
    0x116e,     /* 0x4E N:            jungseong u                    */
    0x1164,     /* 0x4F O:            jungseong yae                  */
    0x1168,     /* 0x50 P:            jungseong ye                   */
    0x1108,     /* 0x51 Q:            choseong ssangpieup            */
    0x1101,     /* 0x52 R:            choseong ssangkiyeok           */
    0x1102,     /* 0x53 S:            choseong nieun                 */
    0x110a,     /* 0x54 T:            choseong ssangsios             */
    0x1167,     /* 0x55 U:            jungseong yeo                  */
    0x1111,     /* 0x56 V:            choseong phieuph               */
    0x110d,     /* 0x57 W:            choseong ssangcieuc            */
    0x1110,     /* 0x58 X:            choseong thieuth               */
    0x116d,     /* 0x59 Y:            jungseong yo                   */
    0x110f,     /* 0x5A Z:            choseong khieukh               */
    0x005b,     /* 0x5B bracketleft:  left bracket                   */
    0x005c,     /* 0x5C backslash:    backslash                      */
    0x005d,     /* 0x5D bracketright: right bracket                  */
    0x005e,     /* 0x5E asciicircum:  circumflex accent              */
    0x005f,     /* 0x5F underscore:   underscore                     */
    0x0060,     /* 0x60 quoteleft:    grave accent                   */
    0x1106,     /* 0x61 a:            choseong  mieum                */
    0x1172,     /* 0x62 b:            jungseong yu                   */
    0x110e,     /* 0x63 c:            choseong  chieuch              */
    0x110b,     /* 0x64 d:            choseong  ieung                */
    0x1103,     /* 0x65 e:            choseong  tikeut               */
    0x1105,     /* 0x66 f:            choseong  rieul                */
    0x1112,     /* 0x67 g:            choseong  hieuh                */
    0x1169,     /* 0x68 h:            jungseong o                    */
    0x1163,     /* 0x69 i:            jungseong ya                   */
    0x1165,     /* 0x6A j:            jungseong eo                   */
    0x1161,     /* 0x6B k:            jungseong a                    */
    0x1175,     /* 0x6C l:            jungseong i                    */
    0x1173,     /* 0x6D m:            jungseong eu                   */
    0x116e,     /* 0x6E n:            jungseong u                    */
    0x1162,     /* 0x6F o:            jungseong ae                   */
    0x1166,     /* 0x70 p:            jungseong e                    */
    0x1107,     /* 0x71 q:            choseong  pieup                */
    0x1100,     /* 0x72 r:            choseong  kiyeok               */
    0x1102,     /* 0x73 s:            choseong  nieun                */
    0x1109,     /* 0x74 t:            choseong  sios                 */
    0x1167,     /* 0x75 u:            jungseong yeo                  */
    0x1111,     /* 0x76 v:            choseong  phieuph              */
    0x110c,     /* 0x77 w:            choseong  cieuc                */
    0x1110,     /* 0x78 x:            choseong  thieuth              */
    0x116d,     /* 0x79 y:            jungseong yo                   */
    0x110f,     /* 0x7A z:            choseong  khieukh              */
    0x007b,     /* 0x7B braceleft:    left brace                     */
    0x007c,     /* 0x7C bar:          vertical bar                   */
    0x007d,     /* 0x7D braceright:   right brace                    */
    0x007e,     /* 0x7E asciitilde:   tilde                          */
    0x0000      /* 0x7F delete                                       */
};

static const ucschar hangul_keyboard_table_2y[] = {
    0x0000,     /* 0x00 null                                         */
    0x0000,     /* 0x01 start of heading                             */
    0x0000,     /* 0x02 start of text                                */
    0x0000,     /* 0x03 end of text                                  */
    0x0000,     /* 0x04 end of transmission                          */
    0x0000,     /* 0x05 enquiry                                      */
    0x0000,     /* 0x06 acknowledge                                  */
    0x0000,     /* 0x07 bell                                         */
    0x0000,     /* 0x08 backspace                                    */
    0x0000,     /* 0x09 character tabulation                         */
    0x0000,     /* 0x0A line feed (lf)                               */
    0x0000,     /* 0x0B line tabulation                              */
    0x0000,     /* 0x0C form feed (ff)                               */
    0x0000,     /* 0x0D carriage return (cr)                         */
    0x0000,     /* 0x0E shift out                                    */
    0x0000,     /* 0x0F shift in                                     */
    0x0000,     /* 0x10 data link escape                             */
    0x0000,     /* 0x11 device control one                           */
    0x0000,     /* 0x12 device control two                           */
    0x0000,     /* 0x13 device control three                         */
    0x0000,     /* 0x14 device control four                          */
    0x0000,     /* 0x15 negative acknowledge                         */
    0x0000,     /* 0x16 synchronous idle                             */
    0x0000,     /* 0x17 end of transmission block                    */
    0x0000,     /* 0x18 cancel                                       */
    0x0000,     /* 0x19 end of medium                                */
    0x0000,     /* 0x1A substitute                                   */
    0x0000,     /* 0x1B escape                                       */
    0x0000,     /* 0x1C information separator four                   */
    0x0000,     /* 0x1D information separator three                  */
    0x0000,     /* 0x1E information separator two                    */
    0x0000,     /* 0x1F information separator one                    */
    0x0000,     /* 0x20 space                                        */
    0x0021,     /* 0x21 exclam:       exclamation mark               */
    0x0022,     /* 0x22 quotedbl:     quotation mark                 */
    0x0023,     /* 0x23 numbersign:   number sign                    */
    0x0024,     /* 0x24 dollar:       dollar sign                    */
    0x0025,     /* 0x25 percent:      percent sign                   */
    0x0026,     /* 0x26 ampersand:    ampersand                      */
    0x0027,     /* 0x27 apostrophe:   apostrophe                     */
    0x0028,     /* 0x28 parenleft:    left parenthesis               */
    0x0029,     /* 0x29 parenright:   right parenthesis              */
    0x002a,     /* 0x2A asterisk:     asterisk                       */
    0x002b,     /* 0x2B plus:         plus sign                      */
    0x002c,     /* 0x2C comma:        comma                          */
    0x002d,     /* 0x2D minus:        minus sign                     */
    0x002e,     /* 0x2E period:       period                         */
    0x002f,     /* 0x2F slash:        slash                          */
    0x0030,     /* 0x30 0:            0                              */
    0x0031,     /* 0x31 1:            1                              */
    0x0032,     /* 0x32 2:            2                              */
    0x0033,     /* 0x33 3:            3                              */
    0x0034,     /* 0x34 4:            4                              */
    0x0035,     /* 0x35 5:            5                              */
    0x0036,     /* 0x36 6:            6                              */
    0x0037,     /* 0x37 7:            7                              */
    0x0038,     /* 0x38 8:            8                              */
    0x0039,     /* 0x39 9:            9                              */
    0x003a,     /* 0x3A colon:        colon                          */
    0x003b,     /* 0x3B semicolon:    semicolon                      */
    0x003c,     /* 0x3C less:         less-than sign                 */
    0x003d,     /* 0x3D equal:        equals sign                    */
    0x003e,     /* 0x3E greater:      greater-than sign              */
    0x003f,     /* 0x3F question:     question mark                  */
    0x0040,     /* 0x40 at:           commercial at                  */
    0x1140,     /* 0x41 A:            choseong pansios               */
    0x1154,     /* 0x42 B:            choseong chitueumchieuch       */
    0x114e,     /* 0x43 C:            choseong chitueumcieuc         */
    0x114c,     /* 0x44 D:            choseong yesieung              */
    0x1104,     /* 0x45 E:            choseong ssangtikeut           */
    0x111a,     /* 0x46 F:            choseong rieul-hieuh           */
    0x1159,     /* 0x47 G:            choseong yeorinhieuh           */
    0x1183,     /* 0x48 H:            jungseong o-u                  */
    0x1163,     /* 0x49 I:            jungseong ya                   */
    0x1165,     /* 0x4A J:            jungseong eo                   */
    0x119e,     /* 0x4B K:            jungseong araea                */
    0x1194,     /* 0x4C L:            jungseong yu-i                 */
    0x1173,     /* 0x4D M:            jungseong eu                   */
    0x1155,     /* 0x4E N:            choseong ceongchieumchieuch    */
    0x1164,     /* 0x4F O:            jungseong yae                  */
    0x1168,     /* 0x50 P:            jungseong ye                   */
    0x1108,     /* 0x51 Q:            choseong ssangpieup            */
    0x1101,     /* 0x52 R:            choseong ssangkiyeok           */
    0x115d,     /* 0x53 S:            choseong nieun-hieuh           */
    0x110a,     /* 0x54 T:            choseong ssangsios             */
    0x1167,     /* 0x55 U:            jungseong yeo                  */
    0x1150,     /* 0x56 V:            choseong ceongchieumcieuc      */
    0x110d,     /* 0x57 W:            choseong ssangcieuc            */
    0x113e,     /* 0x58 X:            choseong ceongchieumsios       */
    0x116d,     /* 0x59 Y:            jungseong yo                   */
    0x113c,     /* 0x5A Z:            choseong chitueumsios          */
    0x005b,     /* 0x5B bracketleft:  left bracket                   */
    0x005c,     /* 0x5C backslash:    backslash                      */
    0x005d,     /* 0x5D bracketright: right bracket                  */
    0x005e,     /* 0x5E asciicircum:  circumflex accent              */
    0x005f,     /* 0x5F underscore:   underscore                     */
    0x0060,     /* 0x60 quoteleft:    grave accent                   */
    0x1106,     /* 0x61 a:            choseong  mieum                */
    0x1172,     /* 0x62 b:            jungseong yu                   */
    0x110e,     /* 0x63 c:            choseong  chieuch              */
    0x110b,     /* 0x64 d:            choseong  ieung                */
    0x1103,     /* 0x65 e:            choseong  tikeut               */
    0x1105,     /* 0x66 f:            choseong  rieul                */
    0x1112,     /* 0x67 g:            choseong  hieuh                */
    0x1169,     /* 0x68 h:            jungseong o                    */
    0x1163,     /* 0x69 i:            jungseong ya                   */
    0x1165,     /* 0x6A j:            jungseong eo                   */
    0x1161,     /* 0x6B k:            jungseong a                    */
    0x1175,     /* 0x6C l:            jungseong i                    */
    0x1173,     /* 0x6D m:            jungseong eu                   */
    0x116e,     /* 0x6E n:            jungseong u                    */
    0x1162,     /* 0x6F o:            jungseong ae                   */
    0x1166,     /* 0x70 p:            jungseong e                    */
    0x1107,     /* 0x71 q:            choseong  pieup                */
    0x1100,     /* 0x72 r:            choseong  kiyeok               */
    0x1102,     /* 0x73 s:            choseong  nieun                */
    0x1109,     /* 0x74 t:            choseong  sios                 */
    0x1167,     /* 0x75 u:            jungseong yeo                  */
    0x1111,     /* 0x76 v:            choseong  phieuph              */
    0x110c,     /* 0x77 w:            choseong  cieuc                */
    0x1110,     /* 0x78 x:            choseong  thieuth              */
    0x116d,     /* 0x79 y:            jungseong yo                   */
    0x110f,     /* 0x7A z:            choseong  khieukh              */
    0x007b,     /* 0x7B braceleft:    left brace                     */
    0x007c,     /* 0x7C bar:          vertical bar                   */
    0x007d,     /* 0x7D braceright:   right brace                    */
    0x007e,     /* 0x7E asciitilde:   tilde                          */
    0x0000      /* 0x7F delete                                       */
};

static const ucschar hangul_keyboard_table_32[] = {
    0x0000,     /* 0x00 null                                         */
    0x0000,     /* 0x01 start of heading                             */
    0x0000,     /* 0x02 start of text                                */
    0x0000,     /* 0x03 end of text                                  */
    0x0000,     /* 0x04 end of transmission                          */
    0x0000,     /* 0x05 enquiry                                      */
    0x0000,     /* 0x06 acknowledge                                  */
    0x0000,     /* 0x07 bell                                         */
    0x0000,     /* 0x08 backspace                                    */
    0x0000,     /* 0x09 character tabulation                         */
    0x0000,     /* 0x0A line feed (lf)                               */
    0x0000,     /* 0x0B line tabulation                              */
    0x0000,     /* 0x0C form feed (ff)                               */
    0x0000,     /* 0x0D carriage return (cr)                         */
    0x0000,     /* 0x0E shift out                                    */
    0x0000,     /* 0x0F shift in                                     */
    0x0000,     /* 0x10 data link escape                             */
    0x0000,     /* 0x11 device control one                           */
    0x0000,     /* 0x12 device control two                           */
    0x0000,     /* 0x13 device control three                         */
    0x0000,     /* 0x14 device control four                          */
    0x0000,     /* 0x15 negative acknowledge                         */
    0x0000,     /* 0x16 synchronous idle                             */
    0x0000,     /* 0x17 end of transmission block                    */
    0x0000,     /* 0x18 cancel                                       */
    0x0000,     /* 0x19 end of medium                                */
    0x0000,     /* 0x1A substitute                                   */
    0x0000,     /* 0x1B escape                                       */
    0x0000,     /* 0x1C information separator four                   */
    0x0000,     /* 0x1D information separator three                  */
    0x0000,     /* 0x1E information separator two                    */
    0x0000,     /* 0x1F information separator one                    */
    0x0000,     /* 0x20 space                                        */
    0x0021,     /* 0x21 exclam:         exclamation mark             */
    0x0022,     /* 0x22 quotedbl:       quotation mark               */
    0x0023,     /* 0x23 numbersign:     number sign                  */
    0x0024,     /* 0x24 dollar:         dollar sign                  */
    0x0025,     /* 0x25 percent:        percent sign                 */
    0x0026,     /* 0x26 ampersand:      ampersand                    */
    0x0027,     /* 0x27 apostrophe:     apostrophe                   */
    0x0028,     /* 0x28 parenleft:      left parenthesis             */
    0x0029,     /* 0x29 parenright:     right parenthesis            */
    0x002a,     /* 0x2A asterisk:       asterisk                     */
    0x002b,     /* 0x2B plus:           plus sign                    */
    0x002c,     /* 0x2C comma:          comma                        */
    0x002d,     /* 0x2D minus:          minus sign                   */
    0x002e,     /* 0x2E period:         period                       */
    0x002f,     /* 0x2F slash:          slash                        */
    0x0030,     /* 0x30 0:              0                            */
    0x0031,     /* 0x31 1:              1                            */
    0x0032,     /* 0x32 2:              2                            */
    0x0033,     /* 0x33 3:              3                            */
    0x0034,     /* 0x34 4:              4                            */
    0x0035,     /* 0x35 5:              5                            */
    0x0036,     /* 0x36 6:              6                            */
    0x0037,     /* 0x37 7:              7                            */
    0x0038,     /* 0x38 8:              8                            */
    0x0039,     /* 0x39 9:              9                            */
    0x003a,     /* 0x3A colon:          colon                        */
    0x003b,     /* 0x3B semicolon:      semicolon                    */
    0x003c,     /* 0x3C less:           less-than sign               */
    0x003d,     /* 0x3D equal:          equals sign                  */
    0x003e,     /* 0x3E greater:        greater-than sign            */
    0x003f,     /* 0x3F question:       question mark                */
    0x0040,     /* 0x40 at:             commercial at                */
    0x11b7,     /* 0x41 A:              jongseong mieum              */
    0x1172,     /* 0x42 B:              jungseong yu                 */
    0x11be,     /* 0x43 C:              jongseong chieuch            */
    0x11bc,     /* 0x44 D:              jongseong ieung              */
    0x11ae,     /* 0x45 E:              jongseong tikeut             */
    0x11af,     /* 0x46 F:              jongseong rieul              */
    0x11c2,     /* 0x47 G:              jongseong hieuh              */
    0x1169,     /* 0x48 H:              jungseong o                  */
    0x1163,     /* 0x49 I:              jungseong ya                 */
    0x1165,     /* 0x4A J:              jungseong eo                 */
    0x1161,     /* 0x4B K:              jungseong a                  */
    0x1175,     /* 0x4C L:              jungseong i                  */
    0x1173,     /* 0x4D M:              jungseong eu                 */
    0x116e,     /* 0x4E N:              jungseong u                  */
    0x1164,     /* 0x4F O:              jungseong yae                */
    0x1168,     /* 0x50 P:              jungseong ye                 */
    0x11b8,     /* 0x51 Q:              jongseong pieup              */
    0x11a8,     /* 0x52 R:              jongseong kiyeok             */
    0x11ab,     /* 0x53 S:              jongseong nieun              */
    0x11ba,     /* 0x54 T:              jongseong sios               */
    0x1167,     /* 0x55 U:              jungseong yeo                */
    0x11c1,     /* 0x56 V:              jongseong phieuph            */
    0x11bd,     /* 0x57 W:              jongseong cieuc              */
    0x11c0,     /* 0x58 X:              jongseong thieuth            */
    0x116d,     /* 0x59 Y:              jungseong yo                 */
    0x11bf,     /* 0x5A Z:              jongseong khieukh            */
    0x005b,     /* 0x5B bracketleft:    left bracket                 */
    0x005c,     /* 0x5C backslash:      backslash                    */
    0x005d,     /* 0x5D bracketright:   right bracket                */
    0x005e,     /* 0x5E asciicircum:    circumflex accent            */
    0x005f,     /* 0x5F underscore:     underscore                   */
    0x0060,     /* 0x60 quoteleft:      grave accent                 */
    0x1106,     /* 0x61 a:              choseong  mieum              */
    0x1172,     /* 0x62 b:              jungseong yu                 */
    0x110e,     /* 0x63 c:              choseong  chieuch            */
    0x110b,     /* 0x64 d:              choseong  ieung              */
    0x1103,     /* 0x65 e:              choseong  tikeut             */
    0x1105,     /* 0x66 f:              choseong  rieul              */
    0x1112,     /* 0x67 g:              choseong  hieuh              */
    0x1169,     /* 0x68 h:              jungseong o                  */
    0x1163,     /* 0x69 i:              jungseong ya                 */
    0x1165,     /* 0x6A j:              jungseong eo                 */
    0x1161,     /* 0x6B k:              jungseong a                  */
    0x1175,     /* 0x6C l:              jungseong i                  */
    0x1173,     /* 0x6D m:              jungseong eu                 */
    0x116e,     /* 0x6E n:              jungseong u                  */
    0x1162,     /* 0x6F o:              jungseong ae                 */
    0x1166,     /* 0x70 p:              jungseong e                  */
    0x1107,     /* 0x71 q:              choseong  pieup              */
    0x1100,     /* 0x72 r:              choseong  kiyeok             */
    0x1102,     /* 0x73 s:              choseong  nieun              */
    0x1109,     /* 0x74 t:              choseong  sios               */
    0x1167,     /* 0x75 u:              jungseong yeo                */
    0x1111,     /* 0x76 v:              choseong  phieuph            */
    0x110c,     /* 0x77 w:              choseong  cieuc              */
    0x1110,     /* 0x78 x:              choseong  thieuth            */
    0x116d,     /* 0x79 y:              jungseong yo                 */
    0x110f,     /* 0x7A z:              choseong  khieukh            */
    0x007b,     /* 0x7B braceleft:      left brace                   */
    0x007c,     /* 0x7C bar:            vertical bar                 */
    0x007d,     /* 0x7D braceright:     right brace                  */
    0x203b,     /* 0x7E asciitilde:     tilde                        */
    0x0000      /* 0x7F delete                                       */
};

static const ucschar hangul_keyboard_table_390[] = {
    0x0000,     /* 0x00 null                                         */
    0x0000,     /* 0x01 start of heading                             */
    0x0000,     /* 0x02 start of text                                */
    0x0000,     /* 0x03 end of text                                  */
    0x0000,     /* 0x04 end of transmission                          */
    0x0000,     /* 0x05 enquiry                                      */
    0x0000,     /* 0x06 acknowledge                                  */
    0x0000,     /* 0x07 bell                                         */
    0x0000,     /* 0x08 backspace                                    */
    0x0000,     /* 0x09 character tabulation                         */
    0x0000,     /* 0x0A line feed (lf)                               */
    0x0000,     /* 0x0B line tabulation                              */
    0x0000,     /* 0x0C form feed (ff)                               */
    0x0000,     /* 0x0D carriage return (cr)                         */
    0x0000,     /* 0x0E shift out                                    */
    0x0000,     /* 0x0F shift in                                     */
    0x0000,     /* 0x10 data link escape                             */
    0x0000,     /* 0x11 device control one                           */
    0x0000,     /* 0x12 device control two                           */
    0x0000,     /* 0x13 device control three                         */
    0x0000,     /* 0x14 device control four                          */
    0x0000,     /* 0x15 negative acknowledge                         */
    0x0000,     /* 0x16 synchronous idle                             */
    0x0000,     /* 0x17 end of transmission block                    */
    0x0000,     /* 0x18 cancel                                       */
    0x0000,     /* 0x19 end of medium                                */
    0x0000,     /* 0x1A substitute                                   */
    0x0000,     /* 0x1B escape                                       */
    0x0000,     /* 0x1C information separator four                   */
    0x0000,     /* 0x1D information separator three                  */
    0x0000,     /* 0x1E information separator two                    */
    0x0000,     /* 0x1F information separator one                    */
    0x0000,     /* 0x20 space                                        */
    0x11bd,     /* 0x21 exclam:         jongseong cieuc              */
    0x0022,     /* 0x22 quotedbl:       quotatioin mark              */
    0x0023,     /* 0x23 numbersign:     number sign                  */
    0x0024,     /* 0x24 dollar:         dollar sign                  */
    0x0025,     /* 0x25 percent:        percent sign                 */
    0x0026,     /* 0x26 ampersand:      ampersand                    */
    0x1110,     /* 0x27 apostrophe:     choseong thieuth             */
    0x0028,     /* 0x28 parenleft:      left parenthesis             */
    0x0029,     /* 0x29 parenright:     right parenthesis            */
    0x002a,     /* 0x2A asterisk:       asterisk                     */
    0x002b,     /* 0x2B plus:           plus sign                    */
    0x002c,     /* 0x2C comma:          comma                        */
    0x002d,     /* 0x2D minus:          minus sign                   */
    0x002e,     /* 0x2E period:         period                       */
    0x1169,     /* 0x2F slash:          jungseong o                  */
    0x110f,     /* 0x30 0:              choseong  khieukh            */
    0x11c2,     /* 0x31 1:              jongseong hieuh              */
    0x11bb,     /* 0x32 2:              jongseong ssangsios          */
    0x11b8,     /* 0x33 3:              jongseong pieup              */
    0x116d,     /* 0x34 4:              jungseong yo                 */
    0x1172,     /* 0x35 5:              jungseong yu                 */
    0x1163,     /* 0x36 6:              jungseong ya                 */
    0x1168,     /* 0x37 7:              jungseong ye                 */
    0x1174,     /* 0x38 8:              jungseong yi                 */
    0x116e,     /* 0x39 9:              jungseong u                  */
    0x003a,     /* 0x3A colon:          colon                        */
    0x1107,     /* 0x3B semicolon:      choseong  pieup              */
    0x0032,     /* 0x3C less:           2                            */
    0x003d,     /* 0x3D equal:          euals sign                   */
    0x0033,     /* 0x3E greater:        3                            */
    0x003f,     /* 0x3F question:       question mark                */
    0x0040,     /* 0x40 at:             commertial at                */
    0x11ae,     /* 0x41 A:              jongseong tikeut             */
    0x0021,     /* 0x42 B:              exclamation mark             */
    0x11b1,     /* 0x43 C:              jongseong rieul-mieum        */
    0x11b0,     /* 0x44 D:              jongseong rieul-kiyeok       */
    0x11bf,     /* 0x45 E:              jongseong khieukh            */
    0x11a9,     /* 0x46 F:              jongseong ssangkiyeok        */
    0x002f,     /* 0x47 G:              slash                        */
    0x0027,     /* 0x48 H:              apostrophe                   */
    0x0038,     /* 0x49 I:              8                            */
    0x0034,     /* 0x4A J:              4                            */
    0x0035,     /* 0x4B K:              5                            */
    0x0036,     /* 0x4C L:              6                            */
    0x0031,     /* 0x4D M:              1                            */
    0x0030,     /* 0x4E N:              0                            */
    0x0039,     /* 0x4F O:              9                            */
    0x003e,     /* 0x50 P:              greater-than sign            */
    0x11c1,     /* 0x51 Q:              jongseong phieuph            */
    0x1164,     /* 0x52 R:              jungseong yae                */
    0x11ad,     /* 0x53 S:              jongseong nieun-hieuh        */
    0x003b,     /* 0x54 T:              semicolon                    */
    0x0037,     /* 0x55 U:              7                            */
    0x11b6,     /* 0x56 V:              jongseong rieul-hieuh        */
    0x11c0,     /* 0x57 W:              jongseong thikeuth           */
    0x11b9,     /* 0x58 X:              jongseong pieup-sios         */
    0x003c,     /* 0x59 Y:              less-than sign               */
    0x11be,     /* 0x5A Z:              jongseong chieuch            */
    0x005b,     /* 0x5B bracketleft:    left bracket                 */
    0x005c,     /* 0x5C backslash:      backslash                    */
    0x005d,     /* 0x5D bracketright:   right bracket                */
    0x005e,     /* 0x5E asciicircum:    circumflex accent            */
    0x005f,     /* 0x5F underscore:     underscore                   */
    0x0060,     /* 0x60 quoteleft:      grave accent                 */
    0x11bc,     /* 0x61 a:              jongseong ieung              */
    0x116e,     /* 0x62 b:              jungseong u                  */
    0x1166,     /* 0x63 c:              jungseong e                  */
    0x1175,     /* 0x64 d:              jungseong i                  */
    0x1167,     /* 0x65 e:              jungseong yeo                */
    0x1161,     /* 0x66 f:              jungseong a                  */
    0x1173,     /* 0x67 g:              jungseong eu                 */
    0x1102,     /* 0x68 h:              choseong  nieun              */
    0x1106,     /* 0x69 i:              choseong  mieum              */
    0x110b,     /* 0x6A j:              choseong  ieung              */
    0x1100,     /* 0x6B k:              choseong  kiyeok             */
    0x110c,     /* 0x6C l:              choseong  cieuc              */
    0x1112,     /* 0x6D m:              choseong  hieuh              */
    0x1109,     /* 0x6E n:              choseong  sios               */
    0x110e,     /* 0x6F o:              choseong  chieuch            */
    0x1111,     /* 0x70 p:              choseong  phieuph            */
    0x11ba,     /* 0x71 q:              jongseong sios               */
    0x1162,     /* 0x72 r:              jungseong ae                 */
    0x11ab,     /* 0x73 s:              jongseong nieun              */
    0x1165,     /* 0x74 t:              jungseong eo                 */
    0x1103,     /* 0x75 u:              choseong  tikeut             */
    0x1169,     /* 0x76 v:              jungseong o                  */
    0x11af,     /* 0x77 w:              jongseong rieul              */
    0x11a8,     /* 0x78 x:              jongseong kiyeok             */
    0x1105,     /* 0x79 y:              choseong  rieul              */
    0x11b7,     /* 0x7A z:              jongseong mieum              */
    0x007b,     /* 0x7B braceleft:      left brace                   */
    0x007c,     /* 0x7C bar:            vertical line(bar)           */
    0x007d,     /* 0x7D braceright:     right brace                  */
    0x007e,     /* 0x7E asciitilde:     tilde                        */
    0x0000      /* 0x7F delete                                       */
};

static const ucschar hangul_keyboard_table_3final[] = {
    0x0000,     /* 0x00 null                                         */
    0x0000,     /* 0x01 start of heading                             */
    0x0000,     /* 0x02 start of text                                */
    0x0000,     /* 0x03 end of text                                  */
    0x0000,     /* 0x04 end of transmission                          */
    0x0000,     /* 0x05 enquiry                                      */
    0x0000,     /* 0x06 acknowledge                                  */
    0x0000,     /* 0x07 bell                                         */
    0x0000,     /* 0x08 backspace                                    */
    0x0000,     /* 0x09 character tabulation                         */
    0x0000,     /* 0x0A line feed (lf)                               */
    0x0000,     /* 0x0B line tabulation                              */
    0x0000,     /* 0x0C form feed (ff)                               */
    0x0000,     /* 0x0D carriage return (cr)                         */
    0x0000,     /* 0x0E shift out                                    */
    0x0000,     /* 0x0F shift in                                     */
    0x0000,     /* 0x10 data link escape                             */
    0x0000,     /* 0x11 device control one                           */
    0x0000,     /* 0x12 device control two                           */
    0x0000,     /* 0x13 device control three                         */
    0x0000,     /* 0x14 device control four                          */
    0x0000,     /* 0x15 negative acknowledge                         */
    0x0000,     /* 0x16 synchronous idle                             */
    0x0000,     /* 0x17 end of transmission block                    */
    0x0000,     /* 0x18 cancel                                       */
    0x0000,     /* 0x19 end of medium                                */
    0x0000,     /* 0x1A substitute                                   */
    0x0000,     /* 0x1B escape                                       */
    0x0000,     /* 0x1C information separator four                   */
    0x0000,     /* 0x1D information separator three                  */
    0x0000,     /* 0x1E information separator two                    */
    0x0000,     /* 0x1F information separator one                    */
    0x0000,     /* 0x20 space                                        */
    0x11a9,     /* 0x21 exclam:         jongseong ssangkiyeok        */
    0x00b7,     /* 0x22 quotedbl:       middle dot                   */
    0x11bd,     /* 0x23 numbersign:     jognseong cieuc              */
    0x11b5,     /* 0x24 dollar:         jongseong rieul-phieuph      */
    0x11b4,     /* 0x25 percent:        jongseong rieul-thieuth      */
    0x201c,     /* 0x26 ampersand:      left double quotation mark   */
    0x1110,     /* 0x27 apostrophe:     choseong  thieuth            */
    0x0027,     /* 0x28 parenleft:      apostrophe                   */
    0x007e,     /* 0x29 parenright:     Tilde                        */
    0x201d,     /* 0x2A asterisk:       right double quotation mark  */
    0x002b,     /* 0x2B plus:           plus sign                    */
    0x002c,     /* 0x2C comma:          comma                        */
    0x0029,     /* 0x2D minus:          right parenthesis            */
    0x002e,     /* 0x2E period:         period                       */
    0x1169,     /* 0x2F slash:          jungseong o                  */
    0x110f,     /* 0x30 0:              choseong  khieukh            */
    0x11c2,     /* 0x31 1:              jongseong hieuh              */
    0x11bb,     /* 0x32 2:              jongseong ssangsios          */
    0x11b8,     /* 0x33 3:              jongseong pieup              */
    0x116d,     /* 0x34 4:              jungseong yo                 */
    0x1172,     /* 0x35 5:              jungseong yu                 */
    0x1163,     /* 0x36 6:              jungseong ya                 */
    0x1168,     /* 0x37 7:              jungseong ye                 */
    0x1174,     /* 0x38 8:              jungseong yi                 */
    0x116e,     /* 0x39 9:              jungseong u                  */
    0x0034,     /* 0x3A colon:          4                            */
    0x1107,     /* 0x3B semicolon:      choseong  pieup              */
    0x002c,     /* 0x3C less:           comma                        */
    0x003e,     /* 0x3D equal:          greater-than sign            */
    0x002e,     /* 0x3E greater:        period                       */
    0x0021,     /* 0x3F question:       exclamation mark             */
    0x11b0,     /* 0x40 at:             jongseong rieul-kiyeok       */
    0x11ae,     /* 0x41 A:              jongseong tikeut             */
    0x003f,     /* 0x42 B:              question mark                */
    0x11bf,     /* 0x43 C:              jongseong khieukh            */
    0x11b2,     /* 0x44 D:              jongseong rieul-pieup        */
    0x11ac,     /* 0x45 E:              jongseong nieun-cieuc        */
    0x11b1,     /* 0x46 F:              jongseong rieul-mieum        */
    0x1164,     /* 0x47 G:              jungseong yae                */
    0x0030,     /* 0x48 H:              0                            */
    0x0037,     /* 0x49 I:              7                            */
    0x0031,     /* 0x4A J:              1                            */
    0x0032,     /* 0x4B K:              2                            */
    0x0033,     /* 0x4C L:              3                            */
    0x0022,     /* 0x4D M:              double quotation mark        */
    0x002d,     /* 0x4E N:              minus sign                   */
    0x0038,     /* 0x4F O:              8                            */
    0x0039,     /* 0x50 P:              9                            */
    0x11c1,     /* 0x51 Q:              jongseong phieuph            */
    0x11b6,     /* 0x52 R:              jongseong rieul-hieuh        */
    0x11ad,     /* 0x53 S:              jongseong nieun-hieuh        */
    0x11b3,     /* 0x54 T:              jongseong rieul-sios         */
    0x0036,     /* 0x55 U:              6                            */
    0x11aa,     /* 0x56 V:              jongseong kiyeok-sios        */
    0x11c0,     /* 0x57 W:              jongseong thikeuth           */
    0x11b9,     /* 0x58 X:              jongseong pieup-sios         */
    0x0035,     /* 0x59 Y:              5                            */
    0x11be,     /* 0x5A Z:              jongseong chieuch            */
    0x0028,     /* 0x5B bracketleft:    left parenthesis             */
    0x003a,     /* 0x5C backslash:      colon                        */
    0x003c,     /* 0x5D bracketright:   less-than sign               */
    0x003d,     /* 0x5E asciicircum:    equals sign                  */
    0x003b,     /* 0x5F underscore:     semicolon                    */
    0x002a,     /* 0x60 quoteleft:      asterisk                     */
    0x11bc,     /* 0x61 a:              jongseong ieung              */
    0x116e,     /* 0x62 b:              jungseong u                  */
    0x1166,     /* 0x63 c:              jungseong e                  */
    0x1175,     /* 0x64 d:              jungseong i                  */
    0x1167,     /* 0x65 e:              jungseong yeo                */
    0x1161,     /* 0x66 f:              jungseong a                  */
    0x1173,     /* 0x67 g:              jungseong eu                 */
    0x1102,     /* 0x68 h:              choseong  nieun              */
    0x1106,     /* 0x69 i:              choseong  mieum              */
    0x110b,     /* 0x6A j:              choseong  ieung              */
    0x1100,     /* 0x6B k:              choseong  kiyeok             */
    0x110c,     /* 0x6C l:              choseong  cieuc              */
    0x1112,     /* 0x6D m:              choseong  hieuh              */
    0x1109,     /* 0x6E n:              choseong  sios               */
    0x110e,     /* 0x6F o:              choseong  chieuch            */
    0x1111,     /* 0x70 p:              choseong  phieuph            */
    0x11ba,     /* 0x71 q:              jongseong sios               */
    0x1162,     /* 0x72 r:              jungseong ae                 */
    0x11ab,     /* 0x73 s:              jongseong nieun              */
    0x1165,     /* 0x74 t:              jungseong eo                 */
    0x1103,     /* 0x75 u:              choseong  tikeut             */
    0x1169,     /* 0x76 v:              jungseong o                  */
    0x11af,     /* 0x77 w:              jongseong rieul              */
    0x11a8,     /* 0x78 x:              jongseong kiyeok             */
    0x1105,     /* 0x79 y:              choseong  rieul              */
    0x11b7,     /* 0x7A z:              jongseong mieum              */
    0x0025,     /* 0x7B braceleft:      percent sign                 */
    0x005c,     /* 0x7C bar:            backslash                    */
    0x002f,     /* 0x7D braceright:     slash                        */
    0x203b,     /* 0x7E asciitilde:     reference mark               */
    0x0000      /* 0x7F delete                                       */
};

static const ucschar hangul_keyboard_table_3sun[] = {
    0x0000,     /* 0x00 null                                         */
    0x0000,     /* 0x01 start of heading                             */
    0x0000,     /* 0x02 start of text                                */
    0x0000,     /* 0x03 end of text                                  */
    0x0000,     /* 0x04 end of transmission                          */
    0x0000,     /* 0x05 enquiry                                      */
    0x0000,     /* 0x06 acknowledge                                  */
    0x0000,     /* 0x07 bell                                         */
    0x0000,     /* 0x08 backspace                                    */
    0x0000,     /* 0x09 character tabulation                         */
    0x0000,     /* 0x0A line feed (lf)                               */
    0x0000,     /* 0x0B line tabulation                              */
    0x0000,     /* 0x0C form feed (ff)                               */
    0x0000,     /* 0x0D carriage return (cr)                         */
    0x0000,     /* 0x0E shift out                                    */
    0x0000,     /* 0x0F shift in                                     */
    0x0000,     /* 0x10 data link escape                             */
    0x0000,     /* 0x11 device control one                           */
    0x0000,     /* 0x12 device control two                           */
    0x0000,     /* 0x13 device control three                         */
    0x0000,     /* 0x14 device control four                          */
    0x0000,     /* 0x15 negative acknowledge                         */
    0x0000,     /* 0x16 synchronous idle                             */
    0x0000,     /* 0x17 end of transmission block                    */
    0x0000,     /* 0x18 cancel                                       */
    0x0000,     /* 0x19 end of medium                                */
    0x0000,     /* 0x1A substitute                                   */
    0x0000,     /* 0x1B escape                                       */
    0x0000,     /* 0x1C information separator four                   */
    0x0000,     /* 0x1D information separator three                  */
    0x0000,     /* 0x1E information separator two                    */
    0x0000,     /* 0x1F information separator one                    */
    0x0000,     /* 0x20 space                                        */
    0x0021,     /* 0x21 exclam:         exclamation mark             */
    0x0022,     /* 0x22 quotedbl:       quotatioin mark              */
    0x0023,     /* 0x23 numbersign:     number sign                  */
    0x0024,     /* 0x24 dollar:         dollar sign                  */
    0x0025,     /* 0x25 percent:        percent sign                 */
    0x0026,     /* 0x26 ampersand:      ampersand                    */
    0x1110,     /* 0x27 apostrophe:     choseong thieuth             */
    0x0028,     /* 0x28 parenleft:      left parenthesis             */
    0x0029,     /* 0x29 parenright:     right parenthesis            */
    0x002a,     /* 0x2A asterisk:       asterisk                     */
    0x002b,     /* 0x2B plus:           plus sign                    */
    0x002c,     /* 0x2C comma:          comma                        */
    0x11bd,     /* 0x2D minus:          jongseong cieuc              */
    0x002e,     /* 0x2E period:         period                       */
    0x11ae,     /* 0x2F slash:          jongseong tikeut             */
    0x1164,     /* 0x30 0:              choseong  yae                */
    0x11c2,     /* 0x31 1:              jongseong hieuh              */
    0x11bb,     /* 0x32 2:              jongseong ssangsios          */
    0x11b8,     /* 0x33 3:              jongseong pieup              */
    0x116d,     /* 0x34 4:              jungseong yo                 */
    0x1172,     /* 0x35 5:              jungseong yu                 */
    0x1163,     /* 0x36 6:              jungseong ya                 */
    0x1168,     /* 0x37 7:              jungseong ye                 */
    0x1174,     /* 0x38 8:              jungseong yi                 */
    0x110f,     /* 0x39 9:              choseong khieukh             */
    0x003a,     /* 0x3A colon:          colon                        */
    0x1107,     /* 0x3B semicolon:      choseong  pieup              */
    0x0032,     /* 0x3C less:           2                            */
    0x11be,     /* 0x3D equal:          jongseong chieuch            */
    0x0033,     /* 0x3E greater:        3                            */
    0x003f,     /* 0x3F question:       question mark                */
    0x0040,     /* 0x40 at:             commertial at                */
    0x11bc,     /* 0x41 A:              jongseong ieung              */
    0x0021,     /* 0x42 B:              exclamation mark             */
    0x005c,     /* 0x43 C:              backslash                    */
    0x005d,     /* 0x44 D:              right bracket                */
    0x1167,     /* 0x45 E:              jungseong yeo                */
    0x1161,     /* 0x46 F:              jungseong a                  */
    0x002f,     /* 0x47 G:              slash                        */
    0x0027,     /* 0x48 H:              apostrophe                   */
    0x0038,     /* 0x49 I:              8                            */
    0x0034,     /* 0x4A J:              4                            */
    0x0035,     /* 0x4B K:              5                            */
    0x0036,     /* 0x4C L:              6                            */
    0x0031,     /* 0x4D M:              1                            */
    0x0030,     /* 0x4E N:              0                            */
    0x0039,     /* 0x4F O:              9                            */
    0x003e,     /* 0x50 P:              greater-than sign            */
    0x11ba,     /* 0x51 Q:              jongseong sios               */
    0x1162,     /* 0x52 R:              jungseong ae                 */
    0x005b,     /* 0x53 S:              left bracket                 */
    0x003b,     /* 0x54 T:              semicolon                    */
    0x0037,     /* 0x55 U:              7                            */
    0x1169,     /* 0x56 V:              jungseong o                  */
    0x11af,     /* 0x57 W:              jongseong rieul              */
    0x003d,     /* 0x58 X:              equals sign                  */
    0x003c,     /* 0x59 Y:              less-than sign               */
    0x002d,     /* 0x5A Z:              minus sign                   */
    0x11c0,     /* 0x5B bracketleft:    jongseong thieuth            */
    0x11bf,     /* 0x5C backslash:      jongseong khieukh            */
    0x11c1,     /* 0x5D bracketright:   jongseong phieuph            */
    0x005e,     /* 0x5E asciicircum:    circumflex accent            */
    0x005f,     /* 0x5F underscore:     underscore                   */
    0x0060,     /* 0x60 quoteleft:      grave accent                 */
    0x11bc,     /* 0x61 a:              jongseong ieung              */
    0x116e,     /* 0x62 b:              jungseong u                  */
    0x1166,     /* 0x63 c:              jungseong e                  */
    0x1175,     /* 0x64 d:              jungseong i                  */
    0x1167,     /* 0x65 e:              jungseong yeo                */
    0x1161,     /* 0x66 f:              jungseong a                  */
    0x1173,     /* 0x67 g:              jungseong eu                 */
    0x1102,     /* 0x68 h:              choseong  nieun              */
    0x1106,     /* 0x69 i:              choseong  mieum              */
    0x110b,     /* 0x6A j:              choseong  ieung              */
    0x1100,     /* 0x6B k:              choseong  kiyeok             */
    0x110c,     /* 0x6C l:              choseong  cieuc              */
    0x1112,     /* 0x6D m:              choseong  hieuh              */
    0x1109,     /* 0x6E n:              choseong  sios               */
    0x110e,     /* 0x6F o:              choseong  chieuch            */
    0x1111,     /* 0x70 p:              choseong  phieuph            */
    0x11ba,     /* 0x71 q:              jongseong sios               */
    0x1162,     /* 0x72 r:              jungseong ae                 */
    0x11ab,     /* 0x73 s:              jongseong nieun              */
    0x1165,     /* 0x74 t:              jungseong eo                 */
    0x1103,     /* 0x75 u:              choseong  tikeut             */
    0x1169,     /* 0x76 v:              jungseong o                  */
    0x11af,     /* 0x77 w:              jongseong rieul              */
    0x11a8,     /* 0x78 x:              jongseong kiyeok             */
    0x1105,     /* 0x79 y:              choseong  rieul              */
    0x11b7,     /* 0x7A z:              jongseong mieum              */
    0x007b,     /* 0x7B braceleft:      left brace                   */
    0x007c,     /* 0x7C bar:            vertical line(bar)           */
    0x007d,     /* 0x7D braceright:     right brace                  */
    0x007e,     /* 0x7E asciitilde:     tilde                        */
    0x0000      /* 0x7F delete                                       */
};

static const ucschar hangul_keyboard_table_3yet[] = {
    0x0000,     /* 0x00 null                                         */
    0x0000,     /* 0x01 start of heading                             */
    0x0000,     /* 0x02 start of text                                */
    0x0000,     /* 0x03 end of text                                  */
    0x0000,     /* 0x04 end of transmission                          */
    0x0000,     /* 0x05 enquiry                                      */
    0x0000,     /* 0x06 acknowledge                                  */
    0x0000,     /* 0x07 bell                                         */
    0x0000,     /* 0x08 backspace                                    */
    0x0000,     /* 0x09 character tabulation                         */
    0x0000,     /* 0x0A line feed (lf)                               */
    0x0000,     /* 0x0B line tabulation                              */
    0x0000,     /* 0x0C form feed (ff)                               */
    0x0000,     /* 0x0D carriage return (cr)                         */
    0x0000,     /* 0x0E shift out                                    */
    0x0000,     /* 0x0F shift in                                     */
    0x0000,     /* 0x10 data link escape                             */
    0x0000,     /* 0x11 device control one                           */
    0x0000,     /* 0x12 device control two                           */
    0x0000,     /* 0x13 device control three                         */
    0x0000,     /* 0x14 device control four                          */
    0x0000,     /* 0x15 negative acknowledge                         */
    0x0000,     /* 0x16 synchronous idle                             */
    0x0000,     /* 0x17 end of transmission block                    */
    0x0000,     /* 0x18 cancel                                       */
    0x0000,     /* 0x19 end of medium                                */
    0x0000,     /* 0x1A substitute                                   */
    0x0000,     /* 0x1B escape                                       */
    0x0000,     /* 0x1C information separator four                   */
    0x0000,     /* 0x1D information separator three                  */
    0x0000,     /* 0x1E information separator two                    */
    0x0000,     /* 0x1F information separator one                    */
    0x0000,     /* 0x20 space                                        */
    0x11bd,     /* 0x21 exclam:         jongseong cieuc              */
    0x0022,     /* 0x22 quotedbl:       quotatioin mark              */
    0x0023,     /* 0x23 numbersign:     number sign                  */
    0x0024,     /* 0x24 dollar:         dollar sign                  */
    0x0025,     /* 0x25 percent:        percent sign                 */
    0x0026,     /* 0x26 ampersand:      ampersand                    */
    0x1110,     /* 0x27 apostrophe:     choseong thieuth             */
    0x0028,     /* 0x28 parenleft:      left parenthesis             */
    0x0029,     /* 0x29 parenright:     right parenthesis            */
    0x002a,     /* 0x2A asterisk:       asterisk                     */
    0x002b,     /* 0x2B plus:           plus sign                    */
    0x002c,     /* 0x2C comma:          comma                        */
    0x002d,     /* 0x2D minus:          minus sign                   */
    0x002e,     /* 0x2E period:         period                       */
    0x1169,     /* 0x2F slash:          jungseong o                  */
    0x110f,     /* 0x30 0:              choseong  khieukh            */
    0x11c2,     /* 0x31 1:              jongseong hieuh              */
    0x11bb,     /* 0x32 2:              jongseong ssangsios          */
    0x11b8,     /* 0x33 3:              jongseong pieup              */
    0x116d,     /* 0x34 4:              jungseong yo                 */
    0x1172,     /* 0x35 5:              jungseong yu                 */
    0x1163,     /* 0x36 6:              jungseong ya                 */
    0x1168,     /* 0x37 7:              jungseong ye                 */
    0x1174,     /* 0x38 8:              jungseong yi                 */
    0x116e,     /* 0x39 9:              jungseong u                  */
    0x003a,     /* 0x3A colon:          colon                        */
    0x1107,     /* 0x3B semicolon:      choseong  pieup              */
    0x113c,     /* 0x3C less:           choseong chitueumsios        */
    0x003d,     /* 0x3D equal:          euals sign                   */
    0x113e,     /* 0x3E greater:        choseong ceongchieumsios     */
    0x003f,     /* 0x3F question:       question mark                */
    0x11eb,     /* 0x40 at:             jongseong pansios            */
    0x11ae,     /* 0x41 A:              jongseong tikeut             */
    0x0021,     /* 0x42 B:              exclamation mark             */
    0x11b1,     /* 0x43 C:              jongseong rieul-mieum        */
    0x11b0,     /* 0x44 D:              jongseong rieul-kiyeok       */
    0x11bf,     /* 0x45 E:              jongseong khieukh            */
    0x11a9,     /* 0x46 F:              jongseong ssangkiyeok        */
    0x119e,     /* 0x47 G:              jungseong araea              */
    0x0027,     /* 0x48 H:              apostrophe                   */
    0x1154,     /* 0x49 I:              choseong chitueumchieuch     */
    0x114c,     /* 0x4A J:              choseong yesieung            */
    0x114e,     /* 0x4B K:              choseong chitueumcieuc       */
    0x1150,     /* 0x4C L:              choseong ceongchieumcieuc    */
    0x1159,     /* 0x4D M:              choseong yeorinhieuh         */
    0x1140,     /* 0x4E N:              choseong pansios             */
    0x1155,     /* 0x4F O:              choseong ceongchieumchieuch  */
    0x003e,     /* 0x50 P:              greater-than sign            */
    0x11c1,     /* 0x51 Q:              jongseong phieuph            */
    0x1164,     /* 0x52 R:              jungseong yae                */
    0x11ad,     /* 0x53 S:              jongseong nieun-hieuh        */
    0x003b,     /* 0x54 T:              semicolon                    */
    0x00b7,     /* 0x55 U:              middle dot                   */
    0x11b6,     /* 0x56 V:              jongseong rieul-hieuh        */
    0x11c0,     /* 0x57 W:              jongseong thikeuth           */
    0x11b9,     /* 0x58 X:              jongseong pieup-sios         */
    0x003c,     /* 0x59 Y:              less-than sign               */
    0x11be,     /* 0x5A Z:              jongseong chieuch            */
    0x005b,     /* 0x5B bracketleft:    left bracket                 */
    0x005c,     /* 0x5C backslash:      backslash                    */
    0x005d,     /* 0x5D bracketright:   right bracket                */
    0x114c,     /* 0x5E asciicircum:    choseong yesieung            */
    0x005f,     /* 0x5F underscore:     underscore                   */
    0x11f9,     /* 0x60 quoteleft:      jongseong yeorinhieuh        */
    0x11bc,     /* 0x61 a:              jongseong ieung              */
    0x116e,     /* 0x62 b:              jungseong u                  */
    0x1166,     /* 0x63 c:              jungseong e                  */
    0x1175,     /* 0x64 d:              jungseong i                  */
    0x1167,     /* 0x65 e:              jungseong yeo                */
    0x1161,     /* 0x66 f:              jungseong a                  */
    0x1173,     /* 0x67 g:              jungseong eu                 */
    0x1102,     /* 0x68 h:              choseong  nieun              */
    0x1106,     /* 0x69 i:              choseong  mieum              */
    0x110b,     /* 0x6A j:              choseong  ieung              */
    0x1100,     /* 0x6B k:              choseong  kiyeok             */
    0x110c,     /* 0x6C l:              choseong  cieuc              */
    0x1112,     /* 0x6D m:              choseong  hieuh              */
    0x1109,     /* 0x6E n:              choseong  sios               */
    0x110e,     /* 0x6F o:              choseong  chieuch            */
    0x1111,     /* 0x70 p:              choseong  phieuph            */
    0x11ba,     /* 0x71 q:              jongseong sios               */
    0x1162,     /* 0x72 r:              jungseong ae                 */
    0x11ab,     /* 0x73 s:              jongseong nieun              */
    0x1165,     /* 0x74 t:              jungseong eo                 */
    0x1103,     /* 0x75 u:              choseong  tikeut             */
    0x1169,     /* 0x76 v:              jungseong o                  */
    0x11af,     /* 0x77 w:              jongseong rieul              */
    0x11a8,     /* 0x78 x:              jongseong kiyeok             */
    0x1105,     /* 0x79 y:              choseong  rieul              */
    0x11b7,     /* 0x7A z:              jongseong mieum              */
    0x007b,     /* 0x7B braceleft:      left brace                   */
    0x007c,     /* 0x7C bar:            vertical line(bar)           */
    0x007d,     /* 0x7D braceright:     right brace                  */
    0x11f0,     /* 0x7E asciitilde:     jongseong yesieung           */
    0x0000      /* 0x7F delete                                       */
};

static const ucschar hangul_keyboard_table_romaja[] = {
    0x0000,     /* 0x00 null                                         */
    0x0000,     /* 0x01 start of heading                             */
    0x0000,     /* 0x02 start of text                                */
    0x0000,     /* 0x03 end of text                                  */
    0x0000,     /* 0x04 end of transmission                          */
    0x0000,     /* 0x05 enquiry                                      */
    0x0000,     /* 0x06 acknowledge                                  */
    0x0000,     /* 0x07 bell                                         */
    0x0000,     /* 0x08 backspace                                    */
    0x0000,     /* 0x09 character tabulation                         */
    0x0000,     /* 0x0A line feed (lf)                               */
    0x0000,     /* 0x0B line tabulation                              */
    0x0000,     /* 0x0C form feed (ff)                               */
    0x0000,     /* 0x0D carriage return (cr)                         */
    0x0000,     /* 0x0E shift out                                    */
    0x0000,     /* 0x0F shift in                                     */
    0x0000,     /* 0x10 data link escape                             */
    0x0000,     /* 0x11 device control one                           */
    0x0000,     /* 0x12 device control two                           */
    0x0000,     /* 0x13 device control three                         */
    0x0000,     /* 0x14 device control four                          */
    0x0000,     /* 0x15 negative acknowledge                         */
    0x0000,     /* 0x16 synchronous idle                             */
    0x0000,     /* 0x17 end of transmission block                    */
    0x0000,     /* 0x18 cancel                                       */
    0x0000,     /* 0x19 end of medium                                */
    0x0000,     /* 0x1A substitute                                   */
    0x0000,     /* 0x1B escape                                       */
    0x0000,     /* 0x1C information separator four                   */
    0x0000,     /* 0x1D information separator three                  */
    0x0000,     /* 0x1E information separator two                    */
    0x0000,     /* 0x1F information separator one                    */
    0x0000,     /* 0x20 space                                        */
    0x0021,     /* 0x21 exclam:       exclamation mark               */
    0x0022,     /* 0x22 quotedbl:     quotation mark                 */
    0x0023,     /* 0x23 numbersign:   number sign                    */
    0x0024,     /* 0x24 dollar:       dollar sign                    */
    0x0025,     /* 0x25 percent:      percent sign                   */
    0x0026,     /* 0x26 ampersand:    ampersand                      */
    0x0027,     /* 0x27 apostrophe:   apostrophe                     */
    0x0028,     /* 0x28 parenleft:    left parenthesis               */
    0x0029,     /* 0x29 parenright:   right parenthesis              */
    0x002a,     /* 0x2A asterisk:     asterisk                       */
    0x002b,     /* 0x2B plus:         plus sign                      */
    0x002c,     /* 0x2C comma:        comma                          */
    0x002d,     /* 0x2D minus:        minus sign                     */
    0x002e,     /* 0x2E period:       period                         */
    0x002f,     /* 0x2F slash:        slash                          */
    0x0030,     /* 0x30 0:            0                              */
    0x0031,     /* 0x31 1:            1                              */
    0x0032,     /* 0x32 2:            2                              */
    0x0033,     /* 0x33 3:            3                              */
    0x0034,     /* 0x34 4:            4                              */
    0x0035,     /* 0x35 5:            5                              */
    0x0036,     /* 0x36 6:            6                              */
    0x0037,     /* 0x37 7:            7                              */
    0x0038,     /* 0x38 8:            8                              */
    0x0039,     /* 0x39 9:            9                              */
    0x003a,     /* 0x3A colon:        colon                          */
    0x003b,     /* 0x3B semicolon:    semicolon                      */
    0x003c,     /* 0x3C less:         less-than sign                 */
    0x003d,     /* 0x3D equal:        equals sign                    */
    0x003e,     /* 0x3E greater:      greater-than sign              */
    0x003f,     /* 0x3F question:     question mark                  */
    0x0040,     /* 0x40 at:           commercial at                  */
    0x1161,     /* 0x41 A:            jungseong a                    */
    0x1107,     /* 0x42 B:            choseong  pieup                */
    0x110e,     /* 0x43 C:            choseong  chieuch              */
    0x1103,     /* 0x44 D:            choseong  tikeut               */
    0x1166,     /* 0x45 E:            jungseong e                    */
    0x1111,     /* 0x46 F:            choseong  phieuph              */
    0x1100,     /* 0x47 G:            choseong  kiyeok               */
    0x1112,     /* 0x48 H:            choseong  heiuh                */
    0x1175,     /* 0x49 I:            jungseong i                    */
    0x110c,     /* 0x4A J:            choseong  cieuc                */
    0x110f,     /* 0x4B K:            choseong  khieukh              */
    0x1105,     /* 0x4C L:            choseong  rieul                */
    0x1106,     /* 0x4D M:            choseong  mieum                */
    0x1102,     /* 0x4E N:            choseong  nieun                */
    0x1169,     /* 0x4F O:            jungseong o                    */
    0x1111,     /* 0x50 P:            choseong  phieuph              */
    0x110f,     /* 0x51 Q:            choseong  khieukh              */
    0x1105,     /* 0x52 R:            choseong  rieul                */
    0x1109,     /* 0x53 S:            choseong  sios                 */
    0x1110,     /* 0x54 T:            choseong  thieuth              */
    0x116e,     /* 0x55 U:            jungseong u                    */
    0x1107,     /* 0x56 V:            choseong  pieup                */
    0x116e,     /* 0x57 W:            jungseong u                    */
    0x110c,     /* 0x58 X:            choseong  cieuc                */
    0x1175,     /* 0x59 Y:            jungseong i                    */
    0x110c,     /* 0x5A Z:            choseong  cieuc                */
    0x005b,     /* 0x5B bracketleft:  left bracket                   */
    0x005c,     /* 0x5C backslash:    backslash                      */
    0x005d,     /* 0x5D bracketright: right bracket                  */
    0x005e,     /* 0x5E asciicircum:  circumflex accent              */
    0x005f,     /* 0x5F underscore:   underscore                     */
    0x0060,     /* 0x60 quoteleft:    grave accent                   */
    0x1161,     /* 0x61 a:            jungseong a                    */
    0x1107,     /* 0x62 b:            choseong  pieup                */
    0x110e,     /* 0x63 c:            choseong  chieuch              */
    0x1103,     /* 0x64 d:            choseong  tikeut               */
    0x1166,     /* 0x65 e:            jungseong e                    */
    0x1111,     /* 0x66 f:            choseong  phieuph              */
    0x1100,     /* 0x67 g:            choseong  kiyeok               */
    0x1112,     /* 0x68 h:            choseong  hieuh                */
    0x1175,     /* 0x69 i:            jungseong i                    */
    0x110c,     /* 0x6A j:            choseong  cieuc                */
    0x110f,     /* 0x6B k:            choseong  khieukh              */
    0x1105,     /* 0x6C l:            choseong  rieul                */
    0x1106,     /* 0x6D m:            choseong  mieum                */
    0x1102,     /* 0x6E n:            choseong  nieun                */
    0x1169,     /* 0x6F o:            jungseong o                    */
    0x1111,     /* 0x70 p:            choseong  pieup                */
    0x110f,     /* 0x71 q:            choseong  khieukh              */
    0x1105,     /* 0x72 r:            choseong  rieul                */
    0x1109,     /* 0x73 s:            choseong  sios                 */
    0x1110,     /* 0x74 t:            choseong  thieuth              */
    0x116e,     /* 0x75 u:            jungseong u                    */
    0x1107,     /* 0x76 v:            choseong  phieuph              */
    0x116e,     /* 0x77 w:            jungseong u                    */
    0x11aa,     /* 0x78 x:            jongseong kiyeoksios           */
    0x1175,     /* 0x79 y:            jungseong i                    */
    0x110c,     /* 0x7A z:            choseong  cieuc                */
    0x007b,     /* 0x7B braceleft:    left brace                     */
    0x007c,     /* 0x7C bar:          vertical bar                   */
    0x007d,     /* 0x7D braceright:   right brace                    */
    0x007e,     /* 0x7E asciitilde:   tilde                          */
    0x0000      /* 0x7F delete                                       */
};

static const ucschar hangul_keyboard_table_ahn[] = {
    0x0000,     /* 0x00 null                                         */
    0x0000,     /* 0x01 start of heading                             */
    0x0000,     /* 0x02 start of text                                */
    0x0000,     /* 0x03 end of text                                  */
    0x0000,     /* 0x04 end of transmission                          */
    0x0000,     /* 0x05 enquiry                                      */
    0x0000,     /* 0x06 acknowledge                                  */
    0x0000,     /* 0x07 bell                                         */
    0x0000,     /* 0x08 backspace                                    */
    0x0000,     /* 0x09 character tabulation                         */
    0x0000,     /* 0x0A line feed (lf)                               */
    0x0000,     /* 0x0B line tabulation                              */
    0x0000,     /* 0x0C form feed (ff)                               */
    0x0000,     /* 0x0D carriage return (cr)                         */
    0x0000,     /* 0x0E shift out                                    */
    0x0000,     /* 0x0F shift in                                     */
    0x0000,     /* 0x10 data link escape                             */
    0x0000,     /* 0x11 device control one                           */
    0x0000,     /* 0x12 device control two                           */
    0x0000,     /* 0x13 device control three                         */
    0x0000,     /* 0x14 device control four                          */
    0x0000,     /* 0x15 negative acknowledge                         */
    0x0000,     /* 0x16 synchronous idle                             */
    0x0000,     /* 0x17 end of transmission block                    */
    0x0000,     /* 0x18 cancel                                       */
    0x0000,     /* 0x19 end of medium                                */
    0x0000,     /* 0x1A substitute                                   */
    0x0000,     /* 0x1B escape                                       */
    0x0000,     /* 0x1C information separator four                   */
    0x0000,     /* 0x1D information separator three                  */
    0x0000,     /* 0x1E information separator two                    */
    0x0000,     /* 0x1F information separator one                    */
    0x0000,     /* 0x20 space                                        */
    0x0021,     /* 0x21 exclam:       exclamation mark               */
    0x0022,     /* 0x22 quotedbl:     quotation mark                 */
    0x0023,     /* 0x23 numbersign:   number sign                    */
    0x0024,     /* 0x24 dollar:       dollar sign                    */
    0x0025,     /* 0x25 percent:      percent sign                   */
    0x0026,     /* 0x26 ampersand:    ampersand                      */
    0x002e,     /* 0x27 apostrophe:   period                         */
    0x0028,     /* 0x28 parenleft:    left parenthesis               */
    0x0029,     /* 0x29 parenright:   right parenthesis              */
    0x002a,     /* 0x2A asterisk:     asterisk                       */
    0x002b,     /* 0x2B plus:         plus sign                      */
    0x11b7,     /* 0x2C comma:        jongseong mieum                */
    0x002d,     /* 0x2D minus:        minus sign                     */
    0x11af,     /* 0x2E period:       jongseong rieul                */
    0x11c2,     /* 0x2F slash:        jongseong hieuh                */
    0x0030,     /* 0x30 0:            0                              */
    0x0031,     /* 0x31 1:            1                              */
    0x0032,     /* 0x32 2:            2                              */
    0x0033,     /* 0x33 3:            3                              */
    0x0034,     /* 0x34 4:            4                              */
    0x0035,     /* 0x35 5:            5                              */
    0x0036,     /* 0x36 6:            6                              */
    0x0037,     /* 0x37 7:            7                              */
    0x0038,     /* 0x38 8:            8                              */
    0x0039,     /* 0x39 9:            9                              */
    0x003a,     /* 0x3A colon:        colon                          */
    0x116e,     /* 0x3B semicolon:    jungseong u                    */
    0x003c,     /* 0x3C less:         less-than sign                 */
    0x003d,     /* 0x3D equal:        equals sign                    */
    0x003e,     /* 0x3E greater:      greater-than sign              */
    0x11f9,     /* 0x3F question:     jongseong yeorinhieuh          */
    0x0040,     /* 0x40 at:           commercial at                  */
    0x1107,     /* 0x41 A:            choseong pieup                 */
    0x11f0,     /* 0x42 B:            jongseong yesieung             */
    0x11b8,     /* 0x43 C:            jongseong pieup                */
    0x1103,     /* 0x44 D:            choseong tikeut                */
    0x1102,     /* 0x45 E:            choseong nieun                 */
    0x1100,     /* 0x46 F:            choseong kiyeok                */
    0x114c,     /* 0x47 G:            choseong yesieung              */
    0x1165,     /* 0x48 H:            jungseong eo                   */
    0x002f,     /* 0x49 I:            slash                          */
    0x119e,     /* 0x4A J:            jungseong araea                */
    0x1175,     /* 0x4B K:            jungseong i                    */
    0x1169,     /* 0x4C L:            jungseong o                    */
    0x11ab,     /* 0x4D M:            jongseong nienu                */
    0x11eb,     /* 0x4E N:            jongseung pansios              */
    0x005b,     /* 0x4F O:            left bracket                   */
    0x005d,     /* 0x50 P:            right bracket                  */
    0x1106,     /* 0x51 Q:            choseong mieum                 */
    0x1105,     /* 0x52 R:            choseong rieul                 */
    0x110c,     /* 0x53 S:            choseong cieuc                 */
    0x1159,     /* 0x54 T:            choseong yeorinhieuh           */
    0x0027,     /* 0x55 U:            apostrophe                     */
    0x11a8,     /* 0x56 V:            jongseong kiyeok               */
    0x1140,     /* 0x57 W:            choseong pansios               */
    0x11ae,     /* 0x58 X:            jongseong tikeut               */
    0x003b,     /* 0x59 Y:            semicolon                      */
    0x11bd,     /* 0x5A Z:            jongseong cieuc                */
    0x002c,     /* 0x5B bracketleft:  comma                          */
    0x005c,     /* 0x5C backslash:    backslash                      */
    0x003f,     /* 0x5D bracketright: qustion mark                   */
    0x005e,     /* 0x5E asciicircum:  circumflex accent              */
    0x005f,     /* 0x5F underscore:   underscore                     */
    0x0060,     /* 0x60 quoteleft:    grave accent                   */
    0x1107,     /* 0x61 a:            choseong  pieup                */
    0x11bc,     /* 0x62 b:            jongseong ieung                */
    0x11b8,     /* 0x63 c:            jongseong pieup                */
    0x1103,     /* 0x64 d:            choseong  tikeut               */
    0x1102,     /* 0x65 e:            choseong nieun                 */
    0x1100,     /* 0x66 f:            choseong kiyeok                */
    0x110b,     /* 0x67 g:            choseong ieung                 */
    0x1165,     /* 0x68 h:            jungseong eo                   */
    0x1173,     /* 0x69 i:            jungseong eu                   */
    0x1161,     /* 0x6A j:            jungseong a                    */
    0x1175,     /* 0x6B k:            jungseong i                    */
    0x1169,     /* 0x6C l:            jungseong o                    */
    0x11ab,     /* 0x6D m:            jongseong nieun                */
    0x11ba,     /* 0x6E n:            jongseong sios                 */
    0x116d,     /* 0x6F o:            jungseong yo                   */
    0x1172,     /* 0x70 p:            jungseong yu                   */
    0x1106,     /* 0x71 q:            choseong mieum                 */
    0x1105,     /* 0x72 r:            choseong rieul                 */
    0x110c,     /* 0x73 s:            choseong cieuc                 */
    0x1112,     /* 0x74 t:            choseong hieuh                 */
    0x1163,     /* 0x75 u:            jungseong ya                   */
    0x11a8,     /* 0x76 v:            jongseong kiyok                */
    0x1109,     /* 0x77 w:            choseong sios                  */
    0x11ae,     /* 0x78 x:            jongseong tikeut               */
    0x1167,     /* 0x79 y:            jungseong yeo                  */
    0x11bd,     /* 0x7A z:            jongseong cieuc                */
    0x007b,     /* 0x7B braceleft:    left brace                     */
    0x007c,     /* 0x7C bar:          vertical bar                   */
    0x007d,     /* 0x7D braceright:   right brace                    */
    0x007e,     /* 0x7E asciitilde:   tilde                          */
    0x0000      /* 0x7F delete                                       */
};


#endif /* libhangul_hangulkeyboard_h */
