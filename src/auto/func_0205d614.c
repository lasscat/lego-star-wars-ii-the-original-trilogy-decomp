#include "m2c.h"

extern void func_0205e068(void *arg0, void *arg1);

void func_0205d614(void *arg0, void *arg1) {
    if (arg1 == 0) {
        return;
    }
    if (M2C_FIELD(arg1, void **, 8) != 0) {
        M2C_FIELD(M2C_FIELD(arg1, void **, 8), void **, 4) = M2C_FIELD(arg1, void **, 4);
    }
    if (M2C_FIELD(arg1, void **, 4) != 0) {
        M2C_FIELD(M2C_FIELD(arg1, void **, 4), void **, 8) = M2C_FIELD(arg1, void **, 8);
    }
    if (arg1 == M2C_FIELD(arg0, void **, 4)) {
        M2C_FIELD(arg0, void **, 4) = M2C_FIELD(arg1, void **, 4);
    }
    if (arg1 == M2C_FIELD(arg0, void **, 8)) {
        M2C_FIELD(arg0, void **, 8) = M2C_FIELD(arg1, void **, 8);
    }
    func_0205e068(M2C_FIELD(arg0, void **, 0x10), arg1);
}
