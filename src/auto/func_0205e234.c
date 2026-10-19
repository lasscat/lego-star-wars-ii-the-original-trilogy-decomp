#include "m2c.h"

M2C_UNK func_0205dfe8(void *);                               /* extern */
M2C_UNK func_020e4858(s32, M2C_UNK, M2C_UNK, M2C_UNK *);     /* extern */
extern M2C_UNK func_0205ded0;

void func_0205e234(void *arg0) {
    s32 *arr = (s32 *) arg0;
    s32 i    = 0;

    if ((s32) M2C_FIELD(arg0, u8 *, 0x22) > 0) {
        do {
            s32 t = arr[i + 9];
            if (t != 0) {
                func_020e4858(t, 0x18, 8, &func_0205ded0);
            }
            arr[i + 9] = 0;
            i += 1;
        } while (i < (s32) M2C_FIELD(arg0, u8 *, 0x22));
    }
    func_0205dfe8(arg0);
}
