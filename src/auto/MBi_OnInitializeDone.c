#include "m2c.h"

s32 WM_SetIndCallback(M2C_UNK *);                       /* extern */
s32 WM_SetLifeTime(M2C_UNK *, u16, u16, u16, s32);   /* extern */
M2C_UNK MBi_CheckWmErrcode(M2C_UNK, s32);                /* extern */
extern M2C_UNK mbi_life_frame;
extern M2C_UNK MBi_ParentCallback;

void MBi_OnInitializeDone(void) {
    MBi_CheckWmErrcode(0x80, WM_SetIndCallback(&MBi_ParentCallback));
    MBi_CheckWmErrcode(0x1D, WM_SetLifeTime(&MBi_ParentCallback, M2C_FIELD(&mbi_life_frame, u16 *, 6),
                                            M2C_FIELD(&mbi_life_frame, u16 *, 2), M2C_FIELD(&mbi_life_frame, u16 *, 0),
                                            (s32) M2C_FIELD(&mbi_life_frame, u16 *, 4)));
}
