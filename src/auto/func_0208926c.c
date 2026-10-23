#include "m2c.h"

typedef struct Node {
    void *obj;
    struct Node *next;
} Node;

typedef struct {
    u8 pad00[0x04];
    Node *head;
    u8 pad08[0x38 - 0x08];
} Foo;

typedef struct {
    u8 pad00[0x08];
    u32 f08;
    u16 f0c;
    u8 pad0e[0x89 - 0x0e];
    u8 f89;
} Obj;

typedef struct {
    u8 pad00[0x394];
    Node *head;
} Bar;

extern s32 data_027e02a4;
extern Foo data_021019f4[];
extern s32 data_0210930c[];

s32 func_0208926c(void) {
    s32 *p   = &data_027e02a4;
    Foo *f   = &data_021019f4[*p];
    Node *n  = f->head;
    u32 r0   = 0;
    s32 mask = 0x802;
    if (n != 0) {
        do {
            if (n != 0) {
                Obj *o = n->obj;
                if (o != 0) {
                    if ((o->f0c & 7) && o->f89) {
                        if ((o->f08 & mask) == 0) {
                            r0 = (r0 + 1) << 16;
                            r0 = r0 >> 16;
                        }
                    }
                }
            }
            n = n->next;
        } while (n != 0);
    }
    {
        Bar *b = *(Bar **) &data_0210930c[0x1a];
        n      = b->head;
        if (n != 0) {
            do {
                if (n != 0) {
                    Obj *o = n->obj;
                    if (o != 0) {
                        if (o->f89) {
                            if ((o->f08 & mask) == 0) {
                                r0 = (r0 + 1) << 16;
                                r0 = r0 >> 16;
                            }
                        }
                    }
                }
                n = n->next;
            } while (n != 0);
        }
    }
    return r0;
}
