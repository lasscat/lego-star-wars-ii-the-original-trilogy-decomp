#include "m2c.h"
#include "engine.h"

void func_0209f2cc(M2C_UNK);
void func_0209f8d4(M2C_UNK);
void func_020c3be0(M2C_UNK, M2C_UNK);

void func_0209f844(s32 arg0) {
    s32 temp_r1;
    s32 temp_r1_2;

    func_0209f8d4(arg0);
    temp_r1 = M2C_FIELD(arg0, s32 *, 0x7C);
    if (temp_r1 != 0) {
        func_020c3be0(arg0 + 0x20, temp_r1);
        func_0209f2cc(arg0 + 0x7C);
    }
    if (((u32) (M2C_FIELD(arg0, u16 *, 0xB2) << 0x1E) >> 0x1F) == 1) {
        M2C_FIELD(arg0, s32 *, 0x7C) = (s32) M2C_FIELD(arg0, s32 *, 0x74);
        M2C_FIELD(arg0, u16 *, 0x80) = (u16) M2C_FIELD(arg0, u16 *, 0x78);
        M2C_FIELD(arg0, u16 *, 0x82) = (u16) M2C_FIELD(arg0, u16 *, 0x7A);
    } else {
        temp_r1_2 = M2C_FIELD(arg0, s32 *, 0x74);
        if (temp_r1_2 != 0) {
            func_020c3be0(arg0 + 0x20, temp_r1_2);
            func_0209f2cc(arg0 + 0x74);
        }
    }
    M2C_FIELD(arg0, u16 *, 0x7A) = (u16) (M2C_FIELD(arg0, u16 *, 0x7A) & ~1);
    M2C_FIELD(arg0, u16 *, 0x7A) = (u16) (M2C_FIELD(arg0, u16 *, 0x7A) | 2);
}
