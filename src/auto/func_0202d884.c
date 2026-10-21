#include "m2c.h"

typedef struct {
    u16 mode;
    u16 pad;
    u32 result;
    u64 input;
} CPRegs;

void func_0202d884(u32 *out, s32 *a1, s32 *a2) {
    volatile CPRegs *cp = (CPRegs *) 0x40002B0;
    s32 v0              = a1[0] - a2[0];
    s32 v1              = a1[1] - a2[1];
    s32 v2              = a1[2] - a2[2];
    s64 d               = (s64) v0 * v0;
    d += (s64) v1 * v1;
    d += (s64) v2 * v2;
    cp->mode  = 1;
    cp->input = d << 2;
    while (cp->mode & 0x8000) {
    }
    *out = (*((volatile u32 *) 0x40002B4) + 1) / 2;
}
