/* Reconstructed from USA ARM9 at 0x02075d00 (176 bytes).
 *
 * Constructor-style initialiser: installs the base vtable, the link and a
 * zeroed header, then replaces the vtable with the derived one and creates
 * four child objects through func_0201ad50().
 */
#include "m2c.h"

typedef struct {
    s32 v;
} UnkVal;

typedef struct {
    u8 b[6];
} Six;

typedef struct {
    u8 a;
    u8 b;
} BytePair;

typedef struct {
    void *vptr;
    s32 link;
    s16 f08;
    void *child[4];
    s32 f1c;
    s32 f20;
    u8 f24;
} Self;

extern void func_0201ad50(void *, s32, void *, UnkVal, UnkVal, u8, void *);
extern M2C_UNK data_020fe77c;
extern M2C_UNK data_020fed00;
extern BytePair data_020ee238[];
extern Six data_020ee240[];

Self *func_02075d00(Self *self, s32 link) {
    UnkVal x;
    UnkVal y;
    int i;

    self->vptr = &data_020fe77c;
    self->link = link;
    self->f08  = 0;
    self->vptr = &data_020fed00;
    self->f1c  = 0;
    self->f20  = 0;
    self->f24  = 0;
    for (i = 0; i < 4; i++) {
        y.v = data_020ee238[i].b << 12;
        x.v = data_020ee238[i].a << 12;
        func_0201ad50((void *) ((u8 *) self + 0xc + i * 4), i + 0xc, &data_020ee240[i], x, y, 0, (void *) 1);
    }
    return self;
}
