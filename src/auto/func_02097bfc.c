#include "m2c.h"

extern s32 data_027e02a8;
extern u8 data_0210930c[];
extern s32 data_02104dc4[];
extern u8 data_0210794c[];

extern u8 func_020917b4(void *arg0);
extern u32 func_0208c7b0(void *arg0);
extern u8 func_02093fd0(s32 arg0);
extern s32 func_0208c72c(s32 *arg0, u32 arg1);
extern void func_020b04f0(void *a, u32 b, void *c, u32 d);
extern void func_02097cb8(u32 a, u32 b, u32 c, u32 d, u32 e);

typedef struct {
    u16 h0;
    u16 h1;
    u32 w0;
    u32 w1;
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    u32 w2;
    u32 w3;
    u32 w4;
} Struct;

void func_02097bfc(u32 a, u32 b, u32 c, u32 d) {
    if (data_027e02a8 & 0x40) {
        Struct s;

        s.h0 = func_020917b4(data_0210930c);
        s.h1 = a;
        s.w0 = b;
        s.w1 = c;
        s.b0 = d;
        s.b2 = func_0208c7b0(data_02104dc4);
        s.b1 = func_0208c72c(data_02104dc4, func_02093fd0(func_020917b4(data_0210930c)));
        func_020b04f0(&data_0210794c[0], 0x37, &s, 0xff);
    } else {
        func_02097cb8(func_020917b4(data_0210930c), a, b, c, d);
    }
}
