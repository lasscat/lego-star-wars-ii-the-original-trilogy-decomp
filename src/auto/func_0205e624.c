#include "m2c.h"

extern void MIi_CpuClearFast(u32 value, void *dest, u32 size);

/* Fills 'size' bytes at 'dst' with the low byte of 'value'.
 * Fully aligned ranges go through MIi_CpuClearFast; otherwise the range is
 * split into a head of bytes, a run of words and a tail of bytes. */
void *func_0205e624(void *dst, u32 value, u32 size) {
    s32 fill;
    u8 *p;
    u32 i;
    u32 head;

    fill = value;
    fill |= fill << 8;
    fill |= fill << 16;

    if ((((u32) dst & 3) == 0) && ((size & 3) == 0)) {
        MIi_CpuClearFast(fill, dst, size);
    } else {
        p    = (u8 *) dst;
        head = 4 - ((u32) p & 3);
        if (head != 4) {
            if (size < head) {
                head = size;
            }
            for (i = 0; i < head; i++) {
                p[i] = (u8) value;
            }
            size -= i;
            p += i;
        }
        {
            u32 words = size >> 2;

            for (i = 0; i < words; i++) {
                ((u32 *) p)[i] = fill;
            }
            p += i << 2;
            size &= 3;
        }
        for (i = 0; i < size; i++) {
            p[i] = (u8) value;
        }
    }
    return dst;
}
