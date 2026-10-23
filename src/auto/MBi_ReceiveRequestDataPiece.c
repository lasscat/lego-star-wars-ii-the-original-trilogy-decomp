/* Reconstructed from USA ARM9 at 0x020dd580 (140 bytes).
 *
 * Copies one request data piece into the piece wise parent buffer and
 * marks the piece as received.  req_data_piece_idx holds the piece
 * buffer: +0x04 base pointer, +0x08 piece size, +0x0C piece count and
 * the per child received flags start at +0x1E0.
 */
#include "m2c.h"

extern M2C_UNK req_data_piece_idx;

M2C_UNK MI_CpuCopy8(void *, void *, u32);     /* extern */
s32 IsGetAllRequestData(s32);                 /* extern */

u8 *MBi_ReceiveRequestDataPiece(u8 *arg0, s32 arg1) {
    s32 temp_r3;
    u8 temp_r5;
    s32 temp_r4;
    u32 temp_r2;
    u32 temp_r1;

    temp_r3 = M2C_FIELD(&req_data_piece_idx, s32 *, 4);
    if (temp_r3 == 0) {
        return 0;
    }
    temp_r5 = arg0[2];
    if ((s32) temp_r5 > M2C_FIELD(&req_data_piece_idx, s32 *, 0xC)) {
        return 0;
    }
    temp_r4 = arg1 - 1;
    temp_r2 = M2C_FIELD(&req_data_piece_idx, s32 *, 8);
    MI_CpuCopy8(arg0 + 3, M2C_FIELD(&req_data_piece_idx, s32 *, 4) + (temp_r4 << 5) + (temp_r5 * temp_r2), temp_r2);
    temp_r1 = M2C_FIELD(M2C_FIELD(&req_data_piece_idx, s32 *, 4) + 0x1E0, s32 *, temp_r4 * 4);
    temp_r1 |= 1 << temp_r5;
    M2C_FIELD(M2C_FIELD(&req_data_piece_idx, s32 *, 4) + 0x1E0, s32 *, temp_r4 * 4) = temp_r1;
    if (IsGetAllRequestData(arg1) != 0) {
        return M2C_FIELD(&req_data_piece_idx, s32 *, 4) + (temp_r4 << 5);
    }
    return 0;
}
