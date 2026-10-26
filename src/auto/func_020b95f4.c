/* Reconstructed from USA ARM9 at 0x020b95f4 (248 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

s32 func_020b9360(u16);     /* extern */
M2C_UNK func_020b938c(u16); /* extern */
extern u8 data_0210db20;
extern void *data_0210db30;

/* Initialize and register a 0x1C-byte keyed record, sourcing its three-word
 * payload from the optional source or owner+0xB0. */
void *func_020b95f4(void *record, void *optionalWordSource, u16 catalogIndex, void *owner) {
    void *ownerWordSource;

    M2C_FIELD(record, s32 *, 0) = 0;
    M2C_FIELD(record, s32 *, 4) = 0;
    M2C_FIELD(record, s32 *, 8) = 0;
    if ((u32) data_0210db20 > 0x19U) {
        return record;
    }
    M2C_FIELD(record, u16 *, 0x18)  = catalogIndex;
    M2C_FIELD(record, u8 *, 0x1A)   = 0U;
    M2C_FIELD(record, s8 *, 0x1B)   = 0;
    M2C_FIELD(record, s32 *, 0x14)  = -1;
    M2C_FIELD(record, void **, 0xC) = owner;
    M2C_FIELD(record, s32 *, 0x10)  = 0;
    if (optionalWordSource != NULL) {
        if (record != optionalWordSource) {
            M2C_FIELD(record, s32 *, 0) = (s32) M2C_FIELD(optionalWordSource, s32 *, 0);
            M2C_FIELD(record, s32 *, 4) = (s32) M2C_FIELD(optionalWordSource, s32 *, 4);
            M2C_FIELD(record, s32 *, 8) = (s32) M2C_FIELD(optionalWordSource, s32 *, 8);
        }
    } else {
        ownerWordSource = owner + 0xB0;
        if (record != ownerWordSource) {
            M2C_FIELD(record, s32 *, 0) = (s32) M2C_FIELD(ownerWordSource, s32 *, 0);
            M2C_FIELD(record, s32 *, 4) = (s32) M2C_FIELD(ownerWordSource, s32 *, 4);
            M2C_FIELD(record, s32 *, 8) = (s32) M2C_FIELD(ownerWordSource, s32 *, 8);
        }
    }
    if (func_020b9360(catalogIndex) != 0) {
        M2C_FIELD(record, u8 *, 0x1A) = (u8) (M2C_FIELD(record, u8 *, 0x1A) | 2);
        func_020b938c(M2C_FIELD(record, u16 *, 0x18));
        M2C_FIELD(record, u8 *, 0x1A) = (u8) (M2C_FIELD(record, u8 *, 0x1A) | 4);
    }
    M2C_FIELD(data_0210db30, M2C_UNK(**)(void **, void *), 8)(&data_0210db30, record);
    data_0210db20 += 1;
    return record;
}
