#include "m2c.h"

extern M2C_UNK data_02107942;
extern M2C_UNK data_02107943;
extern M2C_UNK data_02104d90;
extern M2C_UNK data_02102900;

u8 func_02094068(s32);
u8 func_02094078(s32);
void func_0207f2b0(M2C_UNK);
void func_0205365c(s32 *, s32);
void func_020861bc(void *, s32, s32);
s32 func_02085d20(void *, M2C_UNK);
void func_0205ecc4(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);

void func_0207da48(M2C_UNK arg0) {
    u8 *b;
    u8 *a;
    u32 v;

    a  = (u8 *) &data_02107942;
    *a = func_02094068(M2C_FIELD(arg0, s32 *, 0));
    b  = (u8 *) &data_02107943;
    *b = func_02094078(M2C_FIELD(arg0, s32 *, 0));
    func_0207f2b0(arg0);
    v = M2C_FIELD(arg0, u32 *, 0);
    if (v >= 15) {
        func_0205365c(M2C_FIELD(arg0, s32 *, 0x10), 0);
        M2C_FIELD(arg0, u8 *, 0x27) = 6;
        func_020861bc(&data_02104d90, 0xA, 0);
        func_0205ecc4(&data_02102900, 0xF, 0, 0, 0, 0);
        func_0205ecc4(&data_02102900, 0x1C, 1, 0x1A, 0xE, 0);
    } else {
        if (func_02085d20(&data_02104d90, 0) != 0) {
            func_0205365c(M2C_FIELD(arg0, s32 *, 0x10), 0);
            M2C_FIELD(arg0, u8 *, 0x27) = 6;
            func_020861bc(&data_02104d90, 0xA, 0);
            func_0205ecc4(&data_02102900, 4, 0, 4, *a, *b);
            func_0205ecc4(&data_02102900, 0x30, 1, 0, 0, 0);
        } else {
            func_0205ecc4(&data_02102900, 0x1F, 0, 2, 0, 0);
        }
    }
}
