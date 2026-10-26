#include "m2c.h"

typedef struct Obj {
    void *vptr;
} Obj;
typedef struct State {
    u8 pad0[0x80];
    s32 flag;
} State;
typedef struct Big {
    u32 w[0x310];
} Big;

extern char data_020ffd50[];
extern State data_0210b320;
extern Big data_0210bf40;
extern char data_0210b3e0[];
void *func_0205e624(void *, s32, u32);
Obj *func_020ad354(Obj *self);

enum {
    CLEAR_TAIL_SIZE = 0x70,
};

// Constructor-like reset: installs the vtable, clears the wifi state flag, the 16-entry table (0xC40 bytes)
// and a 0x70-byte block, then returns this (names guessed from callers).
Obj *func_020ad354(Obj *self) {
    self->vptr         = data_020ffd50;
    data_0210b320.flag = 0;
    __builtin__clear(&data_0210bf40, sizeof(data_0210bf40));
    func_0205e624(data_0210b3e0, 0, CLEAR_TAIL_SIZE);
    return self;
}
