#include "m2c.h"

/* Reconstructed from USA ARM9 at 0x0205f45c (196 bytes).
 *
 * func_0205f45c(Manager *mgr, s32 idx)
 *   if (mgr->state[idx] != 1) return;              // state byte at +0x90
 *   mgr->state[idx] = 3;
 *   mgr->objects[idx] = func_0205f574(mgr,        // object pointer at +0x00
 *                                     entry->field_00, entry->field_04,
 *                                     entry->field_08, entry->field_0c);
 *   entry->field_00 = 0;
 *   mgr->objects[idx]->unknown08();               // third vtable slot
 *   func_0205ffb8(mgr);
 *   data_027e02a8 &= ~(4 << idx);                  // global bit mask
 *   if (entry->field_1c == 0) func_02063a90(idx, 0);
 *   data_027e02a8 |= 0x10 << idx;
 *
 * The caller loops idx = 0..1, so the object holds two object pointers, two
 * 0x20 byte table entries and two state bytes.
 */

extern "C" s32 data_027e02a8;
extern "C" void *func_0205f574(void *, u32, s32, s32, s32);
extern "C" void func_0205ffb8(void *);
extern "C" void func_02063a90(s32, s32);

/* Partial interface: the object created by func_0205f574 is used through its
 * third vtable slot.  Declarations only: the original vtables remain in the
 * ROM data.
 */
class CreatedF45C {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08(); // Slot 0x08.
};

/* One 0x20 byte entry of the table at +0x48. */
struct EntryF45C {
    s32 field_00;
    s32 field_04;
    s32 field_08;
    s32 field_0c;
    s32 field_10;
    s32 field_14;
    s32 field_18;
    s32 field_1c;
};

/* The observed layout of the object:
 *   +0x00 the created objects      +0x48 two table entries (0x20 bytes each)
 *   +0x90 two state bytes
 */
struct ManagerF45C {
    CreatedF45C *objects[2]; // +0x00
    u8 pad_08[0x40];          // +0x08
    EntryF45C entries[2];     // +0x48
    u8 pad_88[8];             // +0x88
    u8 state[2];              // +0x90
};

extern "C" void func_0205f45c(ManagerF45C *mgr, s32 idx) {
    s32 flag;

    if (mgr->state[idx] != 1) {
        return;
    }
    mgr->state[idx]            = 3;
    mgr->objects[idx]          = (CreatedF45C *) func_0205f574(mgr, mgr->entries[idx].field_00, mgr->entries[idx].field_04,
                                                               mgr->entries[idx].field_08, mgr->entries[idx].field_0c);
    mgr->entries[idx].field_00 = 0;
    mgr->objects[idx]->unknown08();
    func_0205ffb8(mgr);
    data_027e02a8 &= ~(4 << idx);
    flag = (mgr->entries[idx].field_1c == 0);
    if (flag != 0) {
        func_02063a90(idx, 0);
    }
    data_027e02a8 |= 0x10 << idx;
}
