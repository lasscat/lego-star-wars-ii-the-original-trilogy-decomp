/* Reconstructed from USA ARM9 at 0x020dd464 (284 bytes).
 * Turns one message received from the child into the parent side buffer.
 *
 * Command 7 : piece wise transfer, the buffer is completed by
 *             MBi_ReceiveRequestDataPiece; when every piece is already
 *             present the matching slot of the parent piece buffer is
 *             returned directly.
 * Command 8 : 16 bit value, the buffer ends behind the two header bytes.
 * Command 9 : 16 bit value followed by one full size piece of data.
 */
#include "m2c.h"

extern M2C_UNK req_data_piece_idx;

s32 IsGetAllRequestData(s32 arg0);                   /* extern */
M2C_UNK MI_CpuCopy8(void *, void *, u32);             /* extern */
M2C_UNK MBi_ReceiveRequestDataPiece(void *, s32);     /* extern */

u8 *MBi_SetRecvBufferFromChild(u8 *arg0, u8 *arg1, s32 arg2) {
    u8 temp_r0;
    u8 *temp_r4;
    u8 temp_r2;

    temp_r0 = arg0[0];
    arg1[0] = temp_r0;
    switch (temp_r0) {
        case 7:
            if (IsGetAllRequestData(arg2) != 0) {
                return (u8 *) M2C_FIELD(&req_data_piece_idx, s32 *, 4) + ((arg2 - 1) * 0x20);
            }
            temp_r2 = arg0[1];
            arg1[2] = temp_r2;
            if ((s32) temp_r2 > M2C_FIELD(&req_data_piece_idx, s32 *, 0xC)) {
                return NULL;
            }
            MI_CpuCopy8(arg0 + 2, arg1 + 3, M2C_FIELD(&req_data_piece_idx, s32 *, 8));
            temp_r4 = MBi_ReceiveRequestDataPiece(arg1, arg2);
            break;
        case 8:
            temp_r4                   = arg0 + 3;
            M2C_FIELD(arg1, u16 *, 2) = arg0[1];
            M2C_FIELD(arg1, u16 *, 2) |= (arg0[2] << 8) & 0xFF00;
            break;
        case 9:
            temp_r4                   = arg0 + 3;
            M2C_FIELD(arg1, u16 *, 2) = arg0[1];
            M2C_FIELD(arg1, u16 *, 2) |= (arg0[2] << 8) & 0xFF00;
            MI_CpuCopy8(arg0 + 3, arg1 + 4, M2C_FIELD(&req_data_piece_idx, s32 *, 8));
            temp_r4 = temp_r4 + M2C_FIELD(&req_data_piece_idx, s32 *, 8);
            break;
        default:
            return NULL;
    }
    return temp_r4;
}
