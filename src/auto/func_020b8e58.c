#include "m2c.h"

M2C_UNK func_020b3c1c();                            /* extern */
s32 SND_RecvCommandReply(M2C_UNK);                         /* extern */
M2C_UNK SND_FlushCommand(M2C_UNK);                     /* extern */
M2C_UNK CP_SaveContext(M2C_UNK *);                   /* extern */
M2C_UNK CPi_RestoreContext(M2C_UNK *);                   /* extern */
extern s32 data_0210daf0;
extern M2C_UNK data_0210db14;

void func_020b8e58(void) {
    u8 sp0[28];
    s32 temp_r5;

    if (M2C_FIELD(&data_0210db14, u8 *, 0xA) & 0x80) {
        M2C_FIELD(&data_0210db14, s8 *, 0xB) = 1;
        return;
    }
    temp_r5 = data_0210daf0;
    CP_SaveContext(sp0);
    do {

    } while (SND_RecvCommandReply(0) != 0);
    func_020b3c1c();
    SND_FlushCommand(2);
    CPi_RestoreContext(sp0);
    data_0210daf0 = temp_r5;
}
