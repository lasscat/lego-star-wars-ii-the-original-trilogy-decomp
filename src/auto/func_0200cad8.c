#include "m2c.h"

/* The second argument is passed by value and the function is variadic, so the
 * compiler keeps it in the register save area and reads it back from there
 * before the call (same shape as func_02001b08 / func_02026138). */
typedef struct {
    s32 v;
} UnkVal;

/* Halfword at offset 0x14e of the object; bit 1 is the flag tested here. */
typedef struct {
    u16 flag_a : 1;
    u16 flag_b : 1;
} UnkFlags;

void func_02010384(void *, UnkVal);

void func_0200cad8(void *arg0, UnkVal arg1, ...) {
    UnkFlags *flags = (UnkFlags *) ((u8 *) arg0 + 0x14e);
    if (flags->flag_b == 1) {
        M2C_FIELD(arg0, u32 *, 8) |= 2;
    }
    func_02010384(arg0, arg1);
}
