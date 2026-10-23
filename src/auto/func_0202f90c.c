#include "m2c.h"

extern M2C_UNK data_020fdd84;
extern M2C_UNK data_02101ae4;
M2C_UNK func_020184a0(void *, void *);             /* extern */
M2C_UNK func_020b973c(void *);                     /* extern */

void *func_0202f90c(void *arg0) {
    M2C_FIELD(arg0, void **, 0x0) = &data_020fdd84;
    if (M2C_FIELD(arg0, void **, 0x24) != 0) {
        func_020184a0(&data_02101ae4, M2C_FIELD(arg0, void **, 0x24));
        M2C_FIELD(arg0, void **, 0x24) = 0;
    }
    if (M2C_FIELD(arg0, void **, 0x28) != 0) {
        func_020184a0(&data_02101ae4, M2C_FIELD(arg0, void **, 0x28));
        M2C_FIELD(arg0, void **, 0x28) = 0;
    }
    if (M2C_FIELD(arg0, void **, 0x2c) != 0) {
        func_020b973c(M2C_FIELD(arg0, void **, 0x2c));
        M2C_FIELD(arg0, void **, 0x2c) = 0;
    }
    return arg0;
}
