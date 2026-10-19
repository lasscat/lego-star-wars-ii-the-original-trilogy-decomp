#include "m2c.h"

M2C_UNK MI_CpuFill8(s32, M2C_UNK, M2C_UNK);       /* extern */
extern M2C_UNK req_data_piece_idx;

void MBi_ClearParentPieceBuffer(s32 arg0) {
    s32 temp_r4;

    if (M2C_FIELD(&req_data_piece_idx, s32 *, 4) == 0) {
        return;
    }
    temp_r4 = arg0 - 1;
    MI_CpuFill8(M2C_FIELD(&req_data_piece_idx, s32 *, 4) + (temp_r4 << 5), 0, 0x1E);
    M2C_FIELD((M2C_FIELD(&req_data_piece_idx, s32 *, 4) + (temp_r4 * 4)), s32 *, 0x1E0) = 0;
}
