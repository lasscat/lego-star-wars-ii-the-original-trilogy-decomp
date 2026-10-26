#include "m2c.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

typedef struct {
    s32 v;
} WordArg;

typedef struct {
    u8 pad0[0x14];
    Vec3 pos;
    s32 radius;
} Node;

typedef struct {
    u8 pad[0x20];
    Node *cur;
} Iter;

typedef struct {
    s32 node;
    s32 dist;
} SearchResult;

extern M2C_UNK data_0210930c[];

extern void *func_02074c9c(void *);
extern void func_02074cd0(void *, s32, void *);
extern s32 func_0200aef8(void *, void *, WordArg);
extern void func_0204f9bc(void *, void *, void *, void *, s32);
extern void func_02074d1c(void *);

enum {
    LIFT_Y         = 0x1000,      /* probe points are raised by 1.0 (fixed point 20.12) */
    MIN_CLEARANCE  = 0x2000,
    MAX_CANDIDATES = 8,
};

/* Walks up to 8 nearby candidates around pos (raised by LIFT_Y) and returns the first one that is
 * within its radius or has a clear line of sight (distance >= MIN_CLEARANCE); 0 if none. */
u32 func_02027124(s32 *obj, Vec3 *pos) {
    Vec3 p;
    Iter it;
    SearchResult res;
    Vec3 d;
    WordArg r;
    s32 i;
    Node *n;

    if (*obj == 0) {
        *obj = *(s32 *) ((u8 *) data_0210930c + 0x3c);
    }
    p.x = pos->x;
    p.y = pos->y;
    p.z = pos->z;
    p.y += LIFT_Y;
    func_02074c9c(&it);
    func_02074cd0(&it, *obj, &p);
    for (i = 0; i < MAX_CANDIDATES; i++) {
        n = it.cur;
        if (n == NULL) {
            break;
        }
        r.v = n->radius;
        if (func_0200aef8(&p, &n->pos, r) != 0) {
            return (u32) it.cur;
        }
        d.x = it.cur->pos.x;
        d.y = it.cur->pos.y;
        d.z = it.cur->pos.z;
        d.y += LIFT_Y;
        func_0204f9bc(&res, *(void **) (*(u8 **) ((u8 *) data_0210930c + 0x68) + 0x384), &p, &d, 0);
        if (res.dist >= MIN_CLEARANCE) {
            return (u32) it.cur;
        }
        func_02074d1c(&it);
    }
    return 0;
}
