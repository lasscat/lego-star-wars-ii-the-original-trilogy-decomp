/* Reconstructed from USA ARM9 at 0x02055ba4 (68 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_02055d34(s32, M2C_UNK, M2C_UNK, s32);  /* extern */
s32 func_0205ab44();                                /* extern */
extern M2C_UNK data_02101efc;

void func_02055ba4(s32 arg0, s32 arg1, M2C_UNK arg2, M2C_UNK arg3, s32 arg4) {
    s32 t;

    t = func_0205ab44();
    func_02055d34(t + arg1, arg2, arg3, (arg4 * 0x408) + (s32) &data_02101efc + 0x204);
}
