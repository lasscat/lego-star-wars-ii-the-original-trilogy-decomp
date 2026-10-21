#include "m2c.h"

// The dispatched virtual lives in a second base sub-object at offset 0x08,
// so the call needs the adjusted "this" (obj + 8) and the base vtable.
// Declarations only: the original vtables remain in the ROM data.
class Entity7FBaseA {
public:
    virtual void unknown00();
    int field04;
};

class Entity7FBaseB {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08(void *); // Slot 0x08.
};

class Entity7F : public Entity7FBaseA, public Entity7FBaseB {};

extern "C" void func_0207f56c(Entity7F *obj, void *arg) {
    obj->unknown08(arg);
}
