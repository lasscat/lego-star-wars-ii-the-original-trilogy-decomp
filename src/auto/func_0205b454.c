#include "m2c.h"

M2C_UNK func_0205af6c(void **, M2C_UNK, s16 *);     /* extern */

s32 func_0205b454(M2C_UNK arg0, s16 arg1) {
    void *sp4;
    s16 sp0;

    sp0 = arg1;
    func_0205af6c(&sp4, arg0, &sp0);
    return M2C_FIELD(M2C_FIELD(sp4, void **, 0x10), s32 *, 4);
}
