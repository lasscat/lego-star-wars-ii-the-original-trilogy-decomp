#include "m2c.h"

M2C_UNK clearDataAndInstructionCache();

/* The object pointed to by the five slots: a flags word with bit 0 used. */
typedef struct Sub_0207b420 {
    u8 pad_00[8];
    u32 flags;
} Sub_0207b420;

typedef struct {
    u8 pad_00[0x1c];
    Sub_0207b420 *arr5[5]; /* 0x1c */
    u8 pad_30[0x10];
    s32 count; /* 0x40 */
    u8 **table; /* 0x44 */
} Opaque_0207b420;

void func_0207b420(Opaque_0207b420 *s, s32 idx) {
    s32 slot = idx % 5;

    if (idx < s->count) {
        clearDataAndInstructionCache(s->arr5[slot], (u8 *) s->table[idx] + 2);
        s->arr5[slot]->flags |= 1;
    } else {
        s->arr5[slot]->flags &= ~1;
    }
}
