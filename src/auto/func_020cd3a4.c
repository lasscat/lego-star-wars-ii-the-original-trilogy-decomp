#include "m2c.h"

M2C_UNK func_020cd400(s32);                         /* extern */
M2C_UNK func_020cd7bc(void *, M2C_UNK (*)(s32));    /* extern */
M2C_UNK func_020cd874(void *);                      /* extern */
extern M2C_UNK data_02115424;

void func_020cd3a4(void *arg0, s32 arg1) {
    if (M2C_FIELD(&data_02115424, s32 *, 0x1C) != 0) {
        func_020cd7bc(arg0, func_020cd400);
        M2C_FIELD(arg0, s32 *, 4)    = arg1;
        M2C_FIELD(arg0, s32 *, 0)    = (s32) (M2C_FIELD(arg0, s32 *, 0) | 0x80);
        M2C_FIELD(arg0, s32 *, 0x64) = 1;
        func_020cd874(arg0);
        return;
    }
    func_020cd400(arg1);
}
