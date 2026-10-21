#include "m2c.h"

u16 func_0205d140(s32 arg0, s32 arg1) {
    if (arg1 == 4) {
        arg1 = *(u8 *) (arg0 + 0x2A);
    }
    return *(u16 *) (arg0 + arg1 * 10);
}
