/* Reconstructed from USA ARM9 at 0x020931b0 (92 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

extern M2C_UNK data_021019f4;
extern s32 data_027e02a4;

void *func_020931b0(s32 arg0, s32 arg1) {
    void *temp_r3;
    void *var_ip;
    void *result = NULL;

    var_ip = M2C_FIELD(((u8 *) &data_021019f4 + (data_027e02a4 * 0x38)), void **, 4);
    while (var_ip != NULL) {
        temp_r3 = M2C_FIELD(var_ip, void **, 0);
        if ((M2C_FIELD(temp_r3, u16 *, 0xC) & 3) && (arg1 == M2C_FIELD(temp_r3, u8 *, 0x6BB))) {
            result = temp_r3;
            break;
        }
        var_ip = M2C_FIELD(var_ip, void **, 4);
    }
    return result;
}
