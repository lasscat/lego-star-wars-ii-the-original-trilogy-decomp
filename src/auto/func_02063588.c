#include "m2c.h"

s32 func_02063510(u8 *, M2C_UNK);                   /* extern */
s32 func_02063610(M2C_UNK, M2C_UNK, u8 *);          /* extern */
extern u8 data_020edc58;
extern u8 data_02104364;

s32 func_02063588(void) {
    s32 flags;
    s32 count;
    s32 i;
    u8 *p;
    u8 *q;

    if (func_02063610(0, 2, &data_02104364) == 0) {
        return 1;
    }
    flags = 0;
    if (func_02063510(&data_02104364, 0x20) != 0) {
        flags |= 8;
    }
    count = 0;
    p     = &data_020edc58;
    q     = &data_02104364;
    for (i = 0; i < 8; i++) {
        if (*q != *p) {
            count += 1;
            flags |= 4;
        }
        p += 1;
        q += 1;
    }
    if (count == 8) {
        flags &= ~8;
    }
    return flags;
}
