#include "m2c.h"

M2C_UNK func_0205ded4(void *, M2C_UNK);             /* extern */
M2C_UNK func_0205dfe8(void *);                      /* extern */
extern M2C_UNK data_020fe6c0;

void *func_0205e1a0(void *arg0, s8 arg1) {
    func_0205ded4(arg0, 0xA);
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fe6c0;
    M2C_FIELD(arg0, s8 *, 0x21) = arg1;
    M2C_FIELD(arg0, s8 *, 0x20) = 2;
    func_0205dfe8(arg0);
    return arg0;
}
