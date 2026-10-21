#include "m2c.h"

extern u8 data_0210930c[];
extern u8 data_020f6bab[];

s32 func_0207f478(s32);                                  /* extern */
M2C_UNK func_0200ea7c(M2C_UNK);                          /* extern */
M2C_UNK func_0208e190(M2C_UNK);                          /* extern */
void func_020929a0(void *, u32);                         /* extern */

s32 func_0204a1d4(void *arg0, void *arg1, s32 arg2) {
    u8 *table;

    table = (u8 *) func_0207f478(M2C_FIELD(arg0, u8 *, 0xB));

    switch (arg2) {
        case 0:
        case 1:
        case 6:
            break;
        case 4:
            if (M2C_FIELD(arg1, s32 *, 0x6AC) == 0) {
                return 0;
            }
            break;
        case 3:
            if (M2C_FIELD(arg1, u8 *, 0x6C3) == 0x28 || (M2C_FIELD(arg1, u8 *, 0x6C4) & 4)) {
                return 0;
            }
            break;
        case 8: {
            s32 flags = M2C_FIELD(arg1, s32 *, 0x6CC);
            if ((M2C_FIELD(arg1, u16 *, 0xC) & 1) && func_0200ea7c(arg1) != 0) {
                return 1;
            }
            if (flags & 0x10) {
                M2C_FIELD(arg0, u8 *, 9) = 8;
            }
            return 1;
        }
        case 9: {
            s32 flags = M2C_FIELD(arg1, s32 *, 0x6CC);
            if ((M2C_FIELD(arg1, u16 *, 0xC) & 1) && func_0200ea7c(arg1) != 0) {
                return 1;
            }
            if (flags & 0x1) {
                M2C_FIELD(arg0, u8 *, 9) = 9;
            }
            return 1;
        }
        case 10: {
            s32 flags = M2C_FIELD(arg1, s32 *, 0x6CC);
            if ((M2C_FIELD(arg1, u16 *, 0xC) & 1) && func_0200ea7c(arg1) != 0) {
                return 1;
            }
            if (flags & 0x2) {
                M2C_FIELD(arg0, u8 *, 9) = 10;
            }
            return 1;
        }
        case 11: {
            s32 flags = M2C_FIELD(arg1, s32 *, 0x6CC);
            if ((M2C_FIELD(arg1, u16 *, 0xC) & 1) && func_0200ea7c(arg1) != 0) {
                return 1;
            }
            if (flags & 0x4) {
                M2C_FIELD(arg0, u8 *, 9) = 11;
            }
            return 1;
        }
        case 12: {
            s32 flags = M2C_FIELD(arg1, s32 *, 0x6CC);
            if ((M2C_FIELD(arg1, u16 *, 0xC) & 1) && func_0200ea7c(arg1) != 0) {
                return 1;
            }
            if (flags & 0x8) {
                M2C_FIELD(arg0, u8 *, 9) = 12;
            }
            return 1;
        }
        case 2:
            if (func_0208e190(arg1) == 1) {
                return 0;
            }
            break;
        case 5:
            func_020929a0(data_0210930c, M2C_FIELD(arg0, u8 *, 0xC));
            return 1;
        case 7:
            if (data_020f6bab[M2C_FIELD(arg1, u8 *, 0x6C3) * 0x24] != 0 || (M2C_FIELD(arg1, u8 *, 0x6C4) & 2)) {
                return 0;
            }
            break;
    }

    if (M2C_FIELD(table + arg2 * 8, u8 *, 3) >= M2C_FIELD(arg0, u8 *, 9)) {
        M2C_FIELD(arg0, u8 *, 9) = arg2;
        return 1;
    }
    return 0;
}
