#include "m2c.h"

M2C_UNK func_0206c5c0();                            /* extern */
M2C_UNK func_0206cdf4();                            /* extern */

void func_0206cdbc(void *arg0) {
    s32 temp_r1;

    temp_r1 = M2C_FIELD(arg0, s32 *, 0x60);
    switch (temp_r1) {                              /* irregular */
        case 2:
            func_0206cdf4(arg0);
            M2C_FIELD(arg0, s32 *, 0x60) = 3;
            return;
        case 5:
            func_0206c5c0(arg0);
            return;
    }
}
