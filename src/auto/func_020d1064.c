#include "m2c.h"

M2C_UNK func_020cdd00(void *, M2C_UNK);             /* extern */
extern void *data_02117340;

u16 func_020d1064(void) {
    func_020cdd00(data_02117340 + 8, 2);
    return M2C_FIELD(data_02117340, u16 *, 8);
}
