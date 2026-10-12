#include "m2c.h"

extern s32 *data_0211535c;

void func_020c5dcc(s32 *arg0) {
    if (data_0211535c == NULL) {
        *arg0 = 0;
        data_0211535c = arg0;
    }
}
