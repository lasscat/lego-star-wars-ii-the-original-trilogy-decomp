#include "m2c.h"

class Fx {
public:
    s32 v;
    Fx(s32 x) {
        v = x;
    }
};

struct Item {
    u8 pad0[0x70];
    s32 pos;
    s32 scale;
    s32 key;
};

struct Node {
    Item *item;
    Node *next;
};

struct Owner {
    u8 pad0[0x30C];
    s32 useHead;
    Node *head;
    Node *end;
};

enum {
    FX_ONE  = 0x1000,
    FX_HALF = 0x800
};

/* 20.12 fixed-point multiply, rounded */
static inline s32 fx_mul(s32 a, s32 b) {
    return (s32) ((s64) a * b + FX_HALF >> 12);
}

class Filter {
public:
    virtual void unknown00();
    virtual void onItem(Item *item);
    virtual void onItemArg(Item *item, Fx arg);

    s32 f4;
    s32 min;
    s32 max;
    s32 mode;

    void update(Owner *owner, Fx arg);
};

/* Mode 0: report items whose key lies in [min, max).
 * Mode 1: compare pos against min/max, offset by scale when the bound is not positive. */
extern "C" void func_020bdfcc(Filter *self, Owner *owner, Fx arg) {
    Node *n;
    s32 lower;
    s64 scale;

    switch (self->mode) {
        case 0:
            if (arg.v == FX_ONE) {
                for (n = owner->useHead ? owner->head : owner->end; n != owner->end; n = n->next) {
                    if (n->item->key >= self->min && n->item->key < self->max) {
                        self->onItem(n->item);
                    }
                }
            } else {
                for (n = owner->useHead ? owner->head : owner->end; n != owner->end; n = n->next) {
                    if (n->item->key >= self->min && n->item->key < self->max) {
                        self->onItemArg(n->item, arg);
                    }
                }
            }
            break;
        case 1:
            if (arg.v == FX_ONE) {
                Fx lo = (self->min < 0) ? Fx(FX_ONE) : Fx(0);
                Fx hi = (self->max <= 0) ? Fx(FX_ONE) : Fx(0);
                for (n = owner->useHead ? owner->head : owner->end; n != owner->end; n = n->next) {
                    Item *item = n->item;
                    scale      = item->scale;
                    lower      = self->min;
                    lower += fx_mul(scale, lo.v);
                    if (item->pos >= lower && item->pos < self->max + fx_mul(item->scale, hi.v)) {
                        self->onItem(item);
                    }
                }
            } else {
                Fx lo = (self->min < 0) ? Fx(FX_ONE) : Fx(0);
                Fx hi = (self->max <= 0) ? Fx(FX_ONE) : Fx(0);
                for (n = owner->useHead ? owner->head : owner->end; n != owner->end; n = n->next) {
                    Item *item = n->item;
                    scale      = item->scale;
                    lower      = self->min;
                    lower += fx_mul(scale, lo.v);
                    if (item->pos >= lower && item->pos < self->max + fx_mul(item->scale, hi.v)) {
                        self->onItemArg(item, arg);
                    }
                }
            }
            break;
    }
}
