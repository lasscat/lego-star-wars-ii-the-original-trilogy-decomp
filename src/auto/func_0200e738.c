#include "m2c.h"

typedef struct {
    s32 x, y, z;
} Vec3;

typedef struct {
    u16 v;
} UnkVal;

typedef struct {
    u8 pad[0x1c];
    u8 kind;
    u8 pad2[0x11];
    u8 f2e;
    u8 f2f;
    Vec3 f30;
} Other;

extern void *func_020aaeb4(void);
extern void func_020aaa8c(s32);
extern void func_020a99bc(void *, u8);
extern void func_020a9920(void *);
extern void func_020a0418(void *, s32, s8);
extern void func_020a042c(void *, s32, s8);
extern void func_020a2064(void *, UnkVal);
extern M2C_UNK data_0210930c;

#define G68 M2C_FIELD(&data_0210930c, void **, 0x68)
#define GSH M2C_FIELD(M2C_FIELD(G68, void **, 0x38c), void **, 0x4)
#define GARRAY M2C_FIELD(GSH, s32 *, 0x38)

void func_0200e738(void *arg0, Other *arg1) {
    void *global;
    s16 temp_r4;
    u8 temp_r6;
    u8 kind;

    M2C_FIELD(arg0, void **, 0x808) = arg1;
    func_020aaa8c((s32) func_020aaeb4());
    kind = arg1->kind;
    if (kind == 2) {
        func_020a99bc(func_020aaeb4(), 1);
        func_020a9920(func_020aaeb4());
        M2C_FIELD(func_020aaeb4(), s32 *, 0x220) = 0;
        M2C_FIELD(func_020aaeb4(), s32 *, 0x21c) = 0;
        temp_r6                                  = arg1->f2e;
        M2C_FIELD(func_020aaeb4(), u8 *, 0x241)  = temp_r6;
        func_020a0418(func_020aaeb4(), GARRAY + (arg1->f2f * 8), 1);
        temp_r4 = M2C_FIELD(arg1, s16 *, 0x30);
        if (temp_r4 < 0) {
            return;
        }
        func_020a042c(func_020aaeb4(), GARRAY + (temp_r4 * 8), 1);
        return;
    }
    if (kind == 3) {
        Vec3 position;
        func_020a99bc(func_020aaeb4(), 4);
        position = arg1->f30;
        global   = func_020aaeb4();
        if ((void *) ((s8 *) global + 0x264) != (void *) &position) {
            M2C_FIELD(global, s32 *, 0x264) = position.x;
            M2C_FIELD(global, s32 *, 0x268) = position.y;
            M2C_FIELD(global, s32 *, 0x26c) = position.z;
        }
        return;
    }
    if (kind == 4) {
        func_020a99bc(func_020aaeb4(), 4);
        func_020a2064(func_020aaeb4(), *(UnkVal *) &M2C_FIELD(arg1, u16 *, 0x2e));
        return;
    }
}
