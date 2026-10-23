#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class Element {
public:
    virtual void unknown00();
    virtual void unknown04(); // Slot 0x04.
};

struct Obj74034 {
    u8 pad00[0x38];
    void *field38;
    void *field3c;
    u8 pad40[0x58];
    Element *element[2]; // 0x98.
};

extern "C" M2C_UNK data_02101b78;
extern "C" M2C_UNK data_02101b98;
extern "C" M2C_UNK data_027e0874;

extern "C" void func_0205eb98(void);
extern "C" s32 func_020aaeb4(void);
extern "C" void func_020aa048(void);
extern "C" void func_02053f80(void *);
extern "C" M2C_UNK func_02055c48(s32);
extern "C" M2C_UNK func_020ac278(M2C_UNK *, M2C_UNK, M2C_UNK);
extern "C" void G3X_SetClearColor(s32, s32, s16, s32, s32);
extern "C" M2C_UNK func_0206d5a8(s32);
extern "C" M2C_UNK func_0205e84c(void *);

extern "C" void func_02074034(Obj74034 *self) {
    func_0205eb98();
    func_020aaeb4();
    func_020aa048();
    func_02053f80(&data_02101b78);
    func_02053f80(&data_02101b98);
    func_02055c48(1);
    for (u32 i = 0; i < 2; i++) {
        Element *e = self->element[i];
        if (e != 0) {
            if (e != 0) {
                e->unknown04();
            }
            self->element[i] = 0;
        }
    }
    func_020ac278(&data_027e0874, 4, 0);
    G3X_SetClearColor(0, 0x1f, 0x7fff, 0x3f, 0);
    void *p = self->field38;
    if (p != 0) {
        func_0206d5a8((s32) p);
        func_0205e84c(p);
    }
    p = self->field3c;
    if (p == 0) {
        return;
    }
    func_0206d5a8((s32) p);
    func_0205e84c(p);
}
