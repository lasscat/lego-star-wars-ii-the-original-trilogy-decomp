#include "m2c.h"

typedef struct {
    u16 v;
} HalfWord;

typedef struct {
    s32 v;
} Word;

extern void func_020536ec(void *, s32 *);
extern void func_0205375c(void *, s32 *);
extern void func_02053850(void *, HalfWord);
extern void func_02053888(void *, Word);
extern void func_02053808(void *, s32 *);
extern void func_020538c0(void *, s32);
extern void *func_020531d8(void *);

void func_020535a8(void *self) {
    s32 a[2];
    s32 b[2];
    Word w;
    s32 c[2];
    HalfWord h;

    a[0] = 0;
    a[1] = 0;
    func_020536ec(self, a);
    b[0] = 0;
    b[1] = 0;
    func_0205375c(self, b);
    h.v = 0;
    func_02053850(self, h);
    w.v = 0x1000;
    func_02053888(self, w);
    c[0] = 0;
    c[1] = 0;
    func_02053808(self, c);
    func_020538c0(self, 0);
    M2C_FIELD(func_020531d8(self), s32 *, 4) = 0;
    M2C_FIELD(func_020531d8(self), s32 *, 0x34) |= 1;
}
