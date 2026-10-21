#include "m2c.h"

extern s8 data_021043c6[];
extern void func_02063868(s32 a0, u32 a1);

/* Sets the s16 at data_021043c6 + a0 * 0x32 + a1 * 0xA, then redraws the cell. */
void func_02063a58(s32 a0, s32 a1, s16 a2) {
    *(s16 *) (data_021043c6 + (a0 * 0x32) + (a1 * 0xA)) = *(s16 *) &a2;
    func_02063868(a0, a1);
}
