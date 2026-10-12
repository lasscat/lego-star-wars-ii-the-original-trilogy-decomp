#include "m2c.h"

M2C_UNK func_020b4768(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK data_0210db14;

void func_020b9434(s32 arg0, s32 arg1, s32 arg2) {
    switch (arg0) {                                 /* switch 1; irregular */
    case 0:                                         /* switch 1 */
    case 1:                                         /* switch 1 */
        switch (arg1) {                             /* switch 2; irregular */
        case 0:                                     /* switch 2 */
            M2C_FIELD(&data_0210db14, u8 *, 0xA) = (u8) (M2C_FIELD(&data_0210db14, u8 *, 0xA) | 2);
            return;
        case 1:                                     /* switch 2 */
            M2C_FIELD(&data_0210db14, u8 *, 0xA) = (u8) (M2C_FIELD(&data_0210db14, u8 *, 0xA) | 0x10);
            func_020b4768(0, 0xFF, 0x80, 4);
            return;
        case 2:                                     /* switch 2 */
            func_020b4768(0, 0xFF, 0x80, 4);
            return;
        }
        break;
    case 4:                                         /* switch 1 */
        if (arg2 != 1) {
            return;
        }
        M2C_FIELD(&data_0210db14, s32 *, 4) = arg1;
        M2C_FIELD(&data_0210db14, u8 *, 0xA) = (u8) (M2C_FIELD(&data_0210db14, u8 *, 0xA) | 4);
        return;
    }
}
