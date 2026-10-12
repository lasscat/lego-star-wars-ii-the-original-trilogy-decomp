#include "m2c.h"

extern void *data_0210daf0;
extern M2C_UNK data_0210dafc;

void func_020b4768(s32 arg0, s8 arg1, s8 arg2, s8 arg3) {
    void *temp_ip;

    temp_ip = *((M2C_UNK *)((s8 *)&data_0210dafc + (arg0 * 4)));
    if (temp_ip == NULL) {
        return;
    }
    data_0210daf0 = temp_ip;
    if (arg3 != 0) {
        if (arg1 != 0xFF) {
            M2C_FIELD(temp_ip, s8 *, 0x36) = arg1;
        }
        M2C_FIELD(data_0210daf0, s8 *, 0x37) = arg2;
        M2C_FIELD(data_0210daf0, s8 *, 0x38) = arg3;
    } else {
        M2C_FIELD(temp_ip, s8 *, 0x36) = arg2;
    }
    data_0210daf0 = NULL;
}
