#include "m2c.h"

typedef struct {
    s32 v;
} UnkVal;

typedef struct {
    u8 pad000[8];
    u32 f008;
    u8 pad00C[0xC8];
    u8 fD4[0xD4];
    u16 f1A8;
} Obj;

typedef struct {
    Obj *obj;
    u8 pad04[0x20];
} Slot;

typedef struct {
    Slot slots[26];
    u8 pad3A8[0x20];
    u32 f3C8;
    u8 pad3CC[0xAC];
    u8 f478;
} Mgr;

extern UnkVal data_020ff9a0;

extern void func_0208fa54(Mgr *);
extern void func_02090918(Mgr *);
extern void func_020901d0(Mgr *);
extern void func_020104d0(Obj *);
extern void func_01ffad38(void *, UnkVal, ...);
extern void func_020105fc(Obj *);

void func_0208fb24(Mgr *m) {
    u32 i;

    func_0208fa54(m);
    func_02090918(m);
    if (m->f478 != 0) {
        func_020901d0(m);
    }
    for (i = 0; i < m->f3C8; i++) {
        if ((m->slots[i].obj->f008 & 1) == 1) {
            func_020104d0(m->slots[i].obj);
            if (m->slots[i].obj->f1A8 & 0x40) {
                func_01ffad38(m->slots[i].obj->fD4, data_020ff9a0, 0);
            }
            if (m->slots[i].obj->f1A8 & 4) {
                func_020105fc(m->slots[i].obj);
            }
        }
    }
}
