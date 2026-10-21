/* Reconstructed from USA ARM9 at 0x020724e0 (128 bytes).
 *
 * data_021044a4 is the shared timer/state block (bit field flags in the
 * first byte, 16.16 style times at 0x2a and 0x2c); data_020edf94 is a
 * read-only table of 8-byte entries holding two ranges of 16-bit values.
 * The function reports whether both times of the state fall into the
 * ranges of the selected table entry.
 */
#include "m2c.h"

struct C1c348Data {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 b5 : 1;
    u8 b6 : 1;
    u8 b7 : 1;
    u8 pad[0x29];
    u16 f2a;
    u16 f2c;
};

struct Lsw2FrameEntry {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
};

extern struct C1c348Data data_021044a4;
extern struct Lsw2FrameEntry data_020edf94[];

s32 func_020724e0(M2C_UNK arg0, s32 idx) {
    if (data_021044a4.b4) {
        struct Lsw2FrameEntry *e = &data_020edf94[idx];
        u16 a                    = data_021044a4.f2a;
        u16 f0                   = e->f0;
        u32 c                    = data_021044a4.f2c;
        u16 f6                   = e->f6;
        u16 f4                   = e->f4;
        u16 f2                   = e->f2;
        if ((u32) a >= (u32) f0 && (s32) a < (s32) ((u32) f0 + (u32) f4) && (u32) f2 <= (u32) (u16) c &&
            (s32) (u16) c < (s32) ((u32) f2 + (u32) f6)) {
            return 1;
        }
    }
    return 0;
}
