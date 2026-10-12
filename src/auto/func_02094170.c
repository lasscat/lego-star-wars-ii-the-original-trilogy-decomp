#include "m2c.h"

s32 func_02086204(M2C_UNK *, u8);                   /* extern */
M2C_UNK func_020940c4(void *);                      /* extern */
extern M2C_UNK data_02104d90;

void func_02094170(void *arg0) {
    if (func_02086204(&data_02104d90, M2C_FIELD(arg0, u8 *, 9)) == 0) {
        return;
    }
    func_020940c4(arg0);
}
