#include "engine.h"
#include "m2c.h"

M2C_UNK func_020ce804(void);
void func_020ce818(M2C_UNK);
void func_020cf3dc(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_020d9c54(M2C_UNK);

extern s32 data_0211e40c;

s32 func_020d88e4(s32 arg0) {
    s32 temp_r4;

    temp_r4 = func_020ce804();
    if ((data_0211e40c != 0) && (func_020d9c54(arg0) != 0)) {
        func_020cf3dc(((arg0 - 1) * 0x16) + (data_0211e40c + 0x1340), data_0211e40c + 0x1772, 0x16);
        func_020ce818(temp_r4);
        return data_0211e40c + 0x1772;
    }
    func_020ce818(temp_r4);
    return 0;
}
