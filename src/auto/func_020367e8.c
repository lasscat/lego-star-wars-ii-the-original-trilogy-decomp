#include "m2c.h"

M2C_UNK func_0201807c(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_0202bd60(M2C_UNK);
M2C_UNK func_0204a62c(M2C_UNK, M2C_UNK);
M2C_UNK func_0205e80c(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_0203a780(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_0202c1a8(M2C_UNK, M2C_UNK);

void func_020367e8(void *arg0) {
    s32 var_r1;
    s32 var_r2;
    s32 var_r3;
    s32 var_r4;
    u16 var_r5;
    u16 var_r6;
    volatile u16 var_r7;
    M2C_UNK var_r8;
    u8 var_r9;

    var_r1 = M2C_FIELD(arg0, s32 *, 0x10);
    var_r2 = var_r1;
    if (var_r1 != 0) {
        var_r2 -= 4;
    }
    if (var_r2 != 0) {
        var_r3 = var_r1;
        if (var_r1 != 0) {
            var_r3 -= 4;
        }
        if (M2C_FIELD(var_r3, s32 *, 0x6ac) == 0) {
            M2C_FIELD(arg0, u8 *, 0xc) = M2C_FIELD(arg0, u8 *, 0xc) | 1;
            func_0202bd60(M2C_FIELD(arg0, s32 *, 4) + 0x608);
            return;
        }
        if (M2C_FIELD(arg0, u8 *, 0x21) == 0) {
            var_r4 = var_r1;
            if (var_r1 != 0) {
                var_r4 -= 4;
            }
            M2C_FIELD(arg0, u8 *, 0x21) = M2C_FIELD(var_r4, u8 *, 0x1ad);
        }
    }
    if (M2C_FIELD(arg0, u8 *, 0x20) != 0) {
        func_0202bd60(M2C_FIELD(arg0, s32 *, 4) + 0x608);
        M2C_FIELD(arg0, u8 *, 0xc) = M2C_FIELD(arg0, u8 *, 0xc) | 1;
        return;
    }
    if (M2C_FIELD(arg0, u8 *, 0x22) == 0) {
        if (M2C_FIELD(M2C_FIELD(arg0, s32 *, 4), u8 *, 0x698) != 0) {
            M2C_FIELD(arg0, u8 *, 0x22) = 1;
            func_0204a62c(M2C_FIELD(arg0, s32 *, 4) + 0x5ce, M2C_FIELD(arg0, s32 *, 4));
        }
    }
    if (M2C_FIELD(arg0, u8 *, 0x22) != 0) {
        var_r2 = M2C_FIELD(arg0, s32 *, 0x18);
        if (var_r2 != 0) {
            var_r2 -= 4;
        }
        var_r4 = M2C_FIELD(arg0, s32 *, 4);
        func_0201807c(&var_r6, var_r4, var_r2 + 0xb0, 0);
        var_r5                                             = var_r6;
        M2C_FIELD(M2C_FIELD(arg0, s32 *, 4), u16 *, 0x6b4) = var_r5;
        var_r9                                             = M2C_FIELD(arg0, u8 *, 0x21);
        var_r7                                             = var_r5;
        if (var_r9 != 0) {
            M2C_FIELD(arg0, u8 *, 0x20) = 1;
            var_r8                      = func_0205e80c(0x18, 1, 4);
            if (var_r8 != 0) {
                var_r2 = M2C_FIELD(arg0, s32 *, 0x18);
                if (var_r2 != 0) {
                    var_r2 -= 4;
                }
                var_r4 = M2C_FIELD(arg0, s32 *, 4);
                var_r8 = func_0203a780(var_r8, var_r4, var_r2);
            }
            func_0202c1a8(M2C_FIELD(arg0, s32 *, 4) + 0x5e0, var_r8);
        }
    }
    func_0204a62c(M2C_FIELD(arg0, s32 *, 4) + 0x5ce, M2C_FIELD(arg0, s32 *, 4));
}
