#include "m2c.h"

// Partial interface: the sub-object type only needs the virtual that is
// observed at vtable slot 0x04.
class SubObject {
public:
    virtual void unknown00();
    virtual void unknown04(); // Slot 0x04.
};

// Raw view of the owning object: vptr at 0x0, four sub-object pointers at 0xc.
struct Object {
    void *vptr;
    u32 pad[2];
    SubObject *subs[4];
};

// The class vtable of this object type; it stays in the ROM data.
extern "C" u32 data_020fed00[13];

// Base teardown helper called on the object.
extern "C" void func_0205e84c(void *);

extern "C" Object *func_02075e04(Object *obj) {
    obj->vptr = (void *) &data_020fed00;
    for (int i = 0; i < 4; i++) {
        if (obj->subs[i] != 0) {
            obj->subs[i]->unknown04();
        }
        obj->subs[i] = 0;
    }
    func_0205e84c(obj);
    return obj;
}
