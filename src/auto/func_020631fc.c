#include "m2c.h"

extern u32 data_02104364[];
M2C_UNK func_02063054();                            /* extern */
u16 func_02063510(u16 *, u32);                      /* extern */

void func_020631fc(s32 arg0) {
    u32 *state = data_02104364;
    u32 cur;
    u32 delta;
    u16 *obj;

    func_02063054();
    cur       = state[8];
    delta     = *(u32 *) ((u8 *) state + 0x20) - state[8];
    state[20] = cur;
    state[21] = 0;
    state[22] = delta;
    state[23] = delta * 100 / 160;
    obj       = (u16 *) cur;
    obj[79]   = 0;
    obj[79]   = -func_02063510(obj, 0xa0);
}
