#include "m2c.h"

/* A 16-bit value that is passed by value (2 bytes, so it travels in a register
 * or in a packed half-word slot of the outgoing argument area). */
typedef struct {
    s16 v;
} Value;

extern void func_02063968(s32 a0, s32 a1, u8 a2, Value a3, Value a4, Value a5, s32 a6);

/* Resets one cell of the 2x5 table at data_021043c4 to its default state:
 * the cell index is (a0, 0), a1 is stored in the second byte of the cell.
 */
void func_02063a90(s32 a0, s32 a1) {
    Value v3;
    Value v4;
    Value v5;

    v3.v = 0x2000;
    v4.v = 0;
    v5.v = 0x100;
    func_02063968(a0, 0, 0, v3, v4, v5, a1);
}
