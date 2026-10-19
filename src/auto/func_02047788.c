#include "m2c.h"

M2C_UNK func_0205e84c(s32);
M2C_UNK func_020b973c();
M2C_UNK func_020bc190(s32);
extern M2C_UNK data_020fe33c;

void *func_02047788(void *arg0) {
    s32 *p = arg0;
    u32 i;
    s32 t;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fe33c;
    if (M2C_FIELD(arg0, s32 *, 0x24) != 0) {
        func_020b973c();
        M2C_FIELD(arg0, s32 *, 0x24) = 0;
    }
    for (i = 0; i < 2; i++) {
        t = p[7 + i];
        if (t == 0) {
            if (t != 0) {
                func_020bc190(t);
                func_0205e84c(t);
            }
            p[7 + i] = 0;
        }
    }
    func_0205e84c(arg0);
    return arg0;
}
