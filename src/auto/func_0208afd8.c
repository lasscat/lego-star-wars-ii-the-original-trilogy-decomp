/* Reconstructed from USA ARM9 at 0x0208afd8 (140 bytes).
 *
 * Walks the piece list of a request and lays out one entry per piece.
 */
#include "m2c.h"

s32 func_02053b14(s32 *);                    /* extern */
void func_0208b064(M2C_UNK, u16 *, s32);     /* extern */

void func_0208afd8(s32 arg0, u8 *arg1, s32 arg2, s32 arg3) {
    s32 temp_r0;
    u16 *temp_r5;
    s32 temp_r6;
    s32 temp_r7;

    temp_r0 = func_02053b14(arg0 + 8);
    if (arg3 != 0) {
        temp_r5 = (u16 *) (temp_r0 + 0xCC);
    } else {
        temp_r5 = (u16 *) (temp_r0 + 0x5A0 - (((u32) arg1[1] >> 1) * 4));
    }
    temp_r6 = arg1[1];
    temp_r7 = 1;
    while (temp_r7 <= temp_r6) {
        s32 v = 3;
        if (temp_r7 <= arg2) {
            v = 0;
        }
        func_0208b064(arg0, temp_r5, v);
        temp_r5 += 2;
        temp_r7++;
    }
    arg1[2] = (arg2 == 0) ? 0xFF : (arg2 - 1);
}
