#include "m2c.h"

extern u32 data_02104364[];

/* Resets the counters of the global timer block:
 *   [0x50] = current value of the field at 0x20
 *   [0x54] = 0
 *   [0x58] = difference of the two reads of the field at 0x20
 *   [0x5c] = that difference scaled by 100/160
 * The field at 0x20 is read through two different expressions on purpose:
 * mwccarm folds "x - x" to 0 when both operands are the same expression,
 * while the original code keeps the subtraction.
 */
void func_02063074(s32 arg0) {
    u32 *state = data_02104364;
    u32 cur    = state[8];
    u32 delta  = *(u32 *) ((u8 *) state + 0x20) - state[8];
    state[20]  = cur;
    state[21]  = 0;
    state[22]  = delta;
    state[23]  = delta * 100 / 160;
}
