#include "m2c.h"

M2C_UNK func_020613e8(M2C_UNK *);                   /* extern */
M2C_UNK func_02063b94(M2C_UNK *);                   /* extern */
M2C_UNK func_020680fc(M2C_UNK *);                   /* extern */
s32 func_020867ec(s32 *, M2C_UNK);                  /* extern */
M2C_UNK func_0208b0b8(void *);                      /* extern */
M2C_UNK func_0208cecc(void *);                      /* extern */
M2C_UNK func_02090c1c(M2C_UNK *);                   /* extern */
s32 func_02093bd8(M2C_UNK *);                       /* extern */
M2C_UNK func_020b352c(M2C_UNK *);                   /* extern */
M2C_UNK func_020b9c90(M2C_UNK *);                   /* extern */
extern M2C_UNK data_02102900;
extern M2C_UNK data_02104434;
extern s32 data_02104d90;
extern M2C_UNK data_0210930c;
extern M2C_UNK data_0210db30;
extern s32 data_027e02a8;
extern M2C_UNK data_027e03a0;
extern M2C_UNK data_027e0864;
extern M2C_UNK data_027e0bd0;

void func_0208cdb0(void *arg0) {
    s32 var_r0;

    if (data_027e02a8 & 3) {
        return;
    }
    if ((func_020867ec(&data_02104d90, 2) != 0) || (data_02104d90 & 2)) {
        func_020613e8(&data_027e03a0);
    }
    func_02090c1c(&data_0210930c);
    func_020680fc(&data_027e0864);
    func_020b352c(&data_027e0bd0);
    if (M2C_FIELD(arg0, s32 *, 8) != 0x10) {
        func_0208b0b8(arg0 + 0x2C);
    }
    func_02063b94(&data_02104434);
    func_020b9c90(&data_0210db30);
    if (M2C_FIELD(&data_02102900, void **, 4) != NULL) {
        var_r0 = M2C_FIELD(M2C_FIELD(&data_02102900, void **, 4), s32 *, 4);
    } else {
        var_r0 = 0;
    }
    if (var_r0 == 0x1E) {
        return;
    }
    if (func_02093bd8(&data_0210930c) == 0) {
        return;
    }
    func_0208cecc(arg0);
}
