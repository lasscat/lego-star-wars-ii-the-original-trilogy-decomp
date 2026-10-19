#include "m2c.h"

/* The value argument is passed in a register, but in a variadic function the
 * register save area is what the compiler reads it back from. */
typedef struct {
    s32 v;
} UnkVal;

void func_0204d27c(void *arg0, UnkVal arg1, ...) {
    *(s32 *) ((u8 *) arg0 + 0x28) = arg1.v;
    *(s32 *) ((u8 *) arg0 + 0x18) = arg1.v;
    *(s32 *) ((u8 *) arg0 + 0x20) = *(s32 *) ((u8 *) arg0 + 0x2c) + *(s32 *) ((u8 *) arg0 + 0x28);
}
