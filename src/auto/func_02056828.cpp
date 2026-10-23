#include "m2c.h"

// Partial interface: only the observed vtable slots are declared.
// Declarations only: the original vtable (data_020ff2b4) remains in the ROM data.
class Effect {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    void *field04;
    s32 field08;
    s16 field0c;
    s16 field0e;
};

extern "C" void *func_02067080(M2C_UNK, u8, u8);
extern "C" void *func_0205e80c(u32 size, int heap, int flags);
extern "C" void func_0207f56c(void *obj, void *arg);
extern "C" u8 data_020ff2b4[];
extern "C" u8 data_02106d90[];

extern "C" void func_02056828(M2C_UNK arg0, u8 *arg1) {
    void *entity = func_02067080(arg0, arg1[2], arg1[3]);
    if (entity == 0) {
        return;
    }
    Effect *effect = (Effect *) func_0205e80c(sizeof(Effect), 3, 4);
    if (effect != 0) {
        // The class vtable lives in the ROM data; store its address.
        *(void **) effect = (void *) data_020ff2b4;
    }
    effect->unknown04();
    effect->field0c = *(u16 *) arg1;
    effect->field04 = entity;
    effect->field0e = arg1[4];
    func_0207f56c(*(void **) ((u8 *) data_02106d90 + 0xad8), effect);
}
