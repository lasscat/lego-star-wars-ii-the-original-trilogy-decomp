#include "m2c.h"

typedef struct {
    s32 v;
} Fixed;

typedef struct {
    u16 ax;
    u16 ay;
    Fixed sx;
    Fixed sy;
} Xform;

typedef struct {
    u8 b[6];
} Six;

typedef struct {
    u16 first;
    Six rows[16];
} Table;

extern u8 data_021027f8[];
extern u8 *data_02109358[];
extern Table data_020f7804;

extern void clearDataAndInstructionCache(void *, void *);
extern void func_0201a934(void *, Fixed, Fixed, s16);

static inline u16 ang_add(u16 a, u16 b) {
    u16 r = a;
    r += b;
    return r;
}

static inline s32 ang_sub(u16 a, u16 b) {
    return (s16) ang_add(a, -b);
}

/* State byte 0x6BB values ROW_KIND_FIRST..ROW_KIND_LAST select one of the 16
 * six-byte rows of data_020f7804; the selected row index is cached in
 * self+0x32 and the cache flush only runs when it changes. */
enum {
    ROW_KIND_FIRST = 0x54,
    ROW_KIND_LAST  = 0x63
};

void func_0209ec08(void *self) {
    s32 idx;
    u8 *state;
    u32 kind;
    Xform xf;

    state = data_02109358[data_021027f8[0x2A]];
    kind  = state[0x6BB];
    if (kind >= ROW_KIND_FIRST && kind <= ROW_KIND_LAST) {
        idx = kind - ROW_KIND_FIRST;
        if (M2C_FIELD(self, u8 *, 0x32) != idx) {
            clearDataAndInstructionCache(M2C_FIELD(self, void **, 0x14), &data_020f7804.rows[idx]);
            M2C_FIELD(self, u8 *, 0x32) = idx;
        }
    }
    xf.ay   = 0x8000;
    xf.ax   = 0x8000;
    xf.sx.v = 0x1000;
    xf.sy.v = 0x1000;
    func_0201a934(M2C_FIELD(self, void **, 0x14), xf.sx, xf.sy, ang_sub(0x8000, M2C_FIELD(state, u16 *, 0xCA)));
}
