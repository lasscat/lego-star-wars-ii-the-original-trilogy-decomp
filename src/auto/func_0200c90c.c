#include "m2c.h"

// Joint names looked up on the model, in the order of the ROM table at data_020e5ce0.
typedef struct {
    const char *n[10];
} NameTable;

typedef struct {
    u8 d[0x33];
    s8 id; // joint index found for the name, -1 when absent
    u8 pad[4];
} Blob;

typedef struct {
    u8 base0[0xDC];
    u8 *model; // 0xDC: resource block (header + dictionary)
    u8 base1[0x39C - 0xE0];
    Blob blobs[10]; // 0x39C, 0x38 bytes each (zeroed by func_0200c04c)
    u8 count;       // 0x5CC: number of names that were found
} Actor;

extern NameTable data_020e5ce0;
extern u8 data_021019c4[]; // 17-byte name scratch buffer
void *func_0205e624(void *, s32, s32); // memset
void *strcpy(u8 *, const char *);
s32 func_020c6458(void *, void *); // find a joint by name in a dictionary

// Entry 0 of the resource dictionary: header at p + 8 + ofs, 4-byte entry header, entries `unit` bytes apart.
static inline u8 *Lookup(u8 *p, s32 idx) {
    u8 *t  = p + 8 + *(u16 *) (p + 0xE);
    s32 *e = (s32 *) (t + 4);
    // FAKE: volatile cast keeps the (always 0) entry stride multiply instead of folding it away
    s32 *q = (s32 *) ((u8 *) e + *(volatile u16 *) t * idx);
    return p + *q + 0x40;
}

void func_0200c90c(Actor *self) {
    NameTable names = data_020e5ce0;
    u32 i           = 0;
    self->count     = 0;
    goto test; // FAKE: goto loop keeps the jump to the loop test and the original constant hoisting order
body: {
    s32 j = i; // signed copy of the counter: the original does not strength-reduce blobs[i]
    s32 r;
    func_0205e624(data_021019c4, 0, 17);
    strcpy(data_021019c4, names.n[i]);
    r                 = func_020c6458(Lookup(self->model, 0), data_021019c4);
    self->blobs[j].id = r;
    if (self->blobs[j].id != -1) {
        self->count++;
    }
    i++;
}
test:
    if (i < 10) {
        goto body;
    }
}
