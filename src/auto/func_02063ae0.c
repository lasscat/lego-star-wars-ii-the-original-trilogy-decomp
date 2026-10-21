#include "m2c.h"

/* A 16-bit value that is passed by value: mwcc packs it into a half-word slot
 * of the outgoing argument area, or into a 4-byte temporary just below the
 * frame when it travels in a register. */
typedef struct {
    s16 v;
} Value;

extern void func_02063968(s32 a0, s32 a1, u8 a2, Value a3, Value a4, Value a5, s32 a6);

/* Resets one cell of the 2x5 table at data_021043c4 to its default state:
 * the cell index is (a0, 0), a1 is stored in the second byte of the cell. */
void func_02063ae0(s32 a0, s32 a1) {
    Value v3;
    Value v4;
    Value v5;

    v5.v = -256;
    v4.v = v5.v - 0xF00;
    v3.v = 0x2000;
    func_02063968(a0, 0, 0, v3, v4, v5, a1);
}
