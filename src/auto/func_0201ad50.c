#include "m2c.h"

/* func_0201ad50 - allocates a 0x80 byte block, hands it to func_0201abbc and
 * stores the result through the first argument, then calls func_0201adc4.
 *
 * The "push {r0, r1, r2, r3}" prologue is MWCC's argument home area: the
 * fourth argument is a four byte aggregate passed by value, so it is read
 * back from its home slot ("add r1, sp, #0x24" / "ldr r3, [r1, #0]") and
 * passed on as the fourth argument of func_0201adc4, which takes the same
 * aggregate by value.  The fifth argument is passed as an unsigned byte,
 * which is the "ldrb ip, [sp, #0x2c]" of the original.
 */

typedef struct {
    s32 v;
} UnkVal;

extern void *func_0205e80c(s32 size, s32 flag, s32 align);
extern void *func_0201abbc(void *block, void *arg);
extern void func_0201adc4(void *a, void *b, void *c, UnkVal d, s32 e, u8 f);

void func_0201ad50(void *p0, void *p1, void *p2, UnkVal p3, s32 p4, u8 p5, void *p6) {
    void *block;
    block = func_0205e80c(0x80, 0, 4);
    if (block != 0) {
        block = func_0201abbc(block, p6);
    }
    *(void **) p0 = block;
    func_0201adc4(p0, p1, p2, p3, p4, p5);
}
