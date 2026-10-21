#include "m2c.h"

typedef struct Unk02010aa4 {
    u8 unk_00[0x8c];
    s32 unk_8c;
    u8 unk_90[0x148 - 0x90];
    s32 *unk_148;
    u8 unk_14c[0x190 - 0x14c];
    void *unk_190;
} Unk02010aa4;

extern void func_02017d24(Unk02010aa4 *);
extern void func_0205c774(void *, Unk02010aa4 *, void *, s32);

void func_02010aa4(Unk02010aa4 *self) {
    s32 *p;
    s32 v;
    s32 *vp;

    func_02017d24(self);
    vp = &v;
    p  = self->unk_148;
    if (p) {
        v = *p;
    } else {
        v = 0;
    }
    func_0205c774(self->unk_190, self, &self->unk_8c, *vp >> 12);
}
