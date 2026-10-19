#include "m2c.h"

M2C_UNK func_020aaf54(s32);                         /* extern */
M2C_UNK NNS_G3dRenderObjInit(void *, void *);              /* extern */

void func_020acbc4(void *arg0) {
    void *temp_r2;

    func_020aaf54(arg0 + 4);
    temp_r2 = M2C_FIELD(arg0, void **, 8);
    NNS_G3dRenderObjInit(arg0 + 0x20, temp_r2 + M2C_FIELD((temp_r2 + M2C_FIELD(temp_r2, u16 *, 0xE)), s32 *, 0xC));
    M2C_FIELD(arg0, s8 *, 0x1C) = 1;
}
