#include "m2c.h"

M2C_UNK func_020c2768(s32, s32, M2C_UNK);           /* extern */
s32 func_020c2944();                                /* extern */
extern M2C_UNK data_02102848;

s32 func_0205e5f4(s32 arg0, M2C_UNK arg1) {
    func_020c2768(*((M2C_UNK *) ((s8 *) &data_02102848 + (func_020c2944() << 5))), arg0, arg1);
    return arg0;
}
