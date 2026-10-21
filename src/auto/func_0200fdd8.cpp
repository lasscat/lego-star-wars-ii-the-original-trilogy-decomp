#include "m2c.h"

extern "C" s32 data_027e02a4;

/* Partial interface: unknown virtuals retain their observed vtable slots.
 * Declarations only: the original vtable remains in the ROM data.
 *
 * Class of the objects stored in the list of the current entry.  Slot 0x08
 * returns the identifier that is compared with the searched key.
 */
class Entry {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual u32 unknown08(); // Slot 0x08.
};

/* List node: { entry object, next node }. */
struct ListNode0FDD8 {
    Entry *entry;
    ListNode0FDD8 *next;
};

/* Entry table element; the list of entries starts at offset 0x04. */
struct Ent {
    void *f0;
    ListNode0FDD8 *f4;
    u8 pad[0x30];
};

extern "C" Ent data_021019f4[];

extern "C" Entry *func_0200fdd8(u32 key) {
    Ent *ent            = &data_021019f4[data_027e02a4];
    ListNode0FDD8 *node = ent->f4;
    while (node != 0) {
        Entry *entry = node->entry;
        if (entry->unknown08() == key) {
            return entry;
        }
        node = node->next;
    }
    return 0;
}
