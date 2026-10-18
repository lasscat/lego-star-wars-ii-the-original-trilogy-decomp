/* Reconstructed from USA ARM9 at 0x02034f88 (168 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_0205e624(s32, M2C_UNK, M2C_UNK);       /* extern */
s8 func_020935f8(M2C_UNK *, s8, void *);            /* extern */
extern M2C_UNK data_0210930c;

void func_02034f88(void *arg0, s8 arg1, s8 arg2, s8 arg3) {
    s32 sp4;
    s32 sp0;
    void **temp_r1;
    void **temp_r1_2;

    func_0205e624(arg0 + 0x54, 0, 3);
    M2C_FIELD(arg0, s8 *, 0x30) = 3;
    temp_r1                     = M2C_FIELD(arg0, void ***, 4);
    M2C_FIELD(*temp_r1, M2C_UNK(**)(s32 *, void **, M2C_UNK), 0x3C)(&sp4, temp_r1, 6);
    M2C_FIELD(arg0, s32 *, 0x10) = sp4;
    temp_r1_2                    = M2C_FIELD(arg0, void ***, 4);
    M2C_FIELD(*temp_r1_2, M2C_UNK(**)(s32 *, void **, M2C_UNK), 0x3C)(&sp0, temp_r1_2, 6);
    M2C_FIELD(arg0, s32 *, 0x14) = sp0;
    M2C_FIELD(arg0, s8 *, 0x1C)  = arg3;
    M2C_FIELD(arg0, s8 *, 0x1D)  = 0;
    M2C_FIELD(arg0, s8 *, 0x54)  = arg1;
    M2C_FIELD(arg0, s8 *, 0x55)  = func_020935f8(&data_0210930c, arg1, (void *) ((s8 *) M2C_FIELD(arg0, void ***, 4) + 0xB0));
    M2C_FIELD(arg0, s8 *, 0x56)  = arg2;
}
