#include "m2c.h"

typedef struct {
    s16 a;
    s16 b;
} Entry;

extern Entry data_020edef2[];

void func_02053c2c(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */

void func_0207094c(void *arg0, s32 arg1) {
    s32 i;
    Entry *table;

    for (i = arg1; i < 4; i++) {
        table = data_020edef2;
        func_02053c2c((s8 *) arg0 + 0x28, (table[i].a - 5) / 8, (table[i].b - 5) / 8, 0x18, 3, 0);
    }
}
