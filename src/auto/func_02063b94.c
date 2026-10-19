#include "m2c.h"

M2C_UNK func_02063df8(s32, s32 *);                  /* extern */
extern M2C_UNK data_021027f8;
extern M2C_UNK data_02109358;

void func_02063b94(void *arg0) {
    s32 sp[3];
    void *temp_r2;
    void *var_r5;

    temp_r2 = *((M2C_UNK *) ((s8 *) &data_02109358 + (M2C_FIELD(&data_021027f8, volatile u8 *, 0x2A) * 4)));
    if (temp_r2 == NULL) {
        return;
    }
    sp[0]                                = M2C_FIELD(temp_r2, volatile s32 *, 0xB0);
    sp[1]                                = M2C_FIELD(temp_r2, volatile s32 *, 0xB4);
    sp[2]                                = M2C_FIELD(temp_r2, volatile s32 *, 0xB8);
    M2C_FIELD(arg0, volatile u8 *, 0x60) = (u8) (M2C_FIELD(arg0, volatile u8 *, 0x60) + 1);
    var_r5                               = M2C_FIELD(arg0, void **, 4);
    if (var_r5 == NULL) {
        return;
    }
    do {
        func_02063df8(M2C_FIELD(var_r5, volatile s32 *, 0), sp);
        var_r5 = M2C_FIELD(var_r5, void **, 4);
    } while (var_r5 != NULL);
}
