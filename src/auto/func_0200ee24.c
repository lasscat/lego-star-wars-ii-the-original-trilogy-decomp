#include "m2c.h"

void func_0200ee24(void *arg0) {
    void *var_r1;
    void *var_r1_2;
    void *var_r2;
    void *var_r2_2;

    var_r2 = M2C_FIELD(arg0, void **, 0x820);
    var_r1 = var_r2;
    if (var_r2 != NULL) {
        var_r1 = var_r2 - 4;
    }
    if (var_r1 != NULL) {
        if (var_r2 != NULL) {
            var_r2 -= 4;
        }
        M2C_FIELD(var_r2, s32 *, 8) = (s32) (M2C_FIELD(var_r2, s32 *, 8) | 2);
    }
    var_r2_2 = M2C_FIELD(arg0, void **, 0x828);
    var_r1_2 = var_r2_2;
    if (var_r2_2 != NULL) {
        var_r1_2 = var_r2_2 - 4;
    }
    if (var_r1_2 != NULL) {
        if (var_r2_2 != NULL) {
            var_r2_2 -= 4;
        }
        M2C_FIELD(var_r2_2, s32 *, 8) = (s32) (M2C_FIELD(var_r2_2, s32 *, 8) | 2);
    }
    M2C_FIELD(arg0, s32 *, 0x830) = 0;
}
