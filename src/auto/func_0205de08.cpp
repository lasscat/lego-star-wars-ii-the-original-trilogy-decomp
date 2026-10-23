#include "m2c.h"

// Node of the list reached through obj->f04.
struct C5DE08Node {
    void *f00;
    C5DE08Node *f04; // next
    void *f08;
};

// Partial interface: the unknown virtuals keep their observed vtable slots;
// declarations only, the original vtable stays in the ROM data.
class C5DE08 {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18();
    virtual C5DE08Node *unknown1c(C5DE08Node *node, s32 count); // Slot 0x1c.
    C5DE08Node *f04;
    u32 f08;
    u16 f0c;
    u32 f10;
    void *f14;
};

extern "C" void func_0205e310(void *arg0, void *arg1);
extern "C" void func_0205d568(void *arg0);

extern "C" void func_0205de08(C5DE08 *obj) {
    C5DE08Node *var_r5;
    C5DE08Node *var_r6 = obj->f04;
    if (var_r6 != 0) {
        s32 var_r4 = 0;
        do {
            C5DE08Node *var_r1 = var_r6;
            if (var_r1 != 0) {
                var_r1 = (C5DE08Node *) ((char *) var_r1 - 4);
            }
            if (var_r1 != 0) {
                var_r1 = (C5DE08Node *) ((char *) var_r1 + 4);
            }
            var_r5 = obj->unknown1c(var_r1, var_r4);
            if (var_r6 != 0) {
                var_r6 = (C5DE08Node *) ((char *) var_r6 - 4);
            }
            func_0205e310(obj->f14, var_r6);
            obj->f0c = (u16) (obj->f0c - 1);
            var_r6   = var_r5;
        } while (var_r5 != 0);
    }
    func_0205d568(obj);
}
