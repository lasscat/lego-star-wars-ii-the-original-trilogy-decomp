#include "m2c.h"

M2C_UNK func_020aa7c0(void *, void *);                      /* extern */
void *func_020aa8f0(void *, void *, M2C_UNK, s32, s32, s32); /* extern */

void func_020a0370(void *arg0, void *arg1) {
    void *temp_r0;
    void *temp_r1;
    void *temp_r2;

    temp_r1                         = arg1 + 0xB0;
    M2C_FIELD(arg0, void **, 0x1D0) = arg1;
    if ((arg0 + 0x1D8) != temp_r1) {
        M2C_FIELD(arg0, s32 *, 0x1D8) = (s32) M2C_FIELD(temp_r1, s32 *, 0);
        M2C_FIELD(arg0, s32 *, 0x1DC) = (s32) M2C_FIELD(temp_r1, s32 *, 4);
        M2C_FIELD(arg0, s32 *, 0x1E0) = (s32) M2C_FIELD(temp_r1, s32 *, 8);
    }
    temp_r1 = M2C_FIELD(arg0, void **, 0x1D4);
    if (temp_r1 != NULL) {
        func_020aa7c0(arg0, temp_r1);
    }
    temp_r0                         = func_020aa8f0(arg0, arg1 + 0xB0, 6, 0, 0xFF, 0);
    temp_r2                         = temp_r0 + 0x10;
    M2C_FIELD(arg0, void **, 0x1D4) = temp_r0;
    if (temp_r2 == (arg0 + 0x2BC)) {
        return;
    }
    M2C_FIELD(temp_r2, s32 *, 0) = (s32) M2C_FIELD(arg0, s32 *, 0x2BC);
    M2C_FIELD(temp_r2, s32 *, 4) = (s32) M2C_FIELD(arg0, s32 *, 0x2C0);
    M2C_FIELD(temp_r2, s32 *, 8) = (s32) M2C_FIELD(arg0, s32 *, 0x2C4);
}
