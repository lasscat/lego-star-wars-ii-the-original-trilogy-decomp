#include "m2c.h"

M2C_UNK func_020e4600(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK *); /* extern */
extern M2C_UNK func_02067118;
void func_02067154(void *, s32, void *, s32);                          /* extern */

void func_02066ed0(void *arg0, void *arg1) {
    void *ptr;
    void *p;
    u32 i;
    s32 slot;
    if (M2C_FIELD(arg0, u16 *, 0xC18) == 0) {
        return;
    }
    p = M2C_FIELD(arg0, void **, 0xC);
    if (p != 0) {
        p = (void *) func_020e4600(p, 2, 0x28, 0, &func_02067118, 0);
    }
    M2C_FIELD(arg0, void **, 4)   = p;
    M2C_FIELD(arg0, void **, 0xC) = M2C_FIELD(arg0, void **, 0xC) + 0x58;
    ptr                           = arg1;
    slot                          = 0;
    i                             = 0;
    while (i < (u32) M2C_FIELD(arg0, u16 *, 0xC18)) {
        if (i == 0 || i == (u32) M2C_FIELD(arg0, u16 *, 0xC14)) {
            void *dst = (void *) ((u32) M2C_FIELD(arg0, void **, 4) + (u32) slot * 0x28);
            slot++;
            func_02067154(dst, arg0, ptr, (s32) i);
        }
        ptr = (void *) ((u8 *) ptr + *(u16 *) ptr);
        i++;
    }
}
