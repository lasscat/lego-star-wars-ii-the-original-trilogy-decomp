#include "m2c.h"

M2C_UNK func_0205ab44(u16);
void func_02059efc(void *, u32);

typedef struct {
    u16 f0;
    u16 f2;
} Head;

typedef struct {
    u8 pad0[6];
    u16 count;
    u8 pad1[4];
    u16 list[1];
} Tbl;

void func_02064cd8(Head *arg0, u32 arg1, s32 arg2, u32 arg3) {
    s32 acc;
    u32 i;
    Tbl *tbl;
    u8 *p;
    u32 off;

    tbl = (Tbl *) func_0205ab44(arg0->f2);
    acc = 0;
    i   = 0;
    if (i < tbl->count) {
        u32 offA = (arg3 << 21) + 0x6400000 + (arg1 << 5);
        u32 offB = (arg3 << 21) + 0x6400000 + (arg1 << 6);
        do {
            p = (u8 *) &tbl->list[0] + tbl->list[i];
            if (arg2 == 0) {
                off = acc + offA;
            } else {
                off = acc + offB;
            }
            acc += ((u8) p[2] * (u8) p[3]) >> 1;
            func_02059efc((u8 *) func_0205ab44(arg0->f0) + *(u16 *) (p + 4), off);
            i++;
        } while (i < tbl->count);
    }
}
