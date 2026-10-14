#include "m2c.h"

M2C_UNK func_02055854(M2C_UNK *, void *);           /* extern */
M2C_UNK func_0205e860(s32);                         /* extern */
extern u8 data_021042c4;
extern void *data_027e03a0;
extern M2C_UNK data_027e0410;

void func_020624ec(void *arg0) {
    M2C_FIELD(data_027e03a0, M2C_UNK(**)(void **, void *), 0xC)(&data_027e03a0, arg0);
    func_02055854(&data_027e0410, arg0);
    data_021042c4 -= 1;
    if (M2C_FIELD(arg0, u16 *, 0xC) != 0xFFFF) {
        return;
    }
    func_0205e860(M2C_FIELD(arg0, s32 *, 0));
}
