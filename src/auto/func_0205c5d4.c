#include "m2c.h"

void func_0205c0d0(s32 *);
void func_0205e84c(s32);

typedef struct {
    s32 *ptrs[7];
    u8 pad1[0x0c];
    u16 f28;
    u8 pad2[4];
    u8 f2e;
} Obj;

void func_0205c5d4(Obj *arg0) {
    s32 i;
    for (i = 0; i < 7; i++) {
        s32 *p = arg0->ptrs[i];
        if (p != 0) {
            func_0205c0d0(p);
            func_0205e84c(p);
        }
        arg0->ptrs[i] = 0;
    }
    arg0->f28 = 0xFFFF;
    arg0->f2e = 0;
    arg0->f28 = 0xFFFF;
}
