#include "m2c.h"

M2C_UNK func_02017b54(void *);                      /* extern */
M2C_UNK func_0205a044(void *);                      /* extern */
M2C_UNK func_0205a99c(void *);                      /* extern */
M2C_UNK func_0205e84c(void *);                      /* extern */
extern M2C_UNK data_020fd0a0;

void *func_02019b54(void *arg0) {
    void *temp_r4;
    void *temp_r4_2;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fd0a0;
    temp_r4 = M2C_FIELD(arg0, void **, 0xD4);
    if (temp_r4 != NULL) {
        func_0205a044(temp_r4);
        func_0205e84c(temp_r4);
    }
    temp_r4_2 = M2C_FIELD(arg0, void **, 0xD8);
    if (temp_r4_2 != NULL) {
        func_0205a99c(temp_r4_2);
        func_0205e84c(temp_r4_2);
    }
    func_02017b54(arg0);
    func_0205e84c(arg0);
    return arg0;
}
