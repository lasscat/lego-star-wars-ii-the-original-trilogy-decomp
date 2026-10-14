#include "m2c.h"

M2C_UNK func_020671dc();                            /* extern */
M2C_UNK func_020672a4(void *, s32, void *);         /* extern */
M2C_UNK func_02067378(void *, s32, void *);         /* extern */
M2C_UNK func_02067440(void *, s32, void *);         /* extern */
M2C_UNK func_02067508(void *, s32, void *);         /* extern */

void func_02067154(void *arg0, s32 arg1, void *arg2, s8 arg3) {
    M2C_FIELD(arg0, s32 *, 0)    = arg1;
    M2C_FIELD(arg0, s16 *, 0x18) = (s16) M2C_FIELD(arg2, u8 *, 2);
    M2C_FIELD(arg0, s16 *, 0x1A) = (s16) M2C_FIELD(arg2, u8 *, 3);
    M2C_FIELD(arg0, s16 *, 0x1E) = (s16) M2C_FIELD(arg2, u8 *, 6);
    M2C_FIELD(arg0, s16 *, 0x1C) = (s16) M2C_FIELD(arg2, u8 *, 4);
    M2C_FIELD(arg0, s16 *, 0x20) = (s16) M2C_FIELD(arg2, u8 *, 5);
    M2C_FIELD(arg0, s8 *, 0x22)  = arg3;
    func_020671dc(arg0, arg1, arg2);
    func_020672a4(arg0, arg1, arg2);
    func_02067378(arg0, arg1, arg2);
    func_02067440(arg0, arg1, arg2);
    func_02067508(arg0, arg1, arg2);
}
