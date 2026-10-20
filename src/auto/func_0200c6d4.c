/* Reconstructed from USA ARM9 at 0x0200c6d4 (80 bytes).
 * The matrix array lives at offset 0x39C of the object, with 0x38 bytes per
 * entry; the translation row of (entry[idx] * NNS_G3dGlbGetInvV()) is copied
 * into the three words of the output vector.
 */
#include "m2c.h"

typedef struct {
    f32 _00, _01, _02;
    f32 _10, _11, _12;
    f32 _20, _21, _22;
    f32 _30, _31, _32;
} Mtx43f;

typedef struct {
    Mtx43f mtx;
    u32 pad[2];
} Elem;

typedef struct {
    f32 x, y, z;
} Vec3;

extern void *NNS_G3dGlbGetInvV(void);
extern void MTX_Concat43(const Mtx43f *a, const void *b, Mtx43f *ab);

void func_0200c6d4(void *arg0, s32 idx, Vec3 *out) {
    Mtx43f res;
    Elem *e = &((Elem *) ((u8 *) arg0 + 0x39c))[idx];

    MTX_Concat43(&e->mtx, NNS_G3dGlbGetInvV(), &res);
    out->x = res._30;
    out->y = res._31;
    out->z = res._32;
}
