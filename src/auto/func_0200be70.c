#include "m2c.h"

M2C_UNK func_02001990(void *, M2C_UNK);             /* extern */
M2C_UNK func_02008288(void *, M2C_UNK, M2C_UNK);    /* extern */
void *func_020082a4(s32, M2C_UNK, M2C_UNK);         /* extern */
M2C_UNK func_0204c594(void *, s32 *);               /* extern */
s32 func_020c9268(s32, M2C_UNK);                    /* extern */
extern M2C_UNK func_0200bfc0;

void func_0200be70(void *arg0) {
    s32 sp0[3];
    s32 temp_r0;
    s32 temp_r5;
    s32 temp_r6;
    void *temp_r0_2;
    void *temp_r1;
    void *temp_r2;

    M2C_FIELD(arg0, void **, 0x1C8) = func_020082a4(arg0 + 0x10, 5, 1);
    temp_r6                         = func_020c9268(M2C_FIELD(arg0, s32 *, 0x1C4), 0x2000);
    temp_r5                         = func_020c9268(M2C_FIELD(arg0, s32 *, 0x1C0), 0x2000);
    temp_r0                         = func_020c9268(M2C_FIELD(arg0, s32 *, 0x1BC), 0x2000);
    sp0[1]                          = temp_r5;
    sp0[2]                          = temp_r6;
    sp0[0]                          = temp_r0;
    func_0204c594(M2C_FIELD(arg0, void **, 0x1C8), sp0);
    temp_r0_2 = M2C_FIELD(arg0, void **, 0x1C8);
    temp_r2   = arg0 + 0xB0;
    temp_r1   = temp_r0_2 + 4;
    if (temp_r1 != temp_r2) {
        M2C_FIELD(temp_r1, s32 *, 0) = (s32) M2C_FIELD(temp_r2, s32 *, 0);
        M2C_FIELD(temp_r1, s32 *, 4) = (s32) M2C_FIELD(temp_r2, s32 *, 4);
        M2C_FIELD(temp_r1, s32 *, 8) = (s32) M2C_FIELD(temp_r2, s32 *, 8);
    }
    func_02008288(arg0 + 0x10, 1, 1);
    func_02001990(arg0, 1);
    M2C_FIELD(arg0, s32 *, 0x84)      = 0x11;
    M2C_FIELD(arg0, M2C_UNK **, 0x18) = &func_0200bfc0;
}
