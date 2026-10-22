#include "m2c.h"

extern M2C_UNK func_020184a0(M2C_UNK, M2C_UNK);
extern M2C_UNK func_020b973c(M2C_UNK);
extern M2C_UNK data_020fdd84;
extern M2C_UNK data_02101ae4;

typedef struct {
    void *vptr;
    u8 pad[0x20];
    s32 f_24;
    s32 f_28;
    s32 f_2c;
} Obj;

Obj *func_0202f9f4(Obj *arg0) {
    arg0->vptr = &data_020fdd84;
    if (arg0->f_24) {
        func_020184a0((M2C_UNK) &data_02101ae4, arg0->f_24);
        arg0->f_24 = 0;
    }
    if (arg0->f_28) {
        func_020184a0((M2C_UNK) &data_02101ae4, arg0->f_28);
        arg0->f_28 = 0;
    }
    if (arg0->f_2c) {
        func_020b973c(arg0->f_2c);
        arg0->f_2c = 0;
    }
    return arg0;
}
