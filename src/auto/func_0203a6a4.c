#include "m2c.h"

M2C_UNK func_02004acc(void *);                      /* extern */
s32 func_0205d140(M2C_UNK *);                       /* extern */
extern M2C_UNK data_021027f8;

void func_0203a6a4(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0xD) = 0;
    M2C_FIELD(M2C_FIELD(arg0, void **, 4), s8 *, 0x6BA) = 1;
    func_02004acc(M2C_FIELD(arg0, void **, 4));
    M2C_FIELD(arg0, s32 *, 0x14) = (s32) M2C_FIELD(M2C_FIELD(arg0, void **, 4), u8 *, 0x5DA);
    M2C_FIELD(arg0, s32 *, 0x18) = func_0205d140(&data_021027f8);
}
