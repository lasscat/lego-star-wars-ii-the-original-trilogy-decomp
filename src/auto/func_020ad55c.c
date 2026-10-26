#include "m2c.h"

typedef struct State {
    u8 pad0[0x20];
    s32 mode;
    u8 pad24[0x0c];
    s32 field30;
    u8 pad34[0x4c];
    s32 handle;
} State;

typedef struct Big {
    u32 w[0x310];
} Big;

void func_020ad528(const char *fmt, ...);
void func_0205e860(s32);
s32 func_020ae010(void);
extern char data_020ffe58[];
extern State data_0210b320;
extern Big data_0210bf40;
s32 func_020ad55c(void);

// Resets the wifi layer: zeroes the 0xC40-byte table, releases the handle (if any),
// clears mode and field30 (names guessed from callers), then tail-calls func_020ae010.
s32 func_020ad55c(void) {
    __builtin__clear(&data_0210bf40, sizeof(data_0210bf40));
    if (data_0210b320.handle != 0) {
        func_020ad528(data_020ffe58);
        func_0205e860(data_0210b320.handle);
        data_0210b320.handle = 0;
    }
    data_0210b320.mode    = 0;
    data_0210b320.field30 = 0;
    return func_020ae010();
}
