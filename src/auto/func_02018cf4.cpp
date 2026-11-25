#include "m2c.h"

class Obj;

// Event passed in by func_02019450; only the two virtual slots used here are known.
class Ev {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual u32 getId(); // Slot 0x8; compared with the word at self + 0x1bc.
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18();
    virtual void unknown1c();
    virtual void unknown20();
    virtual void unknown24();
    virtual void unknown28();
    virtual void hit(Obj *, u32, u32); // Slot 0x2c.
};

struct Vec3 {
    s32 x, y, z;
};

// 1.0 in the 20.12 fixed-point format (products round with 0x800, then >> 12).
enum {
    FX_ONE = 0x1000
};

extern "C" {
extern const s16 data_020f88c4[]; // Interleaved {sin, cos} table, 20.12.
extern u8 data_020f4d13[];        // One byte per 12-byte row, row picked by self + 0x1c3.
extern void func_02019554(void *);
extern s32 func_0204a880(void *);
}

// Reads one table entry and multiplies it by 1.0 with rounding (the index parameter holds the result).
static inline s32 trig_entry(u32 i) {
    i = (u32) (((s64) data_020f88c4[i] * FX_ONE + 0x800) >> 12);
    return (s32) i;
}

// Horizontal unit vector (sin, 0, cos) for a 12-bit table angle.
static inline void dir_u(Vec3 *v, s32 idx) {
    s32 i0 = idx * 2;
    s32 i1 = idx * 2 + 1;
    v->x   = trig_entry(i0);
    v->y   = 0;
    v->z   = trig_entry(i1);
}

static inline s32 vec_dot(const Vec3 *a, const Vec3 *b) {
    return (s32) (((s64) a->x * b->x + (s64) a->y * b->y + (s64) a->z * b->z + 0x800) >> 12);
}

extern "C" void func_02018cf4(void *self, Ev *ev) {
    s32 type = M2C_FIELD(ev, u16 *, 0xc);
    s32 dot;
    s32 away;
    u16 flags;

    switch (type) {
        case 1:
        case 2:
            if (M2C_FIELD(self, u32 *, 0x1bc) == ev->getId()) {
                return;
            }
            flags = M2C_FIELD(ev, u16 *, 0x1a8);
            if (flags & 0x80) {
                return;
            }
        // With flag 0x100 set, dot the direction of the angle at ev + 0xca with the vector at self + 0x60.
            away = 0;
            if (flags & 0x100) {
                Vec3 dir;
                dir_u(&dir, M2C_FIELD(ev, u16 *, 0xca) >> 4);
                dot = vec_dot((Vec3 *) ((u8 *) self + 0x60), &dir);
                if (dot <= 0) {
                    away = 1;
                }
            }
            if (away) {
                func_02019554(self);
                return;
            }
            if (func_0204a880((u8 *) ev + 0x5ce) != 0) {
                ev->hit((Obj *) self, M2C_FIELD(self, u8 *, 0x1c4), data_020f4d13[M2C_FIELD(self, u8 *, 0x1c3) * 12]);
                func_02019554(self);
            } else {
                ev->hit((Obj *) self, M2C_FIELD(self, u8 *, 0x1c4), 0xc);
                func_02019554(self);
            }
            break;
        case 4:
            func_02019554(self);
            break;
    }
}
