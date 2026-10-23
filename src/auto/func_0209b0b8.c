/* Reconstructed from USA ARM9 at 0x0209b0b8 (452 bytes).
 *
 * The 12-byte triple in "v" is the "default position" copy of
 * data_020ff9b4; it is refreshed from a scene object (offset 0xb0) and then
 * handed to func_0209b27c together with the per-slot target objects.
 *
 * data_0210930c is used as a byte array: element i holds a scene pointer at
 * byte offset 0x4c.  The loop walks four slots and skips the active one
 * (data_021027f8[0x2a]).
 */
#include "m2c.h"

/* 12-byte position triple. */
typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Tri;

extern Tri data_020ff9b4;
extern s32 data_0210930c[];
extern u8 data_021027f8[];

void func_02001688(s32);
void func_020016c0(void);
void *func_020931b0(void *, s32);
void func_0209b27c(void *, void *, void *);

void func_0209b0b8(void *arg0) {
    Tri v;
    void *obj;
    void *p;
    u8 i;

    func_02001688(0);

    v.x = 0;
    v.y = 0;
    v.z = 0;
    if (&v != &data_020ff9b4) {
        v.x = data_020ff9b4.x;
        v.y = data_020ff9b4.y;
        v.z = data_020ff9b4.z;
    }

    obj = func_020931b0(data_0210930c, 0x17);
    if (obj != 0) {
        Tri *src = (Tri *) ((s8 *) obj + 0xb0);
        if (&v != src) {
            v.x = src->x;
            v.y = src->y;
            v.z = src->z;
        }
        func_0209b27c(arg0, &v, M2C_FIELD(arg0, void **, 0x78));
    } else {
        void *q = M2C_FIELD(arg0, void **, 0x78);
        M2C_FIELD(q, u32 *, 8) &= ~1;
    }

    for (i = 0; i < 4; i++) {
        if (i == data_021027f8[0x2a]) {
            continue;
        }
        p = M2C_FIELD(&data_0210930c[i], void **, 0x4c);
        if (p != 0 && *(u16 *) ((s8 *) p + 0x6f0) == 0xea) {
            Tri *src = (Tri *) ((s8 *) p + 0xb0);
            if (&v != src) {
                v.x = src->x;
                v.y = src->y;
                v.z = src->z;
            }
            func_0209b27c(arg0, &v, M2C_FIELD((s8 *) arg0 + i * 4, void **, 0x68));
            M2C_FIELD(M2C_FIELD(arg0, void **, 0x78), u32 *, 8) |= 1;
            func_0209b27c(arg0, &v, M2C_FIELD(arg0, void **, 0x78));
        } else if (p != 0) {
            Tri *src = (Tri *) ((s8 *) p + 0xb0);
            if (&v != src) {
                v.x = src->x;
                v.y = src->y;
                v.z = src->z;
            }
            func_0209b27c(arg0, &v, M2C_FIELD((s8 *) arg0 + i * 4, void **, 0x68));
        } else {
            void *q = M2C_FIELD((s8 *) arg0 + i * 4, void **, 0x68);
            M2C_FIELD(q, u32 *, 8) &= ~1;
        }
    }

    func_020016c0();
}
