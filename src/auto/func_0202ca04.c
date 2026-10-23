#include "m2c.h"

u16 func_0202ca04(void *, void *);                 /* extern */

u16 func_0202ca04(void *arg0, void *arg1) {
    u16 var_r4 = 0;
    void *var_r1;

    if (arg1 == NULL) {
        return 0;
    }
    var_r1 = M2C_FIELD(arg1, void **, 8);
    if (var_r1 != NULL) {
        if (var_r1 != NULL) {
            var_r1 = (void *) ((s8 *) var_r1 - 4);
        }
        var_r4 += func_0202ca04(arg0, var_r1);
    }
    if (M2C_FIELD(arg1, void **, 0x10) != 0) {
        var_r4 += func_0202ca04(arg0, M2C_FIELD(arg1, void **, 0x10));
    }
    return (u16) (var_r4 + 1);
}
