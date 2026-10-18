/* Reconstructed from USA ARM9 at 0x020801d8 (156 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_020534e0(void *);                      /* extern */
M2C_UNK func_0206549c(void *);                      /* extern */
M2C_UNK func_02067bc0(void *);                      /* extern */
extern M2C_UNK data_020fe6d0;
extern M2C_UNK data_020ff320;

void *func_020801d8(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u8 var_r3;
    s32 var;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fe6d0;
    M2C_FIELD(arg0, s32 *, 4)      = arg1;
    M2C_FIELD(arg0, s32 *, 8)      = arg2;
    M2C_FIELD(arg0, s32 *, 0xC)    = arg3;
    M2C_FIELD(arg0, s32 *, 0x10)   = arg4;
    M2C_FIELD(arg0, s32 *, 0x14)   = 0;
    M2C_FIELD(arg0, s32 *, 0x18)   = 0;
    M2C_FIELD(arg0, s32 *, 0x1C)   = 0;
    M2C_FIELD(arg0, s32 *, 0x20)   = 0;
    M2C_FIELD(arg0, s32 *, 0x24)   = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020ff320;
    func_020534e0(arg0 + 0x48);
    func_020534e0(arg0 + 0x50);
    func_020534e0(arg0 + 0x58);
    func_02067bc0(arg0 + 0x60);
    func_02067bc0(arg0 + 0x68);
    func_0206549c(arg0 + 0x70);
    var_r3 = 0;
    var    = 0;
    do {
        M2C_FIELD(arg0 + (var_r3 * 4), s32 *, 0x28) = var;
        var_r3 += 1;
    } while ((u32) var_r3 < 8U);
    return arg0;
}
