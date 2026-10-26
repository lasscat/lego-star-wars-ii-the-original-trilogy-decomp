#include "m2c.h"

extern M2C_UNK data_020fdbc4;
extern M2C_UNK data_020fdfdc;

/* Initialize a behavior object with its owning actor and copied behavior
 * parameters. */
void func_02037128(void *behavior, s32 actor, void *params) {
    M2C_FIELD(behavior, M2C_UNK **, 0) = &data_020fdbc4;
    M2C_FIELD(behavior, s32 *, 4)      = actor;
    M2C_FIELD(behavior, s8 *, 0xC)     = 0;
    M2C_FIELD(behavior, s8 *, 0xD)     = 0;
    M2C_FIELD(behavior, M2C_UNK **, 0) = &data_020fdfdc;
    M2C_FIELD(behavior, u16 *, 0x10)   = (u16) M2C_FIELD(params, u16 *, 0);
    M2C_FIELD(behavior, u16 *, 0x12)   = (u16) M2C_FIELD(params, u16 *, 2);
    M2C_FIELD(behavior, u8 *, 0x14)    = (u8) M2C_FIELD(params, u8 *, 4);
    M2C_FIELD(behavior, u8 *, 0x15)    = (u8) M2C_FIELD(params, u8 *, 5);
    M2C_FIELD(behavior, s32 *, 0x18)   = (s32) M2C_FIELD(params, s32 *, 8);
    M2C_FIELD(behavior, u8 *, 0x1C)    = (u8) M2C_FIELD(params, u8 *, 0xC);
    M2C_FIELD(behavior, u8 *, 0x1D)    = (u8) M2C_FIELD(params, u8 *, 0xD);
    M2C_FIELD(behavior, u8 *, 0x1E)    = (u8) M2C_FIELD(params, u8 *, 0xE);
    M2C_FIELD(behavior, u8 *, 0x1F)    = (u8) M2C_FIELD(params, u8 *, 0xF);
    M2C_FIELD(behavior, u8 *, 0x20)    = (u8) M2C_FIELD(params, u8 *, 0x10);
    M2C_FIELD(behavior, s32 *, 0x24)   = (s32) M2C_FIELD(params, s32 *, 0x14);
}
