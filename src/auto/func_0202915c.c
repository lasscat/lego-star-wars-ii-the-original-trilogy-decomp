#include "m2c.h"

typedef struct {
    u16 v;
} H;

extern void func_020290e0(u16 *out, M2C_UNK a1, s32 a2);
extern void func_02029120(s32 a0, H a1);

void func_0202915c(s32 a0, s32 a1) {
    H h;
    func_020290e0(&h.v, a0, a1);
    func_02029120(a0, h);
}
