#include "m2c.h"

void func_020d2898(void *);
s32 FS_OpenFile(void *, const void *);
s32 func_020d2bc0(void *);
void func_020d2cbc(void *, void *, u32);

s32 MBi_ReadIconInfo(const void *a0, void *a1, s32 a2) {
    u8 ctx[0x48];
    u32 size;
    u8 *dest;

    size = (a2 != 0) ? 0x200 : 0x20;
    dest = (u8 *) a1;
    if (a2 != 0) {
        dest = dest + 0x20;
    }
    if (a0 == 0) {
        return 0;
    }
    func_020d2898(ctx);
    if (FS_OpenFile(ctx, a0) == 0) {
        return 0;
    }
    if (size != (M2C_FIELD(ctx, u32 *, 0x28) - M2C_FIELD(ctx, u32 *, 0x24))) {
        func_020d2bc0(ctx);
        return 0;
    }
    func_020d2cbc(ctx, dest, size);
    func_020d2bc0(ctx);
    return 1;
}
