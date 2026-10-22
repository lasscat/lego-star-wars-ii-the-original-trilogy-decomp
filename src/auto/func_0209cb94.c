/* Reconstructed from USA ARM9 at 0x0209cb94 (200 bytes). */
#include "m2c.h"

u32 func_02062ae4(s32 arg0);                                /* extern */
void func_020b04f0(void *arg0, s32 arg1, void *arg2, s32 arg3); /* extern */
extern M2C_UNK data_0210794c;

typedef struct Unk_0209cb94 {
    u8 unk_00[4];
    u16 unk_04;
    u8 unk_06;
    u8 unk_07[21];
} Unk_0209cb94;

void func_0209cb94(void *arg0) {
    Unk_0209cb94 buf[2];

    switch (M2C_FIELD(arg0, u8 *, 0x8c)) {
        case 0:
            func_020b04f0(&data_0210794c, 0xd, 0, 0xff);
            break;
        case 1:
            buf[1].unk_04 = func_02062ae4(0x1388);
            buf[1].unk_06 = 3;
            func_020b04f0(&data_0210794c, 0xa, &buf[1], 0xff);
            break;
        case 2:
            buf[0].unk_04 = func_02062ae4(0x1388);
            buf[0].unk_06 = 1;
            func_020b04f0(&data_0210794c, 0xa, &buf[0], 0xff);
            break;
        case 3:
            func_020b04f0(&data_0210794c, 0xb, 0, 0xff);
            break;
    }
}
