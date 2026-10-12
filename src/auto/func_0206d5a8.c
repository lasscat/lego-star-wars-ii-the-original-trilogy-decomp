#include "m2c.h"

M2C_UNK func_0205ab6c(s32);                         /* extern */
M2C_UNK func_02062748(void *);                      /* extern */
M2C_UNK func_0206d5ec(void *);                      /* extern */
extern M2C_UNK data_020fe8bc;

void *func_0206d5a8(void *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fe8bc;
    if (M2C_FIELD(arg0, s32 *, 0x18) != 0) {
        func_0205ab6c(0x1247);
    }
    func_0206d5ec(arg0);
    func_02062748(arg0);
    return arg0;
}
