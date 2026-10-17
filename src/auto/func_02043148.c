#include "m2c.h"

extern M2C_UNK data_020f6bab;

s32 func_02043148(void *arg0) {
    if ((arg0 != NULL) && (*((u8 *) ((s8 *) &data_020f6bab + (M2C_FIELD(arg0, u8 *, 0x6C3) * 0x24))) == 0)) {
        return 1;
    }
    return 0;
}
