#include "m2c.h"

// Partial interface: the 0x40-byte object is allocated raw and its vtable
// pointer is stored by hand, so only the dispatched slot is named here.
// Declarations only: the original vtable (data_020ff2a0) stays in the ROM.
class Entity57F78 {
public:
    virtual void unknown00();
    virtual void unknown04(); // Slot 0x04.
};

extern "C" u32 data_020ff2a0;
extern "C" s32 data_02106d90[1];

extern "C" Entity57F78 *func_02067080(void *obj, u8 a1, u8 a2);
extern "C" void *func_0205e80c(s32 size, s32 a1, s32 a2);
extern "C" s32 FX_Div(s32 a1, s32 a2);
extern "C" void func_0207f6b8(void *obj, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, u8 a6, u8 a7, s32 a8, s32 a9);
extern "C" void func_0207f56c(void *obj, void *arg);

extern "C" void func_02057f78(void *arg0, u8 *a) {
    Entity57F78 *ent = func_02067080(arg0, a[0], a[1]);
    if (ent == 0) {
        return;
    }

    // The object is allocated raw; the vtable pointer is stored by hand.
    Entity57F78 *obj = (Entity57F78 *) func_0205e80c(64, 3, 4);
    if (obj != 0) {
        *(u32 *) obj                = (u32) &data_020ff2a0;
        M2C_FIELD(obj, u32 *, 0x10) = 0;
        M2C_FIELD(obj, u32 *, 0x28) = 0;
        M2C_FIELD(obj, u32 *, 0x2c) = 0;
        M2C_FIELD(obj, u32 *, 0x30) = 0;
        M2C_FIELD(obj, u32 *, 0x34) = 0;
        M2C_FIELD(obj, u32 *, 0x38) = 0;
        M2C_FIELD(obj, u32 *, 0x3c) = 0;
    }
    obj->unknown04();

    // A volatile local keeps the size in memory: the ROM stores it with a
    // predicated store and reloads it for the call below.
    volatile s32 size;
    if (a[7] == 0) {
        size = 4096;
    } else {
        size = FX_Div(a[7] << 12, 40960);
    }

    func_0207f6b8(obj, (s32) ent, a[4], a[6], a[5], size, a[8] != 0, 1, a[2], a[3]);
    func_0207f56c(M2C_FIELD(&data_02106d90, void **, 0xad8), obj);
}
