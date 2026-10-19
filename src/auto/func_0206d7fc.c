#include "m2c.h"

M2C_UNK func_0205375c(void *, s32 *);               /* extern */

void func_0206d7fc(void *arg0, s8 arg1) {
    s32 a[2];
    s32 b[2];
    s32 c[2];
    s32 d[2];

    M2C_FIELD(arg0, s8 *, 0x20) = arg1;
    if (arg1 & 0xFF) {
        a[0] = 0x666;
        a[1] = 0;
        func_0205375c(arg0 + 8, a);
        b[0] = 0x800;
        b[1] = 0;
        func_0205375c(arg0 + 0x10, b);
        return;
    }
    c[0] = 0;
    c[1] = 0;
    func_0205375c(arg0 + 8, c);
    d[0] = 0;
    d[1] = 0;
    func_0205375c(arg0 + 0x10, d);
}
