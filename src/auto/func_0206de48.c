#include "m2c.h"

M2C_UNK func_02053f60(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_0205ecc4(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_02067c68(void *);                      /* extern */
s32 func_0206e098();                                /* extern */
extern M2C_UNK data_02101b78;
extern M2C_UNK data_02102900;

void func_0206de48(s32 *arg0) {
    if (arg0[15] > 0) {
        arg0[15] = arg0[15] - 1;
        return;
    }
    arg0[13] = arg0[13] + 7;
    if (func_0206e098(arg0) == 0) {
        return;
    }
    func_02067c68((s8 *) arg0 + 0x2C);
    func_02053f60(&data_02101b78, 0x400);
    func_0205ecc4(&data_02102900, 0x30, 1, 0, 0, 0);
    M2C_FIELD(&data_02102900, s32 *, 0x84) = 1;
}
