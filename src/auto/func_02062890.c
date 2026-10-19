#include "m2c.h"

M2C_UNK func_0205e84c(void *);                      /* extern */
M2C_UNK func_02062718(void *);                      /* extern */

void func_02062890(void *arg0) {
    s32 var_r4;
    u8 temp_r0;
    void *node;
    void *temp_r6;
    void *var_r7;

    var_r7 = arg0;
    var_r4 = 0;
    do {
        node = M2C_FIELD(var_r7, void **, 4);
        if (node != NULL) {
            do {
                temp_r6 = M2C_FIELD(node, void **, 0);
                node    = M2C_FIELD(node, void **, 4);
                temp_r0 = M2C_FIELD(temp_r6, u8 *, 5);
                if ((temp_r0 != 1) && (temp_r0 != 3)) {

                } else if (temp_r6 != NULL) {
                    func_02062718(temp_r6);
                    func_0205e84c(temp_r6);
                }
            } while (node != NULL);
        }
        var_r4 += 1;
        var_r7 += 0x38;
    } while (var_r4 < 2);
}
