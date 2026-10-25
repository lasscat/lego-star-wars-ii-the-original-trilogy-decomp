#include "m2c.h"

M2C_UNK func_0205e624(s32, M2C_UNK, M2C_UNK);       /* extern */
void func_02007f24(s32 *, double);

/* Fixed-point (20.12) multiply of *a and b, rounded; 0 for a null pointer. */
static inline s32 fxmul_ptr(s32 *a, s32 *b) {
    s32 r  = 0;
    s32 *p = a; // FAKE: local copy keeps the (always-true) null test and the add r0,sp,#4 / ldr form; direct test on the
                // inlined arg is folded away
    if (p) {
        r = (s32) ((((s64) *p * (s64) *b) + 0x800) >> 12);
    }
    return r;
}

void func_020351c0(void *arg0, s32 arg1, s8 arg2) {
    s32 sp8;
    s32 sp4;
    s32 sp0;
    void **temp_r1;
    void **temp_r1_2;

    func_0205e624(arg0 + 0x54, 0, 8);
    M2C_FIELD(arg0, s8 *, 0x30) = 4;
    temp_r1                     = M2C_FIELD(arg0, void ***, 4);
    M2C_FIELD(*temp_r1, M2C_UNK(**)(s32 *, void **, M2C_UNK), 0x3C)(&sp8, temp_r1, 6);
    M2C_FIELD(arg0, s32 *, 0x10) = sp8;
    func_02007f24(&sp0, 1.5);
    temp_r1_2 = M2C_FIELD(arg0, void ***, 4);
    M2C_FIELD(*temp_r1_2, M2C_UNK(**)(s32 *, void **, M2C_UNK), 0x3C)(&sp4, temp_r1_2, 6);
    M2C_FIELD(arg0, s32 *, 0x14) = fxmul_ptr(&sp4, &sp0);
    M2C_FIELD(arg0, s8 *, 0x1D)  = 1;
    M2C_FIELD(arg0, s32 *, 0x54) = arg1;
    M2C_FIELD(arg0, s8 *, 0x58)  = arg2;
}
