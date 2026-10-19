#include "m2c.h"

M2C_UNK __fill_mem();                            /* extern */

s32 memset(s32 arg0) {
    __fill_mem();
    return arg0;
}
