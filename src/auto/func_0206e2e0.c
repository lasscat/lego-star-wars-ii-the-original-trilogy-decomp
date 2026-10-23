#include "m2c.h"

/* 0x1c-byte payload buffer passed to func_020b04f0. */
typedef struct {
    u16 a;
    u8 b;
    u8 c;
    u8 pad[0x1C - 4];
} Payload;

typedef struct {
    u8 pad[0x0C];
    void *f0C;
    u8 pad1[0x14 - 0x10];
    u32 f14;
    u32 f18;
    u32 f1C;
    u8 pad2[0x28 - 0x20];
    u8 f28;
    u8 f29;
    u8 f2A;
} Obj;

extern s32 data_027e02a8;
extern u32 data_02104d90;
extern void *data_02102900;
extern void *data_0210794c;

extern void func_020b04f0(void *, s32, void *, s32);
extern void func_0205ecc4(void *, s32, s32, s32, s32, s32);
extern void func_02060158(s32, s32, s32, s32, ...);
extern void func_020660c0(void *, s32, s32, s32, u16);
extern void func_020861bc(void *, s32, s32);
extern void func_02087044(void *);
extern void func_0206e4ac(void *);
extern void func_0206e6b0(void *);

void func_0206e2e0(Obj *obj) {
    switch (obj->f28) {
        case 3:
            func_0206e4ac(obj);
            return;
        case 6:
            func_0206e6b0(obj);
            return;
        case 0:
            if (data_027e02a8 & 0x40) {
                Payload p;
                p.b = (u8) obj->f14;
                p.c = (u8) obj->f18;
                p.a = obj->f29;
                func_020b04f0(&data_0210794c, 48, &p, 255);
                return;
            }
            func_020861bc(&data_02104d90, 10, 0);
            func_0205ecc4(&data_02102900, 15, 0, 0, 0, 0);
            func_0205ecc4(&data_02102900, 28, 1, obj->f14, obj->f18, obj->f29);
            data_02104d90 &= ~1;
            return;
        case 1:
            if (data_027e02a8 & 0x40) {
                Payload p;
                p.b = (u8) obj->f1C;
                p.a = obj->f2A;
                func_020b04f0(&data_0210794c, 49, &p, 255);
                return;
            }
            func_020861bc(&data_02104d90, 10, 1);
            func_02060158(&data_02102900, 1, 24, 2, obj->f1C, obj->f2A);
            return;
        case 4:
            obj->f28 = 5;
            func_020660c0(obj->f0C, 1, 9, 220, 0);
            func_02060158(&data_02102900, 1, 11, 0);
            func_02087044(&data_02104d90);
            return;
    }
}
