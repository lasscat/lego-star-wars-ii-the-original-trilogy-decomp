#include "m2c.h"

class TileMap {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18();
    virtual void unknown1c(s32);
    virtual void unknown20(s32);
    virtual void unknown24(s32, s32, s32, s32);
};

typedef struct {
    s16 f0;
    s16 f2;
    s16 f4;
    u16 f6;
    u16 f8;
    u8 fa;
    u8 fb;
    u8 fc;
    u8 fd;
} In;

extern M2C_UNK data_02104d90;
extern M2C_UNK data_021098d0;
extern const u8 data_020ef58a[6];

extern "C" s32 func_020867ec(void *, s32);
extern "C" s32 func_0207b68c(s32);
extern "C" void func_02083cd8(TileMap *, TileMap *, s32, s32);
extern "C" void func_0202c498(void *, u8);
extern "C" void func_02004404(void *, u32);
extern "C" void func_02003998(void *, u8);
extern "C" TileMap *func_020508f8(s32, void *, s32, s32, u16);

extern "C" TileMap *func_020509b8(In *p, s32 a1, s32 a2) {
    s32 v[3];
    s32 mode;
    TileMap *obj;
    u16 w;
    s32 ta, tb, tc;

    mode = p->fa;
    w    = *(u16 *) ((u8 *) data_020ef58a + (s16) mode * 24);
    if (func_020867ec(&data_02104d90, 0xe)) {
        mode = func_0207b68c(mode) ? 0x43 : 0x10;
    } else if (func_020867ec(&data_02104d90, 0x10)) {
        mode = func_0207b68c(mode) ? 0x20 : 0x9;
    }
    tc   = p->f4 << 12;
    tb   = p->f2 << 12;
    ta   = p->f0 << 12;
    v[0] = ta;
    v[1] = tb;
    v[2] = tc;
    obj  = func_020508f8(mode, v, p->fb, p->fc, p->f8);
    func_02083cd8((TileMap *) &data_021098d0, obj, a1, a2);
    if (p->fd != 0xc) {
        func_0202c498((void *) ((u8 *) obj + 0x5e0), p->fd);
        if (p->fd == 0xb) {
            obj->unknown24(9, 1, 1, 0);
        }
        if (p->fd == 8 && func_020867ec(&data_02104d90, 9)) {
            func_02004404((void *) obj, 6);
        }
    }
    if (func_020867ec(&data_02104d90, 0xe) || func_020867ec(&data_02104d90, 0x10)) {
        func_02003998((void *) obj, w);
    }
    return obj;
}
