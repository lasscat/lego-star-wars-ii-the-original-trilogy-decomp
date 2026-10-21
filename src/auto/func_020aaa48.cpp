#include "m2c.h"

struct Caaa48Node {
    void *data;
    Caaa48Node *next;
};

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class Caaa48Sub {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18(); // Slot 0x18.
    Caaa48Node *chain;       // Offset 0x4 of the sub-object.
};

// The sub-object is embedded at offset 0x394 of the enclosing object; the
// leading bytes are unknown.  The chain pointer is at 0x398 of the outer object.
class Caaa48Object {
public:
    u8 unknown00[0x394];
    Caaa48Sub sub;
};

extern "C" void func_0205e84c(void *data);

extern "C" void func_020aaa48(Caaa48Object *obj) {
    Caaa48Node *node = obj->sub.chain;
    while (node != 0) {
        void *data = node->data;
        if (data != 0) {
            func_0205e84c(data);
        }
        node = node->next;
    }
    obj->sub.unknown18();
}
