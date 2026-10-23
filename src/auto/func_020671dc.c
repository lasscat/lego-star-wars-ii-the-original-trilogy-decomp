#include "m2c.h"

void *func_020e4600();                     /* extern */
void func_020676cc();                      /* extern */
void func_02067710();                      /* extern */

void func_020671dc(void *arg0, void *arg1, void *arg2) {
    void *base;
    u8 *elem;
    u32 i;

    if (M2C_FIELD(arg0, u16 *, 0x18) == 0) {
        return;
    }
    base = M2C_FIELD(arg1, void **, 0xc);
    if (base != 0) {
        base = func_020e4600(base, M2C_FIELD(arg0, u16 *, 0x18), 8, 0, func_020676cc, 0);
    }
    M2C_FIELD(arg0, void **, 4)   = base;
    M2C_FIELD(arg1, void **, 0xc) = M2C_FIELD(arg1, void **, 0xc) + (M2C_FIELD(arg0, u16 *, 0x18) * 8 + 8);
    elem                          = (u8 *) arg2 + 0x10;
    for (i = 0; i < M2C_FIELD(arg0, u16 *, 0x18); i++) {
        func_02067710((u8 *) M2C_FIELD(arg0, void **, 4) + i * 8, arg1, i, elem, M2C_FIELD(arg0, u8 *, 0x22));
        elem = elem + M2C_FIELD(elem, u16 *, 0);
    }
}
