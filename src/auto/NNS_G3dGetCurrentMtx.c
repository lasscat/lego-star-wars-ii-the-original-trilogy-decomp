#include "m2c.h"

M2C_UNK NNS_G3dGeFlushBuffer();                            /* extern */
M2C_UNK MTX_Copy44To43_(M2C_UNK *, s32);              /* extern */
s32 G3X_GetClipMtx(M2C_UNK *);                       /* extern */
s32 G3X_GetVectorMtx(s32);                             /* extern */

void NNS_G3dGetCurrentMtx(s32 arg0, s32 arg1) {
    u8 sp0[64];

    NNS_G3dGeFlushBuffer();
    M2C_FIELD((void *) 0x04000440, s32 *, 0)    = 0;
    M2C_FIELD((void *) 0x04000440, s32 *, 4)    = 0;
    M2C_FIELD((void *) 0x04000440, s32 *, 0x14) = 0;
    if (arg0 != 0) {
        do {

        } while (G3X_GetClipMtx(sp0) != 0);
        MTX_Copy44To43_(sp0, arg0);
    }
    if (arg1 != 0) {
        do {

        } while (G3X_GetVectorMtx(arg1) != 0);
    }
    M2C_FIELD((void *) 0x04000448, s32 *, 0)  = 1;
    M2C_FIELD((void *) 0x04000448, s32 *, -8) = 2;
}
