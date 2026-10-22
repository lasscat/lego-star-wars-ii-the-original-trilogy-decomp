#include "m2c.h"

extern void func_02067af0(void *);
extern void func_02067b00(void *, u8, void *);
extern void *func_020e4600(void *, int, int, int, void (*)(void *), void (*)(void *));

/* Element list: 8 byte records {void *ptr; u8 flag;} built by func_02067b00. */
typedef struct {
    u8 pad0[0xc];
    u8 *elems;
    u8 pad10[0x1c - 0x10];
    u16 count;
} ElemList;

/* Chunk allocator: keeps the pointer to the last allocated chunk. */
typedef struct {
    u8 pad0[0xc];
    u8 *chunk;
} ChunkList;

/* Offset table: u16 offsets at 0x10 + off, followed by one byte per entry. */
typedef struct {
    u8 pad0[0xa];
    u16 off;
    u8 padC[4];
    u8 data[1];
} OffTable;

void func_02067440(ElemList *a, ChunkList *b, OffTable *c) {
    u16 *tab;
    u8 *bytes;
    u8 *p;
    u32 i;
    u16 off;

    if (a->count == 0) {
        return;
    }
    p = b->chunk;
    if (p != 0) {
        p = func_020e4600(p, a->count, 8, 0, func_02067af0, 0);
    }
    a->elems = p;
    b->chunk += a->count * 8 + 8;
    tab   = (u16 *) (c->data + c->off);
    bytes = (u8 *) tab + a->count * 2;
    for (i = 0; i < a->count; i++) {
        off = tab[i];
        func_02067b00(a->elems + i * 8, bytes[i], (u8 *) tab + off);
    }
}
