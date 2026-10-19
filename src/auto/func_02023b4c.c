#include "m2c.h"

s32 func_0204a880(void *);                          /* extern */

void func_02023b4c(void *arg0, void **arg1) {
    void *temp_r1;

    temp_r1 = *arg1;
    switch (M2C_FIELD(temp_r1, u16 *, 0xC)) {
        case 1:
            if ((func_0204a880(temp_r1 + 0x5CE) != 0) && (M2C_FIELD(arg0, u8 *, 0x1BC) != 1)) {
                M2C_FIELD(arg0, s32 *, 0x21C) = (s32) (M2C_FIELD(arg0, s32 *, 0x21C) + 1);
            }
            break;
        case 4:
            break;
    }
}
