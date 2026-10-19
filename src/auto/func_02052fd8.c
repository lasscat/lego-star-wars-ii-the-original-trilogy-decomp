#include "m2c.h"

M2C_UNK func_020b8e18();                            /* extern */
M2C_UNK func_020ccf20(u16);                         /* extern */
M2C_UNK CARD_UnlockBackup(u16);                         /* extern */
extern s32 data_02101b74;

void func_02052fd8(void) {
    CARD_UnlockBackup((u16) data_02101b74);
    func_020ccf20((u16) data_02101b74);
    func_020b8e18();
}
