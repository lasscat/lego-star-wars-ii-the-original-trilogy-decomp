#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class Entity325F0 {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18(int, int); // Slot 0x18.
    virtual void unknown1c();
    virtual void unknown20();
    virtual void action(int, int, int, int); // Slot 0x24.
    virtual void unknown28();
    virtual void interact(Entity325F0 *, int, int); // Slot 0x2c.
};

// Table entries are 36 bytes wide.
typedef struct {
    u16 v;
    u8 pad[34];
} M2C_T;

// Two byte aggregate, passed by value (the callee reads it back as a halfword).
typedef struct {
    u16 v;
} HalfVal;

// Four byte aggregate, passed by value.
typedef struct {
    s32 v;
} UnkVal;

extern "C" void func_02004b78(void *, M2C_UNK);
extern "C" void *func_0202cb44(void *);
extern "C" void func_02018200(void *, M2C_UNK, M2C_UNK);
extern "C" s32 func_0200ed14(s32, HalfVal, UnkVal, UnkVal, ...);
extern "C" M2C_T data_020f6bc2[];

extern "C" void func_020325f0(Entity325F0 *self) {
    void *p;
    u8 flags;
    u16 v;

    flags = M2C_FIELD(M2C_FIELD(self, Entity325F0 **, 0x4), u8 *, 0x6c4);
    if ((flags & 4) == 0 && (flags & 2) != 0) {
        func_02004b78((void *) M2C_FIELD(self, Entity325F0 **, 0x4), 0x1d);
        M2C_FIELD(self, u8 *, 0xc) = M2C_FIELD(self, u8 *, 0xc) | 1;
        return;
    }

    if (M2C_FIELD(M2C_FIELD(self, Entity325F0 **, 0x4), u16 *, 0xc) != 1) {
        M2C_FIELD(self, void **, 0x10) =
            (void *) func_0202cb44((void *) ((u8 *) M2C_FIELD(self, Entity325F0 **, 0x4) + 0x5e0));
        if (M2C_FIELD(self, void **, 0x10) != 0) {
            func_02018200((void *) M2C_FIELD(self, Entity325F0 **, 0x4), (M2C_UNK) M2C_FIELD(self, void **, 0x10), 0);
        }
    } else {
        HalfVal h;
        UnkVal u;
        UnkVal v2;
        h.v  = 0x2aaa;
        v2.v = 0x1e000;
        u.v  = 0x32000;
        func_0200ed14((s32) M2C_FIELD(self, Entity325F0 **, 0x4), h, u, v2);
    }

    M2C_FIELD(M2C_FIELD(self, Entity325F0 **, 0x4), s32 *, 0x8) =
        M2C_FIELD(M2C_FIELD(self, Entity325F0 **, 0x4), s32 *, 0x8) | 0x200;
    M2C_FIELD(M2C_FIELD(self, Entity325F0 **, 0x4), u16 *, 0x1a8) =
        M2C_FIELD(M2C_FIELD(self, Entity325F0 **, 0x4), u16 *, 0x1a8) | 2;
    M2C_FIELD(self, u8 *, 0xd) = 0;

    v = data_020f6bc2[M2C_FIELD(M2C_FIELD(self, Entity325F0 **, 0x4), u8 *, 0x6c3)].v;
    if (v & 8) {
        M2C_FIELD(self, Entity325F0 **, 0x4)->action(0x2c, 0, 1, 0);
        if (M2C_FIELD(M2C_FIELD(self, Entity325F0 **, 0x4), void **, 0x174) == 0) {
            self->unknown18(0xb, 5);
        }
    } else {
        M2C_FIELD(self, u8 *, 0xc) = M2C_FIELD(self, u8 *, 0xc) | 1;
    }
}
