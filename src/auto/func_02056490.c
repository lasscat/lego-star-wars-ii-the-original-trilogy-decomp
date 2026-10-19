#include "m2c.h"

M2C_UNK func_02048a54(void *, u8);
M2C_UNK func_020b04f0(M2C_UNK *, M2C_UNK, u8 *, M2C_UNK);
extern M2C_UNK data_021027f8;
extern M2C_UNK data_0210794c;
extern M2C_UNK data_02109358;
extern s32 data_027e02a8;

void func_02056490(s32 arg0, u8 *arg1) {
    u8 sp0[0x1c];
    void *temp_r0;

    if (!(data_027e02a8 & 0x40)) {
        temp_r0 =
            M2C_FIELD(*((M2C_UNK *) ((s8 *) &data_02109358 + (M2C_FIELD(&data_021027f8, u8 *, 0x2A) * 4))), void **, 0x5F8);
        if (temp_r0 == NULL) {
            return;
        }
        if (M2C_FIELD(temp_r0, u8 *, 0xE) != 1) {
            return;
        }
        func_02048a54(temp_r0, *arg1);
        return;
    }
    sp0[0] = M2C_FIELD(&data_021027f8, u8 *, 0x2A);
    sp0[1] = *arg1;
    func_020b04f0(&data_0210794c, 0x25, sp0, 0xFF);
}
