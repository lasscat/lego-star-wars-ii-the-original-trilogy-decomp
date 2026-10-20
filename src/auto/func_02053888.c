#include "m2c.h"

typedef struct {
    u32 field_00;
    u32 field_04;
    u8 pad[0x10];
    u32 field_18;
} TableEntry;

extern TableEntry *func_020531d8(const s32 *indices);

void func_02053888(const s32 *indices, u32 value) {
    TableEntry *entry = func_020531d8(indices);
    entry->field_18   = *(volatile u32 *) &value;
    entry             = func_020531d8(indices);
    entry->field_04 |= 1;
}
