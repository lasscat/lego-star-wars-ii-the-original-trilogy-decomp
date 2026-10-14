#include "m2c.h"

M2C_UNK func_0202f9f4(void *);                      /* extern */
M2C_UNK func_0204a0c4(void *);                      /* extern */
M2C_UNK func_0205e84c(void *);                      /* extern */
extern M2C_UNK data_020fe3cc;

void *func_02048984(void *arg0) {
    void *temp_r4;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fe3cc;
    temp_r4                        = M2C_FIELD(arg0, void **, 0x34);
    if (temp_r4 != NULL) {
        func_0204a0c4(temp_r4);
        func_0205e84c(temp_r4);
    }
    M2C_FIELD(arg0, void **, 0x34) = NULL;
    func_0202f9f4(arg0);
    func_0205e84c(arg0);
    return arg0;
}
