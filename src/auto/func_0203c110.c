#include "m2c.h"

void func_0205e84c(void *);
extern M2C_UNK data_020fe1b0;

void *func_0203c110(void *arg0) {
    void *temp_r0;
    void *temp_r1;
    void *temp_r2;

    M2C_FIELD(arg0, M2C_UNK **, 0)                       = &data_020fe1b0;
    M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0x690) = 0;
    temp_r0                                              = M2C_FIELD(arg0, void **, 0x10);
    if (temp_r0 != NULL) {
        temp_r1 = M2C_FIELD(temp_r0, void **, 4);
        if (temp_r1 != NULL) {
            if (temp_r1 != NULL) {
                M2C_FIELD(temp_r1, s8 *, 0x5D6) = 0;
                temp_r2                         = M2C_FIELD(temp_r0, void **, 4);
                M2C_FIELD(temp_r2, s32 *, 8)    = M2C_FIELD(temp_r2, s32 *, 8) | 0x20;
            }
            M2C_FIELD(temp_r0, void **, 4) = NULL;
        }
        func_0205e84c(temp_r0);
    }
    func_0205e84c(arg0);
    return arg0;
}
