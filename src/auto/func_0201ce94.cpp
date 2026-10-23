#include "m2c.h"

/* Reconstructed from USA ARM9 at 0x0201ce94 (0x70 bytes).
 *
 * The global pool at data_021019f4 holds two 0x38-byte objects and
 * data_027e02a4 is the index of the current one.
 */

class Element1CE94;

// Partial interface of the pooled object: unknown virtuals keep their
// observed vtable slots. Declarations only, no vtable is emitted.
class Object1CE94 {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08(Element1CE94 *); // Slot 0x08.
    virtual void unknown0c();
    u8 pad[0x34];                          // Object size 0x38.
};

// Partial interface of the eight elements the argument points to.
class Element1CE94 {
public:
    virtual void unknown00();
    virtual void unknown04();
};

extern "C" Object1CE94 data_021019f4[2];
extern "C" s32 data_027e02a4;

extern "C" void func_0201ce94(Element1CE94 **arr) {
    for (u32 i = 0; i < 8; i++) {
        if (arr[i] != 0) {
            Object1CE94 *ent = &data_021019f4[data_027e02a4];
            ent->unknown08(arr[i]);
            if (arr[i] != 0) {
                arr[i]->unknown04();
            }
            arr[i] = 0;
        }
    }
}
