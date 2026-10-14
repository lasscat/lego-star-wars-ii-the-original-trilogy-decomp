#include "m2c.h"

M2C_UNK func_0205365c(s32, M2C_UNK);                /* extern */
M2C_UNK func_0205e938(void *, M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_0205ea38(void *, M2C_UNK);             /* extern */
M2C_UNK func_0205ea84(void *, M2C_UNK);             /* extern */
M2C_UNK func_0206574c(s32, M2C_UNK, M2C_UNK);       /* extern */
s32 func_02093fd0(s32);                             /* extern */
extern M2C_UNK data_020eff10;

void func_0207d608(void *arg0) {
    func_0205365c(M2C_FIELD(arg0, s32 *, 0x10), 0);
    M2C_FIELD(arg0, s32 *, 0x2C) = 0x8C;
    M2C_FIELD(arg0, s8 *, 0x27)  = 4;
    M2C_FIELD(arg0, s8 *, 0x25)  = 0;
    func_0206574c(M2C_FIELD(arg0, s32 *, 8), 6, -1);
    M2C_FIELD(arg0, s32 *, 0) = func_02093fd0(M2C_FIELD(arg0, s32 *, 4));
    func_0205e938(arg0 + 0x14, &data_020eff10, 0xC, 1);
    func_0205ea38(arg0 + 0x14, 0);
    func_0205ea84(arg0 + 0x14, 1);
}
