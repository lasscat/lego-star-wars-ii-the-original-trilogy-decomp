#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class Entity {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18();
    virtual void unknown1c();
    virtual void unknown20();
    virtual void action(int, int, int, int); // Slot 0x24.
    virtual void unknown28();
    virtual void interact(Entity *, int, int); // Slot 0x2c.
};

// Flag word of an entity; the original code tests bit 1 of it.
typedef struct {
    u16 bit0 : 1;
    u16 bit1 : 1;
} EntityFlags;

// The owner object keeps its entity in the word at offset 0x3c.
#define OWNER_ENTITY(o) (*(Entity **) ((s8 *) (o) + 0x3c))

extern "C" {
s32 func_02066118(s32, s32, s32, s32);
void func_020661b4(s32, s32);
s32 func_02065be8(s32, s32, s32, s32, s32, s32);
s32 *func_02066708(s32);
}

extern "C" s32 func_0207f0f0(void *o) {
    s32 *p;
    s32 res;

    if (OWNER_ENTITY(o) == 0) {
        if (M2C_FIELD(o, s32 *, 0x30) < M2C_FIELD(o, s32 *, 0x34)) {
            M2C_FIELD(o, s32 *, 0x30) = M2C_FIELD(o, s32 *, 0x30) + 1;
            func_02066118(M2C_FIELD(o, s32 *, 8), 2, 1, 0x1e);
            func_02066118(M2C_FIELD(o, s32 *, 8), 2, 2, 0x1e);
            func_020661b4(M2C_FIELD(o, s32 *, 8), M2C_FIELD(o, s32 *, 0x30));
            p                         = func_02066708(0x241);
            M2C_FIELD(o, s32 *, 0x2c) = func_02065be8(M2C_FIELD(o, s32 *, 8), 0xf0, 0x80, 0xa, (s32) p, 1);
            if (M2C_FIELD(o, s32 *, 0x30) >= M2C_FIELD(o, s32 *, 0x34) || M2C_FIELD(o, s32 *, 0x30) >= 10) {
                return 0;
            }
        }
        return 1;
    }

    if (((EntityFlags *) &M2C_FIELD(OWNER_ENTITY(o), u16 *, 0x14e))->bit1 == 1 &&
        M2C_FIELD(o, s32 *, 0x30) < M2C_FIELD(o, s32 *, 0x34)) {
        M2C_FIELD(o, s32 *, 0x30) = M2C_FIELD(o, s32 *, 0x30) + 1;
        func_02066118(M2C_FIELD(o, s32 *, 8), 2, 1, 0x1e);
        func_02066118(M2C_FIELD(o, s32 *, 8), 2, 2, 0x1e);
        func_020661b4(M2C_FIELD(o, s32 *, 8), M2C_FIELD(o, s32 *, 0x30));
        p                         = func_02066708(0x241);
        M2C_FIELD(o, s32 *, 0x2c) = func_02065be8(M2C_FIELD(o, s32 *, 8), 0xf0, 0x80, 0xa, (s32) p, 1);
        OWNER_ENTITY(o)->action(M2C_FIELD(o, s32 *, 0x30) + 0xe4, 0, 1, 0);
        OWNER_ENTITY(o)->action(M2C_FIELD(o, s32 *, 0x30) + 0x79, 0, 1, 0);
        if (M2C_FIELD(o, s32 *, 0x30) >= M2C_FIELD(o, s32 *, 0x34) || M2C_FIELD(o, s32 *, 0x30) >= 10) {
            res = 0;
        } else {
            res = 1;
        }
        return res;
    }
    return 1;
}
