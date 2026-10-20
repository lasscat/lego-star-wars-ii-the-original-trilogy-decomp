#include "m2c.h"

/* Reconstructed from USA ARM9 at 0x0205357c (44 bytes).
 *
 * func_0205357c is a setter on the 0x38 byte table entry that
 * func_020531d8 returns:
 *
 *     entry = &data_02101bb8[indices[0]][indices[1]];
 *     entry->field_00 = value;      // u16
 *     entry->field_34 |= 4;         // u32 bit field
 *
 * The second argument is passed in r1, but the original code reads its low
 * halfword back from the argument home area (the "push {r0, r1, r2, r3}"
 * prologue), so the value is read through the address of the parameter.
 * Reading it through a volatile pointer keeps the parameter in that home
 * slot and reproduces the original register allocation (the entry pointer in
 * r0, the value in r1).
 */
typedef struct {
    u16 field_00;
    u8 pad[0x32];
    u32 field_34;
} TableEntry;

extern TableEntry *func_020531d8(void *indices);

void func_0205357c(void *indices, u16 value) {
    TableEntry *entry = func_020531d8(indices);
    entry->field_00   = *(volatile u16 *) &value;
    entry->field_34 |= 4;
}
