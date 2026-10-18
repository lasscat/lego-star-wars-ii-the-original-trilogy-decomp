/* Reconstructed from USA ARM9 at 0x020338d4 (188 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_02029520(void *);                      /* extern */
extern M2C_UNK data_020fdbc4;
extern M2C_UNK data_020fdea4;
extern M2C_UNK data_0210930c;

void *func_020338d4(void *arg0, void **arg1) {
    s32 sp0;
    void **temp_r1;
    void *temp_r1_2;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fdbc4;
    M2C_FIELD(arg0, void ***, 4)   = arg1;
    M2C_FIELD(arg0, s8 *, 0xC)     = 0;
    M2C_FIELD(arg0, s8 *, 0xD)     = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fdea4;
    func_02029520(arg0 + 0x10);
    M2C_FIELD(arg0, s32 *, 0xA4) = 0;
    M2C_FIELD(arg0, s32 *, 0xA8) = 0;
    M2C_FIELD(arg0, s32 *, 0xAC) = 0;
    M2C_FIELD(arg0, s32 *, 0xB0) = 0;
    M2C_FIELD(arg0, s32 *, 0xB4) = 0;
    M2C_FIELD(arg0, s32 *, 0xB8) = 0;
    M2C_FIELD(arg0, s32 *, 0xBC) = 0;
    temp_r1                      = M2C_FIELD(arg0, void ***, 4);
    M2C_FIELD(*temp_r1, M2C_UNK(**)(s32 *, void **, M2C_UNK), 0x3C)(&sp0, temp_r1, 6);
    M2C_FIELD(arg0, s32 *, 0xBC) = sp0;
    temp_r1_2                    = M2C_FIELD(&data_0210930c, void **, 0x4C) + 0xB0;
    if ((arg0 + 0xA4) != temp_r1_2) {
        M2C_FIELD(arg0, s32 *, 0xA4) = (s32) M2C_FIELD(temp_r1_2, s32 *, 0);
        M2C_FIELD(arg0, s32 *, 0xA8) = (s32) M2C_FIELD(temp_r1_2, s32 *, 4);
        M2C_FIELD(arg0, s32 *, 0xAC) = (s32) M2C_FIELD(temp_r1_2, s32 *, 8);
    }
    return arg0;
}
