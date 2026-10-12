#include "m2c.h"

M2C_UNK func_020d5018(u16);                         /* extern */
M2C_UNK func_020d5034(u16);                         /* extern */
extern s32 data_021173dc;

s32 func_020d2dac(s32 arg0, s32 arg1) {
    switch (arg1) {                                 /* irregular */
    case 9:
        func_020d5018((u16) data_021173dc);
        return 0;
    case 10:
        func_020d5034((u16) data_021173dc);
        return 0;
    case 1:
        return 4;
    default:
        return 8;
    }
}
