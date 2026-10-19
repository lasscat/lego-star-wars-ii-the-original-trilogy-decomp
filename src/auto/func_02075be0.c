/* Reconstructed from USA ARM9 at 0x02075be0.
 * The second parameter is passed by value (4 bytes), which is why the
 * prologue saves r0-r3 and the value is reloaded from [sp, #4].
 */
#include "m2c.h"

typedef struct {
    s32 v;
} OneWord;

void func_02075be0(s32 a0, OneWord a1) {
    s32 *e = (s32 *) ((u8 *) a0 + 0x100);
    s32 *p = (s32 *) a0;
    do {
        p[1] = 0;
        p += 2;
    } while (p < e);
    *(s32 *) ((u8 *) a0 + 0x100) = a1.v;
    *(s32 *) ((u8 *) a0 + 0x104) = 0;
}
