#include "m2c.h"

s32 func_0208da74(u32 arg0) {
    if (arg0 <= 0x2CU) {
        return 0;
    }
    if ((arg0 >= 0x2DU) && (arg0 <= 0x6AU)) {
        return 1;
    }
    if ((arg0 >= 0x6BU) && (arg0 <= 0xB0U)) {
        return 2;
    }
    if ((arg0 >= 0xB1U) && (arg0 <= 0xE7U)) {
        return 3;
    }
    if ((arg0 >= 0xE8U) && (arg0 <= 0xF9U)) {
        return 4;
    }
    return 5;
}
