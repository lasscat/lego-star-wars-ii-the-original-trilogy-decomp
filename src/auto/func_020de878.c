#include "m2c.h"

void *func_020de878(void *arg0, void *arg1, u32 arg2) {
    s8 *d;
    s8 *s;

    if (arg1 >= arg0) {
        d = arg0;
        if (arg2 == 0) {
            return arg0;
        }
        do {
            *d++ = *((s8 *) arg1)++;
        } while (--arg2 != 0);
    } else {
        s = (s8 *) arg1 + arg2;
        d = (s8 *) arg0 + arg2;
        if (arg2 == 0) {
            return arg0;
        }
        do {
            *--d = *--s;
        } while (--arg2 != 0);
    }
    return arg0;
}
