/* Reconstructed from USA ARM9 at 0x02017908 (168 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_02001778();                            /* extern */
M2C_UNK func_020081f0(s32);                         /* extern */
M2C_UNK func_0204fa08(void *);                      /* extern */
M2C_UNK func_0205c990(void *);                      /* extern */
M2C_UNK func_020acd10(void *, M2C_UNK);             /* extern */
extern M2C_UNK data_020fd020;
extern M2C_UNK func_020179b0;

void *func_02017908(void *arg0, s32 arg1, s32 arg2, M2C_UNK arg3) {
    func_02001778();
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fd020;
    func_020081f0(arg0 + 0x10);
    func_0205c990(arg0 + 0x2C);
    func_0204fa08(arg0 + 0x40);
    M2C_FIELD(arg0, s32 *, 0x5C) = 0;
    M2C_FIELD(arg0, s32 *, 0x60) = 0;
    M2C_FIELD(arg0, s32 *, 0x64) = 0;
    M2C_FIELD(arg0, s32 *, 0x68) = 0;
    M2C_FIELD(arg0, s32 *, 0x6C) = 0;
    M2C_FIELD(arg0, s32 *, 0x70) = 0;
    M2C_FIELD(arg0, s32 *, 0x74) = 0;
    M2C_FIELD(arg0, s32 *, 0x78) = 0;
    M2C_FIELD(arg0, s32 *, 0x7C) = 0;
    M2C_FIELD(arg0, s32 *, 0x80) = 0;
    M2C_FIELD(arg0, s32 *, 0x84) = 0x1D;
    M2C_FIELD(arg0, u8 *, 0x88)  = 0xFF;
    M2C_FIELD(arg0, s8 *, 0x89)  = 0;
    func_020acd10(arg0 + 0x8C, arg3);
    M2C_FIELD(arg0, s8 *, 0x42)       = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x10) = &func_020179b0;
    M2C_FIELD(arg0, M2C_UNK **, 0x14) = &func_020179b0;
    M2C_FIELD(arg0, M2C_UNK **, 0x18) = &func_020179b0;
    M2C_FIELD(arg0, M2C_UNK **, 0x1C) = &func_020179b0;
    return arg0;
}
