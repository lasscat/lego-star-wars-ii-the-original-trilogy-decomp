#include "m2c.h"

M2C_UNK __exit(M2C_UNK);                     /* extern */
M2C_UNK __destroy_global_chain();                            /* extern */
extern M2C_UNK __console_exit;

void exit(M2C_UNK arg0) {
    if (M2C_FIELD(&__console_exit, s32 *, 0xC) == 0) {
        __destroy_global_chain();
        if (M2C_FIELD(&__console_exit, M2C_UNK(**)(), 4) != NULL) {
            M2C_FIELD(&__console_exit, M2C_UNK(**)(), 4)();
            M2C_FIELD(&__console_exit, M2C_UNK(**)(), 4) = NULL;
        }
    }
    __exit(arg0);
}
