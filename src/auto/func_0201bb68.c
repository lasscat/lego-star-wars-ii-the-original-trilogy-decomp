#include "m2c.h"

typedef struct {
    u32 y : 8;
    u32 r8 : 8;
    u32 x : 9;
    u32 r25 : 5;
    u32 hi : 2;
    u32 id : 10;
    u32 rest : 22;
} Attr;

typedef struct {
    u8 pad00[8];
    u32 flags8;
    u8 pad0c[4];
    Attr a;
    u8 pad18[3];
    u8 f1b;
    u16 f1c;
    u8 pad1e[2];
    u16 *f20;
    u8 pad24[0x1e];
    u16 f42;
    u8 f44;
    u8 f45;
    u8 pad46[0xe];
    s32 f54;
    s32 f58;
} Obj;

typedef struct {
    u32 w[2];
} Entry;

static inline void set_xy(Attr *p, s32 x, s32 y) {
    p->x = x;
    p->y = y;
}

typedef struct {
    u8 pad[0x721];
    u8 count;
    u8 pad2[2];
} Slot;

extern Slot data_02103374[];

/* Per-screen OAM buffers (OamBuf in func_0201bd78.c): 0x720 B of entries, then a count byte. */
enum Screen {
    SCR_MAIN,
    SCR_SUB
};
enum {
    TILE_NONE = 0xffff
};

/* Draws the object's sprite: through func_0201bd78 when f44 == 0, else pushes f1c copies of its
   OAM attributes onto the buffer of the screen picked by flags8 bit 31. Returns 0 if no tile. */
u32 func_0205ab44(u16);
void func_0201bd78(Obj *, u32, u32, u8, s16 *, u32, Attr *);

s32 func_0201bb68(Obj *self) {
    Attr a;
    s16 pos[2];
    u32 sub;
    s32 n;
    s32 fx;
    s32 fy;

    if (self->f42 == TILE_NONE) {
        return 0;
    }
    a   = self->a;
    fx  = self->f54;
    sub = self->f45 & 2;
    fy  = self->f58;
    if (self->f44 == 0) {
        pos[0]    = fx >> 12;
        pos[1]    = fy >> 12;
        a.x       = pos[0];
        self->a.x = a.x;
        a.y       = (u8) pos[1];
        self->a.y = a.y;
        func_0201bd78(self, func_0205ab44(self->f20[1]), self->f1b, (u8) sub, pos, self->f42, &a);
    } else {
        set_xy(&self->a, fx >> 12, (u8) (fy >> 12));
        self->a.id = self->f42;
        n          = self->f1c;
        if (n > 0) {
            do {
                enum Screen scr = (self->flags8 & 0x80000000) ? SCR_MAIN : SCR_SUB;
                Slot *s         = &data_02103374[scr];
                Entry *e        = (Entry *) s + s->count;
                n--;
                e->w[0] = ((u32 *) &self->a)[0];
                e->w[1] = ((u32 *) &self->a)[1];
                s->count++;
                self->a.x += 0x20;
                self->a.id += self->a.hi * 4;
            } while (n > 0);
        }
    }
    return 1;
}
