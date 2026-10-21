#include "m2c.h"

s32 func_01ffa408(M2C_UNK);                    /* extern */
void func_0205c274(void *, s32, s32);          /* extern */
void func_0205c0f0(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

/* arg1 is a stream cursor: the two reads pull two 16 bit values out of it.
 * arg0 is an array of objects, arg2 selects one of them.
 */
s32 func_0205c8d4(s32 *arg0, M2C_UNK arg1, s32 arg2, M2C_UNK arg3) {
    s32 type = func_01ffa408(arg1);
    s32 flag = func_01ffa408(arg1);
    func_0205c274(arg0[arg2], type, flag);
    func_0205c0f0(arg0[arg2], arg1, arg3);
    return 1;
}
