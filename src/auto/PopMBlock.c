#include "m2c.h"

M2C_UNK *PopMBlock(M2C_UNK **arg0) {
    M2C_UNK *temp_r2;

    temp_r2 = *arg0;
    if (temp_r2 != NULL) {
        *arg0 = *temp_r2;
    }
    return temp_r2;
}
