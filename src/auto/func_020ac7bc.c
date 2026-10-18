/* Reconstructed from USA ARM9 at 0x020ac7bc (108 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_01ffc3d8();                            /* extern */
M2C_UNK func_020c4234();                            /* extern */
M2C_UNK func_020c42dc(M2C_UNK *);                   /* extern */
M2C_UNK func_020c4304(s32 *);                       /* extern */
M2C_UNK func_020c8144(M2C_UNK *);                   /* extern */
extern M2C_UNK data_020ff9b4;
extern M2C_UNK data_027e0c14;
extern M2C_UNK data_027e0cd0;

void func_020ac7bc(void *arg0) {
    s32 sp0[3];

    func_020c8144(&data_027e0cd0);
    M2C_FIELD(&data_027e0c14, s32 *, 0xFC) = (s32) (M2C_FIELD(&data_027e0c14, s32 *, 0xFC) & ~0xA4);
    func_020c42dc(&data_020ff9b4);
    sp0[0] = 0x1000;
    sp0[1] = 0x1000;
    sp0[2] = 0x1000;
    func_020c4304(sp0);
    func_020c4234();
    func_01ffc3d8();
    M2C_FIELD(arg0, u16 *, 0x52) = (u16) (M2C_FIELD(arg0, u16 *, 0x52) & ~8);
}
