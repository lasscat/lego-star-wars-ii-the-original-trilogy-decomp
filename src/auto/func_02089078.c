/* Reconstructed from USA ARM9 at 0x02089078 (388 bytes).
 *
 * arg0 points at an array of 24-byte items.  A parallel table of 10-byte
 * records starts at arg0 + 0x2800; each record holds a signed short at
 * +0xc4, another one at +0xc6 and a signed byte flag at +0xcc.
 */
#include "m2c.h"

void func_020891fc(void *);                     /* extern */

typedef struct {
    u32 f00, f04, f08, f0c;
    u8 f10, f11, f12, f13, f14;
} Item;

void func_02089078(void *arg0, s32 arg1) {
    u16 count = 0;
    u8 i;
    u16 j;

    if (arg1 < 6) {
        s16 a = *(s16 *) ((u8 *) arg0 + (arg1 + 1) * 10 + 0x28c4);
        if (a != 0) {
            s16 b = *(s16 *) ((u8 *) arg0 + arg1 * 10 + 0x28c6);
            if (a <= b) {
                count = (u16) (b - a + 1);
            }
        }
    }
    if (count == 0) {
        return;
    }
    for (i = 6; i > arg1; i--) {
        if (*(s8 *) ((u8 *) arg0 + i * 10 + 0x2800 + 0xcc) == -1) {
            continue;
        }
        for (j = 0; j < count; j++) {
            Item *src = &((Item *) arg0)[j + *(s16 *) ((u8 *) arg0 + i * 10 + 0x2800 + 0xc4)];
            Item *dst = &((Item *) arg0)[j + *(s16 *) ((u8 *) arg0 + i * 10 + 0x2800 + 0xc6)];
            u32 *d    = (u32 *) dst;
            u32 *s    = (u32 *) src;
            if (d != s) {
                d[0] = s[0];
                d[1] = s[1];
                d[2] = s[2];
            }
            d[3]     = s[3];
            dst->f10 = src->f10;
            dst->f11 = src->f11;
            dst->f12 = src->f12;
            dst->f13 = src->f13;
            dst->f14 = src->f14;
            func_020891fc(&((Item *) arg0)[j + *(s16 *) ((u8 *) arg0 + i * 10 + 0x2800 + 0xc4)]);
        }
        *(s16 *) ((u8 *) arg0 + i * 10 + 0x2800 + 0xc6) += count;
        *(s16 *) ((u8 *) arg0 + i * 10 + 0x2800 + 0xc4) += count;
    }
}
