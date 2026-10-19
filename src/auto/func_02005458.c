/* Reconstructed from USA ARM9 at 0x02005458 (188 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"
s32 func_02093534();
M2C_UNK func_0209d08c();
extern M2C_UNK data_02106d90;
extern M2C_UNK data_0210930c;
void func_02005458(void *arg0, void *arg1) {
    s32 temp_r2;
    s32 temp_r1;
    s32 temp_r1_2;
    u16 temp_r0;
    s32 temp_r4;
    temp_r4 = M2C_FIELD(arg0, u8 *, 0x5DA);
    if ((temp_r4 != 4) && (arg1 != NULL)) {
        temp_r2 = func_02093534(&data_0210930c, arg1);
        if (temp_r2 != -1) {
            func_0209d08c(M2C_FIELD(M2C_FIELD(&data_02106d90, void **, 0xAD0), s32 *, 0x10), (u8) temp_r4, temp_r2);
            return;
        }
        temp_r0 = M2C_FIELD(arg1, u16 *, 0xC);
        if (temp_r0 == 0x10) {
            temp_r1 = M2C_FIELD(arg1, s32 *, 0x1BC);
            if (temp_r1 >= 4) {
                return;
            }
            func_0209d08c(M2C_FIELD(M2C_FIELD(&data_02106d90, void **, 0xAD0), s32 *, 0x10), (u8) temp_r4, (s8) temp_r1);
            return;
        }
        if (temp_r0 == 0x8000) {
            temp_r1_2 = M2C_FIELD(arg1, s32 *, 0x1BC);
            if (temp_r1_2 >= 4) {
                return;
            }
            func_0209d08c(M2C_FIELD(M2C_FIELD(&data_02106d90, void **, 0xAD0), s32 *, 0x10), (u8) temp_r4, (s8) temp_r1_2);
        }
    }
}
