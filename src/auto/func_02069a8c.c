#include "m2c.h"

extern M2C_UNK data_02104364;
extern M2C_UNK data_02104d90;

void func_0206574c(M2C_UNK, s32, s32);
M2C_UNK func_02066708(M2C_UNK);
void func_02065be8(M2C_UNK, M2C_UNK, s32, s32, s32, s32);
void func_02065600(M2C_UNK, s32);
void func_020661c4(M2C_UNK, M2C_UNK);
void func_020661d4(M2C_UNK, M2C_UNK);
s32 func_020861a0(s32, s32);
s32 func_02065a78(M2C_UNK, s32, M2C_UNK, s32, s32, M2C_UNK, s32);
void func_02069be8(M2C_UNK, s32);

void func_02069a8c(M2C_UNK arg0, s32 arg1) {
    s32 r5;
    s32 i;
    s32 v;
    u8 *b;
    s32 r9;
    if (arg1 != 0) {
        v = (M2C_FIELD(arg0, u8 *, 0x28) == 1) ? 0x2C : 0x28;
        func_0206574c(M2C_FIELD(arg0, M2C_UNK *, 0x18), 6, -2);
        func_02065be8(M2C_FIELD(arg0, M2C_UNK *, 0x18), 1, 0x80, 0x14, func_02066708(v), 1);
    }
    r5 = 0x32;
    func_02065600(M2C_FIELD(arg0, M2C_UNK *, 0x18), 3);
    b  = (u8 *) &data_02104364;
    i  = 0;
    r9 = 0x2B;
    while (i < 3) {
        u32 *w = (u32 *) &data_02104364;
        func_020661c4(M2C_FIELD(arg0, M2C_UNK *, 0x18), w[i + 4]);
        func_020661d4(M2C_FIELD(arg0, M2C_UNK *, 0x18), b[0xB]);
        v = 0x27;
        if (func_020861a0((s32) &data_02104d90, i)) {
            func_0206574c(M2C_FIELD(arg0, M2C_UNK *, 0x18), 0xC, -2);
            v = 0x2B;
        } else {
            func_0206574c(M2C_FIELD(arg0, M2C_UNK *, 0x18), 6, -1);
        }
        r5 = func_02065a78(M2C_FIELD(arg0, M2C_UNK *, 0x18), r5, r9, 0x68, 0x46, func_02066708(v), 1);
        b++;
        r9 += 0x56;
        i++;
    }
    func_02065600(M2C_FIELD(arg0, M2C_UNK *, 0x18), 4);
    func_0206574c(M2C_FIELD(arg0, M2C_UNK *, 0x18), 6, 0);
    func_02069be8(arg0, M2C_FIELD(arg0, s32 *, 0x1C));
}
