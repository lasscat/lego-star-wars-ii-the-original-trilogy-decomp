#include "m2c.h"

M2C_UNK func_02065600(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK MIi_LockCard();                            /* extern */
M2C_UNK MIi_UnlockCard();                            /* extern */
s32 CARDi_ReadRomID();                                /* extern */
M2C_UNK CARD_SetPulledOutCallback(M2C_UNK *);                   /* extern */
extern M2C_UNK data_02101d78;
extern M2C_UNK data_02101d8c;
extern s32 data_027e02a8;
extern M2C_UNK func_0205509c;

void func_02054e08(void) {
    CARD_SetPulledOutCallback(&func_0205509c);
    data_027e02a8 |= 0x800;
    MIi_LockCard();
    M2C_FIELD(&data_02101d78, s32 *, 4) = CARDi_ReadRomID();
    MIi_UnlockCard();
    func_02065600(&data_02101d8c, 2);
}
