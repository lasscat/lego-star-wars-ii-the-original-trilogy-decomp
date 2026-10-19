#include "m2c.h"

typedef struct {
    u16 v;
    u16 pad;
} W;
extern W data_02100a00[];
extern void *data_0210daf4[];

s32 func_020b9284(s32 arg0) {
    s32 i, j;
    void *p;
    for (i = 0; i < 3; i++) {
        p = data_0210daf4[i + 2];
        if (p == NULL) {
            continue;
        }
        if (*(u8 *) ((s8 *) p + 0x25) == 1) {
            for (j = 0; j < 0x1D; j++) {
                if (*(u16 *) ((s8 *) p + 0x1C) == data_02100a00[j].v) {
                    return j;
                }
            }
        }
        if (arg0 != 0) {
            return 0x1D;
        }
    }
    return 0x1D;
}
