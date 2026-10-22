#include "m2c.h"

typedef struct {
    u8 unk_000[0xe];
    u16 unk_00e;
} Unk0210b320;

extern Unk0210b320 data_0210b320;

extern u32 WM_Disconnect(void *callback, u16 aid);

s32 func_020adc40(s32 arg0, s32 arg1) {
    WM_Disconnect(0, arg1);
    data_0210b320.unk_00e &= ~(1 << arg1);
    return 1;
}
