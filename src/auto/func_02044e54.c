#include "m2c.h"

M2C_UNK func_0202d900();                            /* extern */
extern M2C_UNK data_020fe2ac;

void *func_02044e54(void *arg0) {
    func_0202d900();
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fe2ac;
    M2C_FIELD(arg0, s16 *, 0x10) = 0;
    M2C_FIELD(arg0, s8 *, 0x12) = 0;
    return arg0;
}
