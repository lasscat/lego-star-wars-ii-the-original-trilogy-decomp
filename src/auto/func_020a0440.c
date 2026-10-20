#include "m2c.h"

/* The second argument is a 4-byte value passed by value; the register save
 * area is where the compiler reads it back from. */
typedef struct {
    s32 v;
} UnkVal;

void func_020a0630(void *arg0, UnkVal arg1, u8 arg2);
void func_020a9158(void *arg0);

void func_020a0440(void *arg0, UnkVal arg1, u8 arg2) {
    func_020a0630(arg0, arg1, arg2);
    func_020a9158(arg0);
    M2C_FIELD(arg0, s32 *, 0x200) += 1;
}
