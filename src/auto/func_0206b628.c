/* Reconstructed from USA ARM9 at 0x0206b628 (204 bytes).
 * data_02104364 is a shared state block; bytes 9 and 0xa hold two volume
 * level bytes.  The function nudges one of them up or down and reports
 * whether the level changed.
 */
#include "m2c.h"

extern M2C_UNK data_02104364;

M2C_UNK func_020b8f70(M2C_UNK, M2C_UNK);
M2C_UNK func_020b8f48(M2C_UNK);
M2C_UNK func_020b8f20(M2C_UNK);

s32 func_0206b628(void *arg0, s32 arg1, s32 arg2) {
    s32 mode    = M2C_FIELD(arg0, s32 *, 0x18);
    s32 v       = M2C_FIELD(&data_02104364, u8 *, 0xa);
    s32 changed = 0;

    if (mode == 1) {
        v = M2C_FIELD(&data_02104364, u8 *, 0x9);
    }
    if (arg1 != 0) {
        if (v != 0) {
            func_020b8f70(0xb6, 0);
            if (arg2 == 0) {
                v = v - 1;
            } else {
                v = 0;
            }
            changed = 1;
        }
    } else {
        if (v < 0x7f) {
            func_020b8f70(0xb6, 0);
            if (arg2 == 0) {
                v = v + 1;
            } else {
                v = 0x7f;
            }
            changed = 1;
        }
    }
    if (M2C_FIELD(arg0, s32 *, 0x18) == 0) {
        if (M2C_FIELD(&data_02104364, u8 *, 0xa) != (u8) v) {
            M2C_FIELD(&data_02104364, u8 *, 0xa) = (u8) v;
            func_020b8f48((u8) v);
        }
    } else {
        if (M2C_FIELD(&data_02104364, u8 *, 0x9) != (u8) v) {
            M2C_FIELD(&data_02104364, u8 *, 0x9) = (u8) v;
            func_020b8f20((u8) v);
        }
    }
    return changed;
}
