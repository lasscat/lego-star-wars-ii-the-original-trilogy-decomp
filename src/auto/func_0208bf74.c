#include "m2c.h"

typedef struct {
    u8 pad0[0x54];
    void *unk54[4];
    void *unk64[2];
    u8 pad6C[0xC];
    u32 unk78;
} S;

M2C_UNK func_0208c588(s32, M2C_UNK, s32);           /* extern */

void func_0208bf74(S *arg0) {
    s32 i;

    for (i = 0; i < 4; i++) {
        void *p = arg0->unk54[i];
        if (p != NULL) {
            M2C_FIELD(p, s32 *, 8) &= ~1;
        }
    }
    for (i = 0; i < 2; i++) {
        void *p = arg0->unk64[i];
        if (p != NULL) {
            M2C_FIELD(p, s32 *, 8) &= ~1;
        }
    }
    func_0208c588((s32) ((u8 *) arg0 + 0x40), 0, (s32) ((u8 *) arg0 + 8));
    arg0->unk78 |= 4;
}
