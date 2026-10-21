#include "m2c.h"

extern u32 data_02104364[];
u16 func_02063510(u16 *, u32);

/* Updates the timing block in data_02104364:
 *   [0x58] = delta of the two counters ([0x50] - [0x20])
 *   [0x5c] = that delta scaled by 100/160
 * and rewrites the last halfword of the object at [0x20] with the negated
 * sum of its 80 halfwords (the value is zeroed before the sum is taken).
 */
void func_0206325c(void) {
    u32 *state          = data_02104364;
    u32 obj             = state[8];
    u32 delta           = state[20] - obj;
    state[22]           = delta;
    state[23]           = delta * 100 / 160;
    ((u16 *) obj)[0x4F] = 0;
    ((u16 *) obj)[0x4F] = -func_02063510((u16 *) obj, 0xA0);
}
