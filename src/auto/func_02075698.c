/* Reconstructed from USA ARM9 at 0x02075698 (120 bytes).
 *
 * Appends idx zeroed 4-byte elements to the array of arg0.  When the array
 * still has room (arg0->size + idx <= arg0->capacity) the new elements are
 * cleared in place and the size is bumped; otherwise the growth helpers
 * func_02075784 and func_02075850 are used instead.
 */
#include "m2c.h"

typedef struct {
    u32 *data;
    u32 size;
    u32 capacity;
} Vec;

M2C_UNK memset(M2C_UNK *, M2C_UNK, s32);       /* extern */
M2C_UNK func_02075784(M2C_UNK, M2C_UNK, s32);   /* extern */
M2C_UNK func_02075850(M2C_UNK, M2C_UNK);        /* extern */

void func_02075698(Vec *arg0, u32 arg1) {
    if (arg1 > arg0->capacity || arg0->size > arg0->capacity - arg1) {
        volatile s8 sp0;

        sp0 = 0;
        func_02075784(arg0, arg0->size + arg1 - arg0->capacity, 0);
    } else {
        memset(arg0->data + arg0->size, 0, arg1 * 4);
        arg0->size += arg1;
        return;
    }
    func_02075850(arg0, arg1);
}
