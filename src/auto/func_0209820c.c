/* Reconstructed from USA ARM9 at 0x0209820c.
 * Fills a small record: three byte fields plus a 4-byte name copied from
 * the 4th argument.  The 5th argument is passed on the stack.
 */
#include "m2c.h"

typedef struct {
    u8 pad[0x2f];
    u8 arr[4];
} T;

void func_0209820c(s32 a0, u8 a1, u8 a2, u8 *a3, u8 a4) {
    u32 i;
    T *p                = (T *) a0;
    *(u8 *) (a0 + 0x2c) = a4;
    *(u8 *) (a0 + 0x1e) = a1;
    *(u8 *) (a0 + 0x2e) = a2;
    for (i = 0; i < 4; i++) {
        p->arr[i] = a3[i];
    }
}
