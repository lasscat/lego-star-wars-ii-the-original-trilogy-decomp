#include "m2c.h"

extern s32 data_02101b70[];

typedef struct {
    u16 v;
} HalfWord;

void func_02007f24(s32 *, double);
s32 func_02031214(void *, HalfWord, HalfWord);
s32 func_02018210(void *, HalfWord, HalfWord);
void func_0203095c(void *, u32, s32);

void func_02030540(void *arg0, u32 arg1, HalfWord arg2) {
    s32 lim;
    s32 res;

    M2C_FIELD(M2C_FIELD(arg0, s32 *, 4), s32 *, 8) &= ~0x200;
    lim = (s32) ((((s64) M2C_FIELD(arg0, s32 *, 0x14) * (s64) data_02101b70[0]) + 0x800) >> 12);

    if (arg1 != 0) {
        volatile s32 t;
        s32 v;
        func_02007f24(&t, 0.1);
        v                            = M2C_FIELD(arg0, s32 *, 0x10) + t;
        M2C_FIELD(arg0, s32 *, 0x10) = v;
        if (v > lim) {
            M2C_FIELD(arg0, s32 *, 0x10) = lim;
        }
    } else {
        volatile s32 t;
        s32 v;
        func_02007f24(&t, 0.1);
        v                            = M2C_FIELD(arg0, s32 *, 0x10) - t;
        M2C_FIELD(arg0, s32 *, 0x10) = v;
        if (v < 0) {
            M2C_FIELD(arg0, s32 *, 0x10) = 0;
        }
    }

    if (M2C_FIELD(arg0, u8 *, 0x1d) != 0) {
        HalfWord h;
        h.v = 0x71c;
        res = func_02031214(arg0, arg2, h);
    } else {
        HalfWord h;
        h.v = 0x71c;
        res = func_02018210((void *) M2C_FIELD(arg0, s32 *, 4), arg2, h);
    }
    func_0203095c(arg0, arg1, res);
}
