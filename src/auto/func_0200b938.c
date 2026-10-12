#include "m2c.h"
#include "engine.h"

void func_0200b938(s32 arg0, s32 arg1) {
    M2C_FIELD(arg0, u8 *, 1) = (u8) ((M2C_FIELD(arg0, u8 *, 1) & ~0x7F) | ((u8) arg1 & 0x7F));
    switch (arg1) {                                 /* irregular */
    case 1:
    case 2:
        M2C_FIELD(arg0, s8 *, 0) = 0xF;
        M2C_FIELD(arg0, u8 *, 1) = (u8) (M2C_FIELD(arg0, u8 *, 1) | 0x80);
        return;
    case 3:
        M2C_FIELD(arg0, s8 *, 0) = 0x4F;
        M2C_FIELD(arg0, u8 *, 1) = (u8) (M2C_FIELD(arg0, u8 *, 1) | 0x80);
        return;
    }
}
