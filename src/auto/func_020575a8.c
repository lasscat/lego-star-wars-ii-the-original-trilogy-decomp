#include "m2c.h"

typedef struct {
    u16 v;
} UnkVal;

extern void *func_020aaeb4(void);
extern void func_020a2064(void *, UnkVal);

void func_020575a8(s32 arg0, s16 *arg1) {
    UnkVal sp0;

    sp0.v = (u16) ((*arg1 << 16) / 360);
    func_020a2064(func_020aaeb4(), sp0);
}
