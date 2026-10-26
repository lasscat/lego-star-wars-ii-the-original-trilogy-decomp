#include "m2c.h"

typedef struct {
    s32 v;
} WordArg;

typedef struct Node {
    u8 *obj;
    struct Node *next;
} Node;

typedef struct {
    void *pad;
    Node *head;
} List;

extern List data_027e0308;

extern s32 func_0200aef8(void *, void *, WordArg);
extern void func_0202fa64(void *);
extern void func_020b973c(void *);
extern s32 func_020363b0(void *, void *);
extern void func_020351c0(void *, void *, s32);
extern void func_02034c68(void *);
extern void func_02034e24(void *);
extern void func_02035030(void *);
extern void func_02035274(void *);
extern void func_020357c8(void *);
extern void func_02035cd0(void *);

enum {
    INFO_RELEASE_MASK = 0x802,
    PROBE_RADIUS      = 0x32000,
    KIND_TARGET       = 0x5E,
    ANIM_KIND_MATCH   = 3,
    NO_RESULT         = 5,
};

/* Per-frame update: releases linked state, probes nearby objects for a match, then dispatches on the mode byte. */
void func_02034350(u8 *arg0) {
    u8 *info; /* name guessed from callers */
    u8 *link;
    s32 found;
    Node *node;
    u8 *other;
    u8 *anim;
    s32 res;
    WordArg radius;

    info = *(u8 **) (arg0 + 4);
    if ((*(u32 *) (info + 8) & INFO_RELEASE_MASK) != 0) {
        link = *(u8 **) (arg0 + 0x4C);
        if (link != NULL) {
            *(u32 *) (link + 8) |= 2;
            *(u8 **) (arg0 + 0x4C) = NULL;
        }
        if (*(void **) (arg0 + 0x50) != NULL) {
            func_020b973c(*(void **) (arg0 + 0x50));
            *(void **) (arg0 + 0x50) = NULL;
        }
    }
    func_0202fa64(arg0);
    if ((arg0[0xC] & 2) == 0) {
        return;
    }
    if (arg0[0x34] != 0 && arg0[0x30] != 4) {
        found    = 0;
        radius.v = PROBE_RADIUS;
        for (node = data_027e0308.head; node != NULL && found == 0; node = node->next) {
            other = node->obj;
            if (other[0x6BB] != KIND_TARGET) {
                continue;
            }
            if (func_0200aef8(*(u8 **) (arg0 + 4) + 0xB0, other + 0xB0, radius) != 0) {
                anim = *(u8 **) (other + 0x5F8);
                if (anim != NULL && anim[0xE] == ANIM_KIND_MATCH) {
                    res = func_020363b0(anim, *(void **) (arg0 + 4));
                    if (res != NO_RESULT) {
                        func_020351c0(arg0, other, res);
                        found = 1;
                    }
                }
            }
        }
    }
    switch (arg0[0x30]) {
        case 1:
            func_02034c68(arg0);
            break;
        case 2:
            func_02034e24(arg0);
            break;
        case 3:
            func_02035030(arg0);
            break;
        case 4:
            func_02035274(arg0);
            break;
        case 5:
            func_020357c8(arg0);
            break;
        case 6:
            func_02035cd0(arg0);
            break;
    }
}
