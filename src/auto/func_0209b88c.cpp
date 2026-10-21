#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class Target9B88C {
public:
    // No virtual slot is observed on this object.
};

class Entity9B88C {
public:
    virtual Target9B88C *unknown00(int); // Slot 0x00.
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18();
    virtual s32 unknown1c(); // Slot 0x1c.
};

/* Object updated by this function. */
typedef struct {
    u8 pad00[0x0c];
    u8 f0c;
    u8 pad10[0x1f];
    u8 flags[4];
    u8 order[4];
    u8 pad34[0x04];
    s32 f38;
    s32 f3c;
    u8 pad40[0x10];
    u8 f50;
    u8 pad51[0x61];
    u16 f0b2;
} Obj9B88C;

extern "C" Entity9B88C *data_021092f4;
extern "C" M2C_UNK data_02102900;
extern "C" M2C_UNK data_02108d90;
extern "C" M2C_UNK data_0210794c;

extern "C" s16 func_0209bc04(void *, s32);
extern "C" void func_02072cd0(void);
extern "C" void func_0205ecc4(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
extern "C" s32 func_02060198(void *);
extern "C" void func_020b04f0(void *, M2C_UNK, void *, M2C_UNK);

extern "C" void func_0209b88c(Obj9B88C *self) {
    s32 arr[14];
    self->f0c = 0;
    if (self->f50 != 0) {
        u8 i;
        for (i = 0; i < 4; i++) {
            u8 j;
            for (j = i + 1; j < 4; j++) {
                if (self->flags[self->order[i]] == 100) {
                    continue;
                }
                if (self->flags[self->order[j]] == 100) {
                    continue;
                }
                if (func_0209bc04(self, self->order[i]) < func_0209bc04(self, self->order[j])) {
                    u8 tmp         = self->order[i];
                    self->order[i] = self->order[j];
                    self->order[j] = tmp;
                }
            }
        }
        if (data_021092f4 == 0) {
            self->f50 = 0;
            return;
        }
        if (data_021092f4->unknown1c() != 0) {
            return;
        }
        if (self->f0b2 != 0) {
            Target9B88C *obj = data_021092f4->unknown00(0);
            if (self->f0b2 != M2C_FIELD(obj, u16 *, 0x66)) {
                func_02072cd0();
                self->f50 = 0;
                func_0205ecc4(&data_02102900, 0xf, 0, 0, 0, 0);
                func_0205ecc4(&data_02102900, 0x26, 1, 0, 0, 0);
                M2C_FIELD(&data_02102900, s32 *, 0x84) = 1;
                M2C_FIELD(&data_02102900, s32 *, 0x64) = 1;
                return;
            }
        }
        Target9B88C *obj = data_021092f4->unknown00(0);
        self->f0b2       = M2C_FIELD(obj, u16 *, 0x66);
        s32 diff         = (s32) ((s64) (self->f38 + self->f3c) - M2C_FIELD(&data_02108d90, s32 *, 0x4c8));
        if (diff == 0x3c) {
            if (func_02060198(&data_02102900) == 0) {
                arr[7] = 0;
                func_020b04f0(&data_0210794c, 0x35, &arr[7], 0xff);
            }
        }
        if (diff == 0x1e) {
            if (func_02060198(&data_02102900) == 0) {
                arr[0] = 1;
                func_020b04f0(&data_0210794c, 0x35, &arr[0], 0xff);
            }
        }
        if (diff > 0) {
            return;
        }
        func_020b04f0(&data_0210794c, 0x12, 0, 0xff);
    }
}
