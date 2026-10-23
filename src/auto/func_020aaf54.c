/* Reconstructed from USA ARM9 at 0x020aaf54 (596 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

typedef struct Chunk {
    void *f00;
    u8 pad04[0x08];
    u16 f0c;
    u16 f0e;
} Chunk;

typedef struct Node {
    u32 f00;
    u8 pad04[0x0c];
    Chunk *f10;
} Node;

typedef struct Obj {
    Chunk *f00;
    Chunk *f04;
    u8 *f08;
    void *f0c;
    u16 f10;
    u8 pad12[0x02];
    u16 f14;
} Obj;

extern M2C_UNK data_021027f4;
extern M2C_UNK data_0210a0b4;
extern M2C_UNK data_0210a07c;

extern void func_0205af6c(void **, void *, u16 *);
extern void func_0205b1e0(void *, Chunk *, s32);
extern Chunk *func_0205ab30(u16);
extern s32 func_020c293c(Chunk *);
extern Chunk *func_020c6578(Chunk *);
extern void func_0201c778(u16 *);
extern u8 *func_020abe14(void *, void *, u16 *);
extern s32 func_020ab900(Obj *, void *, void *);
extern void func_020ab8e4(Obj *, Chunk *, void *);
extern void func_020c4070(Chunk *, void *);
extern void func_020c61e0(u8 *, s32, s32);
extern void func_020c6240(u8 *, s32, s32);
extern u8 *func_020abc58(void *, u16);
extern void func_020abbec(void *, Obj *);
extern void DC_FlushRange(Chunk *, s32);

/* Address of the per-stream data block inside a chunk header. */
#define CHUNK_DATA(base) ((u8 *) (base) + *(u32 *) ((u8 *) (base) + ((Chunk *) (base))->f0e + 0xc))

void func_020aaf54(Obj *self, u16 arg1) {
    u16 values[5];
    void *entry;
    Node *found;
    u16 key;
    void *table;
    Chunk *chunk;
    u8 *ptr;
    u32 *p;
    void *val;

    self->f10 = arg1;
    key       = self->f10;
    table     = *(void **) &data_021027f4;
    func_0205af6c(&entry, table, &key);
    found = entry;
    if (found != (Node *) ((u8 *) table + 4)) {
        func_0205b1e0(table, found->f10, 1);
        chunk = found->f10->f00;
    } else {
        chunk = 0;
    }
    self->f00 = chunk;
    if (chunk == 0) {
        self->f00 = func_0205ab30(self->f10);
        DC_FlushRange(self->f00, func_020c293c(self->f00) + 0x20);
        self->f04 = func_020c6578(self->f00);
        p         = (u32 *) ((u8 *) self->f00 + self->f00->f0c);
        if (self->f00->f0e == 1) {
            val = (M2C_FIELD(self->f00, u32 *, 0) == 0x30585442) ? (u8 *) self->f00 + p[0] : NULL;
        } else {
            val = (u8 *) self->f00 + p[1];
        }
        self->f0c = val;
        if (val != 0) {
            func_0201c778(values);
            self->f08 = func_020abe14(&data_0210a0b4, self->f0c, values);
            if (func_020ab900(self, self->f0c, self->f08) != 0) {
                func_020ab8e4(self, self->f00, self->f0c);
            }
            func_020c4070(self->f04, self->f0c);
        }
    } else {
        self->f04 = func_020c6578(chunk);
        p         = (u32 *) ((u8 *) self->f00 + self->f00->f0c);
        if (self->f00->f0e == 1) {
            val = (M2C_FIELD(self->f00, u32 *, 0) == 0x30585442) ? (u8 *) self->f00 + p[0] : NULL;
        } else {
            val = (u8 *) self->f00 + p[1];
        }
        self->f0c = val;
        if (val != 0) {
            ptr       = func_020abc58(&data_0210a07c, self->f10);
            self->f08 = ptr;
            if (*(u8 *) (ptr + 0xc) & 4) {
                self->f14 |= 1;
            }
        }
    }
    if (self->f0c != 0) {
        func_020c61e0(CHUNK_DATA(self->f04), 0, 0x40);
        func_020c61e0(CHUNK_DATA(self->f04), 0, 0x80);
    }
    func_020c6240(CHUNK_DATA(self->f04), 0, 0x3f000000);
    func_020c6240(CHUNK_DATA(self->f04), 0, 0x8000);
    func_020abbec(&data_0210a07c, self);
}
