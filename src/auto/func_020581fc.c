/* Reconstructed from USA ARM9 at 0x020581fc (132 bytes).
 * Names and types are inferred from the binary.
 *
 * func_0202d934 is called with five arguments: the fifth one (-0x1000) is
 * passed on the stack at sp+0.  The binary also stores -0x1000 into sp+4,
 * a slot that is never read back, so that slot is modelled as a volatile
 * local (the same technique used by the already matched sibling
 * func_02058280).  Both writes share the single value computed in ip.
 */
#include "m2c.h"

void *func_02067080(M2C_UNK, u8, u8);                   /* extern */
void func_0202d934(void *, void *, u8, u8, s32);        /* extern */

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

void func_020581fc(M2C_UNK arg0, u8 *arg1) {
    void *a;
    void *b;
    Vec3 v;
    volatile s32 sp4;

    a = func_02067080(arg0, arg1[0], arg1[1]);
    b = func_02067080(arg0, arg1[2], arg1[3]);
    if (a != NULL && b != NULL) {
        v.x = M2C_FIELD(b, s32 *, 0xb0);
        v.y = M2C_FIELD(b, s32 *, 0xb4);
        v.z = M2C_FIELD(b, s32 *, 0xb8);
        sp4 = -0x1000;
        func_0202d934(a, &v, arg1[4], arg1[5], -0x1000);
    }
}
