#include "m2c.h"

extern M2C_UNK data_02101b82;
extern M2C_UNK data_02101b94;

void func_020538c0(void *arg0, s32 arg1) {
    s32 idx;
    s32 bit;
    u16 *p;

    idx = M2C_FIELD(arg0, s32 *, 0);
    if (arg1 != 0) {
        p   = (u16 *) ((s8 *) &data_02101b82 + (idx << 5));
        bit = M2C_FIELD(arg0, s32 *, 4);
        *p  = (u16) (*p | (1 << bit));
        idx = M2C_FIELD(arg0, s32 *, 0);
        M2C_FIELD((s8 *) &data_02101b94 + (idx << 5), u8 *, 0) =
            (u8) (M2C_FIELD((s8 *) &data_02101b94 + (idx << 5), u8 *, 0) | 4);
        return;
    }
    p                                                      = (u16 *) ((s8 *) &data_02101b82 + (idx << 5));
    bit                                                    = M2C_FIELD(arg0, s32 *, 4);
    *p                                                     = (u16) (*p | ~(1 << bit));
    idx                                                    = M2C_FIELD(arg0, s32 *, 0);
    M2C_FIELD((s8 *) &data_02101b94 + (idx << 5), u8 *, 0) = (u8) (M2C_FIELD((s8 *) &data_02101b94 + (idx << 5), u8 *, 0) | 4);
}
