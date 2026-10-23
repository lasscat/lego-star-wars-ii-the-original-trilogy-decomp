/* Reconstructed from USA ARM9 at 0x020c66b0 (124 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

extern u32 NNS_G3dFuncAnmJntNsBcaDefault;
extern void MIi_CpuClear16(u16 value, void *dest, u32 size);

void NNSi_G3dAnmObjInitNsBca(void *arg0, void *arg1, void *arg2) {
    u8 num;
    u32 i;
    u16 *idx;

    *(void **) ((u8 *) arg0 + 0x8) = arg1;
    *(u32 *) ((u8 *) arg0 + 0xc)   = NNS_G3dFuncAnmJntNsBcaDefault;
    num                            = *(u8 *) ((u8 *) arg2 + 0x17);
    *(u8 *) ((u8 *) arg0 + 0x19)   = num;
    MIi_CpuClear16(0, (u8 *) arg0 + 0x1a, num * 2);

    idx = (u16 *) ((u8 *) arg1 + 0x14);
    for (i = 0; i < *(u16 *) ((u8 *) arg1 + 6); i++) {
        u32 val                           = *(u32 *) ((u8 *) arg1 + idx[i]);
        ((u16 *) ((u8 *) arg0 + 0x1a))[i] = (u16) ((val >> 24) | 0x100);
    }
}
