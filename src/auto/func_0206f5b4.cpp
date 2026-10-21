#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.

// Object reached through data_021092f4; only slot 0x18 is observed here.
class Obj6F5B4 {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18(s32); // Slot 0x18.
};

// Object reached through data_0210b348; only slot 0x4c is observed here.
class Owner6F5B4 {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18();
    virtual void unknown1c();
    virtual void unknown20();
    virtual void unknown24();
    virtual void unknown28();
    virtual void unknown2c();
    virtual void unknown30();
    virtual void unknown34();
    virtual void unknown38();
    virtual void unknown3c();
    virtual void unknown40();
    virtual void unknown44();
    virtual void unknown48();
    virtual void unknown4c(s32); // Slot 0x4c.
};

// Event payload: a 16-bit value plus a one byte tag.
struct Ev6F5B4 {
    u8 head[4];
    s16 value;
    u8 tag;
    u8 reserved[21];
};

struct Buf6F5B4 {
    u8 v[10];
    u8 reserved[18];
};

struct Arg6F5B4 {
    u8 pad[0x8c];
    u32 state;
    u8 unk90;
};

extern "C" s32 data_020ffa00[];
extern "C" M2C_UNK data_02104d90;
extern "C" u8 data_0210794c[];
extern "C" M2C_UNK data_02102900;
extern "C" Obj6F5B4 *data_021092f4;
extern "C" Owner6F5B4 *data_0210b348;

extern "C" void func_0206f848(void *);
extern "C" void func_0205ecc4(void *, u8, u8, u8, s32, s32);
extern "C" s32 func_02086534(void *, s32);
extern "C" void func_020b04f0(void *, s32, u8 *, s32);
extern "C" s32 func_02062ae4(s32);
extern "C" void func_02072f94(void);

extern "C" void func_0206f5b4(void *arg0) {
    Arg6F5B4 *arg = (Arg6F5B4 *) arg0;
    switch (arg->state) {
        case 0:
            func_0206f848(arg0);
            break;
        case 1:
        case 2:
        case 3:
            break;
        case 5: {
            u8 tag = arg->unk90;
            if ((tag != 0) && (tag != 1) && (tag != 2)) {
            } else {
                if (tag == 2) {
                    Buf6F5B4 buf;
                    s32 i = 0;
                    u8 *p = buf.v;
                    do {
                        if (func_02086534(&data_02104d90, data_020ffa00[i]) != 0) {
                            *p = (u8) data_020ffa00[i];
                        } else {
                            *p = 100;
                        }
                        i++;
                        p++;
                    } while (i < 10);
                    func_020b04f0(&data_0210794c, 0x43, (u8 *) &buf, 0xff);
                }
                {
                    Ev6F5B4 ev;
                    ev.value = func_02062ae4(0x1388);
                    ev.tag   = arg->unk90;
                    func_020b04f0(&data_0210794c, 0x0a, (u8 *) &ev, 0xff);
                }
                data_021092f4->unknown18(0);
                data_0210b348->unknown4c(0);
                arg->state = 6;
            }
            break;
        }
        case 4:
            func_0205ecc4(&data_02102900, 0x20, 1, 0, 1, 0);
            break;
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
            break;
        default:
            break;
    }
    func_02072f94();
}
