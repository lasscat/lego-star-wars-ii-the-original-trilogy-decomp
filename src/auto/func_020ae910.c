#include "m2c.h"
M2C_UNK func_020ad528(M2C_UNK *);
M2C_UNK func_020ad8b4();
s32 func_020addf0(M2C_UNK);
s32 WM_StartConnectEx(M2C_UNK *, M2C_UNK *, M2C_UNK, M2C_UNK, s32);
extern M2C_UNK data_0210022c;
extern M2C_UNK data_02100258;
extern M2C_UNK data_02100270;
extern M2C_UNK data_0210b320;
extern M2C_UNK data_0210b460;
extern M2C_UNK func_020ae9c8;
s32 func_020ae910(void) {
    s32 st;
    s32 t;
    M2C_FIELD(&data_0210b320, s32 *, 0x48) = 0x22;
    M2C_FIELD(&data_0210b320, s32 *, 0x30) = 0;
    st                                     = M2C_FIELD(&data_0210b320, s32 *, 0x20);
    if ((st != 4) && (st != 6) && (st != 5)) {
        goto big;
    }
    func_020ad528(&data_0210022c);
    return 1;
big:
    t = WM_StartConnectEx(&func_020ae9c8, &data_0210b460, 0, 1, 0);
    if (t == 0) {
        return 1;
    }
    if (t != 2) {
        func_020ad8b4();
        return 0;
    }
    if (func_020addf0(0x23) != 0) {
        func_020ad528(&data_02100258);
        return 1;
    }
    func_020ad528(&data_02100270);
    return 0;
}
