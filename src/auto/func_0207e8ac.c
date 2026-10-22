#include "m2c.h"

M2C_UNK func_02068e34(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK data_020eff10;
extern M2C_UNK data_020ef57c;
extern M2C_UNK data_02104d5c;

typedef struct {
    u8 pad[6];
    s16 f6;
    s16 f8;
    u8 pad2[2];
} EffEntry;

void func_0207e8ac(void *arg0) {
    s32 acc;
    u32 i;
    s32 k;
    EffEntry *p;
    u32 v;
    s32 flag;
    void *obj;

    p   = (EffEntry *) &data_020eff10;
    acc = 1;
    k   = 5;
    for (i = 0; i < 8; i++) {
        flag = 0;
        v    = ((u32 *) &data_02104d5c)[i + 2];
        if (v < 100) {
            u16 kk = (u16) k;
            k++;
            acc += func_02068e34(acc, p->f6, p->f8, kk, M2C_FIELD(arg0, void **, 0x10),
                                 (void *) ((u8 *) &data_020ef57c + v * 0x18 + 8), 0);
            obj                         = ((void **) M2C_FIELD(arg0, void **, 0x14))[i];
            flag                        = 1;
            M2C_FIELD(obj, u32 *, 0x14) = (M2C_FIELD(obj, u32 *, 0x14) & ~0xF000u) | 0xF000u;
        }
        obj                      = ((void **) M2C_FIELD(arg0, void **, 0x14))[i];
        M2C_FIELD(obj, u32 *, 8) = flag ? (M2C_FIELD(obj, u32 *, 8) | 1) : (M2C_FIELD(obj, u32 *, 8) & ~1u);
        p++;
    }
}
