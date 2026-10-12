#include "m2c.h"

M2C_UNK func_020aaf08(s32);                         /* extern */
M2C_UNK func_020acbc4(void *, M2C_UNK);             /* extern */
extern M2C_UNK data_020ffc24;

void *func_020acb18(void *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020ffc24;
    func_020aaf08(arg0 + 4);
    M2C_FIELD(arg0, s8 *, 0x1C) = 0;
    M2C_FIELD(arg0, s8 *, 0x1D) = 0;
    func_020acbc4(arg0, arg1);
    return arg0;
}
