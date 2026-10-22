#include "m2c.h"

extern void *func_0205e80c(s32 size, s32 heap, s32 flags);
extern void *func_02028894(void *a0, void *a1, s32 a2, s32 a3, void *a4, void *a5);
extern void func_0202897c(void *p);
extern void func_0205e84c(void *p);

typedef struct {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
} Table;

typedef struct {
    u8 f00[0xc];
    void *f0c;
    u8 f10[0x40];
    void *f50[2];
    u8 f58[4];
    u8 f5c;
} T;

typedef struct {
    u8 f00[0x10];
    T *f10;
} Obj;

extern Table data_020ed2b4;
extern u8 data_0210930c[];

s32 func_02041c84(Obj *obj, s32 mode) {
    switch (mode) {
        case 9: {
            u32 loc[4];
            u32 *row1;
            u32 *row0;
            T *base = obj->f10;
            void *p;
            u32 i;
            void *old;

            row0   = &loc[0];
            row1   = &loc[2];
            loc[0] = data_020ed2b4.f00;
            loc[1] = data_020ed2b4.f04;
            loc[2] = data_020ed2b4.f10;
            loc[3] = data_020ed2b4.f14;
            for (i = 0; i < 2; i++) {
                p = func_0205e80c(0x20, 3, 4);

                if (p != 0) {
                    p = func_02028894(p, base->f0c, row1[i], row0[i], *(void **) (data_0210930c + 0x4c), &base->f5c);
                }
                old = base->f50[i];
                if (old != p) {
                    if (old != 0) {
                        func_0202897c(old);
                        func_0205e84c(old);
                    }
                    base->f50[i] = p;
                }
            }
            return 1;
        }
        case 10: {
            T *base = obj->f10;
            void *p = 0;
            u32 i;

            for (i = 0; i < 2; i++) {
                void *old = base->f50[i];

                if (old != p) {
                    if (old != 0) {
                        func_0202897c(old);
                        func_0205e84c(old);
                    }
                    base->f50[i] = p;
                }
            }
            return 1;
        }
    }
    return 0;
}
