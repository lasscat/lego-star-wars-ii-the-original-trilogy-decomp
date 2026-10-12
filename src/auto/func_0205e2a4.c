#include "m2c.h"
#include "engine.h"

void func_0205e334(M2C_UNK);

s32 func_0205e2a4(s32 arg0) {
    void *temp_r1;
    void *var_r0;
    void *var_r1;

    temp_r1 = M2C_FIELD(arg0, void **, 0x18);
    if (temp_r1 != NULL) {
        var_r0 = temp_r1;
        if (temp_r1 != NULL) {
            var_r0 = temp_r1 - 4;
        }
        var_r1 = M2C_FIELD(temp_r1, void **, 4);
        if (var_r1 != NULL) {
            var_r1 -= 4;
        }
        if (var_r1 != NULL) {
            var_r1 += 4;
        }
        M2C_FIELD(arg0, void **, 0x18) = var_r1;
        M2C_FIELD(var_r0, s32 *, 4) = 0;
        M2C_FIELD(var_r0, s32 *, 8) = 0;
        M2C_FIELD(var_r0, s32 *, 0xC) = 0;
        M2C_FIELD(var_r0, s32 *, 0x10) = 0;
        M2C_FIELD(var_r0, s32 *, 0x14) = 0;
        M2C_FIELD(arg0, u16 *, 0x1E) = (u16) (M2C_FIELD(arg0, u16 *, 0x1E) - 1);
        return (s32) var_r0;
    }
    func_0205e334(arg0);
    return func_0205e2a4(arg0);
}
