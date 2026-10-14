#include "engine.h"
#include "m2c.h"

M2C_UNK func_020ce804(void);
void func_020ce818(M2C_UNK);

extern void *data_0211e40c;

void func_020d88bc(s32 arg0) {
    s32 temp_r0;

    temp_r0                                 = func_020ce804();
    M2C_FIELD(data_0211e40c, s32 *, 0x14E4) = arg0;
    func_020ce818(temp_r0);
}
