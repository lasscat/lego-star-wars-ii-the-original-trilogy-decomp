#include "m2c.h"

typedef struct {
    u8 pad0[0x34];
    s32 f34;
    s32 pad38;
    s32 f3c;
    u8 f40;
} Mgr;

typedef struct {
    u8 pad0[0x30];
    u8 f30[0x80];
    s32 fb0;
    u8 fb4;
    u8 fb5;
} Obj;

typedef struct {
    s16 a;
    s16 b;
} Pair;

typedef struct {
    u8 a;
    u8 b;
    u8 c;
    u8 d;
} Desc;

typedef struct {
    u32 a;
    u32 b;
} Out;

extern Mgr *data_02107860;

extern void func_0209df00(Obj *);
extern void func_0209e1ac(Obj *);
extern void func_0205365c(void *, s32);
extern void func_02054c80(void *, void *, s32, s32, s32, s32, s32, s32, void *, Desc);
extern void func_02072f94(void);

/* Mode values of the manager byte at 0x40 and the resource ids started for them
 * (names guessed from the switch below). */
enum {
    MGR_MODE_4    = 4,
    MGR_MODE_5    = 5,
    RES_ID_MODE_4 = 0xbb2,
    RES_ID_MODE_5 = 0xebe,
    RES_FLAGS     = 0x100,
};

/* Refreshes the widget's cached copy of the manager state (0x3c -> 0xb0, 0x34 -> 0xb4,
 * 0x40 -> 0xb5): redraws the text when any cached value changed and, when the mode
 * changed, resets the sub-object at 0x30 and starts the mode's resource. */
void func_0209dd64(Obj *self) {
    Mgr **pp;

    func_0209df00(self);
    pp = &data_02107860; // FAKE: cached address of the manager pointer (keeps its literal in a callee-saved register)
    if (self->fb0 != (*pp)->f3c || self->fb4 != (*pp)->f34 ||
        self->fb4 !=
            (*pp)->f34 || // FAKE: repeated compare (folded away); keeps the 0x34 load live first so it colours r1 (cmp r0, r1)
        self->fb5 != (*pp)->f40) {
        func_0209e1ac(self);
        if (self->fb5 != (*pp)->f40) {
            func_0205365c(self->f30, 0);
            switch ((*pp)->f40) {
                case MGR_MODE_5: {
                    Out out;
                    Pair pair;
                    Desc desc;
                    pair.a = 0;
                    pair.b = 0;
                    desc.a = 0;
                    desc.b = 0;
                    desc.c = 0;
                    desc.d = 0;
                    func_02054c80(&out, self->f30, RES_ID_MODE_5, 0, 0, 0, 0, RES_FLAGS, &pair, desc);
                    break;
                }
                case MGR_MODE_4: {
                    Out out;
                    Pair pair;
                    Desc desc;
                    pair.a = 0;
                    pair.b = 0;
                    desc.a = 0;
                    desc.b = 0;
                    desc.c = 0;
                    desc.d = 0;
                    func_02054c80(&out, self->f30, RES_ID_MODE_4, 0, 0, 0, 0, RES_FLAGS, &pair, desc);
                    break;
                }
            }
        }
    }
    func_02072f94();
    self->fb0 = (*pp)->f3c;
    self->fb4 = (*pp)->f34;
    self->fb5 = (*pp)->f40;
}
