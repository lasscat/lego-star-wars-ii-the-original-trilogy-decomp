/* Reconstructed from USA ARM9 at 0x02066470 (204 bytes).
 * The string returned by func_02066708 is scanned for "@<digit>" markers;
 * each marker is replaced in place by the matching 64 byte entry of
 * data_021046fc, shifting the remainder of the string to the right.
 */
#include "m2c.h"

extern M2C_UNK data_021046fc;

M2C_UNK *func_02066708(M2C_UNK);
s32 func_020e0db0(s8 *);
void *func_020de878(void *, void *, u32);
char *strchr(const char *, int);
void *memcpy(void *, const void *, int);

u8 *func_02066470(M2C_UNK arg0, M2C_UNK arg1) {
    s32 i = 0;
    u8 *s = (u8 *) func_02066708(arg1);
    u8 *f;

    f = (u8 *) strchr((char *) s, '@');
    if (f == 0) {
        return s;
    }
    for (; s[i] != 0;) {
        u8 c = s[i];
        if (c == '@') {
            u8 *e   = (u8 *) &data_021046fc + (s[i + 1] - '1') * 0x40;
            s32 len = func_020e0db0(e);
            s32 len2;
            i += 2;
            len2 = func_020e0db0(&s[i]);
            func_020de878(&s[i + len - 2], &s[i], len2 + 1);
            memcpy(&s[i - 2], e, len);
            i += len - 2;
        } else {
            if (c >= 0xf0) {
                i++;
            }
            i++;
        }
    }
    return s;
}
