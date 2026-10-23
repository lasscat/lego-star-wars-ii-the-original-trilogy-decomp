#include "m2c.h"

M2C_UNK func_0207a8c4(M2C_UNK);                     /* extern */
s32 func_0205d0d0(s32, s32, s32);                   /* extern */
void func_02087044(M2C_UNK);                        /* extern */
void func_0205ecc4(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
void func_020b8f70(M2C_UNK, s32);                   /* extern */
M2C_UNK func_020780a4(M2C_UNK);                     /* extern */
M2C_UNK func_020782a8(M2C_UNK);                     /* extern */
M2C_UNK func_020784b8(M2C_UNK);                     /* extern */
void func_02077170(M2C_UNK);                        /* extern */

extern u8 data_021027f8[];
extern u8 data_02104d90[];
extern u8 data_02102900[];

void func_02077088(void *arg0) {
    if (func_0207a8c4(arg0) != 0) {
        return;
    }
    if (func_0205d0d0((s32) data_021027f8, 2, 4) != 0) {
        func_02087044((M2C_UNK) data_02104d90);
        func_0205ecc4((M2C_UNK) data_02102900, 0x30, 1, 0, 1, 0);
        func_020b8f70(0xb5, 0);
        return;
    }
    if (func_020780a4(arg0) != 0) {
        return;
    }
    if (*(u8 *) ((s8 *) arg0 + 0xd0) < 3) {
        if (func_020782a8(arg0) != 0) {
            return;
        }
    }
    if (*(u8 *) ((s8 *) arg0 + 0xd0) == 3) {
        if (func_020784b8(arg0) != 0) {
            return;
        }
    }
    func_02077170(arg0);
}
