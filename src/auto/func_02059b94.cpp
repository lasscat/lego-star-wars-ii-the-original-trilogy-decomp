#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class Event59B94 {
public:
    virtual void unknown00();
    virtual void unknown04(); // Slot 0x04: clears the payload fields.
};

// Raw view of the object header: the vptr lives at offset 0.
struct Event59B94Header {
    void *vptr;
};

// The class vtable of this object type; it stays in the ROM data.
extern "C" u32 data_020ff28c[3];

extern "C" M2C_UNK data_02106d90;

extern "C" void *func_0205e80c(u32 size, s32 heap, s32 align);
extern "C" void func_0207f56c(void *obj, void *arg);

extern "C" void func_02059b94(void *self, u8 *event) {
    Event59B94 *obj = (Event59B94 *) func_0205e80c(16, 3, 4);
    if (obj != 0) {
        ((Event59B94Header *) obj)->vptr = (void *) &data_020ff28c[0];
    }
    obj->unknown04();
    M2C_FIELD(obj, u32 *, 0x4) = event[0];
    M2C_FIELD(obj, u32 *, 0x8) = event[1];
    M2C_FIELD(obj, u16 *, 0xc) = event[2];
    M2C_FIELD(obj, u16 *, 0xe) = event[3];
    func_0207f56c(*(void **) ((u8 *) &data_02106d90 + 0xad8), obj);
}
