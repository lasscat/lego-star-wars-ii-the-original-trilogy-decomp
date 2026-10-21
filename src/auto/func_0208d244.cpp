#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class C8D244Object {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18(); // Slot 0x18.
};

struct C8D244Node {
    void *data;
    C8D244Node *next;
};

extern "C" void func_0205e84c(void *data);

extern "C" void func_0208d244(C8D244Object *obj) {
    if (M2C_FIELD(obj, u8 *, 0x38) == 0) {
        return;
    }
    C8D244Node *node = M2C_FIELD(obj, C8D244Node **, 0x4);
    while (node != 0) {
        func_0205e84c(node->data);
        node = node->next;
    }
    obj->unknown18();
    M2C_FIELD(obj, u8 *, 0x38) = 0;
}
