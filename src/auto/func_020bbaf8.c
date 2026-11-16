#include "m2c.h"

typedef struct {
    s32 v;
} Step;

typedef struct Node {
    void *owner;
    struct Node *next;
} Node;

typedef struct Glob {
    u8 pad[0x4f8];
    s32 count;
    Node *head;
    Node *sentinel;
} Glob;

extern const s16 data_020f88c4[];
extern Glob data_0210e1ec;

extern void *func_020bc190(void *self);
extern void func_0205e84c(void *obj);
extern void func_020bc3cc(void *self, Step dt);

enum {
    FX_ONE = 0x1000
};
enum {
    DIST2_MAX = 0x3d090
};

/* 20.12 fixed-point product with rounding. */
static inline s32 fxmul(s32 a, s64 b) {
    return (s32) (((s64) a * b + 0x800) >> 12);
}

/*
 * Builds the vector (0, 0, -1) rotated about X by the angle at self+0x3c and then about Y by the
 * angle at self+0x3e (sin/cos pairs from data_020f88c4). Repeatedly passes the first list entry
 * with bit 31 set at +0x384 and a zero +0x374 to func_020bc190 and func_0205e84c until no such
 * entry is found. Then, for every entry with bit 3 at +0x384,
 * clears bit 30 when the entry lies on the non-negative side of the vector and within DIST2_MAX
 * (squared, integer units), else sets it and skips; entries without bit 2 get func_020bc3cc(obj, dt).
 */
void func_020bbaf8(void *self, Step dt) {
    s64 Y;
    s64 X;
    s64 Z;
    s32 x;
    s32 y;
    s32 z;
    s32 dz;
    void *obj;
    s64 c;
    Node *node;
    s32 t;
    s32 dy;
    s32 vis;
    s32 d2;
    Node *end;
    s32 found;
    s32 dx;
    s64 s;

    x = 0;
    y = 0;
    z = -FX_ONE;
    if (self != NULL) {
        s = data_020f88c4[(M2C_FIELD(self, u16 *, 0x3c) >> 4) * 2];
        y = -fxmul(z, s);
        c = data_020f88c4[(M2C_FIELD(self, u16 *, 0x3c) >> 4) * 2 + 1];
        z = fxmul(z, c);
        s = data_020f88c4[(M2C_FIELD(self, u16 *, 0x3e) >> 4) * 2];
        c = data_020f88c4[(M2C_FIELD(self, u16 *, 0x3e) >> 4) * 2 + 1];
        t = fxmul(z, c) - fxmul(x, s);
        x = fxmul(x, c) + fxmul(z, s);
        z = t;
    }
    do {
        found = 0;
        node  = data_0210e1ec.count != 0 ? data_0210e1ec.head : data_0210e1ec.sentinel;
        end   = data_0210e1ec.sentinel;
        while (node != end) {
            obj = node->owner;
            if ((M2C_FIELD(obj, u32 *, 0x384) & 0x80000000) && M2C_FIELD(obj, s32 *, 0x374) == 0) {
                found = 1;
                if (obj != NULL) {
                    func_020bc190(obj);
                    func_0205e84c(obj);
                }
                break;
            }
            node = node->next;
        }
    } while (found);
    node = data_0210e1ec.count != 0 ? data_0210e1ec.head : data_0210e1ec.sentinel;
    if (node == data_0210e1ec.sentinel) {
        return;
    }
    Y = y;
    X = x;
    Z = z;
    do {
        obj = node->owner;
        if (M2C_FIELD(obj, u32 *, 0x384) & 8) {
            dz = M2C_FIELD(obj, s32 *, 0x2c) - M2C_FIELD(self, s32 *, 0x2c);
            dy = M2C_FIELD(obj, s32 *, 0x28) - M2C_FIELD(self, s32 *, 0x28);
            dx = M2C_FIELD(obj, s32 *, 0x24) - M2C_FIELD(self, s32 *, 0x24);
            if ((s32) ((X * dx + Y * dy + Z * dz + 0x800) >> 12) < 0) {
                vis = 0;
            } else {
                d2 = (dx >> 12) * (dx >> 12) + (dy >> 12) * (dy >> 12) + (dz >> 12) * (dz >> 12);
                if (d2 > DIST2_MAX) {
                    vis = 0;
                } else {
                    vis = 1;
                }
            }
            if (vis) {
                M2C_FIELD(obj, u32 *, 0x384) &= ~0x40000000;
            } else {
                M2C_FIELD(obj, u32 *, 0x384) |= 0x40000000;
                goto next;
            }
        }
        if (!(M2C_FIELD(obj, u32 *, 0x384) & 4)) {
            func_020bc3cc(obj, dt);
        }
    next:
        node = node->next;
    } while (node != data_0210e1ec.sentinel);
}
