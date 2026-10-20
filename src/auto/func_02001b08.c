#include "m2c.h"

/* The value argument is passed in a register, but in a variadic function the
 * register save area is what the compiler reads it back from. */
typedef struct {
    s32 v;
} UnkVal;

void func_02010384(void *arg0, UnkVal arg1);

void func_02001b08(void *arg0, UnkVal arg1, ...) {
    func_02010384(arg0, arg1);
}
