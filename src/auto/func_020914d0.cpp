#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
//
// Same hierarchy as src/auto/func_0200e4ec.cpp (class EntityE4EC): the same
// global data_021027f8 is compared here and slot 0x0c is dispatched with the
// same "self + 0xb0" argument.
class EntityE4EC {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual s32 unknown0c(void *); // Slot 0x0c.
};

/* The 0x38-byte element array data_021019f4 (same layout as the Ent type of
 * src/auto/func_02093958.c); the walk follows the ->next chain. */
typedef struct {
    void *obj;
    void *next;
    u8 pad[0x30];
} Ent914D0;

extern "C" Ent914D0 data_021019f4[];
extern "C" s32 data_027e02a4;
extern "C" s32 data_027e02a8;
extern "C" u32 data_021027f8;

extern "C" s32 func_0204a880(void *);
extern "C" s32 func_02073034(void);
extern "C" void func_020976e0(EntityE4EC *e, void *t);

extern "C" void func_020914d0(void *arg0) {
    u8 *n = (u8 *) M2C_FIELD(&data_021019f4[data_027e02a4], void **, 4);
    for (; n != 0; n = (u8 *) M2C_FIELD(n, void **, 4)) {
        u8 *cand;
        u8 *t = (u8 *) M2C_FIELD(n, void **, 0);
        cand  = 0;
        if (M2C_FIELD(t, u16 *, 0xC) & 1) {
            cand = t;
            if (func_0204a880(t + 0x5CE) != 0) {
                continue;
            }
        }
        if (M2C_FIELD(t, u32 *, 8) & 0x802) {
            continue;
        }
        if ((M2C_FIELD(t, u16 *, 0xC) & 2) == 0) {
            if (cand == 0) {
                continue;
            }
            u8 v = M2C_FIELD(cand, u8 *, 0x5DA);
            if (v == M2C_FIELD(&data_021027f8, u8 *, 0x2A)) {
                continue;
            }
            if ((data_027e02a8 & 64) != 0) {
                if (v < (u32) func_02073034()) {
                    continue;
                }
            }
        }
        {
            u8 *it = (u8 *) M2C_FIELD(arg0, void **, 4);
            while (it != 0) {
                EntityE4EC *e = (EntityE4EC *) M2C_FIELD(it, void **, 0);
                it            = (u8 *) M2C_FIELD(it, void **, 4);
                u8 type       = M2C_FIELD(e, u8 *, 0x1C);
                if (type != 5 && type != 8) {
                    continue;
                }
                u8 v = (u8) (M2C_FIELD(e, u8 *, 0x2D) + 254);
                if (v > 1) {
                    continue;
                }
                if (e->unknown0c(t + 0xB0) == 0) {
                    continue;
                }
                func_020976e0(e, t);
            }
        }
    }
}
