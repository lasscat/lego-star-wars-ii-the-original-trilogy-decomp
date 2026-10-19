#include "m2c.h"

s32 func_020c2bc4(M2C_UNK *);                       /* extern */
M2C_UNK func_020c2ed8(M2C_UNK *);                   /* extern */
void *func_020c2f24(M2C_UNK *);                     /* extern */
extern M2C_UNK data_02112614;

s32 func_020c2ff4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    void *temp_r0;
    M2C_UNK *local;

    local = &data_02112614;
    if (func_020c2bc4(local) != 0) {
        return 0;
    }
    temp_r0                        = func_020c2f24(local);
    M2C_FIELD(temp_r0, s32 *, 0)   = arg0;
    M2C_FIELD(temp_r0, s32 *, 4)   = arg2;
    M2C_FIELD(temp_r0, s32 *, 8)   = arg1;
    M2C_FIELD(temp_r0, s32 *, 0xC) = arg3;
    func_020c2ed8(local);
    M2C_FIELD(local, s32 *, 0x10) = (s32) (M2C_FIELD(local, s32 *, 0x10) + M2C_FIELD(temp_r0, s32 *, 0xC));
    return 1;
}
