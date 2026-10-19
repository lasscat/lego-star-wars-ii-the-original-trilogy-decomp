#include "m2c.h"

/* Same shape as func_0204d27c: the value argument is read back from the
 * variadic register save area. */
typedef struct {
    s32 v;
} UnkVal;

void func_0204d250(void *arg0, UnkVal arg1, ...) {
    *(s32 *) ((u8 *) arg0 + 0x2c) = arg1.v;
    *(s32 *) ((u8 *) arg0 + 0x14) = arg1.v;
    *(s32 *) ((u8 *) arg0 + 0x1c) = arg1.v;
    *(s32 *) ((u8 *) arg0 + 0x20) = *(s32 *) ((u8 *) arg0 + 0x2c) + *(s32 *) ((u8 *) arg0 + 0x28);
}
