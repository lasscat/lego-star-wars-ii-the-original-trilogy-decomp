/* Reconstructed from USA ARM9 at 0x020c0708 (144 bytes).
 *
 * Same shape as func_020bf250 (slot 1 of the table at 0x0210127c) but the
 * vector lives at +0x60 of the second object.
 */
#include "m2c.h"

typedef struct {
    s32 x, y, z;
} V3;

typedef struct {
    u8 pad[0x60];
    V3 v;
} Target;

typedef struct {
    u8 pad[0x14];
    s32 scale;
} Ctl;

void func_020c0708(Ctl *self, Target *t) {
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
    if ((s32 *) ((u8 *) (void *) t + 0x60) != (s32 *) &v) {
        M2C_FIELD(t, s32 *, 0x60) = v.x;
        M2C_FIELD(t, s32 *, 0x64) = v.y;
        M2C_FIELD(t, s32 *, 0x68) = v.z;
    }
}
