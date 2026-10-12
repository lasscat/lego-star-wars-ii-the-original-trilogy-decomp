#include "m2c.h"

M2C_UNK func_0205365c(s32, M2C_UNK);                /* extern */
M2C_UNK func_020536a8(s32, M2C_UNK);                /* extern */
M2C_UNK func_0205e8bc(void *);                      /* extern */
extern M2C_UNK data_020fe790;

void *func_020683ec(void *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fe790;
    func_020536a8(M2C_FIELD(arg0, s32 *, 0x18), 0);
    func_0205365c(M2C_FIELD(arg0, s32 *, 0x18), 0);
    func_0205e8bc(arg0 + 0xC);
    return arg0;
}
