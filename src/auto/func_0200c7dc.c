#include "m2c.h"

extern void func_0200c894(s32 a0, s32 a1);

/* One 0x28-byte record of the table that starts at a0 + 0x1D0. */
typedef struct {
    void **obj;
    u8 pad[0x24];
} Entry;

void func_0200c7dc(s32 a0, s32 a1) {
    Entry *e = (Entry *) ((s8 *) a0 + 0x1D0) + a1;
    void **p = e->obj;
    if (p != NULL) {
        if (p != NULL) {
            M2C_FIELD(*p, M2C_UNK(**)(), 4)(p);
        }
        e->obj = NULL;
    }
    M2C_FIELD((u8 *) a0 + a1 * 0x28, u8 *, 0x1DF) = 0;
    func_0200c894(a0, M2C_FIELD(a0 + a1 * 0x28, s8 *, 0x1E1));
}
