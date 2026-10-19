#include "m2c.h"
M2C_UNK OS_Terminate();
s32 FS_FindArchive(void *, s32);
M2C_UNK func_020d2898(M2C_UNK *);
s32 FS_OpenFileDirect(M2C_UNK *, s32, s32, s32, s32);
M2C_UNK func_020d2bc0(M2C_UNK *);
s32 func_020d2cbc(M2C_UNK *, s32, s32);
void MBi_ReloadCache(void *arg0) {
    u8 sp4[72];
    void *temp_r4;
    void *temp_r5;
    s32 temp_r5_2;
    temp_r5 = M2C_FIELD(arg0, void **, 0x14);
    temp_r4 = M2C_FIELD(arg0, void **, 0x10);
    func_020d2898(sp4);
    temp_r5_2 = M2C_FIELD(temp_r4, s32 *, 0);
    if (FS_OpenFileDirect(sp4, FS_FindArchive(temp_r5 + 0x10, M2C_FIELD(temp_r5, s32 *, 0x14)), temp_r5_2,
                          temp_r5_2 + M2C_FIELD(temp_r4, s32 *, 4), -1) != 0) {
        if (M2C_FIELD(temp_r4, s32 *, 4) == func_020d2cbc(sp4, M2C_FIELD(temp_r4, s32 *, 8), M2C_FIELD(temp_r4, s32 *, 4))) {
            M2C_FIELD(temp_r4, s32 *, 0xC) = 2;
        }
        func_020d2bc0(sp4);
    }
    if (M2C_FIELD(temp_r4, s32 *, 0xC) == 2) {
        return;
    }
    OS_Terminate();
}
