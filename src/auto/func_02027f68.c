#include "m2c.h"

s32 func_02027f68(void *arg0) {
    u32 x;

    if (arg0 == NULL) {
        return 0;
    }
    x = M2C_FIELD(arg0, u16 *, 0x182);
    switch (x) {
        case 0x1F:
        case 0x20:
        case 0x36:
        case 0x37:
        case 0x38:
        case 0x39:
        case 0x3A:
        case 0x3B:
        case 0x3C:
        case 0x3D:
        case 0x3E:
        case 0x3F:
        case 0x40:
        case 0x41:
            return 1;
        default:
            return 0;
    }
}
