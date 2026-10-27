#include "m2c.h"

typedef struct {
    u16 v;
} HalfWord;

typedef struct {
    s16 f00;
    s16 f02;
} ShortPair;

typedef struct {
    u8 f00;
    u8 f01;
    u8 f02;
    u8 f03;
} Byte4;

/* Flag bits or-ed into the flags word forwarded to func_020549e4. */
enum {
    DRAW_FLAG_KIND_A      = 0x10,
    DRAW_FLAG_ALT         = 0x20,
    DRAW_FLAG_ENTRY_BIT30 = 0x40,
    DRAW_FLAG_KIND_B      = 0x80,
};

/* Table-entry word 1 bit tested above (bit 30), and global bit 9 in data_027e02a8. */
enum {
    ENTRY_WORD_BIT30    = 0x40000000,
    GLOBAL_NO_OWNER_BIT = 0x200,
};

extern u32 data_027e02a8;
extern u8 data_02101b78[];

extern s32 func_02053964(void *);
extern s32 func_020539c8(s32 *);
extern s32 func_02053a28(s32);
extern s16 func_02053a9c();
extern void func_020549e4(void *, void *, HalfWord, u32, u32, u32, u32, u32, u32, u32, ShortPair *, Byte4);

/* Derives extra flag bits from the object's table entry (32-byte entries in data_02101b78,
 * indexed by obj[0]; obj[1] is a level/state), then forwards everything to func_020549e4. */
void func_02054c80(void *out, s32 *obj, u32 arg2, u32 flags, u32 arg4, u32 arg5, u32 arg6, u32 arg7, ShortPair *src_pair,
                   Byte4 bytes) {
    ShortPair pair;
    HalfWord hw;
    ShortPair *pp;
    void *owner;

    if (func_02053964(obj) != 0) {
        flags |= DRAW_FLAG_KIND_B;
    } else if (func_020539c8(obj) != 0) {
        flags |= DRAW_FLAG_KIND_A;
    }
    if (func_02053a28((s32) obj) != 0) {
        flags |= DRAW_FLAG_ALT;
        if ((flags & DRAW_FLAG_KIND_A) == 0) {
            if (*(u32 *) (data_02101b78 + obj[0] * 32 + 4) & ENTRY_WORD_BIT30) {
                flags |= DRAW_FLAG_ENTRY_BIT30;
            }
        }
    }
    pair.f00 = src_pair->f00;
    pair.f02 = src_pair->f02;
    pp       = &pair; // FAKE: address taken after the copy keeps &pair live in a callee-saved register
    if (data_027e02a8 & GLOBAL_NO_OWNER_BIT) {
        owner = 0;
    } else {
        owner = (void *) obj[0];
    }
    hw.v = func_02053a9c(obj);
    func_020549e4(out, owner, hw, arg2, flags, arg4, obj[1], arg5, arg6, arg7, pp, bytes);
}
