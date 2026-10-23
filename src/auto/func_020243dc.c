/* Reconstructed from USA ARM9 at 0x020243dc (356 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

extern M2C_UNK data_020fd9b0;
extern M2C_UNK func_02024540;
extern M2C_UNK func_02024550;

void func_02011384(void *, s32);
M2C_UNK func_020e46bc(void *, M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK *);
M2C_UNK func_0205e624(void *, M2C_UNK, M2C_UNK);

void *func_020243dc(void *arg0, u32 arg1, void *arg2, void *arg3) {
    func_02011384(arg0, arg1);
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fd9b0;
    func_020e46bc((s8 *) arg0 + 0x220, 2, 8, &func_02024540, &func_02024550);
    M2C_FIELD(arg0, s32 *, 0x8) &= ~0x1000000;
    M2C_FIELD(arg0, s8 *, 0x1bc) = 0;
    func_0205e624((s8 *) arg0 + 0x220, 0, 0x10);
    M2C_FIELD(arg0, s8 *, 0x230)  = (arg1 == 0xa4) ? 1 : 2;
    M2C_FIELD(arg0, s8 *, 0x231)  = 0;
    M2C_FIELD(arg0, s8 *, 0x232)  = 0;
    M2C_FIELD(arg0, s8 *, 0x1d8)  = 0;
    M2C_FIELD(arg0, u16 *, 0x234) = 0;
    M2C_FIELD(arg0, s8 *, 0x236)  = 0;
    M2C_FIELD(arg0, s32 *, 0x238) = 0;
    M2C_FIELD(arg0, s32 *, 0x218) = 0;
    switch (arg1) {
        case 0x2b:
            M2C_FIELD(arg0, s8 *, 0x21c) = 0x5f;
            break;
        case 0x115:
            M2C_FIELD(arg0, s8 *, 0x21c) = 0x11;
            break;
        case 0x187:
            M2C_FIELD(arg0, s8 *, 0x21c) = 0xf;
            break;
        case 0xa4:
            M2C_FIELD(arg0, s32 *, 0x84) = 3;
            M2C_FIELD(arg0, u16 *, 0x210) |= 1;
            M2C_FIELD(arg0, s8 *, 0x21c) = 0x3c;
            break;
        case 0x96:
            M2C_FIELD(arg0, s32 *, 0x84) = 3;
            M2C_FIELD(arg0, u16 *, 0x210) |= 1;
            /* fall through */
        case 0x18:
        case 0x4a:
        case 0x85:
        default:
            M2C_FIELD(arg0, s8 *, 0x21c) = 0x40;
            break;
    }
    return arg0;
}
