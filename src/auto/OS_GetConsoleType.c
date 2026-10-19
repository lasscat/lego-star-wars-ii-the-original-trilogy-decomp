#include "m2c.h"

extern s32 data_02101550;

s32 OS_GetConsoleType(void) {
    return data_02101550 = 0x82000001;
}
