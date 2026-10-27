#include "m2c.h"

typedef struct {
    u32 sig;
    u8 pad[8];
} Entry;

typedef struct {
    u8 pad[8];
    u8 language : 7;
    u8 loaded : 1;
    u8 pad0[0x20 - 9];
    s32 buf;
    Entry ent[3];
    u8 a[3];
    u8 b[3];
    u8 c;
} Block;

extern Block data_02104364;
extern Entry data_02104388[];
extern u8 data_02104d90[];

s32 func_0205e4f8(s32, s32, u32);
void func_02085d94(void *, void *);
s32 func_02052df8(void);
s32 func_02063588(void);
s32 func_0206353c(void);
s32 func_02062fe0(s32);
void func_02066634(s32);
u32 func_02063324(void);
void func_02062fbc(s32);

// FAKE: reach the block start from the slot array so the loop base is a separate literal.
static inline Block *slot_base(void) {
    return (Block *) (data_02104388 - 3);
}

enum {
    SLOT_COUNT            = 3,
    BUF_SIZE              = 0xA0,
    BUF_ALIGN             = 4,
    SLOT_MAGIC            = 0xFDDB597D,
    CHECK_FAILED          = 1,
    CHECK_NEEDS_SLOT_INIT = 4,
};

/* Boot-time save data setup: allocates the shared buffer, initialises the three slot records,
 * then runs the save checks and ends in func_02062fbc (shutdown path) if any of them fail. */
void func_02062e98(void) {
    u32 i;
    s32 r;
    u32 flags;

    data_02104364.buf = func_0205e4f8(BUF_SIZE, 3, BUF_ALIGN);
    data_02104364.c   = 3;
    for (i = 0; i < SLOT_COUNT; i++) {
        func_02085d94(data_02104d90, &data_02104388[i]);
        slot_base()->ent[i].sig = SLOT_MAGIC;
        slot_base()->a[i]       = 0;
        slot_base()->b[i]       = 0;
    }
    if (func_02052df8() == 0) {
        func_02062fbc(1);
    }
    flags = func_02063588();
    if (flags == CHECK_FAILED) {
        func_02062fbc(1);
    } else if (flags & CHECK_NEEDS_SLOT_INIT) {
        if (func_0206353c() != 0) {
            for (i = 0; i < SLOT_COUNT; i++) {
                r = func_02062fe0(i);
                if (r != 0) {
                    break;
                }
            }
        } else {
            r = 2;
        }
        if (r != 0) {
            func_02062fbc(1);
        }
    }
    func_02066634(data_02104364.language);
    r = func_02063324();
    if (r == 1) {
        func_02062fbc(r);
    }
}
