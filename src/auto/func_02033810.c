#include "m2c.h"

extern M2C_UNK data_021027f8;
extern M2C_UNK data_0210930c;

M2C_UNK func_0200aef8(void *, void *, s32, s32);

s32 func_02033810(void *arg0) {
    s32 a[4];
    u8 i;
    u32 obj;

    if (*(u16 *) ((u8 *) *(u32 *) ((u8 *) arg0 + 4) + 0xc) != 2) {
        goto end;
    }
    for (i = 0; i < *(u8 *) ((u8 *) &data_021027f8 + 0x29); i++) {
        obj  = *(u32 *) ((u8 *) &data_0210930c + i * 4 + 0x4c);
        a[1] = *(s32 *) ((u8 *) obj + 0xb0);
        a[2] = *(s32 *) ((u8 *) obj + 0xb4);
        a[0] = 0x1e000;
        a[3] = *(s32 *) ((u8 *) obj + 0xb8);
        if (func_0200aef8((u8 *) *(u32 *) ((u8 *) arg0 + 4) + 0xb0, &a[1], 0x1e000, obj) != 0) {
            return 1;
        }
    }
end:
    return 0;
}
