#include "m2c.h"

typedef struct {
    u8 pad[0x88];
    u8 id;
    u8 sub;
} Item;

typedef struct {
    u8 id;
    u8 sub;
} Slot;

typedef struct {
    u8 pad[0x1d];
    u8 ids[3];
    Slot slots[3];
} Owner;

static inline s32 slot_matches(Slot *slot, void *item) {
    s32 match = 0;

    if (slot->id == M2C_FIELD(item, u8 *, 0x88) && slot->sub == M2C_FIELD(item, u8 *, 0x89)) {
        match = 1;
    }
    return match;
}

s32 func_020838b8(Owner *arg0, Item *arg1) {
    s32 i;
    s32 j;
    s32 found;

    if (arg1->sub != 0) {
        for (i = 0; i < 3; i++) {
            if (arg1->id == arg0->ids[i]) {
                return 1;
            }
        }
        for (j = 0; j < 3; j++) {
            found = 0;
            if (slot_matches(&arg0->slots[j], arg1)) {
                found = 1;
            }
            if (found) {
                return 1;
            }
        }
    }
    return 0;
}
