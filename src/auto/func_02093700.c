/* Reconstructed from USA ARM9 at 0x02093700 (600 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

extern u32 data_027e02a8;
extern void **data_021092f4;
extern s32 data_02104d90;
extern M2C_UNK data_0210794c;

unsigned func_020917b4(void *);
u16 func_02093958(s32, s32);
s32 func_02062ab4(s32, s32);
s32 func_02086534(void *, s32);
void *func_020931b0(s32, s32);
u16 func_02090678(void *);
u32 func_02062b10(s32);
void *func_02090668(s32, s32, s32);
M2C_UNK func_020b04f0(s32, s32, void *, s32);
void *func_0205e80c(s32, s32, s32);
void func_020accac(void *, void *, void *, void *);
M2C_UNK func_020029c4(s32, s32, s32, s32, void *);
void func_02093690(void *, s32);
void func_02004b78(s32, s32);

typedef struct {
    s16 a[3];
    s32 b[3];
    s32 c[3];
    struct {
        u16 x;
        u8 y;
    } d;
    u8 pad[0x18];
    u8 sub[0x48];
} Locals;

void func_02093700(void *arg0) {
    Locals loc;
    u16 cur;
    u32 val;
    void *ptr;
    void *obj;
    u8 idx;

    if (data_027e02a8 & 0x40) {
        if (M2C_FIELD(*data_021092f4, s32(**)(), 0x1C)(data_021092f4) != 0) {
            return;
        }
    }
    if (data_02104d90 & 1) {
        return;
    }
    if (M2C_FIELD(arg0, s32 *, 0x70) > 0) {
        M2C_FIELD(arg0, s32 *, 0x70) -= 1;
        return;
    }
    switch (func_020917b4(arg0) - 0xA) {
        case 0:
        case 1:
        case 2:
        case 4:
            if (func_02093958(arg0, 2) >= 8) {
                return;
            }
            cur = (u16) func_02062ab4(0, 0x47);
            idx = 0;
            for (;;) {
                if (idx >= 5) {
                    return;
                }
                if (func_02086534(&data_02104d90, cur) != 0) {
                    if (func_020931b0(arg0, cur) == 0) {
                        break;
                    }
                }
                cur = (u16) func_02062ab4(0, 0x47);
                idx++;
            }
            val                          = (u16) (func_02090678(M2C_FIELD(arg0, void **, 0x68)) - 1);
            val                          = func_02062b10(val);
            ptr                          = func_02090668(M2C_FIELD(arg0, void **, 0x68), val, 0);
            M2C_FIELD(arg0, s32 *, 0x70) = 0xF0;
            if (data_027e02a8 & 0x40) {
                loc.d.y = cur;
                loc.d.x = (u16) val;
                func_020b04f0((s32) &data_0210794c, 0x34, &loc.d, 0xFF);
                return;
            }
            obj = func_0205e80c(0x6F8, 0, 4);
            if (obj != NULL) {
                loc.c[0] = 0x1000;
                loc.c[1] = 0x1000;
                loc.c[2] = 0x1000;
                loc.a[0] = 0;
                loc.a[1] = 0;
                loc.a[2] = 0;
                {
                    s16 *p   = (s16 *) M2C_FIELD(ptr, void **, 0);
                    s32 t2   = p[2] << 12;
                    s32 t1   = p[1] << 12;
                    s32 t0   = p[0] << 12;
                    loc.b[0] = t0;
                    loc.b[1] = t1;
                    loc.b[2] = t2;
                }
                func_020accac(&loc.sub, loc.b, loc.a, loc.c);
                obj = func_020029c4(obj, 2, cur, 0, &loc.sub);
            }
            func_02093690(arg0, obj);
            func_02004b78(obj, 0x22);
            return;
        default:
            return;
    }
}
