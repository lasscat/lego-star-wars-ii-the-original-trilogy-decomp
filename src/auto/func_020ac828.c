/* Reconstructed from USA ARM9 at 0x020ac828 (452 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

void func_020ac828(void *arg0, u32 arg1, s8 arg2) {
    switch (arg1) {
        case 0:
            if (arg2 == 1) {
                M2C_FIELD((void *) 0x04000060, volatile u16 *, 0) =
                    (u16) (M2C_FIELD((void *) 0x04000060, volatile u16 *, 0) & 0xFFFFCFFD);
                return;
            }
            M2C_FIELD((void *) 0x04000060, volatile u16 *, 0) =
                (u16) ((M2C_FIELD((void *) 0x04000060, volatile u16 *, 0) & 0xFFFFCFFD) | 2);
            return;
        case 1:
            if (((u32) (M2C_FIELD(arg0, u16 *, 0x50) << 0x1D) >> 0x1F) == arg2) {
                return;
            }
            if (arg2 != 0) {
                M2C_FIELD((void *) 0x04000060, u16 *, 0) = (u16) ((M2C_FIELD((void *) 0x04000060, u16 *, 0) & ~0x3000) | 0x10);
            } else {
                M2C_FIELD((void *) 0x04000060, u16 *, 0) = (u16) (M2C_FIELD((void *) 0x04000060, u16 *, 0) & 0xCFEF);
            }
            M2C_FIELD(arg0, u16 *, 0x50) = (u16) ((M2C_FIELD(arg0, u16 *, 0x50) & ~4) | ((u32) (arg2 << 0x1F) >> 0x1D));
            return;
        case 2:
            if (((u32) (M2C_FIELD(arg0, u16 *, 0x50) << 0x1C) >> 0x1F) == arg2) {
                return;
            }
            if (arg2 != 0) {
                M2C_FIELD((void *) 0x04000060, u16 *, 0) = (u16) ((M2C_FIELD((void *) 0x04000060, u16 *, 0) & ~0x3000) | 8);
            } else {
                M2C_FIELD((void *) 0x04000060, u16 *, 0) = (u16) (M2C_FIELD((void *) 0x04000060, u16 *, 0) & 0xCFF7);
            }
            M2C_FIELD(arg0, u16 *, 0x50) = (u16) ((M2C_FIELD(arg0, u16 *, 0x50) & ~8) | ((u32) (arg2 << 0x1F) >> 0x1C));
            return;
        case 3:
            if (((u32) (M2C_FIELD(arg0, u16 *, 0x50) << 0x1B) >> 0x1F) == arg2) {
                return;
            }
            if (arg2 != 0) {
                M2C_FIELD((void *) 0x04000060, u16 *, 0) = (u16) ((M2C_FIELD((void *) 0x04000060, u16 *, 0) & ~0x3000) | 4);
                M2C_FIELD((void *) 0x04000060, s16 *, 0x2E0) = 1;
            } else {
                M2C_FIELD((void *) 0x04000060, u16 *, 0) = (u16) (M2C_FIELD((void *) 0x04000060, u16 *, 0) & 0xCFFB);
            }
            M2C_FIELD(arg0, u16 *, 0x50) = (u16) ((M2C_FIELD(arg0, u16 *, 0x50) & ~0x10) | ((u32) (arg2 << 0x1F) >> 0x1B));
            return;
        case 4:
            M2C_FIELD(arg0, s8 *, 0xE) = arg2;
            return;
        case 5:
            M2C_FIELD(arg0, s8 *, 0x1E) = arg2;
            return;
        case 6:
            M2C_FIELD(arg0, s8 *, 0x2E) = arg2;
            return;
        case 7:
            M2C_FIELD(arg0, s8 *, 0x3E) = arg2;
            return;
    }
}
