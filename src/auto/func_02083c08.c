#include "m2c.h"

extern M2C_UNK data_0210930c;

void func_02083c08(s32 *a0, u8 *a1) {
    s32 i;
    s32 k;
    u8 cnt;

    for (i = 0; i < 3; i++) {
        u8 *e  = a1 + i;
        u8 val = e[0x1d];
        s32 len;
        s32 j;
        if (val == 0) {
            continue;
        }
        {
            u32 idx = val + 1;
            u8 *q   = *(u8 **) (M2C_FIELD(&data_0210930c, u8 **, 0x68) + 0x38c);
            q       = *(u8 **) (q + 4);
            if (idx != 0) {
                u8 *rec = *(u8 **) (q + 0x2c);
                len     = rec[idx * 8 - 3];
            } else {
                len = 0;
            }
        }
        j = 0;
        if (len > 0) {
            do {
                u8 v2     = e[0x1d];
                u8 **t2   = M2C_FIELD(a0, u8 ***, 0x54);
                u8 c2     = M2C_FIELD(a0, u8 *, 0x50);
                t2[v2][j] = c2;
                j++;
            } while (j < len);
        }
    }

    for (k = 0; k < 3; k++) {
        u8 len2 = a1[k * 2 + 0x21];
        if (len2 != 0) {
            u8 v2            = a1[k * 2 + 0x20];
            u8 **t2          = M2C_FIELD(a0, u8 ***, 0x54);
            u8 c2            = M2C_FIELD(a0, u8 *, 0x50);
            t2[v2][len2 - 1] = c2;
        }
    }

    cnt                       = M2C_FIELD(a0, u8 *, 0x50);
    M2C_FIELD(a0, u8 *, 0x50) = cnt + 1;
    a0[cnt]                   = (s32) a1;
}
