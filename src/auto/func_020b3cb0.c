#include "m2c.h"

M2C_UNK func_020b4080(s32);                         /* extern */
extern void *data_0210daf0;
extern void *data_0210daf4[];

void func_020b3cb0(void) {
    s32 var_r6;
    void *temp_r1;

    for (var_r6 = 2; var_r6 >= 0; var_r6--) {
        temp_r1 = data_0210daf4[var_r6 + 2];
        if ((temp_r1 != NULL) && (*((u8 *) temp_r1 + 0x25) == 0)) {
            data_0210daf0 = temp_r1;
            func_020b4080(var_r6);
        }
    }
    data_0210daf0 = NULL;
}
