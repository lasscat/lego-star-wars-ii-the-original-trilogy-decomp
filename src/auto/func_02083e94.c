#include "m2c.h"

typedef struct {
    u16 v;
} HalfWord;
typedef struct {
    HalfWord a;
    HalfWord b;
} HwPair;
typedef struct {
    s32 x;
    s32 y;
} Vec;
typedef struct {
    u8 a;
    u8 b;
    u8 c;
    u8 d;
} Quad;
typedef struct {
    s16 a;
    s16 b;
} ShortPair;
typedef struct {
    s32 v;
} S32Box;

extern void func_020ac278(void *, s32, s32);
extern void func_02053ee8(void *, s32, s32);
extern void func_0206d6cc(void *);
extern void func_0206d7fc(void *, s8);
extern void func_020534e0(void *);
extern void func_020534f4(void *, s32, s32, HalfWord);
extern void func_0205365c(void *, s32);
extern void func_02054c80(void *, void *, s32, s32, s32, s32, s32, s32, ShortPair *, Quad);
extern void func_020536ec(void *, void *);
extern void func_02065600(void *, s32);
extern void func_02065658(void *, void *);
extern s32 func_0206653c(s32, s32, s32, s32, s32, s32, s32);
extern void func_0206574c(void *, s32, s32);
extern void func_02053f9c(void *, s32);
extern void func_02007f24(s32 *, s32, f32);
extern s32 func_0205e818(s32, s32, s32);
extern void func_020602ec(void *, HalfWord, s32);
extern void func_020602b0(void *, HalfWord, s32);
extern void func_02060290(void *, S32Box);
extern void func_02060618(void *);
extern void func_02053f44(void *, s32);
extern void func_020540b4(void *, s32, s32);
extern void func_020b90e4(s32, s32);
extern void func_02084a70(void *);

extern M2C_UNK data_027e0874;
extern M2C_UNK data_02101b78;
extern HwPair data_020f0230;
extern M2C_UNK data_02101b98;

void func_02083e94(void *arg0) {
    Vec obj;
    Vec out;
    ShortPair pair;
    Quad q;
    Vec pos;
    u32 f;
    HalfWord hw;
    s32 v;

    func_020ac278(&data_027e0874, 4, 0);
    func_02053ee8(&data_02101b78, 0, 0);
    func_0206d6cc((void *) ((u8 *) arg0 + 0xc80));
    func_0206d7fc((void *) ((u8 *) arg0 + 0xc80), 1);

    func_020534e0(&obj);
    func_020534f4(&obj, 0, 1, data_020f0230.a);
    func_0205365c(&obj, 0);

    pair.a = 0;
    pair.b = 0;
    q.a    = 0;
    q.b    = 0;
    q.c    = 0;
    q.d    = 0;
    func_02054c80(&out, &obj, 0x1399, 0, 1, 0x20, 0x20, 0xe0, &pair, q);

    pos.x = 0;
    pos.y = -0x20000;
    func_020536ec(&obj, &pos);

    func_02053ee8(&data_02101b98, 3, 0);
    func_0206d6cc((void *) ((u8 *) arg0 + 0xac + 0xc00));
    func_0206d7fc((void *) ((u8 *) arg0 + 0xac + 0xc00), 1);
    func_020534f4((void *) ((u8 *) arg0 + 0x68 + 0xc00), 1, 3, data_020f0230.b);
    func_0205365c((void *) ((u8 *) arg0 + 0x68 + 0xc00), 0);
    func_02065600((void *) ((u8 *) arg0 + 0xd8 + 0xc00), 3);
    func_02065658((void *) ((u8 *) arg0 + 0xd8 + 0xc00), (void *) ((u8 *) arg0 + 0x68 + 0xc00));
    func_0206653c(1, 3, 6, 0, 1, 7, 0);
    func_0206574c((void *) ((u8 *) arg0 + 0xd8 + 0xc00), 0, 0);
    func_02053f9c(&data_02101b98, 0);

    func_02007f24(&f, 0, 1.75f);
    M2C_FIELD(arg0, u32 *, 0xd14) = f;
    v                             = func_0205e818(0xc00, 4, 4);
    M2C_FIELD(arg0, u32 *, 0xd08) = v;
    M2C_FIELD(arg0, u32 *, 0xc5c) = v;
    M2C_FIELD(arg0, u32 *, 0xc60) = 0x4001030;
    hw.v                          = 0;
    func_020602ec((void *) ((u8 *) arg0 + 0x30), hw, 0);
    func_020602b0((void *) ((u8 *) arg0 + 0x30), *(HalfWord *) ((u8 *) arg0 + 0xd00 + 0xe), 1);
    func_02060290((void *) ((u8 *) arg0 + 0x30), *(S32Box *) ((u8 *) arg0 + 0x118 + 0xc00));
    func_02060618((void *) ((u8 *) arg0 + 0x30));
    func_02053f44(&data_02101b98, 0x2000);
    func_020540b4(&data_02101b98, 0xb, 3);

    switch (M2C_FIELD(arg0, u32 *, 0x8)) {
        case 0:
            M2C_FIELD(arg0, u32 *, 0xd20) = 5;
            M2C_FIELD(arg0, u32 *, 0xd24) = 0x2e2;
            break;
        case 1:
            M2C_FIELD(arg0, u32 *, 0xd20) = 5;
            M2C_FIELD(arg0, u32 *, 0xd24) = 0x2e8;
            break;
        case 2:
            M2C_FIELD(arg0, u32 *, 0xd20) = 5;
            M2C_FIELD(arg0, u32 *, 0xd24) = 0x2ee;
            break;
        case 3:
            M2C_FIELD(arg0, u32 *, 0xd20) = 5;
            M2C_FIELD(arg0, u32 *, 0xd24) = 0x2f4;
            break;
        case 4:
            M2C_FIELD(arg0, u32 *, 0xd20) = 5;
            M2C_FIELD(arg0, u32 *, 0xd24) = 0x2fa;
            break;
        case 5:
            M2C_FIELD(arg0, u32 *, 0xd20) = 5;
            M2C_FIELD(arg0, u32 *, 0xd24) = 0x300;
            break;
        case 6:
            M2C_FIELD(arg0, u32 *, 0xd20) = 5;
            M2C_FIELD(arg0, u32 *, 0xd24) = 0x306;
            break;
        case 7:
            M2C_FIELD(arg0, u32 *, 0xd20) = 5;
            M2C_FIELD(arg0, u32 *, 0xd24) = 0x30c;
            break;
        case 8:
            M2C_FIELD(arg0, u32 *, 0xd20) = 5;
            M2C_FIELD(arg0, u32 *, 0xd24) = 0x312;
            break;
        case 9:
            M2C_FIELD(arg0, u32 *, 0xd20) = 5;
            M2C_FIELD(arg0, u32 *, 0xd24) = 0x318;
            break;
        case 10:
            M2C_FIELD(arg0, u32 *, 0xd20) = 5;
            M2C_FIELD(arg0, u32 *, 0xd24) = 0x31e;
            break;
        case 11:
            M2C_FIELD(arg0, u32 *, 0xd20) = 5;
            M2C_FIELD(arg0, u32 *, 0xd24) = 0x324;
            break;
        case 12:
            M2C_FIELD(arg0, u32 *, 0xd20) = 5;
            M2C_FIELD(arg0, u32 *, 0xd24) = 0x32a;
            break;
        case 13:
            M2C_FIELD(arg0, u32 *, 0xd20) = 5;
            M2C_FIELD(arg0, u32 *, 0xd24) = 0x330;
            break;
        case 14:
            M2C_FIELD(arg0, u32 *, 0xd20) = 5;
            M2C_FIELD(arg0, u32 *, 0xd24) = 0x336;
            break;
        case 15:
            M2C_FIELD(arg0, u32 *, 0xd20) = 5;
            M2C_FIELD(arg0, u32 *, 0xd24) = 0x33c;
            break;
        case 19:
            M2C_FIELD(arg0, u32 *, 0xd20) = 5;
            M2C_FIELD(arg0, u32 *, 0xd24) = 0x342;
            break;
        case 26:
            M2C_FIELD(arg0, u32 *, 0xd20) = 0x1ec;
            M2C_FIELD(arg0, u32 *, 0xd24) = 0x348;
            M2C_FIELD(arg0, u8 *, 0xeba)  = 1;
            break;
    }

    func_020b90e4(0, 0xff);
    func_02084a70(arg0);
    M2C_FIELD(arg0, u8 *, 0xeb9) = 1;
}
