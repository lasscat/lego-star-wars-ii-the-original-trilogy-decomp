#include "m2c.h"

M2C_UNK func_0205df74(M2C_UNK **);                  /* extern */
M2C_UNK func_0205e234();                            /* extern */
extern M2C_UNK data_020fe6c0;

M2C_UNK **func_0205e1dc(M2C_UNK **arg0) {
    *arg0 = &data_020fe6c0;
    func_0205e234();
    func_0205df74(arg0);
    return arg0;
}
