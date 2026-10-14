#include "m2c.h"

M2C_UNK func_0205d378(void *, M2C_UNK);             /* extern */
M2C_UNK func_0205d568(void *);                      /* extern */
extern M2C_UNK data_020fe65c;

void *func_0205d7d8(void *arg0, s32 arg1) {
    func_0205d378(arg0, 0);
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fe65c;
    M2C_FIELD(arg0, s32 *, 0x14)   = arg1;
    func_0205d568(arg0);
    return arg0;
}
