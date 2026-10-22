#include "m2c.h"

M2C_UNK *func_02066708(M2C_UNK);                  /* extern */
u8 func_020658c8(void *, u8 *);                  /* extern */
s32 func_02065840(void *, u8 *);                 /* extern */
void func_02064b10(void *, void *, void *);      /* extern */

void func_02064b3c(void *arg0, s16 *arg1, void *arg2, M2C_UNK arg3, s32 arg4) {
    s16 buf[2];
    s16 h;
    u8 *p;

    p      = (u8 *) func_02066708(arg3);
    h      = func_020658c8(arg2, p);
    buf[0] = func_02065840(arg2, p);
    buf[1] = h;
    if (arg4 == 1) {
        arg1[0] = (s16) (arg1[0] - (buf[0] + 1) / 2);
    } else if (arg4 == 2) {
        arg1[0] = (s16) (arg1[0] - buf[0]);
    }
    func_02064b10(arg0, arg1, buf);
}
