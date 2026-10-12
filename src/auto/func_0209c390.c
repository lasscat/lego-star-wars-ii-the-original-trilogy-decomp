#include "m2c.h"

s32 func_0205d0d0(M2C_UNK *, M2C_UNK, M2C_UNK);     /* extern */
M2C_UNK func_0209c41c(void *);                      /* extern */
M2C_UNK func_0209c4b4(void *);                      /* extern */
M2C_UNK func_0209c4cc(void *);                      /* extern */
extern M2C_UNK data_021027f8;

void func_0209c390(void *arg0) {
    if ((func_0205d0d0(&data_021027f8, 0x200, 4) != 0) && (M2C_FIELD(arg0, u8 *, 0x28) != 0)) {
        func_0209c41c(arg0);
        func_0209c4b4(arg0);
        M2C_FIELD(arg0, u8 *, 0x28) = (u8) (M2C_FIELD(arg0, u8 *, 0x28) - 1);
    }
    if (func_0205d0d0(&data_021027f8, 0x100, 4) == 0) {
        return;
    }
    if ((u32) M2C_FIELD(arg0, u8 *, 0x28) >= 2U) {
        return;
    }
    func_0209c41c(arg0);
    func_0209c4cc(arg0);
    M2C_FIELD(arg0, u8 *, 0x28) = (u8) (M2C_FIELD(arg0, u8 *, 0x28) + 1);
}
