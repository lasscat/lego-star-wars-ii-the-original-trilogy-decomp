#include "m2c.h"

typedef struct {
    u16 v;
} H;

extern void func_02029068(u16 *out, M2C_UNK in, s32 arg);
extern void func_02029120(s32 a0, H a1);

void func_02029198(s32 a0, s32 a1) {
    H h;
    func_02029068(&h.v, a0, a1);
    func_02029120(a0, h);
}
