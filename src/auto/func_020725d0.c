#include "m2c.h"

M2C_UNK func_0205e5b0(s32);                         /* extern */
extern M2C_UNK data_020feb50;

void *func_020725d0(void *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020feb50;
    func_0205e5b0(M2C_FIELD(arg0, s32 *, 0x28));
    return arg0;
}
