#include "m2c.h"

extern M2C_UNK data_027e03a0;

extern void func_0209f844(s32);
extern void NNS_G3dRenderObjRemoveAnmObj(M2C_UNK, M2C_UNK);
extern M2C_UNK func_0209f1b0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
extern M2C_UNK func_02061194(M2C_UNK, M2C_UNK, M2C_UNK);
extern M2C_UNK func_0205ab1c(M2C_UNK);
extern void func_020c3af4(s32, s32);

typedef struct {
    s32 v; /* 0x00 */
    u16 a; /* 0x04 */
    u16 b; /* 0x06 */
} Slot;

typedef struct {
    s32 f00;             /* 0x00 */
    s32 f04;             /* 0x04 */
    s32 *f08;            /* 0x08 */
    u8 pad0c[0x74 - 0x0c]; /* 0x0c */
    Slot slots[5];       /* 0x74 */
    s32 f9c;             /* 0x9c */
    s32 fa0;             /* 0xa0 */
    s32 fa4;             /* 0xa4 */
    s32 fa8;             /* 0xa8 */
    u16 fac;             /* 0xac */
    u16 fae;             /* 0xae */
    u16 fb0;             /* 0xb0 */
    u16 fb2;             /* 0xb2 */
    s32 fb4;             /* 0xb4 */
    s32 fb8;             /* 0xb8 */
} Obj;

void func_0209f640(Obj *obj, s32 arg1, s32 arg2, s32 arg3, u8 arg4) {
    s32 temp_r4;
    s32 base;
    s32 off;

    if (*(u16 *) arg1 >= 0x78 && *(u16 *) arg1 <= 0xa0) {
        temp_r4 = 3;
        if (*(u16 *) arg1 < 0x8a) {
            temp_r4 = 2;
        } else if (*(u16 *) arg1 >= 0x9c) {
            temp_r4 = 4;
        }
        if (obj->slots[temp_r4].v != 0) {
            NNS_G3dRenderObjRemoveAnmObj((s32) obj + 0x20, obj->slots[temp_r4].v);
        }
        base = obj->f08;
        off  = *(s32 *) ((u8 *) base + *(u16 *) ((u8 *) base + 0xe) + 0xc);
        if (func_0209f1b0(&obj->slots[temp_r4], *(u16 *) ((u8 *) arg1 + 2), base + off, arg2, arg4, 0) == 0) {
            return;
        }
        func_020c3af4((s32) obj + 0x20, obj->slots[temp_r4].v);
        return;
    }
    if (arg3 == 0 && *(u16 *) arg1 == obj->fae) {
        u32 flag = ((u32) (*(u16 *) ((u8 *) obj + 0x7a) << 0x1c)) >> 0x1f;
        if (arg4 == (flag == 1 ? 1 : 0)) {
            obj->slots[0].b = (u16) ((obj->slots[0].b & ~1) | 1);
            obj->slots[0].b = (u16) (obj->slots[0].b & ~2);
            return;
        }
    }
    func_0209f844((s32) obj);
    obj->f9c = arg1;
    obj->fae = *(u16 *) arg1;
    if (*(u16 *) ((u8 *) arg1 + 8) != 0xffff) {
        obj->fb4 = func_02061194(&data_027e03a0, *(u16 *) ((u8 *) arg1 + 8), (s32) obj + 0xb8);
    }
    if (*(u16 *) ((u8 *) arg1 + 6) != 0xffff) {
        obj->fa0 = func_0205ab1c(*(u16 *) ((u8 *) arg1 + 6));
    }
    obj->fb2 = (u16) (obj->fb2 & ~4);
    obj->fb2 = (u16) (obj->fb2 & ~8);
    obj->fb2 = (u16) (obj->fb2 & ~0x10);
    obj->fb2 = (u16) (obj->fb2 & ~0x20);
    obj->fb2 = (u16) (obj->fb2 & ~0x40);
    obj->fb2 = (u16) (obj->fb2 & ~0x80);
    base     = obj->f08;
    off      = *(s32 *) ((u8 *) base + *(u16 *) ((u8 *) base + 0xe) + 0xc);
    if (func_0209f1b0(&obj->slots[0], *(u16 *) ((u8 *) arg1 + 2), base + off, arg2, arg4, 1) == 0) {
        return;
    }
    if (obj->slots[1].v == obj->slots[0].v) {
        return;
    }
    func_020c3af4((s32) obj + 0x20, obj->slots[0].v);
}
