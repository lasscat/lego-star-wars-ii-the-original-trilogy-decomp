#include "m2c.h"

void *func_02018508(void *, s32);                   /* extern */
M2C_UNK func_02018610(void *);                      /* extern */
void *func_0205e80c(M2C_UNK, M2C_UNK, M2C_UNK);     /* extern */
extern M2C_UNK data_020e5d08;

void *func_02018420(void *arg0, s32 arg1) {
    void *temp_r0;
    void *temp_r5;
    void *var_r1;

    if (*((u8 *) ((s8 *) &data_020e5d08 + (arg1 * 6))) == 0) {
        var_r1 = M2C_FIELD(arg0, void **, 4);
        if (var_r1 != NULL) {
        loop_2:
            temp_r5 = M2C_FIELD(var_r1, void **, 0);
            if (arg1 == M2C_FIELD(temp_r5, u8 *, 6)) {
                func_02018610(temp_r5);
                return temp_r5;
            }
            var_r1 = M2C_FIELD(var_r1, void **, 4);
            if (var_r1 == NULL) {
                goto block_5;
            }
            goto loop_2;
        }
    }
block_5:
    temp_r0 = func_0205e80c(0xC, 3, 4);
    if (temp_r0 == NULL) {
        return temp_r0;
    }
    return func_02018508(temp_r0, arg1);
}
