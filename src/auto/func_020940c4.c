#include "m2c.h"

M2C_UNK func_0205e84c(void *);                      /* extern */
M2C_UNK func_02062748(void *);                      /* extern */
M2C_UNK func_020675d8(s32, u8);                     /* extern */
M2C_UNK func_0206763c(s32, u8);                     /* extern */
extern M2C_UNK data_0210930c;

s32 func_020940c4(void *arg0) {
    func_0206763c(M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0210930c, void **, 0x68), void **, 0x38C), s32 *, 4) + 0x28, M2C_FIELD(arg0, u8 *, 6));
    func_020675d8(M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0210930c, void **, 0x68), void **, 0x38C), s32 *, 4) + 0x28, M2C_FIELD(arg0, u8 *, 7));
    if (M2C_FIELD(arg0, u8 *, 8) != 0) {
        if (arg0 != NULL) {
            func_02062748(arg0);
            func_0205e84c(arg0);
        }
        return 1;
    }
    return 0;
}
