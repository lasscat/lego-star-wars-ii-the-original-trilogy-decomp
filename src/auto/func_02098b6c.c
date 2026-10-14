#include "m2c.h"

M2C_UNK func_0200fa74(s32);                         /* extern */
M2C_UNK func_02062a40(u16);                         /* extern */
M2C_UNK func_02072e54();                            /* extern */
extern M2C_UNK data_021019f4;
extern void **data_021092f4;
extern s32 data_027e02a4;

void func_02098b6c(void *arg0) {
    func_02072e54();
    if (data_021092f4 != NULL) {
        func_02062a40(M2C_FIELD(arg0, u16 *, 0x2B04));
        M2C_FIELD(*data_021092f4, M2C_UNK(**)(void **, M2C_UNK), 0x18)(data_021092f4, 1);
    }
    func_0200fa74((data_027e02a4 * 0x38) + (s32) &data_021019f4);
}
