/* Reconstructed from USA ARM9 at 0x0208bb5c (124 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_0205a060(s32);                         /* extern */
M2C_UNK func_0205a3e8(s32, void *, M2C_UNK);        /* extern */
M2C_UNK func_0205aa40(s32);                         /* extern */
M2C_UNK func_0205aa74(s32, s32);                    /* extern */
s32 func_0205ab44(u16);                             /* extern */
extern M2C_UNK data_020ef57c;
extern M2C_UNK data_020ef588;

void func_0208bb5c(void *arg0, s32 arg1) {
    s32 temp_r5;
    s32 temp_r5_2;

    if (M2C_FIELD(arg0, s32 *, 0x78) & 0x14) {
        return;
    }
    temp_r5 = arg1 * 0x18;
    func_0205a3e8(M2C_FIELD(M2C_FIELD(arg0, void **, 0x58), s32 *, 0xD4), (s8 *) &data_020ef57c + temp_r5 + 8, 0);
    temp_r5_2 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x58), s32 *, 0xD8);
    func_0205aa74(temp_r5_2, func_0205ab44(*(u16 *) ((s8 *) &data_020ef588 + temp_r5)));
    func_0205aa40(M2C_FIELD(M2C_FIELD(arg0, void **, 0x58), s32 *, 0xD8));
    func_0205a060(M2C_FIELD(M2C_FIELD(arg0, void **, 0x58), s32 *, 0xD4));
}
