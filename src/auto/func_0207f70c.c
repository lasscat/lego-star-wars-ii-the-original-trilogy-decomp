#include "m2c.h"

typedef struct {
    s32 v;
} WordArg;

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

typedef struct {
    u8 pad0[8];
    u32 flags;
    u8 pad1[0x60 - 0xC];
    Vec3 vel; /* name guessed from callers */
} Ent;

typedef struct {
    u8 pad0[4];
    Ent *ent;
    s32 path_id;
    u8 pad1[8];
    u32 point_idx;
    s32 arg0;
    s32 arg1;
    u16 timer; /* name guessed from callers */
    u16 pad3;
    u8 no_path; /* set by func_0207f6b8 when path_id == -1 */
    u8 pad4[3];
    Vec3 target; /* waypoint position, filled by func_0207f890 */
    Vec3 step;   /* target minus entity position, from func_0207f890 */
} PathFollower;

typedef struct {
    u8 pad0[0x34];
    u8 *table;
} Sub;

typedef struct {
    u8 pad0[4];
    Sub *sub;
} Mid;

typedef struct {
    u8 pad0[0x38C];
    Mid *mid;
} Game;

typedef struct {
    u8 pad0[0x68];
    Game *game;
} Globals;

typedef struct {
    u8 pad[6];
    u8 flag;
} PathPoint;

extern Globals data_0210930c;
extern Vec3 data_020ff9b4;

extern s32 func_0200aef8(void *, void *, WordArg);
extern void func_02090584(Game *, s32, s32);
extern u8 func_02067b18(void *);
extern PathPoint *func_02090688(Game *, s32, u32);
extern void func_020675d8(void *, s32);
extern void func_0207f890(PathFollower *);

enum {
    ENT_FLAG_REMOVED = 0x2, /* name guessed from use */
    ARRIVE_RADIUS    = 0x2000,
};

/* Path-follow step: at each waypoint advance to the next one; returns 1 when the path is finished. */
s32 func_0207f70c(PathFollower *s) {
    Ent *ent;
    s32 arrived;
    Vec3 *dst;
    WordArg radius;
    PathPoint *point;

    ent = s->ent;
    if (ent == NULL || (ent->flags & ENT_FLAG_REMOVED) == ENT_FLAG_REMOVED) {
        s->ent = NULL;
        func_02090584(data_0210930c.game, s->arg0, s->arg1);
        return 1;
    }
    radius.v = ARRIVE_RADIUS;
    arrived  = 1;
    if (func_0200aef8((u8 *) ent + 0xB0, &s->target, radius) == 0) {
        s->timer--;
        if (s->timer != 0) {
            arrived = 0;
        }
    }
    if (arrived != 0) {
        if (s->no_path != 0 || ++s->point_idx >= func_02067b18(data_0210930c.game->mid->sub->table + s->path_id * 8)) {
            dst = &s->ent->vel;
            if (dst != &data_020ff9b4) {
                dst->x = data_020ff9b4.x;
                dst->y = data_020ff9b4.y;
                dst->z = data_020ff9b4.z;
            }
            func_02090584(data_0210930c.game, s->arg0, s->arg1);
            return 1;
        }
        point = func_02090688(data_0210930c.game, s->path_id, s->point_idx);
        if (point->flag != 0) {
            func_020675d8((u8 *) data_0210930c.game->mid->sub + 0x28, point->flag);
        }
        func_0207f890(s);
    }
    dst = &s->ent->vel;
    if (dst != &s->step) {
        dst->x = s->step.x;
        dst->y = s->step.y;
        dst->z = s->step.z;
    }
    return 0;
}
