#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class Entity977F8 {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual s32 unknown08(); // Slot 0x08.
};

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fc;
    u8 pad[12];
} Payload;

typedef struct {
    u8 b;
    u8 pad[27];
} SmallPayload;

extern "C" u32 data_027e02a8;
extern "C" u8 data_0210794c[];
extern "C" u8 data_02104d90[];

extern "C" void func_02004b78(void *obj, s32 id);
extern "C" void func_020871d8(void *tag, s32 value);
extern "C" void func_020b04f0(void *tag, s32 id, void *data, u32 size);
extern "C" void func_02096684(void *obj);

extern "C" void func_020977f8(void *arg0, void *arg1) {
    u8 *self       = (u8 *) arg0;
    Entity977F8 *o = (Entity977F8 *) arg1;
    u8 kind        = M2C_FIELD(self, u8 *, 0x2D);
    if (kind == 2) {
        if ((data_027e02a8 & 64) == 0) {
            func_02004b78(o, 5);
        } else {
            Payload p;
            p.f0 = (u32) o->unknown08();
            p.f4 = M2C_FIELD(o, u32 *, 0x6A0);
            p.f8 = M2C_FIELD(o, u32 *, 0x6A4);
            p.fc = M2C_FIELD(o, u32 *, 0x6A8);
            func_020b04f0(data_0210794c, 23, &p, 255);
        }
    } else if (kind == 3) {
        if ((data_027e02a8 & 64) == 0) {
            func_02004b78(o, 41);
        } else {
            Payload p;
            p.f0 = (u32) o->unknown08();
            p.f4 = M2C_FIELD(o, u32 *, 0x6A0);
            p.f8 = M2C_FIELD(o, u32 *, 0x6A4);
            p.fc = M2C_FIELD(o, u32 *, 0x6A8);
            func_020b04f0(data_0210794c, 24, &p, 255);
        }
    } else {
        if (M2C_FIELD(o, u16 *, 12) == 1) {
            if ((data_027e02a8 & 64) == 0) {
                func_020871d8(data_02104d90, (s32) M2C_FIELD(o, s8 *, 0x5DA));
            } else {
                SmallPayload s2;
                s2.b = M2C_FIELD(o, u8 *, 0x5DA);
                func_020b04f0(data_0210794c, 59, &s2, 255);
            }
        }
    }
    func_02096684(arg0);
}
