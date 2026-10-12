#include "m2c.h"

M2C_UNK func_0205df74(M2C_UNK **);                  /* extern */
M2C_UNK func_0205e234();                            /* extern */
M2C_UNK func_0205e84c(M2C_UNK **);                  /* extern */
extern M2C_UNK data_020fe6c0;

M2C_UNK **func_0205e204(M2C_UNK **arg0) {
    *arg0 = &data_020fe6c0;
    func_0205e234();
    func_0205df74(arg0);
    func_0205e84c(arg0);
    return arg0;
}
