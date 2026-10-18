/* Reconstructed from USA ARM9 at 0x02017e3c (76 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_0206769c(s32, u8, u8);                 /* extern */
extern M2C_UNK data_0210930c;

void func_02017e3c(void *arg0) {
    s32 var_r1;

    if (!((M2C_FIELD(arg0, volatile u8 *, 0x88) != 0xFF) && (M2C_FIELD(arg0, volatile u8 *, 0x89) != 0))) {
        var_r1 = 0;
    } else {
        var_r1 = 1;
    }
    if (var_r1 == 0) {
        return;
    }
    func_0206769c(M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0210930c, void **, 0x68), void **, 0x38C), s32 *, 4) + 0x28,
                  M2C_FIELD(arg0, volatile u8 *, 0x88), M2C_FIELD(arg0, volatile u8 *, 0x89));
}
