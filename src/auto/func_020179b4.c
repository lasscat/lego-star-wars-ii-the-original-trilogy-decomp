/* Reconstructed from USA ARM9 at 0x020179b4 (168 bytes).
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

/* Initialize an Obj: reset its embedded components and state, copy transform
 * data from the supplied 0x48-byte record into the component at +0x8C, then
 * install four identical handlers in the dispatch slots at +0x10 through +0x1C.
 * The two middle constructor arguments are unused here.
 */
void *func_020179b4(void *object, s32 arg1, s32 arg2, M2C_UNK transform) {
    func_02001778();
    M2C_FIELD(object, M2C_UNK **, 0) = &data_020fd020;
    func_020081f0(object + 0x10);
    func_0205c990(object + 0x2C);
    func_0204fa08(object + 0x40);
    M2C_FIELD(object, s32 *, 0x5C) = 0;
    M2C_FIELD(object, s32 *, 0x60) = 0;
    M2C_FIELD(object, s32 *, 0x64) = 0;
    M2C_FIELD(object, s32 *, 0x68) = 0;
    M2C_FIELD(object, s32 *, 0x6C) = 0;
    M2C_FIELD(object, s32 *, 0x70) = 0;
    M2C_FIELD(object, s32 *, 0x74) = 0;
    M2C_FIELD(object, s32 *, 0x78) = 0;
    M2C_FIELD(object, s32 *, 0x7C) = 0;
    M2C_FIELD(object, s32 *, 0x80) = 0;
    M2C_FIELD(object, s32 *, 0x84) = 0x1D;
    M2C_FIELD(object, u8 *, 0x88)  = 0xFF;
    M2C_FIELD(object, s8 *, 0x89)  = 0;
    func_020acd10(object + 0x8C, transform);
    M2C_FIELD(object, s8 *, 0x42)       = 0;
    M2C_FIELD(object, M2C_UNK **, 0x10) = &func_020179b0;
    M2C_FIELD(object, M2C_UNK **, 0x14) = &func_020179b0;
    M2C_FIELD(object, M2C_UNK **, 0x18) = &func_020179b0;
    M2C_FIELD(object, M2C_UNK **, 0x1C) = &func_020179b0;
    return object;
}
