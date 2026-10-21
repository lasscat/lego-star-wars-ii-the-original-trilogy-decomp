#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class Manager1CDB8 {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c(void *); // Slot 0x0c.
};

/* Configuration block copied into a freshly created object. */
struct Config {
    u8 pad[0x24];
    s32 f24;
    s32 f28;
    s32 f2c;
    s32 f30;
    s32 f34;
    s32 f38;
    u16 f3c;
    u16 f3e;
    u16 f40;
    u16 f42;
    u8 f44;
    u8 f45;
};

extern "C" s32 data_021019f4;
extern "C" s32 data_027e02a4;

extern "C" s32 func_0201cf04(s32 *table, s32 key);
extern "C" s32 func_0201cf44(s32 *table);
extern "C" void *func_0205e80c(s32 size, s32 align, s32 flag);
extern "C" void *func_0200ff50(void *obj, s32 a1, s32 a2, s32 a3, Config *a4);
extern "C" void func_02001990(void *self, s32 mode);

extern "C" s32 func_0201cdb8(s32 *table, s32 key) {
    s32 slot = func_0201cf04(table, key);
    if (slot == 0xffff) {
        slot      = func_0201cf44(table);
        void *obj = func_0205e80c(0x1bc, 3, 4);
        if (obj != 0) {
            Config cfg;
            cfg.f24 = 0;
            cfg.f28 = 0;
            cfg.f2c = 0;
            cfg.f30 = 0x1000;
            cfg.f34 = 0x1000;
            cfg.f38 = 0x1000;
            cfg.f3c = 0;
            cfg.f3e = 0;
            cfg.f40 = 0;
            cfg.f44 = 1;
            cfg.f45 = 1;
            obj     = func_0200ff50(obj, 4, key, 0, &cfg);
        }
        table[slot] = (s32) obj;
        func_02001990(obj, 0);
        Manager1CDB8 *mgr = (Manager1CDB8 *) ((s32) &data_021019f4 + data_027e02a4 * 0x38);
        mgr->unknown0c((void *) table[slot]);
    }
    return slot;
}
