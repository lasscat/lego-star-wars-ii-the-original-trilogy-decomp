#include "m2c.h"

typedef struct {
    u8 v;
} Tag;

typedef struct {
    s32 *begin;
    s32 size;
    s32 cap;
} Vec;

void func_02093eac(Vec *, u32, Tag);
void *func_02093e68(Vec *);
void *memcpy(void *, const void *, int);
void *memset(void *, int, int);

static inline void swap_s32(s32 *a, s32 *b) {
    s32 t = *a;
    *a    = *b;
    *b    = t;
}

static inline void swap_ptr(s32 **a, s32 **b) {
    s32 *t = *a;
    *a     = *b;
    *b     = t;
}

static inline void tag_use(Tag t) {}

void func_02093d88(Vec *self, u32 n) {
    Vec tmp;
    s32 *old;
    s32 bytes;
    s32 cnt;
    s32 *pcap;

    tmp.begin = 0;
    tmp.size  = 0;
    tmp.cap   = 0;
    func_02093eac(&tmp, n, (Tag) {0});
    old   = self->begin;
    cnt   = (s32) ((u8 *) (old + self->size) - (u8 *) old) / 4; // FAKE: byte difference stops folding to size*4
    bytes = cnt * 4;
    tag_use((Tag) {0}); // FAKE: empty by-value inline reproducing the dead byte store of an allocator temp
    memcpy(tmp.begin + tmp.size, old, bytes);
    memset(old, 0, bytes);
    tmp.size += cnt;
    tag_use((Tag) {0}); // FAKE: empty by-value inline reproducing the dead byte store of an allocator temp
    self->size = 0;
    pcap       = &tmp.cap; // FAKE: pointer local keeps the cap swap addressed through a register
    swap_s32(&self->cap, pcap);
    swap_ptr(&self->begin, &tmp.begin);
    swap_s32(&self->size, &tmp.size);
    func_02093e68(&tmp);
}
