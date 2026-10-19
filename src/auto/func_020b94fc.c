#include "m2c.h"

M2C_UNK func_020b3c1c();                            /* extern */
s32 SND_RecvCommandReply(M2C_UNK);                         /* extern */
M2C_UNK SND_FlushCommand(M2C_UNK);                     /* extern */
extern M2C_UNK data_0210db14;

#define REG_IME (*(volatile u16 *) 0x04000208)

u32 func_020b94fc(void) {
    u16 temp_r0;
    u8 temp_r2;

    if (!(M2C_FIELD(&data_0210db14, u8 *, 0xA) & 0x80)) {
        return (u32) &data_0210db14;
    }
    temp_r2 = REG_IME;
    REG_IME = 0;
    if (M2C_FIELD(&data_0210db14, u8 *, 0xB) != 0) {
        do {

        } while (SND_RecvCommandReply(0) != 0);
        func_020b3c1c();
        SND_FlushCommand(2);
        M2C_FIELD(&data_0210db14, u8 *, 0xB) = 0U;
    }
    M2C_FIELD(&data_0210db14, u8 *, 0xA) = (u8) (M2C_FIELD(&data_0210db14, u8 *, 0xA) & ~0x80);
    temp_r0                              = REG_IME;
    REG_IME                              = temp_r2;
    return temp_r0;
}
