#include "m2c.h"

class Sink {
public:
    virtual void s0();
    virtual void s1();
    virtual void take(void *);
};

struct Arg {
    s32 v;
};

class Item;
typedef int (Item::*Pmf)(void *, Arg);

class Item {
public:
    u8 pad0[0x1E];
    u16 timer;
    u16 flag;
    u8 pad22;
    u8 kind;
};

struct Node {
    Item *item;
    Node *next;
};

class Ctx {
public:
    u8 pad0[4];
    Node *list;
    u8 pad8[0xA0];
    Pmf handler;
    u8 padb0[0xF6 - 0xB8 - 0 + 0];
};

extern "C" {
void func_020b9584(s32, void *);
void func_02006ad0(void *, s32);
void func_020855ac(void *, s32);
void func_0209d0c4(void *, u8);
struct Tab {
    s16 v[4];
};
extern const Tab data_020f6a7c;
extern u8 data_02104d94[];
struct Globals {
    u8 pad0[0x10];
    void *work;
};
extern Globals *data_02107860;
}

enum {
    EVT_STATE_MASK = 0x803,
    HANDLER_ARG    = 0x9000,
    KIND_SPECIAL   = 3,
    SFX_SPECIAL    = 0x67,
    SFX_NORMAL     = 0x1A,
    ITEM_DONE_TIME = 10,
};

// Event handler: for each list item not yet flagged, calls the pointer-to-member handler stored in the
// object; on a hit plays a sound, flags the item with a 10 tick timer and notifies the sink at self+0x38.
extern "C" void func_02095240(u8 *self, u8 *evt) {
    Arg arg; // by-value one-word struct: handler argument is reloaded from the stack in the loop
    Tab tab;
    Pmf h;
    Item *it;
    Node *n;
    s32 hit;

    arg.v = HANDLER_ARG;
    tab   = data_020f6a7c;
    if ((*(u32 *) (evt + 8) & EVT_STATE_MASK) != 1) {
        return;
    }
    n            = *(Node **) (self + 4);
    Globals *&gr = data_02107860; // FAKE: reference local hoists the data_02107860 literal out of the loop (r8)
    h            = *(Pmf *) (self + 0xA8);
    do {
        it  = n->item;
        hit = 0;
        n   = n->next;
        if (!(it->flag & 1)) {
            if ((it->*h)(evt + 0xB0, arg) != 0) {
                hit = 1;
            }
        }
        if (hit) {
            if (it->kind == KIND_SPECIAL) {
                void *w;
                func_020b9584(SFX_SPECIAL, it);
                func_02006ad0(evt, 1);
                w = gr->work;
                if (w != NULL) {
                    func_0209d0c4(w, *(u8 *) (evt + 0x5DA));
                }
            } else {
                func_020855ac(data_02104d94, tab.v[it->kind]);
                func_020b9584(SFX_NORMAL, it);
                self[0xF6] = it->kind;
            }
            it->flag  = 1;
            it->timer = ITEM_DONE_TIME;
            ((Sink *) (self + 0x38))->take(it);
        }
    } while (n != NULL);
}
