#include "m2c.h"

M2C_UNK func_0205e84c(void *);                      /* extern */
M2C_UNK func_0209f590(void *, u32);                 /* extern */
M2C_UNK func_020acb90(void *);                      /* extern */
M2C_UNK func_020e47fc(void *, M2C_UNK, M2C_UNK, M2C_UNK *); /* extern */
extern M2C_UNK data_020ffbb8;
extern M2C_UNK func_0209f19c;

void *func_0209f4e4(void *arg0) {
    u32 temp_r1;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020ffbb8;
    temp_r1                        = (u32) (M2C_FIELD(arg0, u16 *, 0xB2) << 0x1F) >> 0x1F;
    if (temp_r1 != 0) {
        func_0209f590(arg0, temp_r1);
    }
    func_020e47fc(arg0 + 0x74, 5, 8, &func_0209f19c);
    func_020acb90(arg0);
    func_0205e84c(arg0);
    return arg0;
}
