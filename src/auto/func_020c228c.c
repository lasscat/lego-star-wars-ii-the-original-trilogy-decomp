#include "m2c.h"

void *func_020c228c(void *arg0, u16 arg1) {
    u8 *p = *(u8 **) arg0;
    s32 v;
    *(u16 *) p         = arg1;
    *(u16 *) (p + 2)   = 0;
    v                  = *(s32 *) ((u8 *) arg0 + 4) - ((s32) p + 0x10);
    *(s32 *) (p + 4)   = v;
    *(s32 *) (p + 8)   = 0;
    *(s32 *) (p + 0xc) = 0;
    return p;
}
