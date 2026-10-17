#include "m2c.h"

s32 func_02060198(M2C_UNK *);                       /* extern */
M2C_UNK func_02072f94();                            /* extern */
s32 func_02087844(void *);                          /* extern */
M2C_UNK func_02087bf4(void *);                      /* extern */
extern M2C_UNK data_02102900;

void func_0208774c(void *arg0) {
    void **temp_r0;

    if (func_02060198(&data_02102900) != 0) {
        return;
    }
    if (func_02087844(arg0) == 0) {
        temp_r0 = M2C_FIELD(arg0, void ***, 0xC4);
        if (temp_r0 != NULL) {
            M2C_FIELD(*temp_r0, M2C_UNK(**)(), 8)(temp_r0);
        }
    }
    func_02087bf4(arg0);
    func_02072f94();
}
