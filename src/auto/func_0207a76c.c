#include "m2c.h"

typedef void (*Fn)(void *);

void func_0207a76c(M2C_UNK *arg0) {
    u32 i;
    M2C_UNK *o;

    i = 0;
    do {
        o = arg0[55 + i];
        if (o != NULL) {
            if (o != NULL) {
                M2C_FIELD(*(void ***) o, Fn *, 4)(o);
            }
            arg0[55 + i] = 0;
        }
        i++;
    } while (i < 0x14);
    o = arg0[0x4b];
    if (o == NULL) {
        return;
    }
    if (o != NULL) {
        M2C_FIELD(*(void ***) o, Fn *, 4)(o);
    }
    arg0[0x4b] = 0;
}
