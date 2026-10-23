#include "m2c.h"

extern u16 data_020ece7c[4];

void func_0201c778(u16 *);
void func_0201c858(u16 *, s32, u16);
s32 func_020ab574(void *, void *, s32);
void func_0201c7e8(u16 *, u16 *);
s32 func_0201c814(u16 *);
s32 func_0205ab58(s32);
s32 func_020ab770(void *, s32, s32, s32, u8);
s32 func_0205ab44(s32);
s32 func_020ab828(void *, s32, s32, s32, s32, u8);

void func_0201d89c(void *arg0, u16 arg1) {
    u16 tbl[4];
    u16 vals[5];
    u16 v;
    s32 r;
    void *base;

    base = (void *) ((s8 *) arg0 + 0xd8);
    if (M2C_FIELD(arg0, u8 *, 0x1c0) == arg1) {
        return;
    }
    tbl[0]                       = data_020ece7c[0];
    tbl[1]                       = data_020ece7c[1];
    tbl[2]                       = data_020ece7c[2];
    tbl[3]                       = data_020ece7c[3];
    M2C_FIELD(arg0, u8 *, 0x1c0) = arg1;
    func_0201c778(vals);
    v = tbl[arg1];
    func_0201c858(vals, 0, v);
    r = func_020ab574(base, vals, 0);
    func_0201c7e8(vals, (u16 *) r);
    if (func_0201c814(vals) != 0) {
        return;
    }
    func_020ab770(base, 0, func_0205ab58(0x93f), 0x1000, 0);
    func_020ab828(base, 0, func_0205ab44(v), 4, 0, 0);
}
