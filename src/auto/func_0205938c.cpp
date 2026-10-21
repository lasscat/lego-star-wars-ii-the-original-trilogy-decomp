#include "m2c.h"

// Row of the table reached through obj->f04->rows.
// Only the byte at +5 (the iteration count) is observed.
struct C5938CRow {
    u32 f00;
    u8 f04;
    u8 f05; // iteration count
    u16 f06;
};

// Holder of the row table; only the table pointer (offset 0x2c) is observed.
struct C5938CHolder {
    u8 pad[0x2c];
    C5938CRow *rows;
};

// Object that owns the table holder (field at offset 4).
class C5938CObject {
public:
    u32 f00;
    C5938CHolder *f04;
};

// Item reached through the table.
// Partial interface: the unknown virtuals keep their observed vtable slots;
// declarations only, the original vtable stays in the ROM data.
class C5938CItem {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18();
    virtual void unknown1c();
    virtual void unknown20();
    virtual void unknown24();
    virtual void unknown28();
    virtual void unknown2c();
    virtual void unknown30();
    virtual void unknown34();
    virtual void unknown38();
    virtual void unknown3c();
    virtual void unknown40();
    virtual void unknown44(); // Slot 0x44.
    u32 f04;
    u32 f08;
    u16 f0c; // kind
};

extern "C" void *func_02067080(C5938CObject *obj, u32 index, u32 slot);

extern "C" void func_0205938c(C5938CObject *obj, u8 *p) {
    u8 v                 = *p;
    C5938CHolder *holder = obj->f04;
    u8 count;
    if (v != 0) {
        count = holder->rows[v - 1].f05;
    } else {
        count = 0;
    }
    u32 index;
    u32 i = 1;
    if (count >= 1) {
        index = v - 1;
        do {
            C5938CItem *item = (C5938CItem *) func_02067080(obj, index, i);
            if (item != 0 && item->f0c == 4) {
                item->unknown44();
            }
            i++;
        } while (i <= count);
    }
}
