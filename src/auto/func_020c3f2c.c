#include "m2c.h"

/* Reconstructed from USA ARM9 at 0x020c3f2c (152 bytes).
 *
 * Walks a list of byte entries and writes a 16 bit value into a slot
 * table.  The value is the sum of two 16 bit quantities; when the flag
 * field is even both of them are halved first.
 */

typedef struct {
    u16 sprite;
    u8 count;
    u8 flags;
} Entry;

typedef struct {
    u16 a;
    u16 b;
} Info;

typedef struct {
    u8 pad[0x2c];
    u32 value;
} Obj;

typedef struct {
    u8 pad[4];
    u16 e0;
    u16 e1;
    u16 e2;
    u16 index;
} Base;

extern void func_020c3f2c(Base *base, Entry *entry, Obj *obj, Info *info);

void func_020c3f2c(Base *base, Entry *entry, Obj *obj, Info *info) {
    u8 *tbl = (u8 *) base + entry->sprite;
    u16 d   = info->a;
    u16 v   = (u16) obj->value;
    u32 i;

    if ((info->b & 1) == 0) {
        d = d >> 1;
        v = v >> 1;
    }

    for (i = 0; i < entry->count; i++) {
        u16 sum                            = d + v;
        u16 idx                            = base->index;
        u8 k                               = tbl[i];
        u8 *p                              = (u8 *) base + 4 + idx;
        u16 w                              = *(u16 *) p;
        u32 off                            = w * k + (u32) p;
        u32 v2                             = *(u32 *) (off + 4);
        *(u16 *) ((u8 *) base + v2 + 0x1c) = sum;
    }

    entry->flags |= 1;
}
