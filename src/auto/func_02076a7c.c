#include "m2c.h"

typedef struct {
    u16 v;
} HalfWord;

typedef struct {
    s16 f00;
    s16 f02;
} ShortPair;

typedef struct {
    u8 f00[8];
} Byte8;

typedef struct {
    u8 f00;
    u8 f01;
    u8 f02;
    u8 f03;
} Byte4;

extern u16 data_020ee258[];

extern void func_020534e0(void *);
extern void func_020534f4(void *, s32, s32, HalfWord);
extern void func_0205365c(void *, s32);
extern void func_02054c80(void *, void *, u16, u32, u32, u32, u32, u32, void *, Byte4);
extern void func_02065600(void *, s32);
extern void func_02065658(void *, void *);
extern void func_0206574c(void *, s32, s32);
extern u16 func_02065be8(void *, u32, s32, s32, void *, s32);
extern void func_0206653c(s32, s32, s32, s32, s32, s32, s32);
extern void *func_02066708(s32);
extern void func_02076bc0(void *, s32);

enum {
    UI_PART_OFFSET        = 0x54,    /* embedded sub-object that is drawn */
    UI_PART_HANDLE_OFFSET = 0x84, /* u16 handle returned by func_02065be8 */
};

/* Builds the screen's UI part: sets up a local sprite/palette object, draws it
 * through the part at self + 0x54, stores the returned handle, then runs the
 * shared finish step func_02076bc0 with flag 0. Names are guesses from callees. */
void func_02076a7c(void *self) {
    s32 obj[2]; /* name guessed from callers */
    Byte8 out;
    ShortPair pair;
    Byte4 bytes; /* name guessed from callers */

    func_020534e0(obj);
    func_020534f4(obj, 0, 1, *(HalfWord *) &data_020ee258[0]);
    func_0205365c(obj, 0x30);
    pair.f00  = 0;
    pair.f02  = 0;
    bytes.f00 = 0;
    bytes.f01 = 0;
    bytes.f02 = 0x20;
    bytes.f03 = 0x1e;
    func_02054c80(&out, obj, 0x1398, 0x100, 0x31, 0x30, 0, 0x10, &pair, bytes);
    func_0206653c(0, 3, 0, 5, 7, 7, 0);
    func_02065600(self + UI_PART_OFFSET, 4);
    func_02065658(self + UI_PART_OFFSET, obj);
    func_0206574c(self + UI_PART_OFFSET, 0, 0);
    M2C_FIELD(self, u16 *, UI_PART_HANDLE_OFFSET) =
        func_02065be8(self + UI_PART_OFFSET, 0x10e, 0x80, 8, func_02066708(0xb), 1);
    func_02076bc0(self, 0);
}
