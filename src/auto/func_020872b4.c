/* Reconstructed from USA ARM9 at 0x020872b4 (220 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_020534e0(void *);                                 /* extern */
M2C_UNK func_0206549c(void *);                                 /* extern */
M2C_UNK func_0206d4d0(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_020882bc(void *);                                 /* extern */
extern M2C_UNK data_020fe6d0;
extern M2C_UNK data_020ff414;

/* Initializes the factory-created type 0x30 object, its embedded records,
 * and the nested component at offset 0xE8. */
void *func_020872b4(void *object, s32 type_id, s32 arg2, s32 arg3, s32 arg4) {
    M2C_FIELD(object, M2C_UNK **, 0) = &data_020fe6d0;
    M2C_FIELD(object, s32 *, 4)      = type_id;
    M2C_FIELD(object, s32 *, 8)      = arg2;
    M2C_FIELD(object, s32 *, 0xC)    = arg3;
    M2C_FIELD(object, s32 *, 0x10)   = arg4;
    M2C_FIELD(object, s32 *, 0x14)   = 0;
    M2C_FIELD(object, s32 *, 0x18)   = 0;
    M2C_FIELD(object, s32 *, 0x1C)   = 0;
    M2C_FIELD(object, s32 *, 0x20)   = 0;
    M2C_FIELD(object, s32 *, 0x24)   = 0;
    M2C_FIELD(object, M2C_UNK **, 0) = &data_020ff414;
    func_020534e0(object + 0x28);
    func_020534e0(object + 0x30);
    func_0206549c(object + 0x38);
    func_0206549c(object + 0x68);
    func_0206d4d0(object + 0x98, 1, 3, 2, 1);
    M2C_FIELD(object, s32 *, 0xC4) = 0;
    M2C_FIELD(object, s8 *, 0xC8)  = 0;
    M2C_FIELD(object, s8 *, 0xC9)  = 0;
    M2C_FIELD(object, s8 *, 0xCA)  = 0;
    M2C_FIELD(object, s8 *, 0xCB)  = 0;
    M2C_FIELD(object, s8 *, 0xCC)  = 0;
    M2C_FIELD(object, s8 *, 0xCD)  = 0;
    M2C_FIELD(object, s8 *, 0xCE)  = 0;
    M2C_FIELD(object, u8 *, 0xCF)  = 0xFF;
    M2C_FIELD(object, s32 *, 0xD0) = 0;
    M2C_FIELD(object, s32 *, 0xD4) = 0;
    M2C_FIELD(object, s32 *, 0xD8) = 0;
    M2C_FIELD(object, s32 *, 0xDC) = 0;
    M2C_FIELD(object, s32 *, 0xE0) = 0;
    M2C_FIELD(object, s32 *, 0xE4) = 1;
    func_020882bc(object + 0xE8);
    return object;
}
