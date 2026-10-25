#include "m2c.h"

typedef struct {
    u8 kind;
    s32 b;
    s32 c;
} S0;

typedef struct {
    u16 id;
    u16 flags;
} Entry;

extern u8 data_02100a74[];
extern u8 data_02100a76[];
extern Entry data_02100d98[];

u32 func_02062b10(s32);
void func_020b94e4(void);
void func_020b94fc(void);
s32 func_020bb4fc(u16, u16, s32, s32, S0, s32);

s32 func_020b8fa4(s32 arg0, S0 arg1, s32 arg2) {
    u32 first = *(u16 *) (data_02100a76 + arg0 * 4);
    u32 count = *(u16 *) (data_02100a74 + arg0 * 4);
    u32 n;
    Entry *e;
    s32 ret;

    if (count > 1) {
        n = func_02062b10((u16) (count - 1));
    } else {
        n = 0;
    }
    e = &data_02100d98[first + n];
    func_020b94e4();
    if (arg1.kind >= 3 && arg1.kind < 7) {
        if (arg1.c == 0) {
            arg1.c = e->flags;
        }
    }
    ret = func_020bb4fc(e->id, e->flags, 0xFF, 0xFF, arg1, arg2);
    func_020b94fc();
    return ret;
}
