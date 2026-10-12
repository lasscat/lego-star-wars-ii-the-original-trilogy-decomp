#include "m2c.h"

M2C_UNK func_020aaf08(s32);                         /* extern */
extern M2C_UNK data_020ffc24;

void *func_020acae8(void *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020ffc24;
    func_020aaf08(arg0 + 4);
    M2C_FIELD(arg0, s8 *, 0x1C) = 0;
    M2C_FIELD(arg0, s8 *, 0x1D) = 0;
    return arg0;
}
