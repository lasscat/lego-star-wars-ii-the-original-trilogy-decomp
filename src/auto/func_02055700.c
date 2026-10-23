/* Reconstructed from USA ARM9 at 0x02055700 (0x154 bytes).
 *
 * The function walks the region described by the "p" descriptor and links a
 * cell of the grid stored at obj+0x24 into a list for every grid position
 * inside the region.  The six bounds are kept in a local array; the original
 * code clears them with a pointer loop, which is what the ROM shows.
 */
#include "m2c.h"

extern void func_02055854(M2C_UNK, M2C_UNK);
extern void func_020558f0(M2C_UNK, void *, void **);
extern s32 func_0201aaec(void);

void func_02055700(void *obj, void *p) {
    s32 x0;
    s32 shx;
    s32 limx;
    s32 y0;
    s32 limy;
    s32 shy;
    s32 v[6];
    s32 *b = v;
    s32 x;
    s32 y;

    do {
        *b++ = 0;
    } while (b < v + 6);

    func_02055854(obj, p);

    /* Lower and upper bound of the three coordinates, relative to the scale
     * stored in the descriptor. */
    v[0] = *(s32 *) ((u8 *) p + 0x1c) - *(s32 *) ((u8 *) *(void **) p + 0x10);
    v[1] = *(s32 *) ((u8 *) p + 0x1c) + *(s32 *) ((u8 *) *(void **) p + 0x10);
    v[2] = *(s32 *) ((u8 *) p + 0x20) - *(s32 *) ((u8 *) *(void **) p + 0x10);
    v[3] = *(s32 *) ((u8 *) p + 0x20) + *(s32 *) ((u8 *) *(void **) p + 0x10);
    v[4] = *(s32 *) ((u8 *) p + 0x24) - *(s32 *) ((u8 *) *(void **) p + 0x10);
    v[5] = *(s32 *) ((u8 *) p + 0x24) + *(s32 *) ((u8 *) *(void **) p + 0x10);

    /* Grid cell indices; the shift amount comes from func_0201aaec(). */
    x0   = v[0] >> (func_0201aaec() + 5);
    shx  = func_0201aaec() + 5;
    limx = v[1];
    y0   = v[4] >> (func_0201aaec() + 5);
    shy  = func_0201aaec();
    shy += 5;
    limy = v[5];

    for (y = y0; y <= (limy >> shy); y++) {
        for (x = x0; x <= (limx >> shx); x++) {
            u8 *cell = (u8 *) obj + 0x24;
            cell += (((u32) x) << 28) >> 22;
            cell += (((u32) y) << 28) >> 26;
            func_020558f0(obj, p, (void **) cell);
        }
    }
}
