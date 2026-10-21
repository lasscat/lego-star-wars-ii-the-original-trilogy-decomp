#include "m2c.h"

struct C7F4C8Node {
    void *data;
    C7F4C8Node *next;
};

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class C7F4C8Sub {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18(); // Slot 0x18.
    C7F4C8Node *chain;       // Offset 0x4 of the sub-object.
};

// The sub-object is embedded at offset 0x8 of the enclosing object; the two
// leading words are unknown.  The chain pointer is at 0xc of the outer object.
class C7F4C8Object {
public:
    u32 unknown00;
    u32 unknown04;
    C7F4C8Sub sub;
};

extern "C" void func_0205e84c(void *data);

extern "C" void func_0207f4c8(C7F4C8Object *obj) {
    C7F4C8Node *node = obj->sub.chain;
    while (node != 0) {
        func_0205e84c(node->data);
        node = node->next;
    }
    obj->sub.unknown18();
}
