#include "m2c.h"

s32 func_020676e4(s32 arg0, s32 arg1);
s32 func_020e4600(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
void func_020677f0(void *arg0);

typedef struct {
    s32 f0;
    u8 *f4;
} Elem_02067710;

typedef struct {
    Elem_02067710 *f0;
    u8 f4;
    u8 f5;
    u8 f6;
} Unk_02067710;

void func_02067710(Unk_02067710 *a0, s32 *a1, u8 a2, u8 *a3, s32 a4) {
    u8 *p;
    Elem_02067710 *cur;
    u32 i;
    u8 n;

    a0->f5 = a3[3];
    a0->f4 = a2;
    a0->f6 = a4;
    if (a0->f5 == 0) {
        return;
    }
    func_020676e4((s32) a0, a3[3]);
    p   = a3 + 4 + func_020676e4((s32) a0, a3[3]);
    cur = (Elem_02067710 *) a1[3];
    n   = a0->f5;
    if (cur != 0) {
        cur = (Elem_02067710 *) func_020e4600((s32) cur, n, 8, 0, (s32) func_020677f0, 0);
    }
    a0->f0 = cur;
    a1[3]  = a1[3] + (a0->f5 * 8 + 8);
    i      = 0;
    while (i < a0->f5) {
        a0->f0[i].f4 = p;
        p += a3[i + 4];
        i++;
    }
}
