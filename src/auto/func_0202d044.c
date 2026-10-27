#include "m2c.h"

typedef struct Ref Ref;
/* Intrusive singly linked list of Refs; a Link sits 4 bytes into its owning Target. */
typedef struct Link {
    Ref *first;
} Link;
struct Ref {
    Link *owner;
    Link next;
};

typedef struct Target {
    u8 pad0[4];
    Link link;
    u8 pad8[4];
    u16 kind;
    u8 padE[0x6b2];
    u8 count;
} Target;

typedef Target Info;

/* Candidate record filled by func_0202d2bc (object, distance). */
typedef struct Entry {
    void *obj;
    s32 dist;
} Entry;

typedef struct Tracker {
    u8 done;
    u8 pad1;
    u8 level;
    u8 pad3;
    s16 val;
    u8 pad6[6];
    Ref ref;
} Tracker;

enum {
    MAX_CANDIDATES  = 15,  /* size of the candidate buffer passed to func_0202d2bc */
    LEVEL_THRESHOLD = 3,  /* level at which the counter below is bumped */
    KIND_MATCH      = 1,       /* kind value compared against at the end */
};

extern struct {
    u8 pad[0x34];
    s32 counter;
} data_027e0bd0;

extern void func_02005428(void *reference, void *object);
extern s32 func_0202cf34(void *, void *, void *);
extern u32 func_0202d2bc(void *, void *, Entry *, u32);
extern void *func_0202d444(void *, void *, Entry *, u32);
extern void func_0202d560(void *, void *);

static inline Target *link_target(Link *l) {
    if (l != NULL) {
        l = (Link *) ((u8 *) l - 4);
    }
    return (Target *) l;
}

static inline Link *target_link(Target *t) {
    if (t != NULL) {
        t = (Target *) ((u8 *) t + 4);
    }
    return (Link *) t;
}

static inline void ref_unlink(Ref *r) {
    Ref *cur;
    Link *l = r->owner;
    if (l != NULL) {
        cur = l->first;
        while (cur != r) {
            l   = &cur->next;
            cur = l->first;
        }
        l->first = r->next.first;
    }
}

static inline void ref_attach(Ref *r, Link *l) {
    if (l != NULL) {
        r->owner      = l;
        r->next.first = l->first;
        l->first      = r;
    } else {
        r->owner      = NULL;
        r->next.first = NULL;
    }
}

static inline void ref_set(Ref *r, Link *l) {
    ref_unlink(r);
    ref_attach(r, l);
}

/* Does nothing if self->done is set. Otherwise gathers up to MAX_CANDIDATES candidates,
 * picks a target and repoints self->ref at it (counting it), or revalidates the
 * current referent / clears the reference; then updates the level and, at
 * LEVEL_THRESHOLD or above, bumps a global counter when a kind matches. */
void func_0202d044(Tracker *self, Info *info) {
    Entry found[MAX_CANDIDATES];
    Target *target;
    u32 n;
    Entry *p;

    if (self->done != 0) {
        return;
    }
    p = found;
    do {
        p->obj  = NULL;
        p->dist = 0;
        p++;
    } while (p < found + MAX_CANDIDATES);
    n      = func_0202d2bc(self, info, found, MAX_CANDIDATES);
    target = func_0202d444(self, info, found, n);
    if (target != NULL) {
        if (func_0202cf34(self, info, target) != 0) {
            Ref tmp;
            Link *l;
            func_02005428(&tmp, target);
            l = target_link(link_target(tmp.owner));
            ref_set(&self->ref, l);
            ref_unlink(&tmp);
            target->count++;
        }
    } else {
        if (link_target(self->ref.owner) != NULL && func_0202cf34(self, info, link_target(self->ref.owner)) != 0) {
            link_target(self->ref.owner)->count++;
        } else {
            ref_set(&self->ref, target_link(NULL));
            self->val = 0;
        }
    }
    func_0202d560(self, info);
    if (self->level >= LEVEL_THRESHOLD) {
        if (info->kind != KIND_MATCH) {
            if (link_target(self->ref.owner) == NULL) {
                return;
            }
            if (link_target(self->ref.owner)->kind != KIND_MATCH) {
                return;
            }
        }
        data_027e0bd0.counter++;
    }
}
