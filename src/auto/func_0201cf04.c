#include "m2c.h"

/* Searches an 8 entry table of object pointers for the entry whose u16 field
   at byte offset 0x180 equals the low byte of the key. Returns the index of
   the match, or 0xffff when there is none. */
s32 func_0201cf04(s32 *table, s32 key) {
    u32 i;
    u32 target = key & 0xff;
    for (i = 0; i < 8; i++) {
        s32 *p = table[i];
        if (p != 0 && target == *(u16 *) ((s8 *) p + 0x180)) {
            return i;
        }
    }
    return 0xffff;
}
