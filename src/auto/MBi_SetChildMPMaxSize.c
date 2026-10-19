#include "engine.h"
#include "m2c.h"

M2C_UNK _s32_div_f(M2C_UNK, M2C_UNK);

extern M2C_UNK req_data_piece_idx;

void MBi_SetChildMPMaxSize(s32 arg0) {
    s32 temp_r1;

    temp_r1                                     = arg0 - 2;
    M2C_FIELD(&req_data_piece_idx, s32 *, 8)    = temp_r1;
    M2C_FIELD(&req_data_piece_idx, s32 *, 0xC)  = _s32_div_f(0x1E, temp_r1);
    M2C_FIELD(&req_data_piece_idx, s32 *, 0x10) = 0x1E;
}
