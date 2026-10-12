#include "m2c.h"

M2C_UNK func_0205df94();                            /* extern */
M2C_UNK func_0205e84c(M2C_UNK **);                  /* extern */
extern M2C_UNK data_020fe6a0;

M2C_UNK **func_0205df4c(M2C_UNK **arg0) {
    *arg0 = &data_020fe6a0;
    func_0205df94();
    func_0205e84c(arg0);
    return arg0;
}
