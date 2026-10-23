#include "m2c.h"

s32 func_02093fd0(s32);                                          /* extern */
void func_0205ecc4(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
extern M2C_UNK data_02102900;
extern u8 data_02106d90[];
extern u8 data_02107942[];

void func_0206d334(void *arg0) {
    u8 *p;

    if (data_02106d90[0xbb5] != 0) {
        p = &data_02107942[0];
        if (func_02093fd0(p[0]) != func_02093fd0(0xe)) {
            func_0205ecc4(&data_02102900, 0xf, 0, 0, 0, 0);
            func_0205ecc4(&data_02102900, 0x1c, 1, func_02093fd0(p[0]), p[0], data_02106d90[0xbb3]);
            return;
        } else {
            func_0205ecc4(&data_02102900, 4, 0, 4, p[0], data_02106d90[0xbb3]);
        }
    } else {
        p = &data_02107942[0];
        if (func_02093fd0(p[0]) != func_02093fd0(0xe)) {
            func_0205ecc4(&data_02102900, 4, 0, 0x12, p[0], M2C_FIELD(arg0, s32 *, 8));
        } else {
            func_0205ecc4(&data_02102900, 4, 0, 4, p[0], data_02106d90[0xbb3]);
        }
    }
    func_0205ecc4(&data_02102900, 0x30, 1, 0, 0, 0);
}
