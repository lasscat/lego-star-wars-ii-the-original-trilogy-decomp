#include "m2c.h"

M2C_UNK func_020540cc(void *, u16, u16);            /* extern */
M2C_UNK func_020540e4(void *, u16, u16);            /* extern */
extern M2C_UNK data_02101b78;

void func_02067ca0(void *arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4) {
    s32 temp_ip;

    temp_ip = M2C_FIELD(arg0, s32 *, 4);
    switch (temp_ip) {                              /* irregular */
    case 0:
        func_020540cc((M2C_UNK *)((s8 *)&data_02101b78 + (M2C_FIELD(arg0, s32 *, 0) << 5)), (u16) (arg3 | (arg1 << 8)), (u16) (arg4 | (arg2 << 8)));
        return;
    case 1:
        func_020540e4((M2C_UNK *)((s8 *)&data_02101b78 + (M2C_FIELD(arg0, s32 *, 0) << 5)), (u16) (arg3 | (arg1 << 8)), (u16) (arg4 | (arg2 << 8)));
        return;
    }
}
