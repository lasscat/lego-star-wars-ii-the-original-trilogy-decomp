#include "m2c.h"

typedef struct {
    void *b;
    s32 a;
} Elem;

typedef struct {
    u8 pad[0x6f8];
    Elem arr[32];
    u32 pad2;
    u32 count;
} Obj;

typedef struct {
    u16 pad[6];
    u16 f0c;
} Sub;

void func_0201811c(void *out, Obj *o, void *p, int flag);

void *func_02048f44(void *p) {
    Obj *o = *(Obj **) ((u8 *) p + 4);
    u32 i;
    s16 v;
    for (i = 0; i < o->count; i++) {
        s32 a   = o->arr[i].a;
        void *b = o->arr[i].b;
        if (a > 10240000) {
            return 0;
        }
        func_0201811c(&v, o, b, 1);
        if (((Sub *) b)->f0c == 2) {
            s32 t = v;
            if (t < 0) {
                t = -t;
            }
            if (t < 0x4000) {
                return b;
            }
        }
    }
    return 0;
}
