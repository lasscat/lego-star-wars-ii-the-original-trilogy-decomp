#include "m2c.h"

s32 func_020ca6c4();                                /* extern */
extern M2C_UNK data_02115384;

void func_020cc0f4(void) {
    s32 temp_r0;

    temp_r0                             = func_020ca6c4();
    M2C_FIELD(&data_02115384, s32 *, 8) = temp_r0;
    switch (temp_r0) {                              /* irregular */
        case 0x0:
            return;
        case 0x40:
            M2C_FIELD(&data_02115384, s32 *, 4) = 0x06894000;
            return;
        case 0x20:
            M2C_FIELD(&data_02115384, s32 *, 4) = 0x06890000;
            return;
    }
}
