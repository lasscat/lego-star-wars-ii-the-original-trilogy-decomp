#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtables remain in the ROM data.
class LocalObj {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08(void *); // Slot 0x08.
    u8 pad04[8];  // 0x04..0x0b.
    u16 field0c;  // 0x0c.
    u8 pad0e[42]; // 0x0e..0x37.
};

// Storage of the stack object; the object is set up by func_0205d6f8.
struct LocalObjFrame {
    void *vptr;   // 0x00.
    u8 pad04[8];  // 0x04..0x0b.
    u16 field0c;  // 0x0c.
    u8 pad0e[42]; // 0x0e..0x37.
};

struct ListEntry {
    void *ptr;   // 0x00.
    void *other; // 0x04.
};

class ListOwner {
public:
    ListEntry *items; // 0x00.
    u8 pad04;         // 0x04.
    u8 count;         // 0x05.
};

extern "C" void func_0205d6f8(LocalObj *, int);
extern "C" void func_0205d72c(LocalObj *);
extern "C" void func_020903f0(void *, void *, int);
extern "C" u8 data_0210930c[];

extern "C" void func_020679f0(ListOwner *self) {
    LocalObjFrame frame;
    func_0205d6f8((LocalObj *) &frame, 10);
    for (u32 i = 0; i < self->count; i++) {
        void *item = self->items[i].ptr;
        if (item != 0) {
            ((LocalObj *) &frame)->unknown08(item);
        }
    }
    if (frame.field0c != 0) {
        func_020903f0(*(void **) (data_0210930c + 0x68), &frame, 0);
    }
    func_0205d72c((LocalObj *) &frame);
}
