#include "m2c.h"

extern s8 data_021043c4[];

/* Sets one 10-byte cell of the 2x5 table at data_021043c4.
 * The cell is {u8, u8, s16, s16, s16, s16}; the row is arg0 * 0x32 bytes,
 * the cell inside the row is arg1 * 0xA bytes.
 */
void func_02063968(s32 a0, s32 a1, u8 a2, s16 a3, s16 a4, s16 a5, u8 a6, ...) {
    s16 v3 = *(s16 *) &a3;

    if (v3 != 0x2000) {
        *(s16 *) (data_021043c4 + 2 + (a0 * 0x32) + (a1 * 0xA)) = v3;
    }
    *(u8 *) (data_021043c4 + (a0 * 0x32) + (a1 * 0xA))      = a2;
    *(u8 *) (data_021043c4 + 1 + (a0 * 0x32) + (a1 * 0xA))  = a6;
    *(s16 *) (data_021043c4 + 4 + (a0 * 0x32) + (a1 * 0xA)) = a5;
    if (a5 < 0) {
        *(s16 *) (data_021043c4 + 8 + (a0 * 0x32) + (a1 * 0xA)) = *(s16 *) (data_021043c4 + 2 + (a0 * 0x32) + (a1 * 0xA));
        *(s16 *) (data_021043c4 + 6 + (a0 * 0x32) + (a1 * 0xA)) = a4;
    } else {
        *(s16 *) (data_021043c4 + 6 + (a0 * 0x32) + (a1 * 0xA)) = *(s16 *) (data_021043c4 + 2 + (a0 * 0x32) + (a1 * 0xA));
        *(s16 *) (data_021043c4 + 8 + (a0 * 0x32) + (a1 * 0xA)) = a4;
    }
}
