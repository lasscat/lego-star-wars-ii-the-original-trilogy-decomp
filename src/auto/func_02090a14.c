#include "m2c.h"

M2C_UNK func_020966a4(void *);       /* extern */
M2C_UNK func_0201cd88(void *);
M2C_UNK func_0208d3e4(void *);
M2C_UNK func_02094380(void *);
M2C_UNK func_020550c4(void *);
M2C_UNK func_02083940(void *);
M2C_UNK func_02095f18(void *);

void *func_02090a14(u8 *self) {
    s32 i;
    s8 *b;
    u16 *p;
    u16 *e;

    func_020966a4(self);
    M2C_FIELD(self, s32 *, 0x3c) = 0;
    M2C_FIELD(self, s32 *, 0x40) = 0;
    M2C_FIELD(self, s8 *, 0x48)  = 0;
    M2C_FIELD(self, s32 *, 0x5c) = 0;
    p                            = (u16 *) (self + 0x60);
    do {
        *p++ = 0xffff;
    } while ((u8 *) p < (u8 *) (self + 0x68));
    M2C_FIELD(self, s32 *, 0x68) = 0;
    func_0201cd88(self + 0x74);
    func_0208d3e4(self + 0x94);
    func_02094380(self + 0xa4);
    func_020550c4(self + 0x1a0);
    func_02083940(self + 0x5c4);
    func_02095f18(self + 0x61c);
    M2C_FIELD(self, s8 *, 0x924)  = 0;
    M2C_FIELD(self, s8 *, 0x925)  = 0;
    M2C_FIELD(self, s32 *, 0x928) = 0;
    M2C_FIELD(self, s8 *, 0x92c)  = 0;
    M2C_FIELD(self, s8 *, 0x92d)  = 0;
    M2C_FIELD(self, s32 *, 0x958) = 0x1000;
    M2C_FIELD(self, s32 *, 0x95c) = 0x1000;
    M2C_FIELD(self, s32 *, 0x960) = 0;
    b                             = (s8 *) self;
    for (i = 0; i < 4; i++) {
        ((s32 *) ((s8 *) self + 0x4c))[i] = 0;
        b[0x92e + i]                      = 0xff;
        b[0x932 + i]                      = 0;
    }
    return self;
}
