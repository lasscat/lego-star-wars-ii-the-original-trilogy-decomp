#include "m2c.h"

M2C_UNK func_02004dec(void *, M2C_UNK);             /* extern */
M2C_UNK func_020b04f0(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK data_02106d90;
extern M2C_UNK data_0210794c;
extern void **data_021092f4;
extern s32 data_027e02a8;

void func_0200ed78(void *arg0, M2C_UNK arg1) {
    void *temp_r1;
    void *temp_r1_2;

    if ((M2C_FIELD(M2C_FIELD(&data_02106d90, void **, 0xAD0), s8 *, 0x41) == M2C_FIELD(arg0, u8 *, 0x5DA)) &&
        (data_027e02a8 & 0x40) && (M2C_FIELD(*data_021092f4, s32(**)(), 0x1C)(data_021092f4) == 0)) {
        func_020b04f0(&data_0210794c, 0x1C, 0, 0xFF);
    }
    temp_r1 = M2C_FIELD(arg0, void **, 0x814);
    if (temp_r1 != NULL) {
        M2C_FIELD(temp_r1, s32 *, 8) = (s32) (M2C_FIELD(temp_r1, s32 *, 8) & ~1);
    }
    temp_r1_2 = M2C_FIELD(arg0, void **, 0x818);
    if (temp_r1_2 != NULL) {
        M2C_FIELD(temp_r1_2, s32 *, 8) = (s32) (M2C_FIELD(temp_r1_2, s32 *, 8) & ~1);
    }
    func_02004dec(arg0, arg1);
}
