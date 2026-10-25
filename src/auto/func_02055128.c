#include "m2c.h"

extern void func_02055210(M2C_UNK, M2C_UNK);
extern void func_02017e8c(void *, s32 *);
extern void func_020554cc(M2C_UNK, void *, void **);
extern s32 func_0201aaec(void);

void func_02055128(void *obj, void *p) {
    s32 x0;
    s32 shx;
    s32 limx;
    s32 y0;
    s32 limy;
    s32 shy;
    s32 v[6];
    s32 *b = v;
    s32 x;
    s32 y;

    do {
        *b++ = 0;
    } while (b < v + 6);

    func_02055210(obj, p);
    func_02017e8c(p, v);

    x0   = v[0] >> (func_0201aaec() + 5);
    shx  = func_0201aaec() + 5;
    limx = v[1];
    y0   = v[4] >> (func_0201aaec() + 5);
    shy  = func_0201aaec();
    shy += 5;
    limy = v[5];

    for (y = y0; y <= (limy >> shy); y++) {
        for (x = x0; x <= (limx >> shx); x++) {
            u8 *cell = (u8 *) obj + 0x24;
            cell += (((u32) x) << 28) >> 22;
            cell += (((u32) y) << 28) >> 26;
            func_020554cc(obj, p, (void **) cell);
        }
    }
}
