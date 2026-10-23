#include "m2c.h"

/* func_020600f0 (0x020600f0, 0x68 bytes) -- MATCHES the USA ARM9 bytes exactly.
 *
 * Layout of the object (r0), reconstructed from the addressing modes:
 *   +0x94 : Row rows[2]      (32-byte rows, 8 s32 per row)
 *   +0xd4 : s32  counts[2]    (one counter per row)
 *
 * The counter for row `a1` is read through two different expressions in the
 * original code, which is why the ROM uses two different address forms for
 * the same word:
 *   o->counts[a1]   -> [r5 + r1, lsl #2]   with r5 = o + 0xd4
 *   cur[53]         -> [ip + 0xd4]         with ip = o + a1*4
 * (cur[53] is the same word as o->counts[a1]: o + a1*4 + 0xd4.)
 *
 * The function stores one packed word  a2 | (a3 << 16)  at rows[a1].v[count]
 * and then a3-1 further words taken from the `arr` array, one per counter
 * slot, incrementing the counter for every word written.
 */

typedef struct {
    s32 v[8];
} Row;

typedef struct {
    u8 pad[0x94];
    Row rows[2];
    s32 counts[2];
} Obj;

void func_020600f0(Obj *o, s32 a1, s32 a2, s32 a3, u32 *arr) {
    s32 *cur = (s32 *) ((char *) o + a1 * 4);
    s32 i;
    s32 j;
    u32 v;

    i = o->counts[a1];
    j = cur[53];
    o->counts[a1]++;
    o->rows[a1].v[j] = a2 | (a3 << 16);
    while (a3--) {
        v = *arr++;
        i = cur[53];
        cur[53]++;
        o->rows[a1].v[i] = v;
    }
}
