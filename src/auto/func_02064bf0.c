#include "m2c.h"

M2C_UNK func_0205e624(void *, M2C_UNK, M2C_UNK);    /* extern */
extern M2C_UNK data_021044fc;
extern M2C_UNK data_021045fc;

void func_02064bf0(s32 arg0) {
    func_0205e624((M2C_UNK *) ((s8 *) &data_021044fc + (arg0 << 7)), 0, 0x80);
    func_0205e624((M2C_UNK *) ((s8 *) &data_021045fc + (arg0 << 7)), 0xFF, 0x80);
}
