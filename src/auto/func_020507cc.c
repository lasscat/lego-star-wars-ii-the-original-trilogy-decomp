#include "m2c.h"

M2C_UNK func_0204a124(M2C_UNK *, s32, s32);         /* extern */
M2C_UNK func_0205084c(void *, s32 *);               /* extern */

struct Pair {
    s32 in[3];
    s32 out[3];
};
struct V {
    s32 x;
    s32 y;
    s32 z;
};

void func_020507cc(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    struct Pair p;
    s32 temp_r1;
    s32 temp_r2;
    s32 temp_r3;
    struct V *v;
    s32 var_r0;

    func_0204a124(p.in, arg2 + 0x10, arg3 + 0x30);
    v        = (struct V *) p.in;
    temp_r3  = v->z >> 1;
    temp_r2  = v->y >> 1;
    temp_r1  = v->x;
    p.out[1] = temp_r2;
    p.out[2] = temp_r3;
    p.out[0] = temp_r1 >> 1;
    var_r0   = ((M2C_FIELD(arg0, s32 *, 0x28) == (temp_r1 >> 1)) && (temp_r2 == M2C_FIELD(arg0, s32 *, 0x2C)) &&
              (temp_r3 == M2C_FIELD(arg0, s32 *, 0x30)))
                   ? 0
                   : 1;
    if (var_r0 == 0) {
        return;
    }
    func_0205084c(arg0, p.out);
}
