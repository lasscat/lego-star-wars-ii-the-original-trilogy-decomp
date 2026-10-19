#include "m2c.h"

s32 WM_SetEntry(M2C_UNK);                         /* extern */

s32 func_020adc88(void) {
    if (WM_SetEntry(0) == 2) {
        return 1;
    }
    return 0;
}
