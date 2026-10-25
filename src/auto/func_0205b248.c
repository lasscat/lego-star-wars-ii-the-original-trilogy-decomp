#include "m2c.h"

/*
 * Drops one reference from the shared entry hanging off a node returned by
 * func_0205af6c. The reference count is the 7-bit field at bits 16..22 of the
 * word at +8 (see func_0205b1e0). When the count reaches zero the entry's
 * buffer and the entry itself are released and func_0205b488 unlinks the node.
 */

typedef struct {
    s32 unk_00;
    u32 unk_04;
    u32 unk_08;
} Unk0205b248Entry;

typedef struct {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0c;
    Unk0205b248Entry *unk_10;
} Unk0205b248Node;

typedef struct {
    Unk0205b248Node *node;
} Unk0205b248Iter;

extern void func_0205af6c(Unk0205b248Iter *, void *, u16 *);
extern s32 func_0205e5b0(s32);
extern void func_0205e84c(void *);
extern void func_0205b488(s32 *, void *, Unk0205b248Iter);

static inline u32 refCount(Unk0205b248Entry *e) {
    return (e->unk_08 << 9) >> 25;
}

void func_0205b248(void *a0, u16 a1, ...) {
    Unk0205b248Iter it;
    Unk0205b248Iter cur;
    Unk0205b248Node *n;
    s32 res;
    Unk0205b248Entry *e;
    // FAKE: volatile view of n->unk_10 so each access re-reads the entry pointer (stops load merging)
    Unk0205b248Entry *volatile *pe;

    func_0205af6c(&it, a0, &a1);
    n  = it.node;
    pe = &n->unk_10;
    if (refCount(*pe) == 0) {
        return;
    }
    e         = *pe;
    e->unk_08 = (e->unk_08 & ~0x7f0000) | (((refCount(e) - 1) & 0x7f) << 16);
    if (refCount(*pe) != 0) {
        return;
    }
    func_0205e5b0((*pe)->unk_00);
    func_0205e84c(*pe);
    cur.node = n;
    func_0205b488(&res, a0, cur);
}
