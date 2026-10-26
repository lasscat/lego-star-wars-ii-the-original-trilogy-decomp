typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef long s32;
typedef unsigned long u32;
class CObj {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9(s32, s32, s32, s32);
};

typedef struct {
    u16 v;
} Angle;

typedef struct {
    Angle x;
    Angle y;
    Angle z;
} Rot;

typedef void (*VFn)(void *, s32, s32, s32, s32);

extern "C" {
extern void func_020b9584(s32, void *);
extern void func_020186ec(void *, void *, Angle);
extern void func_0209f590(void *);
extern s32 func_0209f53c(void *, u32);
extern void func_020108f4(void *, s32, s32);
extern u8 data_020f4d15[];
extern u8 data_020f4d0e[];
}

enum {
    ROT_QUARTER_TURN = 0x4000,
    STATE_NONE       = 0x276,
};

// Per-state setup of an object: plays the state's sound, aims the attached parts, starts the animation.
extern "C" void func_02019554(CObj *obj) {
    u8 *o = (u8 *) obj;
    Rot rot;

    if (data_020f4d15[o[0x1c3] * 12] != 0xc9) {
        func_020b9584(data_020f4d15[o[0x1c3] * 12], o + 0xb0);
    }
    switch (o[0x1c3]) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 10:
        case 12:
            rot.y.v = ROT_QUARTER_TURN;
            rot.x.v = ROT_QUARTER_TURN;
            rot.z.v = *(u16 *) (o + 0xca) + ROT_QUARTER_TURN;
            func_020186ec(*(void **) (o + 0x1c8), o + 0xb0, rot.z);
            break;
        case 7:
            func_020186ec(*(void **) (o + 0x1c8), o + 0xb0, *(Angle *) (o + 0xca));
            func_020186ec(*(void **) (o + 0x1cc), o + 0xb0, *(Angle *) (o + 0xca));
            break;
    }
    if (*(u16 *) (data_020f4d0e + o[0x1c3] * 12) != STATE_NONE) {
        func_0209f590(o + 0xd4);
        func_0209f53c(o + 0xd4, *(u16 *) (data_020f4d0e + o[0x1c3] * 12));
        obj->f9(0, 0, 1, 0);
        o[0x1c1] = 1;
        func_020108f4(o, 1, 1);
    } else {
        *(u32 *) (o + 8) |= 2;
    }
}
