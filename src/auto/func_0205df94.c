#include "m2c.h"
void func_0205dfe8(void *);
void func_0205e860(s32);
void func_0205df94(void *arg0) {
    s32 i = 0;
    u32 z = 0;
    if ((s32) M2C_FIELD(arg0, u8 *, 0x22) > 0) {
        do {
            if (((s32 *) arg0)[i + 1] != 0) {
                func_0205e860(((s32 *) arg0)[i + 1]);
            }
            ((s32 *) arg0)[i + 1] = z;
            i += 1;
        } while (i < (s32) M2C_FIELD(arg0, u8 *, 0x22));
    }
    func_0205dfe8(arg0);
}
