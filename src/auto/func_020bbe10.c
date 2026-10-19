#include "m2c.h"
M2C_UNK func_0205e84c(void *);                      /* extern */
M2C_UNK func_020bc190(void *);                      /* extern */
extern M2C_UNK data_0210e1ec;
void func_020bbe10(s32 arg0) {
    void **var_r0;
    void *temp;
    if (arg0 != 0) {
        void **var_r3;
        if (M2C_FIELD(&data_0210e1ec, s32 *, 0x4F8) != 0) {
            var_r3 = M2C_FIELD(&data_0210e1ec, void ***, 0x4FC);
        } else {
            var_r3 = M2C_FIELD(&data_0210e1ec, void ***, 0x500);
        }
        if (var_r3 == M2C_FIELD(&data_0210e1ec, void ***, 0x500)) {
            return;
        }
        do {
            void *temp_r2                    = M2C_FIELD(var_r3, void **, 0);
            M2C_FIELD(temp_r2, s32 *, 0x384) = (s32) (M2C_FIELD(temp_r2, s32 *, 0x384) | 0x80000000);
            var_r3                           = M2C_FIELD(var_r3, void ***, 4);
        } while (var_r3 != M2C_FIELD(&data_0210e1ec, void ***, 0x500));
        return;
    }
    if (M2C_FIELD(&data_0210e1ec, s32 *, 0x4F8) == 0) {
        return;
    }
    do {
        if (M2C_FIELD(&data_0210e1ec, s32 *, 0x4F8) != 0) {
            var_r0 = M2C_FIELD(&data_0210e1ec, void ***, 0x4FC);
        } else {
            var_r0 = M2C_FIELD(&data_0210e1ec, void ***, 0x500);
        }
        temp = *var_r0;
        if (temp != NULL) {
            func_020bc190(temp);
            func_0205e84c(temp);
        }
    } while (M2C_FIELD(&data_0210e1ec, s32 *, 0x4F8) != 0);
}
