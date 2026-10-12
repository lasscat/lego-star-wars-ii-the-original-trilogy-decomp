#include "m2c.h"

M2C_UNK func_020c99fc(u16);                         /* extern */
extern u16 data_02115368;

u16 func_020ca66c(u16 *arg0) {
    u16 temp_r4;

    temp_r4 = *arg0;
    *arg0 = 0;
    data_02115368 |= temp_r4;
    func_020c99fc(temp_r4);
    return temp_r4;
}
