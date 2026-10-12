#include "m2c.h"

M2C_UNK func_02088674(void *, u16, M2C_UNK);        /* extern */

void func_02088734(void *arg0) {
    func_02088674(arg0, M2C_FIELD(arg0, u16 *, 0xA), 2);
    M2C_FIELD(arg0, s16 *, 0xC) = 4;
}
