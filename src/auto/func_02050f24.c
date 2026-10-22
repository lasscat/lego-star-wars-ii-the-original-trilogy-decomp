#include "m2c.h"

/* Reconstructed from USA ARM9 at 0x02050f24 (152 bytes).
 *
 * Builds a position vector and a colour vector (both in 4.12 fixed point)
 * out of an input descriptor and hands them, together with two extra
 * scalars, to func_02060fa4.
 *
 * The packed colour field is split into three 5 bit channels; the two
 * remaining unsigned fields are scaled by 4096 as well.
 */

typedef struct {
    s16 x;
    s16 y;
    s16 z;
    s16 unused;
    u16 a;
    u16 b;
    u16 c;
} InColor;

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

typedef struct {
    s32 v;
} UnkVal;

extern void func_02060fa4(void *, void *, UnkVal, UnkVal);

void func_02050f24(InColor *s) {
    Vec3 pos;
    Vec3 col;
    UnkVal u;
    UnkVal v;
    u16 g;

    pos.x = 0;
    pos.y = 0;
    pos.z = 0;
    pos.x = s->x << 12;
    pos.y = s->y << 12;
    pos.z = s->z << 12;

    g     = s->c;
    col.x = (g & 0x1f) << 12;
    col.y = ((g >> 5) & 0x1f) << 12;
    col.z = ((g >> 10) & 0x1f) << 12;

    v.v = s->b << 12;
    u.v = s->a << 12;

    func_02060fa4(&pos, &col, u, v);
}
