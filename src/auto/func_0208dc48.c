#include "m2c.h"

extern M2C_UNK data_020f2146;
extern M2C_UNK data_020f2416;
extern M2C_UNK data_020f2b1e;
extern M2C_UNK data_020f3492;
extern M2C_UNK data_020f3e6a;

s16 func_0208dc48(u32 arg0) {
    if (arg0 <= 0x2CU) {
        return *((u16 *) ((s8 *) &data_020f2416 + (arg0 * 0x28)));
    }
    if ((arg0 >= 0x2DU) && (arg0 <= 0x6AU)) {
        return *((u16 *) ((s8 *) &data_020f3e6a + ((arg0 - 0x2D) * 0x2C)));
    }
    if ((arg0 >= 0x6BU) && (arg0 <= 0xB0U)) {
        return *((u16 *) ((s8 *) &data_020f3492 + ((arg0 - 0x6B) * 0x24)));
    }
    if ((arg0 >= 0xB1U) && (arg0 <= 0xE7U)) {
        return *((u16 *) ((s8 *) &data_020f2b1e + ((arg0 - 0xB1) * 0x2C)));
    }
    if ((arg0 >= 0xE8U) && (arg0 <= 0xF9U)) {
        return *((u16 *) ((s8 *) &data_020f2146 + ((arg0 - 0xE8) * 0x28)));
    }
    return -1;
}
