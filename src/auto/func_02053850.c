#include "m2c.h"

/* Reconstructed from USA ARM9 at 0x02053850 (56 bytes).
 *
 * func_02053850 is a setter on the 0x38 byte table entry that
 * func_020531d8 returns:
 *
 *     entry = &data_02101bb8[indices[0]][indices[1]];
 *     entry->field_1C = value;      // u16
 *     entry->field_04 |= 1;         // u32 bit field
 *
 * The value is passed in r1, but the original code reads its low halfword
 * back from the argument home area (the "push {r0, r1, r2, r3}" prologue),
 * so it is read through the address of the parameter.  Reading it through a
 * volatile pointer keeps the parameter in that home slot and reproduces the
 * original register allocation (the entry pointer in r0, the value in r1).
 * The reload is an unsigned halfword load (ldrh, not ldrsh), so the value
 * is an unsigned 16 bit quantity.
 */
typedef struct {
    u32 field_00;
    u32 field_04;
    u8 pad[0x14];
    u16 field_1C;
} TableEntry;

extern TableEntry *func_020531d8(const s32 *indices);

void func_02053850(const s32 *indices, u16 value) {
    TableEntry *entry = func_020531d8(indices);
    entry->field_1C   = *(volatile u16 *) &value;
    entry             = func_020531d8(indices);
    entry->field_04 |= 1;
}
