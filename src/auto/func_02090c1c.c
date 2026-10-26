#include "m2c.h"

M2C_UNK func_020914d0(void *);
M2C_UNK func_0209679c(void *);

extern u8 data_02106d90[];
extern s32 *data_02102900;
extern u8 data_021027f8[];
extern M2C_UNK data_021019f4;
extern M2C_UNK data_027e03a0;

enum {
    STATE_READY = 4,
    SLOT_COUNT  = 4,
};

/* Per-frame update of an object: clears the pending flag when the global state reaches 4, runs the
   sub-updates if a child (+0x68) is attached, then notifies each of the 4 slot pointers (+0x4c). */
void func_02090c1c(u8 *obj) {
    s32 state; /* global state value, 0 if no global block */
    s32 i;

    if (obj[0x48] != 0 && data_02106d90[0xc28] != 0) {
        state = data_02102900 != NULL ? data_02102900[1] : 0;
        if (state == STATE_READY) {
            func_0208cecc((s32) data_02102900);
            obj[0x48] = 0;
        }
    }
    if (*(void **) (obj + 0x68) != NULL) {
        func_02093700(obj);
        func_02093a00(obj);
        func_0208fb24(*(void **) (obj + 0x68));
        if (obj[0x925] != 0) {
            func_0209289c(obj);
            obj[0x925] = 0;
        } else if (*(s32 *) (obj + 0x928) != 0) {
            func_020927f0(obj);
            *(s32 *) (obj + 0x928) = 0;
        }
        if (data_021027f8[0x2a] == 0) {
            func_02091688(obj);
        }
        func_020914d0(obj);
        func_0209679c(obj);
        func_02091604(obj);
        for (i = 0; i < SLOT_COUNT; i++) {
            void *slot = ((void **) (obj + 0x4c))[i];
            if (slot != NULL) {
                func_0200e890(slot, &data_021019f4);
            }
        }
    }
    func_020612ac(&data_027e03a0);
    func_0208d5dc(obj + 0x94);
}
