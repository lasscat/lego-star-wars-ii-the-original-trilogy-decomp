#include "m2c.h"

/* Partial interface: unknown virtuals retain their observed vtable slots.
 * Declarations only: the original vtable remains in the ROM data. */
class Thing71268 {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c(); /* Slot 0x0c. */
};

typedef struct {
    u8 a : 4;
    u8 b : 1;
    u8 c : 3;
} ByteFlags71268;

typedef struct {
    s16 f0;
    s16 f2;
    s16 f4;
    s16 f6;
} Rec71268;

typedef struct {
    ByteFlags71268 flags;
    u8 pad[0x29];
    s16 f2a;
    s16 f2c;
} Glob71268;

extern "C" Glob71268 data_021044a4;
extern "C" Rec71268 data_020edf64[];
extern "C" u8 data_021027f8[];
extern "C" s32 func_0205d0d0(void *, u32, u32);
extern "C" void func_02071184(void *);

#define F90 (*(s32 *) ((s8 *) self + 0x90))
#define F8C (*(s32 *) ((s8 *) self + 0x8c))

extern "C" void func_02071268(void *self) {
    if (data_021044a4.flags.b) {
        s16 t1    = data_021044a4.f2a;
        s16 t2    = data_021044a4.f2c;
        s8 result = -1;
        u8 i;
        for (i = 0; i < 4; i++) {
            s16 a = data_020edf64[i].f0;
            /* The three condition flags are declared in reverse order of
             * use: that ordering reproduces the original register
             * allocation (cond3 -> r3, cond2 -> r12, cond1 -> lr). */
            int cond3 = 0;
            int cond2 = 0;
            int cond1 = 0;
            if (!(t1 < a)) {
                s16 c = data_020edf64[i].f4;
                if (t1 < a + c) {
                    cond1 = 1;
                }
            }
            if (cond1) {
                s16 b = data_020edf64[i].f2;
                if (t2 >= b) {
                    cond2 = 1;
                }
            }
            if (cond2) {
                s16 b = data_020edf64[i].f2;
                s16 d = data_020edf64[i].f6;
                if (t2 < b + d) {
                    cond3 = 1;
                }
            }
            if (cond3) {
                result = (s8) i;
                break;
            }
        }
        if (result == -1) {
            return;
        }
        if (result != F90) {
            F90 = result;
            func_02071184(self);
            return;
        }
        switch (F90) {
            case 0:
                F8C = 0xb;
                break;
            case 1:
                F8C = 0xc;
                break;
            case 2:
                F8C = 0xd;
                break;
            case 3:
                F8C = 0xa;
                break;
        }
        ((Thing71268 *) self)->unknown0c();
    } else {
        if (func_0205d0d0(data_021027f8, 0x40, 4) != 0) {
            s32 v = F90 - 1;
            F90   = v;
            if (v < 0 || v >= 4) {
                F90 = 3;
            }
            func_02071184(self);
            return;
        }
        if (func_0205d0d0(data_021027f8, 0x80, 4) != 0) {
            s32 v = F90 + 1;
            F90   = v;
            if (v < 0 || v >= 4) {
                F90 = 0;
            }
            func_02071184(self);
            return;
        }
        if (func_0205d0d0(data_021027f8, 1, 4) != 0) {
            switch (F90) {
                case 0:
                    F8C = 0xb;
                    break;
                case 1:
                    F8C = 0xc;
                    break;
                case 2:
                    F8C = 0xd;
                    break;
                case 3:
                    F8C = 0xa;
                    break;
            }
            ((Thing71268 *) self)->unknown0c();
        }
    }
}
