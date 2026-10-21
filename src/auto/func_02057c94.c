#include "m2c.h"

/* The setter family takes the value in a small struct by value; mwcc keeps the
   struct in a stack temp and reloads it through its address when passing it. */
typedef struct {
    s32 v;
} UnkVal;

extern void *func_020aaeb4(void);
extern void func_020a98e4(void *, UnkVal);

void func_02057c94(s32 arg0, u16 *arg1) {
    UnkVal sp0;

    sp0.v = (s32) (*arg1) << 0xC;
    func_020a98e4(func_020aaeb4(), sp0);
}
