#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class ManagerAF594 {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14();
    virtual void *unknown18(void *); // Slot 0x18.
    virtual s32 unknown1c();         // Slot 0x1c.
    virtual void unknown20();
    virtual void *unknown24(s32);    // Slot 0x24.
};

extern "C" s32 data_0210b348;
extern "C" u32 data_027e02a8;

extern "C" s32 func_020ad310();
extern "C" void DC_FlushRange(void *base, u32 size);
extern "C" void func_020ce878();
extern "C" void *func_020af3c0(void *obj);
extern "C" void *func_020af3c8(void *obj, u16 index);
extern "C" void func_020af3d8(void *obj, u16 index, u8 value);
extern "C" void MI_CpuCopy8(const void *src, void *dest, u32 size);

extern "C" s32 func_020af594(void *obj) {
    if (func_020ad310() == 5) {
        DC_FlushRange((s8 *) obj + 0x40, 512);
        DC_FlushRange((s8 *) obj + 0x240, 512);
        while ((*(ManagerAF594 **) &data_0210b348)->unknown18(func_020af3c0(obj)) == 0) {
            if (func_020ad310() != 5) {
                return 0;
            }
            if ((*(ManagerAF594 **) &data_0210b348)->unknown1c() == 3) {
                return 0;
            }
            func_020ce878();
        }
        for (u16 i = 0; i < 4; i++) {
            void *p   = func_020af3c8(obj, i);
            void *res = (*(ManagerAF594 **) &data_0210b348)->unknown24(i);
            if (res != 0) {
                MI_CpuCopy8(res, p, 112);
                func_020af3d8(obj, i, 1);
            } else {
                func_020af3d8(obj, i, 0);
            }
        }
    } else {
        for (u16 i = 0; i < 3; i++) {
            func_020af3d8(obj, i, 0);
        }
        if ((data_027e02a8 & 64) != 0) {
            return 0;
        }
    }
    return 1;
}
