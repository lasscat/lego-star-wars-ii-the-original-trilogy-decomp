/* Reconstructed from USA ARM9 at 0x020dd60c (84 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

extern M2C_UNK req_data_piece_idx;

s32 IsGetAllRequestData(s32 arg0) {
    u16 var_r2;
    s32 temp_r3;

    var_r2 = 0;
    if ((s32) M2C_FIELD(&req_data_piece_idx, s32 *, 0xC) > 0) {
        temp_r3 = M2C_FIELD((M2C_FIELD(&req_data_piece_idx, s32 *, 4) + ((arg0 - 1) * 4)), s32 *, 0x1E0);
        do {
            if (!(temp_r3 & (1 << var_r2))) {
                return 0;
            }
            var_r2 += 1;
        } while ((s32) M2C_FIELD(&req_data_piece_idx, s32 *, 0xC) > (s32) var_r2);
    }
    return 1;
}
