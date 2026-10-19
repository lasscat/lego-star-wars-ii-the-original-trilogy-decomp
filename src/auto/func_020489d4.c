#include "m2c.h"

M2C_UNK func_0202fa64(void *);                      /* extern */
M2C_UNK func_02048ac8(void *);                      /* extern */
M2C_UNK func_0204a0c4(s32);                         /* extern */
M2C_UNK func_0205e84c(s32);                         /* extern */
extern s32 data_02104d90;

void func_020489d4(void *arg0) {
    s32 temp_r5;

    temp_r5 = M2C_FIELD(arg0, s32 *, 0x34);
    if ((temp_r5 != 0) && (M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 8) & 0x802)) {
        if (temp_r5 != 0) {
            func_0204a0c4(temp_r5);
            func_0205e84c(temp_r5);
        }
        M2C_FIELD(arg0, s32 *, 0x34) = 0;
    }
    func_0202fa64(arg0);
    if (!(data_02104d90 & 1)) {
        func_02048ac8(arg0);
        return;
    }
    M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0x64) = 0;
}
