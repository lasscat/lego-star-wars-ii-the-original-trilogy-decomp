#include "m2c.h"

class Manager734B0 {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18();
    virtual s32 unknown1c();
};

typedef struct {
    u8 pad0[0xAA];
    u16 fAA;
    u16 fAC;
    u8 pad1;
    u8 fAF;
    u8 pad2;
    u8 fB1;
} Sub;

typedef struct {
    u8 pad[0xE000];
    Sub sub;
} Obj;

extern "C" Manager734B0 *data_021092f4;
extern "C" u32 data_02104d44;
extern "C" char data_0210794c[];
extern "C" char data_020febd0[];

extern "C" int sprintf(char *dst, const char *fmt, ...);
extern "C" void func_020b04f0(char *tag, s32 id, void *data, u32 size);
extern "C" void func_02073750(void *obj);

extern "C" void func_020734b0(Obj *arg0) {
    char buf[52];
    if (data_021092f4->unknown1c() == 0) {
        if (data_02104d44 != arg0->sub.fAA) {
            sprintf(buf, data_020febd0, arg0->sub.fAA, M2C_FIELD(arg0, u32 *, 0xA4));
        }
        data_02104d44 = arg0->sub.fAA;
    } else {
        if (data_02104d44 != arg0->sub.fAC) {
            sprintf(buf, data_020febd0, arg0->sub.fAC, M2C_FIELD(arg0, u32 *, 0xA4));
        }
        data_02104d44 = arg0->sub.fAC;
    }
    if (data_021092f4->unknown1c() != 0) {
        if (arg0->sub.fAF == 0) {
            if (arg0->sub.fB1 != 0) {
                func_020b04f0(data_0210794c, 4, 0, 255);
                arg0->sub.fAF = 1;
            } else {
                func_020b04f0(data_0210794c, 5, 0, 255);
            }
        }
    }
    if (data_021092f4->unknown1c() != 0) {
        return;
    }
    if (arg0->sub.fAF == 0) {
        return;
    }
    func_02073750(arg0);
}
