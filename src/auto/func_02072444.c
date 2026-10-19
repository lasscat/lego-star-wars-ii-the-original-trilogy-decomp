#include "m2c.h"

s32 func_020ad310();                                /* extern */
M2C_UNK func_020afd7c(void *, u16);                 /* extern */
M2C_UNK func_020b01a8();                            /* extern */
u32 func_020b01bc();                                /* extern */
M2C_UNK func_020cea74();                            /* extern */
extern M2C_UNK *data_0210b348;

void func_02072444(void *arg0) {
    switch (func_020b01bc()) {
        case 1:
            func_020afd7c(arg0 + 0xBC, (u16) M2C_FIELD(arg0, s32 *, 0xA8));
            return;
        case 7:
            func_020b01a8();
            return;
        case 0:
            switch (func_020ad310()) {
                case 1:
                    M2C_FIELD(M2C_FIELD(data_0210b348, void **, 0), M2C_UNK(**)(), 0x50)(data_0210b348);
                    return;
                case 0:
                    return;
                case 3:
                    return;
                default:
                    func_020cea74();
                    return;
            }
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            return;
    }
}
