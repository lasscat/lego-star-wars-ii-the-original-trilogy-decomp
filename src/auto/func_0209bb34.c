#include "m2c.h"

extern u8 data_02108d90[];
extern u8 data_0210930c[];

extern void func_02001688(s32 arg0);
extern void func_020016c0(void);
extern s32 func_0209ce44(s32 arg0);
extern void func_0205e84c(s32 arg0);
extern void *func_0205e80c(u32 a, u32 b, u32 c);
extern void *func_0209cc5c(s8 *arg0);

/* Layout of the object this function resets; only the fields listed here are
 * touched (the rest is padding that the original object also left alone). */
typedef struct {
    u8 pad0[0x10];
    void *f10;
    u8 pad1[0x18];
    u8 f2c[4];
    u8 pad2[8];
    u32 f38;
    u8 pad3[0x14];
    u8 f50;
} Obj;

void func_0209bb34(Obj *obj) {
    u8 i;
    void *p;

    obj->f50 = 1;
    obj->f38 = M2C_FIELD(data_02108d90, u32 *, 0x4c8);
    func_02001688(0);
    for (i = 0; i < 4; i++) {
        void *entry = *(void **) ((u8 *) data_0210930c + i * 4 + 0x4c);

        if (entry != 0) {
            obj->f2c[i] = M2C_FIELD(entry, u8 *, 0x6bb);
        } else {
            obj->f2c[i] = 0x64;
        }
    }
    func_020016c0();
    p = obj->f10;
    if (p != 0) {
        if (p) {
            func_0209ce44(p);
            func_0205e84c(p);
        }
        obj->f10 = 0;
    }
    p = func_0205e80c(0x12c, 3, 4);
    if (p != 0) {
        p = func_0209cc5c(p);
    }
    obj->f10 = p;
}
