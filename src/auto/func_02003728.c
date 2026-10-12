#include "m2c.h"

M2C_UNK func_0200c22c(void *);                      /* extern */
M2C_UNK func_0202beb0(void *);                      /* extern */
M2C_UNK func_020b9068(s32);                         /* extern */
s32 func_020b9304(s32);                             /* extern */
extern M2C_UNK data_020fccc8;
extern void *data_027e0308;

void *func_02003728(void *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fccc8;
    if (func_020b9304(M2C_FIELD(arg0, s32 *, 0x6E4)) != 0) {
        func_020b9068(M2C_FIELD(arg0, s32 *, 0x6E4));
    }
    M2C_FIELD(data_027e0308, M2C_UNK (**)(void **, void *), 0xC)(&data_027e0308, arg0);
    func_0202beb0(arg0 + 0x5E0);
    func_0200c22c(arg0);
    return arg0;
}
