#include "m2c.h"

typedef struct {
    s32 x, y, z;
} Vec;

typedef struct {
    u8 d[0x48];
} Mtx;

typedef struct {
    Vec pos;
    u8 id;
    u8 pad[0x1c - 0xd];
} Msg;

struct Iface {
    struct {
        void *slots[7];
        s32 (*check)(void *self);
    } *vt;
};

enum {
    OBJ_KIND_SPAWNED = 0x1b,
    NET_MSG_SPAWN    = 0x3a,
    NET_MSG_ALL      = 0xff,
    NET_FLAG_ACTIVE  = 0x40,
    FX_ONE           = 0x1000,
};

extern s32 func_0208c6ac(void *, u8, u8);
extern void func_020b04f0(void *, s32, void *, s32);
extern void func_020accac(void *, void *, void *, void *);
extern void *func_02015138(u32, s32, void *);
extern void func_02015dcc(void *, u8, u8, u8, u8, u8);
extern void func_0208fec8(void *, void *);

extern u8 data_0210930c[];
extern u8 data_02104dc4[];
extern u32 data_027e02a8;
extern struct Iface *data_021092f4;
extern u8 data_0210794c[];

/* Spawns object kind 0x1b at the s16 map position in arg0 (12-bit fixed point), or sends the spawn over the
   network when the link flag is set. Returns the new object, or 0. */
void *func_020526dc(s16 *arg0) {
    Mtx m;
    Msg msg;
    Vec pos;
    Vec scale;
    u16 rot[3];
    void *obj;
    s32 a;
    s32 b;
    s32 c;

    if (func_0208c6ac(data_02104dc4, *(u8 *) (M2C_FIELD(data_0210930c, u8 **, 0x68) + 0x47a), *(u8 *) (arg0 + 4)) == 0) {
        if (data_027e02a8 & NET_FLAG_ACTIVE) {
            if (data_021092f4->vt->check(data_021092f4) == 0) {
                c         = arg0[2] << 12;
                b         = arg0[1] << 12;
                a         = arg0[0] << 12;
                msg.id    = *(u8 *) (arg0 + 4);
                msg.pos.x = a;
                msg.pos.y = b;
                msg.pos.z = c;
                func_020b04f0(data_0210794c, NET_MSG_SPAWN, &msg, NET_MSG_ALL);
                return 0;
            }
        } else {
            c       = arg0[2] << 12;
            b       = arg0[1] << 12;
            a       = arg0[0] << 12;
            pos.x   = a;
            pos.y   = b;
            pos.z   = c;
            scale.x = FX_ONE;
            scale.y = FX_ONE;
            scale.z = FX_ONE;
            rot[0]  = 0;
            rot[1]  = 0;
            rot[2]  = 0;
            func_020accac(&m, &pos, rot, &scale);
            obj = func_02015138(OBJ_KIND_SPAWNED, 0, &m);
            func_02015dcc(obj, 0, *(u8 *) (arg0 + 4), 0, 0, 0);
            func_0208fec8(M2C_FIELD(data_0210930c, void **, 0x68), obj);
            return obj;
        }
    }
    return 0;
}
