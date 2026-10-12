#include "m2c.h"

M2C_UNK func_020861bc(M2C_UNK *, u16, u8);          /* extern */
extern M2C_UNK data_02104d90;

void func_02057064(s32 arg0, void *arg1) {
    func_020861bc(&data_02104d90, M2C_FIELD(arg1, u16 *, 0), M2C_FIELD(arg1, u8 *, 2));
}
