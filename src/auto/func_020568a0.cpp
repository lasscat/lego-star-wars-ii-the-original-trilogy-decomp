#include "m2c.h"

// Partial interface: the virtual observed at vtable slot 0x04.
// Declarations only: the original vtable stays in the ROM data.
class Cls568 {
public:
    virtual void unknown00();
    virtual void unknown04(); // Slot 0x04.
};

// Raw view of the object header: the vptr lives at offset 0.
struct Cls568Header {
    void *vptr;
};

// The class vtable of this object type; it stays in the ROM data.
extern "C" u32 data_020ff278[];

// Global manager object; it stays in the ROM data.
extern "C" u32 data_02106d90[];

extern "C" void *func_02067080(M2C_UNK, u8, u8);
extern "C" void *func_0205e80c(M2C_UNK, M2C_UNK, M2C_UNK);
extern "C" void func_0207f56c(void *, void *);

extern "C" void func_020568a0(M2C_UNK arg0, u8 *arg1) {
    Cls568 *obj;

    obj = (Cls568 *) func_02067080(arg0, arg1[0], arg1[1]);
    if (obj == 0) {
        return;
    }
    obj = (Cls568 *) func_0205e80c(0x10, 3, 4);
    if (obj != 0) {
        ((Cls568Header *) obj)->vptr = (void *) &data_020ff278;
    }
    obj->unknown04();
    M2C_FIELD(obj, u32 *, 0x4) = arg1[0];
    M2C_FIELD(obj, u32 *, 0x8) = arg1[1];
    M2C_FIELD(obj, u16 *, 0xc) = arg1[2];
    M2C_FIELD(obj, u16 *, 0xe) = arg1[3];
    func_0207f56c(M2C_FIELD(&data_02106d90, void **, 0xad8), obj);
}
