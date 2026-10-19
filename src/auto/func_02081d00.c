#include "m2c.h"

typedef struct {
    u8 pad0[0x28];
    void *unk28[8];
    u8 pad48[0xC0 - 0x48];
    void *unkC0[8];
    u8 padE0[0x108 - 0xE0];
    s32 f108;
    s32 arr10C[3];
    u8 pad118[0x124 - 0x118];
    s32 f124;
} S;

M2C_UNK func_02081de4(void *, s32, s32);            /* extern */
M2C_UNK func_02081eac(void *, s32);                 /* extern */
M2C_UNK func_02082648(void *);                      /* extern */

void func_02081d00(S *arg0, s32 arg1) {
    s32 i;

    if (arg1 == arg0->f108) {
        return;
    }
    if (arg0->f108 < 6) {
        i = 0;
        do {
            if (arg0->unkC0[i] != NULL) {
                void *vt = M2C_FIELD(arg0->unkC0[i], void **, 0);
                ((void (*)(void *)) M2C_FIELD(vt, void **, 4))(arg0->unkC0[i]);
            }
            arg0->unkC0[i] = NULL;
            if (arg0->unk28[i] != NULL) {
                M2C_FIELD(arg0->unk28[i], s32 *, 8) |= 2;
                arg0->unk28[i] = NULL;
            }
            i += 1;
        } while (i < 8);
    }
    arg0->f108 = arg1;
    arg0->f124 = 0;
    for (i = 0; i < 6; i++) {
        func_02081de4(arg0, i, (i == arg0->f108) ? 1 : 0);
    }
    for (i = 0; i < 3; i++) {
        func_02081eac(arg0, i + arg0->arr10C[arg0->f108]);
    }
    func_02082648(arg0);
}
