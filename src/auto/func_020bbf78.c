#include "m2c.h"

M2C_UNK func_020c099c(void *);                      /* extern */
void *func_020c0fd0(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK data_0211179c;

void func_020bbf78(void *arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
    void *temp;

    temp = M2C_FIELD(arg0, void **, 0x64);
    if (temp != NULL) {
        M2C_FIELD(temp, s32 *, 0x10) = M2C_FIELD(temp, s32 *, 0x10) - 1;
        if ((M2C_FIELD(temp, s32 *, 0xC) == 0) && (M2C_FIELD(temp, s32 *, 0x10) == 0)) {
            func_020c099c(temp);
        }
    }
    temp                           = func_020c0fd0(&data_0211179c, arg1, arg2, arg3);
    M2C_FIELD(arg0, void **, 0x64) = temp;
    M2C_FIELD(temp, s32 *, 0x10)   = M2C_FIELD(temp, s32 *, 0x10) + 1;
}
