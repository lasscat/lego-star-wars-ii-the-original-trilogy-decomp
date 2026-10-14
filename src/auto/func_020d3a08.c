#include "engine.h"
#include "m2c.h"

M2C_UNK func_020ce804(void);
void func_020ce818(M2C_UNK);

extern M2C_UNK data_0211748c;

s32 func_020d3a08(void) {
    s32 temp_r0;

    temp_r0 = func_020ce804();
    if (M2C_FIELD(&data_0211748c, s32 *, 0x18) != 0) {
        func_020ce818(temp_r0);
        return 0;
    }
    M2C_FIELD(&data_0211748c, s32 *, 0x18) = 1;
    func_020ce818(temp_r0);
    return 1;
}
