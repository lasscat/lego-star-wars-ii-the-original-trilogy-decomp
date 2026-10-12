#include "m2c.h"

M2C_UNK func_0207281c();                            /* extern */
M2C_UNK func_020861bc(M2C_UNK *, M2C_UNK);          /* extern */
extern M2C_UNK data_02104d90;
extern void **data_0210b348;

void func_020b10a8(void *arg0) {
    func_0207281c();
    M2C_FIELD(*data_0210b348, M2C_UNK (**)(void **, M2C_UNK), 0x4C)(data_0210b348, 1);
    M2C_FIELD(arg0, s8 *, 0xC) = 5;
    M2C_FIELD(arg0, s8 *, 6) = 1;
    func_020861bc(&data_02104d90, 0xB);
}
