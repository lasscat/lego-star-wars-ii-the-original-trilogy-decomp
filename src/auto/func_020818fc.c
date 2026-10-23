#include "m2c.h"

void func_0205e860(s32);                             /* extern */
void *func_020aaeb4();                              /* extern */
M2C_UNK G3X_SetClearColor(M2C_UNK, M2C_UNK, s32, M2C_UNK, s32); /* extern */
M2C_UNK func_0200171c(M2C_UNK);                     /* extern */

void func_020818fc(s32 *arg0) {
    s32 i;
    s32 v;
    void *p;

    for (i = 0; i < 5; i++) {
        v = arg0[0x4D + i];
        if (v != 0) {
            func_0205e860(v);
        }
        arg0[0x4D + i] = 0;
    }
    v = arg0[0x57];
    if (v != 0) {
        func_0205e860(v);
    }
    arg0[0x57]                 = 0;
    p                          = func_020aaeb4();
    M2C_FIELD(p, s8 *, 0x1B0)  = 0;
    M2C_FIELD(p, s32 *, 0x1AC) = (s32) (M2C_FIELD(p, s32 *, 0x1AC) | 4);
    G3X_SetClearColor(0, 0x1F, 0x7FFF, 0x3F, 0);
    func_0200171c(0);
}
