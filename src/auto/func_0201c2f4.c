#include "m2c.h"

M2C_UNK func_0201ad00(void *);                      /* extern */
extern M2C_UNK data_020fd164;

void *func_0201c2f4(void *arg0) {
    s32 temp_r1;
    void *temp_r0;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fd164;
    temp_r0                        = M2C_FIELD(arg0, void **, 0x80);
    if (temp_r0 != NULL) {
        temp_r1                      = M2C_FIELD(temp_r0, s32 *, 4) - 1;
        M2C_FIELD(temp_r0, s32 *, 4) = temp_r1;
        if ((temp_r1 == 0) && (temp_r0 != NULL)) {
            M2C_FIELD(M2C_FIELD(temp_r0, void **, 0), M2C_UNK(**)(), 4)(temp_r0);
        }
    }
    func_0201ad00(arg0);
    return arg0;
}
