#include "m2c.h"

M2C_UNK MI_CpuFill8(s32, M2C_UNK, M2C_UNK);       /* extern */
extern M2C_UNK req_data_piece_idx;

void MBi_SetParentPieceBuffer(s32 arg0) {
    M2C_FIELD(&req_data_piece_idx, s32 *, 4) = arg0;
    MI_CpuFill8(arg0, 0, 0x21C);
}
