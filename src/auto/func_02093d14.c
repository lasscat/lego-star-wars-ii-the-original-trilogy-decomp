#include "m2c.h"

s32 func_020871cc(M2C_UNK *);                       /* extern */
extern M2C_UNK data_02104d90;

s32 func_02093d14(s32 arg0) {
    if (func_020871cc(&data_02104d90) == -1) {
        return 0;
    }
    return M2C_FIELD((arg0 + (func_020871cc(&data_02104d90) * 4)), s32 *, 0x4C);
}
