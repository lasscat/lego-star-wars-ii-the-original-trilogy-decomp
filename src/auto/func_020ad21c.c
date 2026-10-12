#include "m2c.h"

s32 func_02073034();                                /* extern */
extern u8 data_02104344;
extern M2C_UNK data_0210930c;

void func_020ad21c(void *arg0) {
    s32 temp_r1;
    s32 temp_r1_2;
    u8 var_r5;
    void *temp_r0;
    void *temp_r2;

    var_r5 = 0;
    M2C_FIELD(arg0, s32 *, 0x60) = 0;
    if (func_02073034() > 0) {
        do {
            temp_r2 = (M2C_UNK *)((s8 *)&data_0210930c + (var_r5 * 4));
            temp_r0 = M2C_FIELD(temp_r2, void **, 0x4C);
            if (temp_r0 != NULL) {
                temp_r1 = M2C_FIELD(arg0, s32 *, 0x60) + M2C_FIELD(temp_r0, s32 *, 0xB0);
                M2C_FIELD(arg0, s32 *, 0x60) = temp_r1;
                temp_r1_2 = temp_r1 + M2C_FIELD(M2C_FIELD(temp_r2, void **, 0x4C), s32 *, 0xB4);
                M2C_FIELD(arg0, s32 *, 0x60) = temp_r1_2;
                M2C_FIELD(arg0, s32 *, 0x60) = (s32) (temp_r1_2 + M2C_FIELD(M2C_FIELD(temp_r2, void **, 0x4C), s32 *, 0xB8));
            }
            var_r5 += 1;
        } while ((s32) var_r5 < func_02073034());
    }
    M2C_FIELD(arg0, s16 *, 0x68) = (s16) data_02104344;
}
