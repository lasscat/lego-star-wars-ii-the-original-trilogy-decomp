/* compiler: 2.0/sp1p5 -O2 */
#include "m2c.h"

M2C_UNK MB_DisconnectChild(u16);                    /* extern */
M2C_UNK OS_DisableInterrupts();                     /* extern */
M2C_UNK OS_RestoreInterrupts();                     /* extern */
M2C_UNK func_020afcac(M2C_UNK);                     /* extern */
s32 func_020b01e0(u16);                             /* extern */
extern M2C_UNK data_0210da80;

void func_020affbc(void) {
    M2C_UNK m2c_irq;
    u16 temp_r0;
    u16 var_r5;

    func_020afcac(3);
    var_r5 = 1;
    do {
        if ((M2C_FIELD(&data_0210da80, u16 *, 0xA) & (1 << var_r5)) && (func_020b01e0(var_r5) == 1)) {
            temp_r0                                = ~(1 << var_r5);
            m2c_irq                                = OS_DisableInterrupts();
            M2C_FIELD(&data_0210da80, u16 *, 0xA)  = (u16) (M2C_FIELD(&data_0210da80, u16 *, 0xA) & temp_r0);
            M2C_FIELD(&data_0210da80, u16 *, 0xC)  = (u16) (M2C_FIELD(&data_0210da80, u16 *, 0xC) & temp_r0);
            M2C_FIELD(&data_0210da80, u16 *, 0xE)  = (u16) (M2C_FIELD(&data_0210da80, u16 *, 0xE) & temp_r0);
            M2C_FIELD(&data_0210da80, u16 *, 0x10) = (u16) (M2C_FIELD(&data_0210da80, u16 *, 0x10) & temp_r0);
            M2C_FIELD(&data_0210da80, u16 *, 0x12) = (u16) (M2C_FIELD(&data_0210da80, u16 *, 0x12) & temp_r0);
            M2C_FIELD(&data_0210da80, u16 *, 0x14) = (u16) (M2C_FIELD(&data_0210da80, u16 *, 0x14) & temp_r0);
            OS_RestoreInterrupts(m2c_irq);
            MB_DisconnectChild(var_r5);
        }
        var_r5 += 1;
    } while ((u32) var_r5 < 0x10U);
}
