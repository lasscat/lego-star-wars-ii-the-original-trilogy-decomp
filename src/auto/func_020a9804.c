#include "m2c.h"

s32 func_020a9804(s32 arg0, s32 arg1) {
    s32 temp_r7;                          /* best distance (uninitialised, guarded by temp_r9) */
    s32 temp_r8  = 0;                      /* index of the best element */
    s32 temp_r9  = 0;                      /* "a best element was found" flag */
    u32 temp_r10 = 0;                     /* element index */

    while (temp_r10 < (u32) func_02067b54(M2C_FIELD(arg0, s32 *, 0x21C))) {
        s32 temp_r0 = func_020a97e0(arg0, func_02067b48(M2C_FIELD(arg0, s32 *, 0x21C), temp_r10), arg1);
        if (temp_r9 == 0 || temp_r0 < temp_r7) {
            temp_r7 = temp_r0;
            temp_r9 = 1;
            temp_r8 = temp_r10;
        }
        temp_r10 = (temp_r10 + 1) & 0xFF;
    }
    return temp_r8;
}
