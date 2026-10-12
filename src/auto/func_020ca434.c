#include "m2c.h"

M2C_UNK func_020c99fc();                            /* extern */
extern u16 data_02115368;

void func_020ca434(s32 arg0) {
    data_02115368 |= arg0;
    func_020c99fc(arg0);
}
