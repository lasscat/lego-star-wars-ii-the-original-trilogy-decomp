#include "m2c.h"

M2C_UNK func_0205e84c(void *);                      /* extern */
M2C_UNK func_020b9068(s32);                         /* extern */
M2C_UNK func_020b96ec(void *);                      /* extern */

void func_020b973c(void *arg0) {
    func_020b9068(M2C_FIELD(arg0, s32 *, 0x14));
    if (arg0 == NULL) {
        return;
    }
    func_020b96ec(arg0);
    func_0205e84c(arg0);
}
