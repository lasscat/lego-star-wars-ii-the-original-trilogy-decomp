#include "m2c.h"

M2C_UNK func_02062814(M2C_UNK *, void *, M2C_UNK, M2C_UNK);  /* extern */
extern M2C_UNK data_020fe71c;
extern M2C_UNK data_021042d4;

void *func_020626d8(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fe71c;
    M2C_FIELD(arg0, s8 *, 4)       = 1;
    M2C_FIELD(arg0, s8 *, 5)       = arg1;
    func_02062814(&data_021042d4, arg0, 0, arg1);
    return arg0;
}
