/* Reconstructed from USA ARM9 at 0x0201807c (160 bytes).
 *
 * Computes the 16 bit angle (yaw) between two objects: the difference of the
 * two positions is taken component wise, optionally reversed, and the x/z
 * components are handed to the fixed point arc-tangent (func_020985d8).
 *
 * The statement order (z, y, x) and the volatile copy of the two components
 * are what the original code generation shows.
 */
#include "m2c.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} V3;

typedef struct {
    s32 x;
    s32 z;
} XZ;

extern s16 func_020985d8(s32, s32);

void func_0201807c(M2C_UNK out, M2C_UNK a, V3 *b, s32 flag) {
    V3 d;
    V3 t;
    volatile XZ q;
    s32 v0;
    s32 v1;
    s32 v2;

    v2  = b->z - M2C_FIELD(a, s32 *, 0xb8);
    v1  = b->y - M2C_FIELD(a, s32 *, 0xb4);
    v0  = b->x - M2C_FIELD(a, s32 *, 0xb0);
    d.x = v0;
    d.y = v1;
    d.z = v2;
    if (flag) {
        v2  = M2C_FIELD(a, s32 *, 0xb8) - b->z;
        v1  = M2C_FIELD(a, s32 *, 0xb4) - b->y;
        v0  = M2C_FIELD(a, s32 *, 0xb0) - b->x;
        t.x = v0;
        t.y = v1;
        t.z = v2;
        if ((s32 *) &d != (s32 *) &t) {
            d.x = v0;
            d.y = v1;
            d.z = v2;
        }
    }
    q.z            = d.z;
    q.x            = d.x;
    *((s16 *) out) = func_020985d8(d.x, d.z);
}
