#include "m2c.h"

M2C_UNK func_020cf344(s32, M2C_UNK, M2C_UNK);       /* extern */
extern M2C_UNK data_0211e444;

void func_020dd388(s32 arg0) {
    M2C_FIELD(&data_0211e444, s32 *, 4) = arg0;
    func_020cf344(arg0, 0, 0x21C);
}
