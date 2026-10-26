#include "m2c.h"

typedef struct Ent Ent;
typedef struct Node Node;
struct Ent {
    u8 pad0[0x20];
    u16 flags;
    u8 b22;
    u8 b23;
    u8 b24;
    u8 b25;
};
struct Node {
    Ent *ent;
    Node *next;
};
typedef struct {
    s32 m[12];
} Blk;
typedef struct {
    Blk e[2];
} BlkPair;

extern u32 data_027e02a8;
extern u8 data_021027f8[];
extern u8 *data_02109358[];
typedef struct {
    u8 pad[0x4c];
    void *slot[8];
} Glob;
extern Glob data_0210930c;
extern const BlkPair data_020f6a84;

void func_0209468c(u8 *, s32);
void func_02095240(u8 *, void *);
void func_020953b0(u8 *);
void func_02095854(u8 *);
void func_02094eb0(u8 *, Ent *);
void func_0205d4c8(u8 *, Node *);
void func_0205e84c(Ent *);
void func_02095920(u8 *, Ent *, Blk *, u32, u32);
s32 func_02073034(void);

void func_02094ca0(u8 *self) {
    BlkPair tbl;
    Ent *e;
    Node *node;
    u32 i;
    Node *cur;

    if (M2C_FIELD(self, u16 *, 0x7c) != 0) {
        func_0209468c(self, 0);
    }
    if (M2C_FIELD(self, u16 *, 0xc) == 0) {
        return;
    }
    if (data_027e02a8 & 0x40) {
        for (i = 0; i < func_02073034(); i++) {
            void *p = data_0210930c.slot[i];
            if (p != 0) {
                func_02095240(self, p);
            }
        }
    } else {
        func_02095240(self, data_02109358[data_021027f8[0x2a]]);
    }
    if (M2C_FIELD(self, u16 *, 0x44) != 0) {
        func_020953b0(self);
    }
    func_02095854(self);
    tbl  = data_020f6a84;
    node = M2C_FIELD(self, Node **, 4);
    if (node == 0) {
        return;
    }
    do {
        s32 alive;
        e   = node->ent;
        cur = node;
        func_02094eb0(self, e);
        if (e->b25 == 0) {
            e->b25 = 2;
            e->b24 = e->b24 + 1;
            if (e->b24 >= M2C_FIELD(self + e->b23, u8 *, 0xf2)) {
                e->b24 = 0;
            }
        } else {
            e->b25 = e->b25 - 1;
        }
        alive = 1;
        if ((data_027e02a8 & 3) == 0 && (e->flags & 8)) {
            e->b22 = e->b22 - 1;
            if (e->b22 == 0) {
                node = node->next;
                func_0205d4c8(self, cur);
                if (e != 0) {
                    func_0205e84c(e);
                }
                alive = 0;
            }
        }
        if (alive) {
            s32 idx = 0;
            u32 off = ((u16) M2C_FIELD(self, u32 *, 0xb0)) << 3;
            s32 k   = e->b23;
            if (k == 3) {
                idx++;
                off += 0x1000;
            }
            func_02095920(self, e, &tbl.e[idx], off, ((u16) M2C_FIELD(self, u32 *, 0xb8 + k * 16)) << 3);
            node = node->next;
        }
    } while (node != 0);
}
