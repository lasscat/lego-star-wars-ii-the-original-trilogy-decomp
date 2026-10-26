#include "m2c.h"

extern u8 data_020fe77c[];
extern u8 data_020fe7d8[];
extern u8 data_020fe7f0[];
extern u8 data_02104364[];
extern u8 data_02102900[];

void *func_0206d0d8(void *, s32);
void func_02065600(void *, s32);
void func_02065658(void *, void *);
void func_0206574c(void *, s32, s32);
void func_0206653c(s32, s32, s32, s32, s32, s32, s32);
s32 func_020601d8(void *, s32, s32, s32, s32);
void func_020601ac(void *, s32, s32, s32, s32, s32);
void func_02069a8c(void *, s32);

enum {
    SAVE_BYTE_MODE     = 0x4E,   // mode byte, valid range 0..2
    SAVE_BYTE_FLAGS    = 0x4B,  // three one-shot flag bytes
    SAVE_FLAG_COUNT    = 3,
    STATE_FLAG_PENDING = 1,
    MODE_MAX           = 2,
    DEFAULT_COUNT      = 10,
};

// Object laid out as two bases: main vptr at +0x00, sub-object vptr at +0x0C (names guessed from callers).
typedef struct Obj {
    void *vptr;     // 0x00
    s32 a4;
    u16 a8;
    u8 pad_a[2];
    void *subVptr;  // 0x0C (sub-object, vptr at +0)
    u8 pad10[4];
    s32 a14;
    void *a18;
    u32 a1c;
    s32 a20;
    s32 a24;
    u8 b28, b29, b2a, b2b;
} Obj;

// Constructor: sets up the object, reads the saved mode and flag bytes, then starts the screen.
Obj *func_02069350(Obj *self, s32 arg1, void *arg2, s32 arg3, s32 arg4) {
    s32 i;
    u32 v;
    self->vptr = data_020fe77c;
    self->a4   = arg1;
    self->a8   = 0;
    func_0206d0d8(&self->subVptr, 1);
    self->vptr    = data_020fe7d8;
    self->subVptr = data_020fe7f0;
    self->a14     = arg3;
    self->a18     = arg2;
    self->a20     = arg4;
    self->a24     = DEFAULT_COUNT;
    self->b28     = 0;
    self->b29     = 0;
    self->b2a     = 0;
    self->b2b     = 0;
    func_02065600(self->a18, 4);
    func_02065658(self->a18, (void *) self->a14);
    func_0206574c(self->a18, 0, 0);
    func_0206653c(1, 0, 1, 3, 4, 5, 0);
    v         = data_02104364[SAVE_BYTE_MODE];
    self->a1c = v;
    if (v > MODE_MAX) {
        self->a1c = 0;
    }
    if (self->a20 == 1) {
        self->b28 = 1;
    }
    func_020601d8(data_02102900, arg3, 0x140, 5, 0);
    for (i = 0; i < SAVE_FLAG_COUNT; i++) {
        if (data_02104364[SAVE_BYTE_FLAGS + i] == STATE_FLAG_PENDING) {
            data_02104364[SAVE_BYTE_FLAGS + i] = 0;
            self->b2b                          = 1;
        }
    }
    if (self->b2b != 0) {
        func_020601ac(data_02102900, 1, 0x25, -1, 0, 0);
    } else {
        func_02069a8c(self, 1);
    }
    return self;
}
