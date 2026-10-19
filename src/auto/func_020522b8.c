#include "m2c.h"

M2C_UNK func_02083b14(M2C_UNK *, M2C_UNK, s32 *, s32 *, s32, s32, s32, s32, s32, s32, s32, s32, s32); /* extern */
extern M2C_UNK data_021098d0;

s32 func_020522b8(void *arg0) {
    s16 *p = arg0;
    s32 coords[3];
    s32 size[3];
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 e;
    s32 f;

    c         = p[2] << 0xC;
    b         = p[1] << 0xC;
    a         = p[0] << 0xC;
    coords[0] = a;
    coords[1] = b;
    coords[2] = c;
    f         = ((u16 *) arg0)[6] << 0xC;
    e         = ((u16 *) arg0)[5] << 0xC;
    d         = ((u16 *) arg0)[4] << 0xC;
    size[0]   = d;
    size[1]   = e;
    size[2]   = f;
    func_02083b14(&data_021098d0, 0, coords, size, (s32) M2C_FIELD(arg0, u8 *, 0xE), (s32) M2C_FIELD(arg0, u8 *, 0xF),
                  (s32) M2C_FIELD(arg0, u8 *, 0x10), (s32) M2C_FIELD(arg0, u8 *, 0x11), (s32) M2C_FIELD(arg0, u8 *, 0x12),
                  (s32) M2C_FIELD(arg0, u8 *, 0x13), (s32) M2C_FIELD(arg0, u8 *, 0x14), (s32) M2C_FIELD(arg0, u8 *, 0x15),
                  (s32) M2C_FIELD(arg0, u8 *, 0x16));
    return 0;
}
