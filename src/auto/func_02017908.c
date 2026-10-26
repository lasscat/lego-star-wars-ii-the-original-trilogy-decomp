/* Reconstructed from USA ARM9 at 0x02017908 (168 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_02001778();                /* extern */
M2C_UNK func_020081f0(s32);             /* extern */
M2C_UNK func_0204fa08(void *);          /* extern */
M2C_UNK func_0205c990(void *);          /* extern */
M2C_UNK func_020acd10(void *, M2C_UNK); /* extern */
extern M2C_UNK data_020fd020;
extern M2C_UNK func_020179b0;

/* Initialize the shared object layout: initialize embedded state at +0x10,
 * +0x2C, and +0x40; clear the following word fields; copy the caller's
 * configuration into +0x8C; and install four shared callback pointers.
 * Callers such as func_0200fe94 and func_020199d0 continue initialization
 * after this base setup. The meanings of the cleared fields and sentinels
 * are not established here.
 */
void *func_02017908(void *self, s32 arg1, s32 arg2, M2C_UNK initialConfig) {
    func_02001778();
    M2C_FIELD(self, M2C_UNK **, 0) = &data_020fd020;
    func_020081f0(self + 0x10);
    func_0205c990(self + 0x2C);
    func_0204fa08(self + 0x40);
    M2C_FIELD(self, s32 *, 0x5C) = 0;
    M2C_FIELD(self, s32 *, 0x60) = 0;
    M2C_FIELD(self, s32 *, 0x64) = 0;
    M2C_FIELD(self, s32 *, 0x68) = 0;
    M2C_FIELD(self, s32 *, 0x6C) = 0;
    M2C_FIELD(self, s32 *, 0x70) = 0;
    M2C_FIELD(self, s32 *, 0x74) = 0;
    M2C_FIELD(self, s32 *, 0x78) = 0;
    M2C_FIELD(self, s32 *, 0x7C) = 0;
    M2C_FIELD(self, s32 *, 0x80) = 0;
    M2C_FIELD(self, s32 *, 0x84) = 0x1D;
    M2C_FIELD(self, u8 *, 0x88)  = 0xFF;
    M2C_FIELD(self, s8 *, 0x89)  = 0;
    func_020acd10(self + 0x8C, initialConfig);
    M2C_FIELD(self, s8 *, 0x42)       = 0;
    M2C_FIELD(self, M2C_UNK **, 0x10) = &func_020179b0;
    M2C_FIELD(self, M2C_UNK **, 0x14) = &func_020179b0;
    M2C_FIELD(self, M2C_UNK **, 0x18) = &func_020179b0;
    M2C_FIELD(self, M2C_UNK **, 0x1C) = &func_020179b0;
    return self;
}
