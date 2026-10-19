#include "m2c.h"

M2C_UNK CARD_LockRom(u16);                         /* extern */
M2C_UNK CARD_UnlockRom(u16);                         /* extern */
extern s32 fsi_card_lock_id;

s32 FSi_RomArchiveProc(s32 arg0, s32 arg1) {
    switch (arg1) {                                 /* irregular */
        case 9:
            CARD_LockRom((u16) fsi_card_lock_id);
            return 0;
        case 10:
            CARD_UnlockRom((u16) fsi_card_lock_id);
            return 0;
        case 1:
            return 4;
        default:
            return 8;
    }
}
