#include "m2c.h"
M2C_UNK func_020cd4e4(void *);
M2C_UNK func_020cdca0(s32, void *);
s32 func_020ce804();
M2C_UNK func_020ce818(s32);
extern M2C_UNK data_02115448;
void func_020cdb70(void *arg0) {
    s32 temp = func_020ce804();
    s32 d    = M2C_FIELD(&data_02115448, s32 *, 4);
    if (M2C_FIELD(arg0, s32 *, 8) == d) {
        s32 n                       = M2C_FIELD(arg0, s32 *, 0xC) - 1;
        M2C_FIELD(arg0, s32 *, 0xC) = n;
        if (n == 0) {
            func_020cdca0(d, arg0);
            M2C_FIELD(arg0, s32 *, 8) = 0;
            func_020cd4e4(arg0);
        }
    }
    func_020ce818(temp);
}