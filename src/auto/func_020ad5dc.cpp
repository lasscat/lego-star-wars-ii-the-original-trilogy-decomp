#include "m2c.h"

class Wifi {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual s32 slot08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18();
    virtual void unknown1c();
    virtual void unknown20();
    virtual void unknown24();
    virtual void unknown28();
    virtual void unknown2c();
    virtual void unknown30();
    virtual void unknown34();
    virtual void unknown38();
    virtual void unknown3c();
    virtual void unknown40();
    virtual s32 slot44();
};

typedef struct State {
    u8 pad0[0x20];
    s32 mode;
    u8 pad24[0x20];
    s32 sub;
    u8 pad48[0x38];
    s32 handle;
} State;

enum {
    MODE_BUSY     = 1,
    MODE_IDLE     = 2,
    MODE_ACTIVE_A = 4,
    MODE_ACTIVE_B = 5,
    MODE_ACTIVE_C = 6,
};

typedef struct Big {
    u32 w[0x310];
} Big;

extern "C" {
void func_020ad528(const char *fmt, ...);
void func_0205e860(s32);
s32 func_020aecd8(void);
s32 func_020aecfc(void);
s32 func_020ae4bc(void);
s32 func_020ae4d4(void);
extern char data_020ffe88[];
extern char data_020ffe58[];
extern char data_020ffea4[];
extern char data_020ffec4[];
extern char data_020ffee4[];
extern char data_020fff0c[];
extern char data_020fff24[];
extern char data_020fff3c[];
extern char data_020fff64[];
extern State data_0210b320;
extern Big data_0210bf40;
s32 func_020ad5dc(Wifi *self);
}

// Shuts the wifi layer down for the current state: clears the 16-entry table
// (0xC40 bytes), releases the handle, then dispatches on mode/sub (names guessed from callers).
// __builtin__clear is the compiler's own aggregate zero-fill intrinsic (no source-level FAKE).
s32 func_020ad5dc(Wifi *self) {
    if (data_0210b320.mode == MODE_BUSY) {
        func_020ad528(data_020ffe88);
        return 0;
    }
    __builtin__clear(&data_0210bf40, sizeof(data_0210bf40));
    if (data_0210b320.handle != 0) {
        func_020ad528(data_020ffe58);
        func_0205e860(data_0210b320.handle);
        data_0210b320.handle = 0;
    }
    if (data_0210b320.mode == MODE_IDLE) {
        func_020ad528(data_020ffea4);
        return self->slot44();
    }
    if (data_0210b320.mode != MODE_ACTIVE_C && data_0210b320.mode != MODE_ACTIVE_B && data_0210b320.mode != MODE_ACTIVE_A) {
        func_020ad528(data_020ffec4);
        return self->slot08();
    }
    func_020ad528(data_020ffee4);
    switch (data_0210b320.sub) {
        case 3:
            return func_020aecd8();
        case 1:
        case 5:
            func_020ad528(data_020fff0c);
            return func_020aecfc();
        case 2:
            return func_020ae4bc();
        case 0:
        case 4:
            func_020ad528(data_020fff24);
            return func_020ae4d4();
        default:
            func_020ad528(data_020fff3c);
            func_020ad528(data_020fff64);
            return 0;
    }
}
