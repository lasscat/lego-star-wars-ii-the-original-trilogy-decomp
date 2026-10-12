#include "m2c.h"

M2C_UNK func_020b3b38(M2C_UNK *, u8, u8);           /* extern */
extern M2C_UNK data_021027f8;
extern M2C_UNK data_02109358;
extern M2C_UNK data_027e0bd0;

void func_02098308(void *arg0, s32 arg1) {
    if (arg1 != *((M2C_UNK *)((s8 *)&data_02109358 + (M2C_FIELD(&data_021027f8, u8 *, 0x2A) * 4)))) {
        return;
    }
    func_020b3b38(&data_027e0bd0, M2C_FIELD(arg0, u8 *, 0x3B), M2C_FIELD(arg0, u8 *, 0x3C));
}
