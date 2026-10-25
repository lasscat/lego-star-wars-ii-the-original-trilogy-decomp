/* Reconstructed from USA ARM9 at 0x02028fb0 (184 bytes).
 *
 * Rotates a vector about the Y axis: the input vector is copied to the
 * output, then x and z are replaced by the fixed point (12 bit fraction)
 * rotation using the sine/cosine pair from the angle table. The angle is
 * passed in a one-halfword struct and indexed by its top 12 bits.
 *
 * The products are formed one statement at a time (z*sin, x*cos, x*sin,
 * z*cos) and one temporary holds z*sin, then x*sin and finally the new z;
 * that statement sequence gives the original register allocation.
 */
#include "m2c.h"

extern const s16 data_020f88c4[];

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} V3;

typedef struct {
    u16 v;
} Ang;

void func_02028fb0(V3 *out, V3 *in, Ang ang) {
    s32 s;
    s32 c;
    s32 x;
    s32 z;
    s32 nx;
    s32 t;

    out->x = in->x;
    out->y = in->y;
    out->z = in->z;
    s      = data_020f88c4[(ang.v >> 4) * 2];
    c      = data_020f88c4[(ang.v >> 4) * 2 + 1];
    x      = out->x;
    z      = out->z;
    t      = (s32) (((s64) z * s + 0x800) >> 12);
    nx     = (s32) (((s64) x * c + 0x800) >> 12);
    nx += t;
    t      = (s32) (((s64) x * s + 0x800) >> 12);
    t      = (s32) (((s64) z * c + 0x800) >> 12) - t;
    out->x = nx;
    out->z = t;
}
