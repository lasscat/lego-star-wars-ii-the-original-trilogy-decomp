#include "m2c.h"

M2C_UNK func_02060158(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_02053f60(M2C_UNK *, M2C_UNK);          /* extern */
s32 func_020867ec(M2C_UNK *, M2C_UNK);              /* extern */
extern M2C_UNK data_02101b78;
extern M2C_UNK data_02102900;
extern M2C_UNK data_02104d90;

void func_0206adbc(void *arg0) {
    if ((func_020867ec(&data_02104d90, 4) != 0) && (M2C_FIELD(arg0, u8 *, 7) != 0)) {
        if (M2C_FIELD(arg0, u8 *, 8) == 0) {
            return;
        }
    }
    M2C_FIELD(arg0, s8 *, 6) = 1;
    M2C_FIELD(arg0, u8 *, 8) = 1U;
    func_02060158(&data_02102900, 0, 0x12, 0);
    M2C_FIELD(arg0, s16 *, 0xA)  = 0;
    M2C_FIELD(arg0, s16 *, 0xC)  = 0;
    M2C_FIELD(arg0, s16 *, 0xE)  = 0xFF;
    M2C_FIELD(arg0, s16 *, 0x10) = 0xBF;
    M2C_FIELD(arg0, u8 *, 7)     = 1U;
    func_02053f60(&data_02101b78, 0x200);
}
