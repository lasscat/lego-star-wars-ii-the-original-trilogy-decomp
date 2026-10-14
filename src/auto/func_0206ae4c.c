#include "m2c.h"

M2C_UNK func_02053f44(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_02060158(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_0206af28(void *);                      /* extern */
extern M2C_UNK data_02101b78;
extern M2C_UNK data_02102900;

void func_0206ae4c(void *arg0) {
    if ((M2C_FIELD(arg0, u8 *, 7) == 0) && (M2C_FIELD(arg0, u8 *, 6) == 0) && (M2C_FIELD(arg0, u8 *, 8) == 0)) {
        return;
    }
    M2C_FIELD(arg0, u8 *, 6) = 0U;
    M2C_FIELD(arg0, u8 *, 7) = 0U;
    M2C_FIELD(arg0, u8 *, 8) = 0U;
    func_02060158(&data_02102900, 0, 0x13, 0);
    M2C_FIELD(arg0, s16 *, 0xA)  = 0;
    M2C_FIELD(arg0, s16 *, 0xC)  = 0;
    M2C_FIELD(arg0, s16 *, 0xE)  = 0xFF;
    M2C_FIELD(arg0, s16 *, 0x10) = 0xBF;
    func_0206af28(arg0);
    func_02053f44(&data_02101b78, 0x200);
}
