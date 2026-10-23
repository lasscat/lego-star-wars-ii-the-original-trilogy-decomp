#include "m2c.h"

/* func_0204f5a0: normalises the vector passed by value (x, y, z) and writes the
 * result to out[0..2].  The zero vector is detected first; in that case the
 * global zero vector data_020ff9b4 is copied instead.
 * The three components are tested through volatile loads, so the components are
 * read again (not reused from the test) in the normalising branch.
 */

typedef unsigned long long u64;
typedef volatile u16 vu16;
typedef volatile u32 vu32;
typedef volatile u64 vu64;

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

extern Vec3 data_020ff9b4;

void func_0204f5a0(Vec3 *out, s32 a, Vec3 v) {
    s64 t;
    s64 div;
    s32 sqrt;

    if (*(volatile s32 *) &v.x == 0 && *(volatile s32 *) &v.y == 0 && *(volatile s32 *) &v.z == 0) {
        if (&v != &data_020ff9b4) {
            v.x = data_020ff9b4.x;
            v.y = data_020ff9b4.y;
            v.z = data_020ff9b4.z;
        }
    } else {
        t = (s64) v.x * v.x;
        t += (s64) v.y * v.y;
        t += (s64) v.z * v.z;

        (*(vu16 *) 0x04000280) = 2;
        (*(vu64 *) 0x04000290) = 1LL << 56;
        (*(vu64 *) 0x04000298) = t;
        (*(vu16 *) 0x040002B0) = 1;
        (*(u64 *) 0x040002B8)  = t << 2;

        while ((*(vu16 *) 0x040002B0) & 0x8000) {
        }
        sqrt = (s32) (*(vu32 *) 0x040002B4);

        while ((*(vu16 *) 0x04000280) & 0x8000) {
        }
        div = (s64) (*(u64 *) 0x040002A0);
        div *= sqrt;

        v.x = (s32) ((div * v.x + (1LL << 44)) >> 45);
        v.y = (s32) ((div * v.y + (1LL << 44)) >> 45);
        v.z = (s32) ((div * v.z + (1LL << 44)) >> 45);
    }

    out->x = v.x;
    out->y = v.y;
    out->z = v.z;
}
