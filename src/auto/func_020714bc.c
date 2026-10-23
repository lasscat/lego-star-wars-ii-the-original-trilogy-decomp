#include "m2c.h"

extern u8 data_020fe6d0[];
extern u8 data_020feb10[];
extern u8 data_020edfa4[];
extern u8 data_020edfb8[];
extern u8 data_020edfd0[];

void func_020534e0(void *);
void func_0206d4d0(void *, s32, s32, s32, s32);
void func_0206549c(s32 *);
u32 func_02062b10(s32);
void func_0205e624(void *, s32, s32);
u8 func_020666f8(void);
void *func_02066708(s32);
s32 func_020e0db0(s8 *);
void func_02066b84(u8 *, u32, u16 *);
void func_020730d0(s32);

typedef struct {
    void *f0;
    s32 f4;
    s32 f8;
    s32 fc;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1c;
    s32 f20;
    s32 f24;
    u8 s28[8];
    u8 s30[8];
    u8 pad38[0x64 - 0x38];
    s32 s64;
    u8 pad68[0x94 - 0x68];
    s32 f94;
    s32 f98;
    s32 f9c;
    u8 padA0[0xa4 - 0xa0];
    s32 fa4;
    u8 padA8[0xb0 - 0xa8];
    s32 fb0;
    u16 fb4;
    u8 padB6[0xbc - 0xb6];
    void *fbc;
    void *fc0;
    void *fc4;
    void *fc8;
    void *fcc;
    s32 fd0;
    u8 fd4;
    u8 padD5[0xf8 - 0xd5];
    u16 ff8[0x40];
    u16 f178[0x80];
} Obj;

Obj *func_020714bc(Obj *this, s32 a, s32 b, s32 c, s32 d) {
    u8 *p;

    this->f0  = data_020fe6d0;
    this->f4  = a;
    this->f8  = b;
    this->fc  = c;
    this->f10 = d;
    this->f14 = 0;
    this->f18 = 0;
    this->f1c = 0;
    this->f20 = 0;
    this->f24 = 0;
    this->f0  = data_020feb10;

    func_020534e0(this->s28);
    func_020534e0(this->s30);
    func_0206d4d0(this->pad38, 1, 4, 2, 3);
    func_0206549c(&this->s64);

    this->f94 = 0;
    this->f98 = 0;
    this->f9c = 0x80000000;
    this->fa4 = 0;
    this->fb0 = 2;
    this->fb4 = func_02062b10(0xffff);

    func_0205e624(&this->fbc, 0, 0x3c);
    func_0205e624(this->ff8, 0, 0x80);
    func_0205e624(this->f178, 0, 0x100);

    p = func_02066708(func_020666f8() + 0x15);
    func_02066b84(p, func_020e0db0(p) + 1, this->ff8);

    p = func_02066708(func_020666f8() + 0x1c);
    func_02066b84(p, func_020e0db0(p) + 1, this->f178);

    this->fbc = data_020edfa4;
    this->fc0 = this->ff8;
    this->fc4 = this->f178;
    this->fc8 = data_020edfb8;
    this->fcc = data_020edfd0;
    this->fd0 = 0x00400141;
    this->fd4 = 4;

    if (d == 2) {
        func_020730d0(4);
    }
    return this;
}
