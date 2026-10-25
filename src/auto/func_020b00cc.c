#include "m2c.h"

s32 func_020d89bc(u16, s32);                            /* extern */
s32 OS_DisableInterrupts(void);                         /* extern */
void OS_RestoreInterrupts(s32);                         /* extern */
void MB_DisconnectChild(u16);                           /* extern */
void func_020afcac(s32);                                /* extern */
extern M2C_UNK data_0210da80;

void func_020b00cc(void) {
    u16 var_r7;
    u16 var_r8;
    s32 temp_r0;
    u16 mask;

    var_r8 = 0;
    for (var_r7 = 1; var_r7 < 0x10U; var_r7++) {
        if (M2C_FIELD(&data_0210da80, u16 *, 0x12) & (1 << var_r7)) {
            if (func_020d89bc(var_r7, 3) == 0) {
                mask    = ~(1 << var_r7);
                temp_r0 = OS_DisableInterrupts();
                M2C_FIELD(&data_0210da80, u16 *, 0xA) &= mask;
                M2C_FIELD(&data_0210da80, u16 *, 0xC) &= mask;
                M2C_FIELD(&data_0210da80, u16 *, 0xE) &= mask;
                M2C_FIELD(&data_0210da80, u16 *, 0x10) &= mask;
                M2C_FIELD(&data_0210da80, u16 *, 0x12) &= mask;
                M2C_FIELD(&data_0210da80, u16 *, 0x14) &= mask;
                OS_RestoreInterrupts(temp_r0);
                MB_DisconnectChild(var_r7);
            } else {
                var_r8 |= 1 << var_r7;
            }
        }
    }
    if (var_r8 == 0) {
        func_020afcac(7);
    } else {
        func_020afcac(4);
    }
}
