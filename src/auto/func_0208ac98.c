#include "m2c.h"

typedef void (*Fn)(void *);

M2C_UNK func_020535a8(void *);
M2C_UNK func_020536a8(void *);
M2C_UNK func_02055c48(M2C_UNK);

void func_0208ac98(M2C_UNK *arg0) {
    u32 i;
    M2C_UNK *o;

    i = 0;
    do {
        o = arg0[21 + i];
        if (o != NULL) {
            if (o != NULL) {
                M2C_FIELD(*(void ***) o, Fn *, 4)(o);
            }
            arg0[21 + i] = 0;
        }
        i++;
    } while (i < 4);
    o = arg0[25];
    if (o != NULL) {
        M2C_FIELD(*(void ***) o, Fn *, 4)(o);
    }
    arg0[25] = 0;
    o        = arg0[26];
    if (o != NULL) {
        M2C_FIELD(*(void ***) o, Fn *, 4)(o);
    }
    arg0[26] = 0;
    func_020536a8(arg0 + 2);
    func_020535a8(arg0 + 2);
    func_02055c48(0);
}
