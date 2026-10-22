#include "m2c.h"

extern u8 data_0210b320[];
extern char data_020ffe28[];
extern char data_020ffe40[];

void func_020ad528(const char *fmt, ...);
M2C_UNK func_0205e838(M2C_UNK);
M2C_UNK func_020ade64(void);

s32 func_020ad438(void) {
    s32 temp;

    M2C_FIELD(data_0210b320, s32 *, 0x40) = 0xc80;
    M2C_FIELD(data_0210b320, s32 *, 0x3c) = 0x220;
    if (M2C_FIELD(data_0210b320, s32 *, 0x38) == 0) {
        func_020ad528(data_020ffe28, 0xc80);
        temp                                  = func_0205e838(M2C_FIELD(data_0210b320, s32 *, 0x40) + 0x1f);
        M2C_FIELD(data_0210b320, s32 *, 0x18) = temp;
        M2C_FIELD(data_0210b320, s32 *, 0x38) = (temp + 0x1f) & ~0x1f;
    }
    if (M2C_FIELD(data_0210b320, s32 *, 0x24) == 0) {
        func_020ad528(data_020ffe40, M2C_FIELD(data_0210b320, s32 *, 0x3c));
        temp                                  = func_0205e838(M2C_FIELD(data_0210b320, s32 *, 0x3c) + 0x1f);
        M2C_FIELD(data_0210b320, s32 *, 0x1c) = temp;
        M2C_FIELD(data_0210b320, s32 *, 0x24) = (temp + 0x1f) & ~0x1f;
    }
    func_020ad528(data_020ffe28, M2C_FIELD(data_0210b320, s32 *, 0x40));
    func_020ad528(data_020ffe40, M2C_FIELD(data_0210b320, s32 *, 0x3c));
    M2C_FIELD(data_0210b320, s32 *, 0x2c) = 0;
    M2C_FIELD(data_0210b320, u16 *, 0x8)  = 0;
    M2C_FIELD(data_0210b320, u16 *, 0xe)  = 1;
    M2C_FIELD(data_0210b320, s32 *, 0x30) = 0;
    M2C_FIELD(data_0210b320, s32 *, 0x10) = 0;
    if (func_020ade64() == 0) {
        return 0;
    }
    return 1;
}
