#include "m2c.h"

s32 func_020d0dd8();                                /* extern */
s32 func_020d0e14();                                /* extern */

s32 func_020d0e50(void) {
    s32 temp_r4;

    temp_r4 = func_020d0dd8();
    return (0x100 - temp_r4) - func_020d0e14();
}
