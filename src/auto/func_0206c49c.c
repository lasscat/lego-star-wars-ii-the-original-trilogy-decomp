/* func_0206c49c (USA ARM9, 0x0206c49c, 292 bytes).
 * Builds two rows of 16-bit values from the touch-screen state block: the mask selects
 * which of the two passes runs, the row offset comes from the field at 0x70 and the
 * packed pixel pairs are written into the destination array. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

struct Unk {
    u8 pad00[0x70];
    s32 f70;
    s32 f74;
    u8 pad78[0x800 - 0x78];
    u8 pad84[0x84];
    u16 f884;
    u8 pad86[2];
    u16 f888;
    u16 f88a;
};

void func_0206c49c(struct Unk *arg0, u16 *arg1, s32 arg2) {
    u32 mask;
    u32 base;
    s32 i;
    s32 k;
    s32 j;
    s32 r5;
    s32 r6;
    u16 *dst;

    mask = (arg0->f884 == 2) ? 3 : (1 << arg0->f884);
    base = 0;
    for (i = 0; i <= 1; i++, base += 0x12) {
        if (((i + 1) & mask) == 0) {
            continue;
        }
        if (arg0->f884 == 2) {
            if (i == 0) {
                r5 = (arg0->f70 >> 5) - 1;
            } else {
                r5 = ((arg0->f70 >> 5) * 3) - 2;
            }
        } else {
            r5 = (arg0->f70 >> 4) - 1;
        }
        r6 = base + ((i == arg2) ? 1 : 0) * 9 + 0x13;
        for (k = arg0->f74; k < arg0->f74 + 3; k++) {
            dst = arg1 + k * 32 + r5;
            for (j = 0; j < 3; j++) {
                *dst++ = (u16) ((arg0->f88a + r6) | ((arg0->f888 + 1) << 12));
                r6++;
            }
        }
    }
}
