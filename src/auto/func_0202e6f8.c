#include "m2c.h"

/* func_02032b44 takes its 4th and 9th parameters as one-word structs passed
   by value (the callee reads the 4th through its address).  The caller builds
   each argument in a stack temporary (sp+0x18, sp+0x14) and then passes the
   copy, which is why those slots are written but never read back here. */

typedef struct {
    s32 value;
} Fixed;

M2C_UNK func_02018278(M2C_UNK *, s32, s32, s32, s32, s32, s32); /* extern */
s32 func_0202cb44(s32);                             /* extern */
M2C_UNK func_02032b44(s32, s32, M2C_UNK *, Fixed, s32, s32, s32, s32, Fixed); /* extern */
s32 func_0205e80c(M2C_UNK, M2C_UNK, M2C_UNK);       /* extern */

void func_0202e6f8(s32 arg0) {
    M2C_UNK sp1C[3];
    Fixed second;
    Fixed first;
    s32 temp_r0;

    func_02018278(sp1C, arg0, func_0202cb44(arg0 + 0x5E0), 0x82, 0xB4, 0x14, 0x32);
    temp_r0 = func_0205e80c(0x40, 1, 4);
    if (temp_r0 != 0) {
        second.value = -0x1000;
        first.value  = 0x2000;
        func_02032b44(temp_r0, arg0, sp1C, first, 1, 0, 1, 0, second);
    }
}
