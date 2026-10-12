#include "m2c.h"

void *func_0205e80c(s32, M2C_UNK, M2C_UNK);         /* extern */
M2C_UNK func_02061194(M2C_UNK *, s32, void *);      /* extern */
M2C_UNK func_02066fa0(s32);                         /* extern */
M2C_UNK func_02066fc8(s32);                         /* extern */
M2C_UNK func_02083978(void *);                      /* extern */
void *func_0208f760(void *, M2C_UNK, M2C_UNK);      /* extern */
M2C_UNK func_0208fd24(void *);                      /* extern */
M2C_UNK func_020903c4(void *);                      /* extern */
M2C_UNK func_020910bc(void *);                      /* extern */
M2C_UNK func_020917b4(void *);                      /* extern */
M2C_UNK func_0209320c(void *);                      /* extern */
s32 func_02094010();                                /* extern */
M2C_UNK func_0209468c(void *, M2C_UNK);             /* extern */
extern M2C_UNK data_027e03a0;

void func_02090f3c(void *arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 temp_r0;
    void *var_r0;

    var_r0 = func_0205e80c(0x4A8, 3, 4);
    if (var_r0 != NULL) {
        var_r0 = func_0208f760(var_r0, arg1, arg2);
    }
    M2C_FIELD(arg0, void **, 0x68) = var_r0;
    func_020910bc(arg0);
    func_02083978(arg0 + 0x5C4);
    func_02066fa0(M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s32 *, 0x38C));
    func_0209320c(arg0);
    func_02066fc8(M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s32 *, 0x38C));
    func_020903c4(M2C_FIELD(arg0, void **, 0x68));
    func_0208fd24(M2C_FIELD(arg0, void **, 0x68));
    func_0209468c(arg0 + 0xA4, 1);
    func_020917b4(arg0);
    temp_r0 = func_02094010();
    if (temp_r0 != 0xFFFF) {
        func_02061194(&data_027e03a0, temp_r0, arg0 + 0x6C);
    }
    M2C_FIELD(arg0, s8 *, 0x925) = 0;
    M2C_FIELD(arg0, s8 *, 0x92C) = 0;
    M2C_FIELD(arg0, s8 *, 0x92D) = 0;
}
