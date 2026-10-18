/* Reconstructed from USA ARM9 at 0x020591b8 (108 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_0201c7a0(M2C_UNK *, s32);              /* extern */
M2C_UNK func_0201c858(M2C_UNK *, u8, u16);          /* extern */
M2C_UNK func_0201c8a0(M2C_UNK *, void *);           /* extern */
void *func_02067080(M2C_UNK, u8, u8);               /* extern */
extern M2C_UNK data_020f7290;

void func_020591b8(M2C_UNK arg0, void *arg1) {
    M2C_UNK sp0[3];
    u16 temp_r5;
    void *temp_r0;

    temp_r0 = func_02067080(arg0, M2C_FIELD(arg1, u8 *, 0), M2C_FIELD(arg1, u8 *, 1));
    if (temp_r0 == NULL) {
        return;
    }
    temp_r5 = *((u16 *) ((s8 *) &data_020f7290 + (M2C_FIELD(arg1, u8 *, 3) * 2)));
    func_0201c7a0(sp0, M2C_FIELD(temp_r0, s32 *, 0xE0) + 0x14);
    func_0201c858(sp0, M2C_FIELD(arg1, u8 *, 2), temp_r5);
    func_0201c8a0(sp0, temp_r0 + 0xD8);
}
