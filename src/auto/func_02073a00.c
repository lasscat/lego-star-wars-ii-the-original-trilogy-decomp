/* Reconstructed from USA ARM9 at 0x02073a00 (360 bytes).
 * Names and types are inferred from the binary.
 *
 * The original routine is a C++ constructor of a class whose vtable lives at
 * data_020fec0c; it first installs the base class vtable (data_020fe6d0) and
 * then its own. It is reconstructed here as plain C, following the same
 * m2c-style idiom already used for the sibling constructors in src/auto.
 */
#include "m2c.h"

M2C_UNK func_020534e0(void *);                      /* extern */
M2C_UNK func_0206549c(s32 *);                       /* extern */
M2C_UNK func_0205e80c(s32, s32, s32);               /* extern */
M2C_UNK func_0206d4d0(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
void func_020e46bc(M2C_UNK, M2C_UNK, M2C_UNK, void (*)(), void (*)()); /* extern */
s32 func_02062a7c(s32, s32);                        /* extern */
void func_0206afa4(void);                           /* extern */
void func_02064a34(void *);                         /* extern */
extern M2C_UNK data_020fe6d0;
extern M2C_UNK data_020fec0c;

typedef struct {
    M2C_UNK *f00;
    s32 f04;
    s32 f08;
    s32 f0C;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1C;
    s32 f20;
    s32 f24;
    s32 f28;
    s32 f2C;
    s32 f30;
    s32 f34;
    s32 f38;
    s32 f3C;
    s32 f40;
    u8 f44[0x2C];
    s32 f70;
    u8 f74[0x24];
    s32 f98[2];
    s16 fA0[2];
    s16 fA4[2];
    u8 fA8;
    u8 fA9;
    u8 fAA;
} Unknown_02073a00;

void *func_02073a00(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Unknown_02073a00 *var_r4 = (Unknown_02073a00 *) arg0;
    u32 i;
    M2C_UNK var_r0;

    var_r4->f00 = &data_020fe6d0;
    var_r4->f04 = arg1;
    var_r4->f08 = arg2;
    var_r4->f0C = arg3;
    var_r4->f10 = arg4;
    var_r4->f14 = 0;
    var_r4->f18 = 0;
    var_r4->f1C = 0;
    var_r4->f20 = 0;
    var_r4->f24 = 0;
    var_r4->f00 = &data_020fec0c;
    func_020534e0(&var_r4->f28);
    func_020534e0(&var_r4->f30);
    var_r4->f38 = 0;
    var_r4->f3C = 0;
    func_0206549c(&var_r4->f40);
    var_r4->f70 = 0;
    func_020e46bc(&var_r4->f74[0], 3, 0xC, func_02064a34, func_0206afa4);
    var_r4->fA8 = 0;
    var_r4->fA9 = 0;
    var_r4->fAA = 0;
    for (i = 0; i < 2; i++) {
        var_r4->f98[i] = 0;
        var_r4->fA0[i] = 0;
        var_r4->fA4[i] = func_02062a7c(0, 0x40);
    }
    if (var_r4->f08 == 4) {
        var_r4->f38 = var_r4->f0C;
        var_r4->f3C = var_r4->f10;
    } else {
        var_r0 = func_0205e80c(0x2C, 3, 4);
        if (var_r0 != 0) {
            var_r0 = func_0206d4d0(var_r0, 0, 1, 2, 3);
        }
        var_r4->f38 = var_r0;
        var_r0      = func_0205e80c(0x2C, 3, 4);
        if (var_r0 != 0) {
            var_r0 = func_0206d4d0(var_r0, 1, 1, 0, 1);
        }
        var_r4->f3C = var_r0;
    }
    return arg0;
}
