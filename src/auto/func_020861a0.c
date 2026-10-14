#include "m2c.h"

extern M2C_UNK data_021043ac;

s32 func_020861a0(s32 arg0, s32 arg1) {
    if (((u8 *) &data_021043ac)[arg1] == 0) {
        return 1;
    }
    return 0;
}
