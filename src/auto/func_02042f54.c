#include "m2c.h"

M2C_UNK func_02004acc(void *);                      /* extern */
extern s32 data_020ff9b4[3];

void func_02042f54(void *arg0) {
    s32 *p;

    M2C_FIELD(arg0, u8 *, 0xD) = 0;
    p                          = (s32 *) ((s8 *) M2C_FIELD(arg0, void **, 4) + 0x60);
    if (p != data_020ff9b4) {
        p[0] = data_020ff9b4[0];
        p[1] = data_020ff9b4[1];
        p[2] = data_020ff9b4[2];
    }
    M2C_FIELD(M2C_FIELD(arg0, void **, 4), s8 *, 0x6BA) = 1;
    func_02004acc(M2C_FIELD(arg0, void **, 4));
}
