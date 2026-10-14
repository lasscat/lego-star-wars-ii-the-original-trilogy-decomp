#include "engine.h"
#include "m2c.h"

M2C_UNK func_020d9c54(M2C_UNK);

extern s32 data_0211e40c;

s32 func_020d8968(s32 arg0) {
    if ((data_0211e40c != 0) && (func_020d9c54(arg0) != 0) &&
        (M2C_FIELD((data_0211e40c + ((arg0 - 1) * 4)), s32 *, 0x14E8) == 7)) {
        return 1;
    }
    return 0;
}
