#include "m2c.h"

M2C_UNK func_02001778(void *, M2C_UNK, M2C_UNK);  /* extern */
M2C_UNK MIi_CpuClear16(M2C_UNK, void *, M2C_UNK); /* extern */
extern M2C_UNK data_020fd0f0;

/* Initialize the object header with the selector-driven common setup, then
 * clear 0x3C bytes at +0x10. The explicit stores reset additional state,
 * set two halfwords to 0xFFFF, and preserve the existing flags while ORing
 * in 0x401401; the object pointer is returned.
 */
void *func_0201abbc(void *object, M2C_UNK initializerSelector) {
    u16 v;
    func_02001778(object, 0x100, initializerSelector);
    M2C_FIELD(object, M2C_UNK **, 0) = &data_020fd0f0;
    M2C_FIELD(object, s32 *, 0x2C)   = 0;
    M2C_FIELD(object, s32 *, 0x30)   = 0;
    M2C_FIELD(object, s32 *, 0x34)   = 0;
    M2C_FIELD(object, s32 *, 0x38)   = 0;
    M2C_FIELD(object, s32 *, 0x4C)   = 0;
    M2C_FIELD(object, s32 *, 0x50)   = 0;
    M2C_FIELD(object, s32 *, 0x54)   = 0;
    M2C_FIELD(object, s32 *, 0x58)   = 0;
    M2C_FIELD(object, s32 *, 0x5C)   = 0;
    M2C_FIELD(object, s32 *, 0x60)   = 0;
    M2C_FIELD(object, s32 *, 0x64)   = 0;
    M2C_FIELD(object, s32 *, 0x68)   = 0;
    M2C_FIELD(object, s32 *, 0x6C)   = 0;
    M2C_FIELD(object, s32 *, 0x70)   = 0;
    M2C_FIELD(object, s16 *, 0x78)   = 0;
    M2C_FIELD(object, s32 *, 0x7C)   = 0;
    MIi_CpuClear16(0, object + 0x10, 0x3C);
    v                              = 0xFFFF;
    M2C_FIELD(object, u16 *, 0x1E) = v;
    M2C_FIELD(object, u16 *, 0x42) = v;
    M2C_FIELD(object, s32 *, 8)    = (s32) (M2C_FIELD(object, s32 *, 8) | 0x401401);
    return object;
}
