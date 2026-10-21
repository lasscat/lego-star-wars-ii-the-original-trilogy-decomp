#include "m2c.h"

// Entry61194 allocated at the head of the function (8 bytes).
class Entry61194 {
public:
    u32 f0; // 0x00
    u32 f4; // 0x04
};

// Record referenced by a list node.
class Rec {
public:
    u32 f0;  // 0x00
    s32 f4;  // 0x04
    u32 f8;  // 0x08
    u16 f12; // 0x0c
};

// List node: record, next link and alternate link.
class Node {
public:
    Rec *f0;  // 0x00
    Node *f4; // 0x04
    Node *f8; // 0x08
};

// Sub61194-object at offset 0x38 with its own vtable.
class Sub61194 {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08(Entry61194 *); // Slot 0x8.
    virtual void unknown0c(Rec *);   // Slot 0xc.
};

class Owner61194 {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14(Entry61194 *); // Slot 0x14.
    Node *listA;  // 0x04
    u8 pad[0x30]; // 0x08
    Sub61194 sub;      // 0x38
    Node *list;   // 0x3c
};

// Table returned by func_0205ab30.
struct Table {
    u8 count;  // 0x00
    u8 pad01[3];
    u8 width;  // 0x04
    u8 pad05[3];
    u8 data[1]; // 0x08
};
extern "C" void *func_0205e80c(u32 size, u32 heap, u32 flags);
extern "C" Table *func_0205ab30(u32 index);
extern "C" Entry61194 *func_02061f40(Entry61194 *self, u8 *data, u32 width, u32 index, u32 id);

extern "C" void func_02061194(Owner61194 *self, u32 index, u32 *out) {
    s32 offset;
    Entry61194 *entry   = (Entry61194 *) func_0205e80c(8, 3, 4);
    entry->f0           = index;
    entry->f4           = 0;
    s32 id              = 0;
    volatile Node *node = self->list;
    if (node != 0) {
        do {
            Rec *rec  = node->f0;
            node      = node->f4;
            s32 value = rec->f4;
            if (value >= id) {
                id = value + 1;
            }
        } while (node != 0);
    }
    entry->f4 = id;
    self->sub.unknown08(entry);
    Table *table     = func_0205ab30((u16) index);
    s32 count        = table->count;
    Entry61194 *last = 0;
    s32 i            = 0;
    u32 width        = table->width;
    u32 stride       = 44;
    while (i < count) {
        offset           = i * stride * width;
        Entry61194 *item = (Entry61194 *) func_0205e80c(44, 3, 4);
        if (item != 0) {
            item = func_02061f40(item, table->data + offset, width, index, entry->f4);
        }
        if (last == 0) {
            last = item;
        }
        i++;
    }
    *out = entry->f4;
    self->unknown14(last);
}
