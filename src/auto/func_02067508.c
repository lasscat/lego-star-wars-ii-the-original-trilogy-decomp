#include "m2c.h"

M2C_UNK func_020e4600(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK *); /* extern */
extern M2C_UNK func_02067b5c;
void func_02067b70(void *, s32, void *, void *);                      /* extern */

void func_02067508(void *arg0, void *arg1, void *arg2) {
    void *p;
    u8 *data;
    u32 i;

    if (M2C_FIELD(arg0, u16 *, 0x20) == 0) {
        return;
    }
    p = M2C_FIELD(arg1, void **, 0xC);
    if (p != 0) {
        p = (void *) func_020e4600(p, M2C_FIELD(arg0, u16 *, 0x20), 0xC, 0, &func_02067b5c, 0);
    }
    M2C_FIELD(arg0, void **, 0x14) = p;
    M2C_FIELD(arg1, void **, 0xC)  = M2C_FIELD(arg0, u16 *, 0x20) * 0xC + 8 + M2C_FIELD(arg1, void **, 0xC);
    data                           = (u8 *) arg2 + 0x10 + M2C_FIELD(arg2, u16 *, 0xC);
    i                              = 0;
    while (i < (u32) M2C_FIELD(arg0, u16 *, 0x20)) {
        func_02067b70(M2C_FIELD(arg0, void **, 0x14) + i * 0xC, M2C_FIELD(data, u8 *, 3), data,
                      (void *) (data + M2C_FIELD(data, u8 *, 2)));
        data = (u8 *) data + M2C_FIELD(data, u16 *, 0);
        i++;
    }
}
