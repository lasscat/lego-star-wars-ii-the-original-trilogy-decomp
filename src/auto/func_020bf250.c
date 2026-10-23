/* Reconstructed from USA ARM9 at 0x020bf250 (144 bytes).
 *
 * Virtual method (slot 1 of the table at 0x021011ec): scales the vector at
 * +0x54 of the second object by the fixed-point factor at +0x14 of the first.
 * The three products are rounded ((p + 0x800) >> 12) and written back in place.
 */
#include "m2c.h"

typedef struct {
    s32 x, y, z;
} V3;

typedef struct {
    u8 pad[0x54];
    V3 v;
} Target;

typedef struct {
    u8 pad[0x14];
    s32 scale;
} Ctl;

void func_020bf250(Ctl *self, Target *t) {
    s32 sc;
    s32 z, y, x;
    V3 v;
    sc  = self->scale;
    z   = (s32) (((s64) t->v.z * (s64) sc + 0x800) >> 12);
    y   = (s32) (((s64) t->v.y * (s64) sc + 0x800) >> 12);
    x   = (s32) (((s64) t->v.x * (s64) sc + 0x800) >> 12);
    v.x = x;
    v.y = y;
    v.z = z;
    if ((s32 *) ((u8 *) (void *) t + 0x54) != (s32 *) &v) {
        M2C_FIELD(t, s32 *, 0x54) = v.x;
        M2C_FIELD(t, s32 *, 0x58) = v.y;
        M2C_FIELD(t, s32 *, 0x5c) = v.z;
    }
}
