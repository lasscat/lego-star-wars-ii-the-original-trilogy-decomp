#include "m2c.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

// Partial interface: only slot 0x24 is dispatched here.
class ObjBase {
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
    virtual void unknown24(s32 a, s32 b, s32 c, s32 d); // Slot 0x24.
};

struct Obj : public ObjBase {
    u8 pad04[0x5c];
    Vec3 pos;
    u8 pad6c[0x6bb - 0x6c];
    u8 b6bb;
};

typedef struct {
    u8 pad00[4];
    s32 id;
} Mode;

typedef struct {
    u8 pad00[4];
    Mode *mode;
    u8 pad08[0x64 - 0x08];
    s32 w64;
    u8 pad68[0x84 - 0x68];
    s32 w84;
} Ctx;

typedef struct {
    u8 pad00[4];
    u8 *p4;
} Sub38c;

typedef struct {
    u8 pad00[0x38c];
    Sub38c *s38c;
    u8 pad390[0x47a - 0x390];
    u8 b47a;
} Game;

typedef struct {
    u8 pad00[0x4c];
    Obj *objs[7];
    Game *game;
} World;

typedef struct {
    u8 type;
    u8 mode;
    s16 value;
    u8 pad04[0x10];
} Entry;

typedef struct {
    u8 a;
    u8 b;
} Pair;

typedef struct {
    u32 flag : 1;
    u32 rest : 31;
    u8 pad04[0x50 - 0x04];
    u8 b50;
    s8 b51;
    u8 pad52[0x4374 - 0x52];
    Pair pairs[100];
} State;

typedef struct {
    u8 pad00[0x29];
    u8 count;
} Cfg;

extern "C" Ctx data_02102900;
extern "C" World data_0210930c;
extern "C" u8 data_02104df4;
extern "C" State data_02104d90;
extern "C" s32 data_02104d5c;
extern "C" Entry data_020eedac[];
extern "C" s32 data_02104dc4;
extern "C" Cfg data_021027f8;
extern "C" Vec3 data_020ff9b4;

extern "C" void func_0205ecc4(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern "C" void func_020675d8(void *arg0, s32 arg1);
extern "C" void func_0206dd60(void);
extern "C" void func_0207c450(s32 *arg0);
extern "C" void func_0207c478(s32 *arg0, u32 arg1);
extern "C" void func_0208642c(State *arg0);
extern "C" void func_02086458(State *base, u32 bit);
extern "C" s32 func_02086534(State *base, u32 bit);
extern "C" void func_02086558(State *base, u32 bit);
extern "C" s32 func_02086588(State *base, u32 bit);
extern "C" void func_02088b78(void *arg0);
extern "C" void func_02088b84(void *arg0, u8 arg1);
extern "C" s32 func_0208c6dc(s32 *arg0, u32 arg1);
extern "C" u8 func_02093fd0(s32 arg0);

static inline void reset_state(void) {
    func_02088b78(&data_02104df4);
    data_02104d90.b50 = 0;
    data_02104d90.b51 = -1;
}

static inline void vec_set(Vec3 *d, const Vec3 *s) {
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

static inline void start_mode(u32 arg1, s32 arg2, s32 arg4) {
    if (arg4 != 0) {
        func_0206dd60();
        func_0205ecc4(&data_02102900, 0x1e, 1, 0, 0, 0);
    }
    func_0205ecc4(&data_02102900, 4, 0, 4, arg1, arg2);
    if (arg4 != 0) {
        data_02102900.w84 = 1;
        data_02102900.w64 = 1;
    }
}

enum {
    MODE_ID_BUSY = 0x1e,     // Mode id that makes this call a no-op.
    RANGE_FIRST  = 9,         // Lower bound of the special id range (inclusive).
    RANGE_LAST   = 14,         // Upper bound of the special id range (inclusive).
    ENTRY_COUNT  = 100,       // Entries in data_020eedac / bits tested in data_02104d90.
};

// Changes from id arg0 to id arg1. Does nothing while the current mode id is
// MODE_ID_BUSY. When arg1 enters the 9..14 range from outside it: resets
// data_02104df4/data_02104d90 state, walks the ENTRY_COUNT-entry table setting
// or clearing each entry's bit, sets the state flag, calls virtual slot 0x24
// on each object and copies data_020ff9b4 into its Vec3 at +0x60, then calls
// func_0205ecc4 with codes 0x33 and 0x34 (func_02093fd0(arg1), arg0).
// Otherwise it resets or updates data_02104df4 and calls func_0205ecc4 with
// code 4 (plus code 0x1e first when arg4 is set).
extern "C" void func_02097cb8(u32 arg0, u32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Mode *mode = data_02102900.mode;
    s32 id     = (mode != 0) ? mode->id : 0;

    if (id == MODE_ID_BUSY) {
        return;
    }
    if (arg3 != 0) {
        func_020675d8(data_0210930c.game->s38c->p4 + 0x28, arg3);
    }
    if (!(arg0 >= RANGE_FIRST && arg0 <= RANGE_LAST) && (arg1 >= RANGE_FIRST && arg1 <= RANGE_LAST)) {
        Entry *e;
        u32 i;
        u8 count;

        reset_state();
        func_0207c450(&data_02104d5c);
        e = data_020eedac;
        for (i = 0; i < ENTRY_COUNT; i++, e++) {
            if (func_02086588(&data_02104d90, i) != 0) {
                continue;
            }
            if (func_02086534(&data_02104d90, i) != 0) {
                continue;
            }
            if (((e->type == 5 && func_0208c6dc(&data_02104dc4, data_0210930c.game->b47a) != 0) || e->type == 4) &&
                e->value == data_0210930c.game->b47a) {
                if (func_02086534(&data_02104d90, i) != 0) {
                    continue;
                }
                if (e->mode == 1) {
                    func_02086458(&data_02104d90, i);
                } else if (e->mode == 0) {
                    func_02086558(&data_02104d90, i);
                }
            } else if (data_02104d90.pairs[i].a != 0 && e->type == 2) {
                if (func_02086534(&data_02104d90, i) != 0) {
                    continue;
                }
                if (e->mode == 1) {
                    func_02086458(&data_02104d90, i);
                    func_0207c478(&data_02104d5c, i);
                } else if (e->mode == 0) {
                    func_02086558(&data_02104d90, i);
                }
            } else if (data_02104d90.pairs[i].b != 0 && e->type == 1) {
                if (func_02086534(&data_02104d90, i) != 0) {
                    continue;
                }
                if (e->mode == 1) {
                    func_02086458(&data_02104d90, i);
                    func_0207c478(&data_02104d5c, i);
                } else if (e->mode == 0) {
                    func_02086558(&data_02104d90, i);
                }
            }
        }
        func_0208642c(&data_02104d90);
        data_02104d90.flag = 1;
        for (i = 0; i < data_021027f8.count; i++) {
            data_0210930c.objs[i]->unknown24(0, 0, 1, 0);
            vec_set(&data_0210930c.objs[i]->pos, &data_020ff9b4);
        }
        data_02104d5c = data_0210930c.objs[0]->b6bb;
        func_0205ecc4(&data_02102900, 0x33, 0, 4, func_02093fd0(arg1), arg0);
        func_0205ecc4(&data_02102900, 0x34, 1, 4, func_02093fd0(arg1), arg0);
        return;
    }
    if (arg0 >= RANGE_FIRST && arg0 <= RANGE_LAST) {
        if (func_02093fd0(arg0) != func_02093fd0(arg1)) {
            reset_state();
        } else {
            func_02088b84(&data_02104df4, arg0);
        }
        start_mode(arg1, arg2, arg4);
    } else {
        if (func_02093fd0(arg0) != func_02093fd0(arg1)) {
            reset_state();
        }
        func_02088b84(&data_02104df4, arg0);
        start_mode(arg1, arg2, arg4);
    }
}
