/* Reconstructed from USA ARM9 at 0x02056fac (184 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_0205ecc4(); /* extern */
s32 func_02086534();                  /* extern */
extern M2C_UNK data_02102900;
extern M2C_UNK data_02104d90;

void func_02056fac(void) {
    s32 var_r5;

    for (var_r5 = 0; var_r5 < 3; var_r5++) {
        if (func_02086534(&data_02104d90, var_r5 + 0x49) != 0) {
            func_0205ecc4(&data_02102900, 0x1F, 0, 0, 0, 0);
            func_0205ecc4(&data_02102900, 0xB, 1, 0, 0, 0);
            return;
        }
    }
    func_0205ecc4(&data_02102900, 9, 0, 0, 0, 0);
    func_0205ecc4(&data_02102900, 0xA, 1, 0, 0, 0);
}
