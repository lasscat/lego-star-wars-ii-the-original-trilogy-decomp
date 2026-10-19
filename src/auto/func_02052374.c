#include "m2c.h"

M2C_UNK func_02083b14(M2C_UNK *, M2C_UNK, s32 *, s32 *, s32, s32, s32, s32, s32, s32, s32, s32, s32); /* extern */
extern M2C_UNK data_021098d0;

s32 func_02052374(void *arg0) {
    s16 *p = arg0;
    s32 coords[3];
    s32 size[3];
    s32 a;
    s32 b;
    s32 c;
    s32 u;

    c         = p[2] << 0xC;
    b         = p[1] << 0xC;
    a         = p[0] << 0xC;
    coords[0] = a;
    coords[1] = b;
    coords[2] = c;
    u         = ((u16 *) arg0)[4] << 0xC;
    size[0]   = u;
    size[1]   = u;
    size[2]   = u;
    func_02083b14(&data_021098d0, 1, coords, size, (s32) M2C_FIELD(arg0, u8 *, 0xA), (s32) M2C_FIELD(arg0, u8 *, 0xB),
                  (s32) M2C_FIELD(arg0, u8 *, 0xC), (s32) M2C_FIELD(arg0, u8 *, 0xD), (s32) M2C_FIELD(arg0, u8 *, 0xE),
                  (s32) M2C_FIELD(arg0, u8 *, 0xF), (s32) M2C_FIELD(arg0, u8 *, 0x10), (s32) M2C_FIELD(arg0, u8 *, 0x11),
                  (s32) M2C_FIELD(arg0, u8 *, 0x12));
    return 0;
}
