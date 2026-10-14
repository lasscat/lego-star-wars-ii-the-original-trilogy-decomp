#include "m2c.h"

M2C_UNK func_020a486c();                            /* extern */
M2C_UNK func_020a5234();                            /* extern */
M2C_UNK func_020a542c();                            /* extern */

void func_020a4830(void *arg0) {
    u8 temp_r1;

    temp_r1 = M2C_FIELD(arg0, u8 *, 0x23E);
    switch (temp_r1) {                              /* irregular */
        case 2:
            func_020a5234(arg0);
            return;
        case 3:
            func_020a486c(arg0);
            return;
        case 1:
            func_020a542c(arg0);
            return;
    }
}
