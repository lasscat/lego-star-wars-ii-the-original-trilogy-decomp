/* Reconstructed from USA ARM9 at 0x020c3490 (116 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

s32 NNSi_GfdFreeLnkVram(M2C_UNK *, M2C_UNK *, u32, s32);  /* extern */
extern M2C_UNK data_0211262c;
extern M2C_UNK data_02112630;
extern M2C_UNK mgr_;

s32 NNS_GfdFreeLnkTexVram(s32 arg0) {
    s32 ret;
    u32 off  = (u32) (arg0 << 0x10) >> 0xD;
    u32 size = ((u32) (arg0 & 0x7FFF0000) >> 0x10) * 0x10;
    u32 flag = ((u32) (arg0 & 0x80000000)) >> 31;
    if (size != 0) {
        if (flag != 0) {
            ret = NNSi_GfdFreeLnkVram(&data_0211262c, &data_02112630, off, size);
        } else {
            ret = NNSi_GfdFreeLnkVram(&mgr_, &data_02112630, off, size);
        }
        if (ret != 0) {
            return 0;
        }
        return 1;
    }
    return 2;
}
