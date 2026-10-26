#include "m2c.h"

extern "C" {
s32 func_0200f5d0(void *a, void *b, s32 r, s32 *out);
void func_0202cc14(s32 *, const void *);
s32 func_0202d7f8(void *, s32, void *, s32);
s32 func_0202cecc(void *, void *);
void func_020dde64(void *base, u32 n, u32 size, s32 (*cmp)(void *, void *), void *stack);
}
extern "C" M2C_UNK data_0210930c;
extern "C" M2C_UNK data_027e0308;

typedef struct {
    void *obj;
    s32 dist;
} Entry;

typedef struct ListNode {
    void *obj;
    struct ListNode *next;
} ListNode;

typedef struct {
    u32 pad;
    ListNode *head;
} List;

typedef s32 (*VFunc)(void *);
class Entity {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18();
    virtual void unknown1c();
    virtual void unknown20();
    virtual void unknown24();
    virtual void unknown28();
    virtual void unknown2c();
    virtual void unknown30();
    virtual void unknown34();
    virtual void unknown38();
    virtual void unknown3c();
    virtual void unknown40();
    virtual int kind();
};

static inline s32 obj_kind(void *o, s32 flag) {
    s32 k = ((Entity *) o)->kind();
    if ((u32) (k - 8) <= 1U) {
        if (flag != 0) {
            k = 2;
        }
    }
    return k;
}

extern "C" u32 func_0202d2bc(void *arg0, void *self, Entry *out, u32 max) {
    void *stack[8];
    struct {
        s32 tmp;
        s32 dist;
        s32 radius;
    } L;
    u32 count;
    ListNode *node;
    void *obj;
    s32 flag;
    s32 *rp;
    s32 kind;
    void *st;
    void *info;

    M2C_FIELD(arg0, u8 *, 3) = 3;
    info                     = M2C_FIELD(self, void **, 0x5fc);
    L.radius                 = 0x64000;
    if (info != NULL) {
        func_0202cc14(&L.tmp, info);
        L.radius = L.tmp;
    }
    st   = M2C_FIELD(&data_0210930c, void **, 0x68);
    flag = L.dist = 0;
    rp            = &L.radius;
    if (M2C_FIELD(st, u8 *, 0x47a) == 0x10) {
        flag = 1;
    }
    kind  = obj_kind(self, flag);
    count = 0;
    for (node = M2C_FIELD(&data_027e0308, ListNode **, 4); node != NULL; node = node->next) {
        obj = node->obj;
        if (self == obj) {
            continue;
        }
        if ((M2C_FIELD(obj, u32 *, 8) & 0x100803) != 0x100001) {
            continue;
        }
        if (func_0202d7f8(self, kind, obj, obj_kind(obj, flag)) == 0) {
            continue;
        }
        if (func_0200f5d0((u8 *) self + 0xb0, (u8 *) obj + 0xb0, *rp, &L.dist) == 0) {
            continue;
        }
        out[count].obj  = obj;
        out[count].dist = L.dist;
        count++;
        if (count >= max) {
            break;
        }
    }
    if (count > 1) {
        func_020dde64(out, count, 8, func_0202cecc, stack);
    }
    return count;
}
