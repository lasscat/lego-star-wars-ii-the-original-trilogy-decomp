/* Reconstructed from USA ARM9 at 0x02010460 (112 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

void func_02010460(void *arg0) {
    void *var_lr = M2C_FIELD(arg0, void **, 0x188);
    void *temp_ip;
    s32 *src;

    if (var_lr == NULL) {
        return;
    }
loop_3:
    temp_ip = M2C_FIELD(var_lr, void **, 0);
    if (M2C_FIELD(temp_ip, s32 *, 8) != M2C_FIELD(arg0, s32 *, 0x18C)) {
        return;
    }
    if (M2C_FIELD(temp_ip, u16 *, 0xC) != M2C_FIELD(M2C_FIELD(arg0, void **, 0x170), u16 *, 8)) {
        return;
    }
    src = (s32 *) ((s8 *) arg0 + 0xB0);
    if ((temp_ip + 0x10) != (void *) src) {
        M2C_FIELD(temp_ip, s32 *, 0x10) = M2C_FIELD(src, s32 *, 0);
        M2C_FIELD(temp_ip, s32 *, 0x14) = M2C_FIELD(src, s32 *, 4);
        M2C_FIELD(temp_ip, s32 *, 0x18) = M2C_FIELD(src, s32 *, 8);
    }
    var_lr = M2C_FIELD(var_lr, void **, 4);
    if (var_lr == NULL) {
        return;
    }
    goto loop_3;
}
