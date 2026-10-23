#include "m2c.h"

typedef struct {
    s32 unk0;
    u8 *f04;
    s32 unk8;
    u8 f0c;
    u8 pad0d[9];
    u8 f16;
    u8 pad17[9];
    void *f20;
} Obj;

extern u8 data_020ed2f3[];

void func_020b973c(void *p);
s32 func_0204fa30(u8 *p);
void func_02004b78(void *p, s32 a);
void func_0204a1c4(u8 *p);
void func_0204a400(u8 *p, void *q, s32 n);
s32 func_0204a530(u8 *p);
void func_0204a544(u8 *p, void *q);

void func_02046d84(Obj *obj, s32 flag) {
    if (flag != 0) {
        if (obj->f20 != 0) {
            func_020b973c(obj->f20);
            obj->f20 = 0;
        }
        return;
    }
    if (func_0204fa30(obj->f04 + 0x40) == 3) {
        obj->f0c |= 1;
        func_02004b78(obj->f04, 0x12);
        return;
    }
    func_0204a1c4(obj->f04 + 0x5ce);
    func_0204a400(obj->f04 + 0x5ce, obj->f04, 0);
    if (func_0204a530(obj->f04 + 0x5ce) != 0) {
        if (*(u8 *) (obj->f04 + 0x5d7) != 2 || data_020ed2f3[obj->f16 * 16] == 0x1f) {
            func_0204a544(obj->f04 + 0x5ce, obj->f04);
            obj->f0c |= 1;
            return;
        }
    }
    if (*(u16 *) (obj->f04 + 0x5ce) & 0xf0) {
        obj->f0c |= 1;
    }
}
