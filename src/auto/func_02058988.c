#include "m2c.h"

/* The setter takes a small struct by value; mwcc keeps the struct in a stack
   temp and reloads it through the outgoing argument area. */
typedef struct {
    u16 v;
} UnkVal;

extern void *func_020aaeb4(void);
extern void func_020a9890(void *, UnkVal);

void func_02058988(s32 arg0, u8 *arg1) {
    UnkVal sp0;

    sp0.v = (u16) ((arg1[0] << 16) / 360);
    func_020a9890(func_020aaeb4(), sp0);
}
