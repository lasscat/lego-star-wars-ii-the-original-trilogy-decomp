#include "m2c.h"

// Node of the chain reached through obj->f04.
struct C94610Node {
    void *f00;
    C94610Node *f04; // next
};

// Row of the table at obj + 0xb0 (16 bytes each, four rows).
struct C94610Row {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
};

// Polymorphic member embedded at obj + 0x38.
// Partial interface: the unknown virtuals keep their observed vtable slots;
// declarations only, the original vtable stays in the ROM data.
class C94610Sub {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18(); // Slot 0x18.
    u32 f04;
};

// Receiver of the function.
// Partial interface: the unknown virtuals keep their observed vtable slots;
// declarations only, the original vtable stays in the ROM data.
class C94610 {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18(); // Slot 0x18.
    C94610Node *f04;
    u8 pad[0x30];
    C94610Sub sub38;
    u8 pad2[0x70];
    C94610Row rows[4];
};

extern "C" void *func_0205e84c(void *arg0);
extern "C" s32 func_020653d4(void *arg0);

extern "C" void func_02094610(C94610 *obj) {
    C94610Node *node = obj->f04;
    if (node != 0) {
        do {
            void *data = node->f00;
            if (data != 0) {
                func_0205e84c(data);
            }
            node = node->f04;
        } while (node != 0);
    }
    obj->unknown18();
    obj->sub38.unknown18();
    for (u32 i = 0; i < 4; i++) {
        func_020653d4(&obj->rows[i]);
    }
    M2C_FIELD(obj, u8 *, 0xf7) = 0;
}
