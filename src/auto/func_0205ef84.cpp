#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class AnimObject {
public:
    virtual void unknown00();
    virtual void unknown04(); // Slot 0x04.
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10(); // Slot 0x10.
    virtual void unknown14(s32, s32, s32); // Slot 0x14.
};

extern "C" u32 data_027e02a8;

extern "C" u8 func_02063948(s32, s32);
extern "C" void func_02063ae0(s32, s32);

extern "C" s32 func_0205ef84(void *self, s32 index, u8 *out) {
    s32 result = 0;
    if (data_027e02a8 & (0x10 << index)) {
        if (func_02063948(index, 0) == 3) {
            data_027e02a8 = data_027e02a8 & ~(0x10 << index);
            u8 *states;
            if (*(u32 *) ((u8 *) self + index * 0x20 + 0x48) != 0 && ((states = (u8 *) self + 0x90), states[index] == 2)) {
                data_027e02a8 = data_027e02a8 | (4 << index);
                states[index] = 1;
                if (*(AnimObject **) ((u8 *) self + index * 4) != 0) {
                    (*(AnimObject **) ((u8 *) self + index * 4))->unknown10();
                    u8 *src                = (u8 *) *(AnimObject **) ((u8 *) self + index * 4);
                    u8 *dest               = (u8 *) self + (index << 5);
                    *(u32 *) (dest + 0x08) = *(u32 *) (src + 0x04);
                    *(u32 *) (dest + 0x0c) = *(u32 *) (src + 0x08);
                    *(u32 *) (dest + 0x10) = *(u32 *) (src + 0x0c);
                    *(u32 *) (dest + 0x14) = *(u32 *) (src + 0x10);
                    *(u32 *) (dest + 0x18) = *(u32 *) (src + 0x14);
                    *(u32 *) (dest + 0x1c) = *(u32 *) (src + 0x18);
                    *(u32 *) (dest + 0x20) = *(u32 *) (src + 0x1c);
                    *(u32 *) (dest + 0x24) = *(u32 *) (src + 0x20);
                    if (*(AnimObject **) ((u8 *) self + index * 4) != 0) {
                        (*(AnimObject **) ((u8 *) self + index * 4))->unknown04();
                    }
                    *(AnimObject **) ((u8 *) self + index * 4) = 0;
                    result                                     = 1;
                }
            } else {
                AnimObject *obj = *(AnimObject **) ((u8 *) self + index * 4);
                if (obj != 0) {
                    obj->unknown14(8, 0, 0);
                }
            }
        }
        *out = 1;
    } else {
        if (*(u32 *) ((u8 *) self + index * 0x20 + 0x48) != 0) {
            {
                u8 flag = (*(u32 *) ((u8 *) self + index * 0x20 + 0x64) == 0);
                if (flag) {
                    func_02063ae0(index, 0);
                }
            }
            data_027e02a8 |= (0x10 << index);
            u8 *rowptr      = (u8 *) self + index;
            rowptr[0x90]    = 2;
            AnimObject *obj = *(AnimObject **) ((u8 *) self + index * 4);
            if (obj != 0) {
                obj->unknown14(7, 0, 0);
            }
        } else {
            *out = 1;
        }
    }
    return result;
}
