#include "m2c.h"

void func_020891fc(M2C_UNK arg0);

/* 8-byte list entries: a flag byte, a counter byte and a -1 word. */
typedef struct {
    u8 field_00;
    u8 field_01;
    u16 pad_02;
    s32 field_04;
} Unk_0208a8d0_Entry;

/* Sub-object at object+0x2000: the list of 0xb4 entries and a flag byte. */
typedef struct {
    u8 pad_000[0x2c0];
    Unk_0208a8d0_Entry entries[0xb4];
    u8 pad_860[0x208];
    u8 flag;
} Unk_0208a8d0_Sub;

typedef struct {
    u8 pad_000[0x2000];
    Unk_0208a8d0_Sub sub;
} Unk_0208a8d0;

void func_0208a8d0(M2C_UNK arg0) {
    Unk_0208a8d0 *obj;
    u32 i;
    u8 *entry;

    obj = (Unk_0208a8d0 *) arg0;

    obj->sub.flag = 1;

    /* 0x168 records of 0x18 bytes at the start of the object. */
    entry = (u8 *) obj;
    for (i = 0; i < 0x168; i++) {
        func_020891fc((M2C_UNK) entry);
        entry += 0x18;
    }

    for (i = 0; i < 0xb4; i++) {
        obj->sub.entries[i].field_00 = 0xff;
        obj->sub.entries[i].field_01 = 0;
        obj->sub.entries[i].field_04 = -1;
    }
}
