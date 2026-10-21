#include "m2c.h"

extern M2C_UNK data_02101b78;
extern M2C_UNK data_02104d18;
extern M2C_UNK data_0210930c;
extern M2C_UNK data_02104d90;
extern M2C_UNK data_02102900;
extern M2C_UNK data_02107944;
extern M2C_UNK data_021093a0;

void func_02067c68(M2C_UNK *);
void func_02053f60(void *, s32);
void func_02053f44(void *, s32);
void func_02053f24(void *, s32);
void GX_SetBankForBG(s32);
void GX_SetBankForSubBG(s32);
s32 func_020867ec(M2C_UNK *, s32);
void func_02060158(M2C_UNK *, s32, s32, s32);
void func_02001688(s32);
void func_020016c0(void);
void func_020675d8(M2C_UNK *, u8);
void func_0208d478(M2C_UNK *, s32);

void func_0206ded4(M2C_UNK *arg0) {
    M2C_UNK *obj;
    u32 i;

    func_02067c68((u8 *) arg0 + 0x2C);
    func_02053f60(&data_02101b78, 0x400);
    func_02053f44(&data_02101b78, 0x200);
    func_02053f24(&data_02101b78, 0);
    GX_SetBankForBG(*(M2C_UNK *) ((u8 *) &data_02104d18 + 4));
    GX_SetBankForSubBG(*(M2C_UNK *) ((u8 *) &data_02104d18 + 0));
    *(u16 *) 0x05000400 = *(u32 *) ((u8 *) arg0 + 0x40);
    for (i = 0; i < 4; i++) {
        obj = ((M2C_UNK *) &data_0210930c)[0x13 + i];
        if (obj != 0 && (*(u32 *) ((u8 *) obj + 8) & 1) == 1) {
            *(u8 *) ((u8 *) obj + 0x5D6) = 0;
            *(u16 *) ((u8 *) obj + 0x1A8) &= ~0x10;
            if (*(u8 *) ((u8 *) obj + 0x6BE) < 10) {
                *(u8 *) ((u8 *) obj + 0x6BE) = 10;
            }
        }
    }
    if (func_020867ec(&data_02104d90, 4) == 0) {
        func_02060158(&data_02102900, 0, 0x13, 0);
    } else {
        func_02053f60(&data_02101b78, 0x200);
    }
    func_02001688(0);
    {
        u8 *flag = (u8 *) &data_02107944;
        u8 val   = *flag;

        if (val != 0) {
            func_020675d8(M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0210930c, void **, 0x68), void **, 0x38C), s32 *, 4) + 0x28,
                          val);
            *flag = 0;
        }
    }
    func_020016c0();
    *(u32 *) ((u8 *) &data_02104d18 + 4) = 0;
    *(u32 *) ((u8 *) &data_02104d18 + 0) = 0;
    if (func_020867ec(&data_02104d90, 7) != 0) {
        func_0208d478(&data_021093a0, 1);
    } else if (func_020867ec(&data_02104d90, 8) != 0) {
        func_0208d478(&data_021093a0, 2);
    } else if (func_020867ec(&data_02104d90, 5) != 0) {
        func_0208d478(&data_021093a0, 0);
    }
}
