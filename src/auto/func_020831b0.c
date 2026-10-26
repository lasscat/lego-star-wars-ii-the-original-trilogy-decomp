#include "m2c.h"

u8 func_020832b0(s32 arg0, s32 arg1);
void func_0208dd40(void *src, void *dst, s32 n);

enum {
    CODE_COUNT    = 5,
    CONVERT_SIZE  = 0x40,
    LONG_TEXT_LEN = 0x19,
    NARROW_WIDTH  = 10,
    WIDE_WIDTH    = 15,
};

// Builds a 5-entry code list for the object, converts it to a text string, and draws it,
// using a wider layout when the string is longer than 25 characters.
void func_020831b0(void *obj) { // name guessed from callers
    struct {
        u16 codes[CODE_COUNT];
        s8 text[0x44];
    } buf;
    s32 i;
    s32 width;

    for (i = 0; i < CODE_COUNT; i++) {
        buf.codes[i] = func_020832b0((s32) obj, i);
    }
    func_0208dd40(buf.codes, buf.text, CONVERT_SIZE);
    func_02053c2c((u8 *) obj + 0x58, 0, 0, 0x20, 4, 0);
    width = NARROW_WIDTH;
    if ((u32) func_020e0db0(buf.text) > LONG_TEXT_LEN) {
        func_02065600((u8 *) obj + 0x70, 2);
        func_0206653c(0, 3, 7, 7, 7, 7, 0);
        width = WIDE_WIDTH;
    } else {
        func_02065600((u8 *) obj + 0x70, 4);
        func_0206653c(0, 3, 7, 7, 7, 7, 0);
    }
    func_02065be8((u8 *) obj + 0x70, 0x100, 0x80, width, (s32) buf.text, 1);
}
