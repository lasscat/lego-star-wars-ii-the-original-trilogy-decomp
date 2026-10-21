#include "m2c.h"

/* The NDS ARM9 coprocessor (CP) block:
 *   0x040002B0  u16  command / status (bit 15 = busy)
 *   0x040002B4  u32  result
 *   0x040002B8  u64  square root input (32.32 fixed point)
 */
typedef struct {
    u16 mode;
    u16 pad;
    u32 result;
    u64 input;
} CPRegs;

/* Squared distance of two fixed point positions, square rooted in hardware:
 * the 64 bit sum of squares is written to the CP as a 32.32 value (<< 2),
 * the square root is started, and the result is halved. */
void func_02007eb4(u32 *out, s32 *a1, volatile s32 *a2) {
    volatile CPRegs *cp = (CPRegs *) 0x40002B0;
    s32 dz              = a1[2] - a2[2];
    s32 dx              = a1[0] - a2[0];
    s64 d               = (s64) dx * dx;
    d += (s64) dz * dz;
    cp->mode  = 1;
    cp->input = d << 2;
    while (cp->mode & 0x8000) {
    }
    *out = (*((volatile u32 *) 0x40002B4) + 1) / 2;
}
