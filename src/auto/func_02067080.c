#include "m2c.h"

extern M2C_UNK data_021027f8;
extern M2C_UNK data_0210930c;
extern M2C_UNK data_02109354;
extern M2C_UNK data_02109358;

M2C_UNK func_02093d14(M2C_UNK);
M2C_UNK func_02093d4c(M2C_UNK);

M2C_UNK func_02067080(M2C_UNK arg0, u32 arg1, u32 arg2) {
    M2C_UNK a;
    M2C_UNK b;
    M2C_UNK c;

    if (arg1 == 0xff) {
        if (arg2 <= 4) {
            return *((M2C_UNK *) ((s8 *) &data_02109354 + (arg2 * 4)));
        }
    }
    if (arg1 == 0xff) {
        if (arg2 > 4) {
            if (arg2 == 5) {
                return *((M2C_UNK *) ((s8 *) &data_02109358 + (M2C_FIELD(&data_021027f8, u8 *, 0x2A) * 4)));
            }
            if (arg2 == 6) {
                return func_02093d14(&data_0210930c);
            }
            if (arg2 == 7) {
                return func_02093d4c(&data_0210930c);
            }
        }
    }
    a = *((M2C_UNK *) ((s8 *) arg0 + 4));
    b = *((M2C_UNK *) ((s8 *) a + 0x2C));
    c = *((M2C_UNK *) ((s8 *) b + (arg1 * 8)));
    return *((M2C_UNK *) ((s8 *) c + ((arg2 - 1) * 8)));
}
