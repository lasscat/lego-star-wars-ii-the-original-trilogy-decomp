#include "m2c.h"

M2C_UNK MI_Copy36B(void *, void *); /* copies 36 decimal bytes */

/* Copy bytes 0x00..0x45 of the 0x48-byte transform record into embedded
 * storage; the final two bytes are untouched. */
void *func_020acd10(void *destination_transform, void *source_transform) {
    MI_Copy36B(source_transform, destination_transform);
    M2C_FIELD(destination_transform, s32 *, 0x24) = (s32) M2C_FIELD(source_transform, s32 *, 0x24);
    M2C_FIELD(destination_transform, s32 *, 0x28) = (s32) M2C_FIELD(source_transform, s32 *, 0x28);
    M2C_FIELD(destination_transform, s32 *, 0x2C) = (s32) M2C_FIELD(source_transform, s32 *, 0x2C);
    M2C_FIELD(destination_transform, s32 *, 0x30) = (s32) M2C_FIELD(source_transform, s32 *, 0x30);
    M2C_FIELD(destination_transform, s32 *, 0x34) = (s32) M2C_FIELD(source_transform, s32 *, 0x34);
    M2C_FIELD(destination_transform, s32 *, 0x38) = (s32) M2C_FIELD(source_transform, s32 *, 0x38);
    M2C_FIELD(destination_transform, u16 *, 0x3C) = (u16) M2C_FIELD(source_transform, u16 *, 0x3C);
    M2C_FIELD(destination_transform, u16 *, 0x3E) = (u16) M2C_FIELD(source_transform, u16 *, 0x3E);
    M2C_FIELD(destination_transform, u16 *, 0x40) = (u16) M2C_FIELD(source_transform, u16 *, 0x40);
    M2C_FIELD(destination_transform, u16 *, 0x42) = (u16) M2C_FIELD(source_transform, u16 *, 0x42);
    M2C_FIELD(destination_transform, u8 *, 0x44)  = (u8) M2C_FIELD(source_transform, u8 *, 0x44);
    M2C_FIELD(destination_transform, u8 *, 0x45)  = (u8) M2C_FIELD(source_transform, u8 *, 0x45);
    return destination_transform;
}
