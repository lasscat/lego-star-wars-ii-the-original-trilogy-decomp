#include "m2c.h"

extern u16 data_02115758;

void func_020ce5cc(s32 arg0) {
    data_02115758 |= 1 << arg0;
}
