#include "m2c.h"

M2C_UNK func_020ad7a4(M2C_UNK);                     /* extern */
M2C_UNK func_020ad8b4();                            /* extern */
s32 WM_SetParentParameter(M2C_UNK *, M2C_UNK *);            /* extern */
extern M2C_UNK data_0210b320;
extern M2C_UNK data_0210b3a0;
extern M2C_UNK func_020ae128;

s32 func_020ae0d8(void) {
    M2C_FIELD(&data_0210b320, s32 *, 0x48) = 0x20;
    func_020ad7a4(3);
    if (WM_SetParentParameter(&func_020ae128, &data_0210b3a0) == 2) {
        return 1;
    }
    func_020ad8b4();
    func_020ad7a4(9);
    return 0;
}
