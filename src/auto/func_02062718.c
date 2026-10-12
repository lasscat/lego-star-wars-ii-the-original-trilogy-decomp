#include "m2c.h"

M2C_UNK func_02062868(M2C_UNK *, void *, u8);       /* extern */
extern M2C_UNK data_020fe71c;
extern M2C_UNK data_021042d4;

void *func_02062718(void *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fe71c;
    func_02062868(&data_021042d4, arg0, M2C_FIELD(arg0, u8 *, 5));
    return arg0;
}
