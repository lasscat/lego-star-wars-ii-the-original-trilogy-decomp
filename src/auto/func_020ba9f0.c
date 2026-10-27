#include "m2c.h"

typedef struct {
    u8 kind;
    s32 b;
    s32 c;
} S3;

typedef struct {
    void *ptr;
    u16 id;
    s8 refs;
    u8 f07;
    u8 flags;
    u8 f09;
    u8 f0a;
    u8 pad0b;
    s32 count;
    s32 f10;
    s32 f14;
    s32 f18;
} SndSlot;

typedef struct {
    u16 off;
    u16 pad02;
    u8 b4;
    u8 b5;
    u8 b6;
    u8 b7;
    s32 w8;
    s32 wc;
    s32 w10;
    s32 w14;
    u8 rest[0xc];
} SndHdr;

extern s32 func_0205e540(s32 first, s32 second, s32 value);
extern s32 func_0205e5b0(void *p);
extern void func_020b9cc4(u8 *out, u8 *in, u32 count, u32 wide);
extern void func_020ba778(s32 pos, s32 whence);
extern void *func_020ba798(void *buf, s32 n);
extern void func_020ba7e0();
extern void func_020bace0(SndSlot *src, S3 arg);

extern u8 data_0210db84[];
extern SndSlot data_0210dd98[];
extern u8 data_0210dea4[];

enum {
    SND_NO_ENTRY        = 0xFF,    /* returned when no slot is available or loading fails */
    SND_ID_NONE         = 0xFFFF,   /* id value meaning "no sound" */
    SND_SLOT_LAST       = 23,     /* slots are scanned from index 23 down to 0 */
    SND_SLOT_SIZE       = 0x1C,   /* sizeof(SndSlot) */
    SND_KIND_REFCOUNTED = 7,/* kind whose slot is reference counted and shareable (refs = 1) */
    SND_HDR_SIZE        = 0x24,    /* size of one SndHdr table entry */
    SND_FLAG_PACKED     = 0x8,  /* data is stored compressed and is decoded on load */
    SND_FLAG_WIDE       = 0x2,    /* selects the wide mode passed to func_020b9cc4 */
    SND_F0A_SET         = 0x80,
    SND_F0A_DEFAULT     = 0x20,
    SND_ALLOC_A         = 3,
    SND_ALLOC_B         = 4,
};

/*
 * Loads sound entry `id` from the file table into a free slot (or reuses an
 * already loaded refcounted slot for the same id) and returns the slot index.
 * `arg` is passed on to func_020bace0 after the slot is filled.
 */
s32 func_020ba9f0(u16 id, S3 arg) {
    SndHdr hdr;
    s32 pos;
    SndSlot *slot;
    u8 *p;
    s32 found;
    s32 i;
    u8 *data;
    s32 size;
    s32 decoded;
    s32 count;
    u8 fl;
    s32 width;

    if (id == SND_ID_NONE) {
        return SND_NO_ENTRY;
    }
    found = SND_NO_ENTRY;
    p     = data_0210dea4;
    for (i = SND_SLOT_LAST; i >= 0; p -= SND_SLOT_SIZE, i--) {
        if (*(s32 *) (p + 0x178) == 0) {
            found = i;
        } else if (id == *(u16 *) (p + 0x17C) && *(s8 *) (p + 0x17E) > 0 && arg.kind == SND_KIND_REFCOUNTED) {
            data_0210dd98[i].refs++;
            return i;
        }
    }
    if (found == SND_NO_ENTRY) {
        return SND_NO_ENTRY;
    }
    /* seek to this id's header in the table and read it */
    pos  = *(s32 *) (data_0210db84 + 0x7C) + id * SND_HDR_SIZE;
    slot = &data_0210dd98[found];
    func_020ba778(pos, 0);
    func_020ba798(&hdr, SND_HDR_SIZE);
    slot->id = id;
    if (arg.kind == SND_KIND_REFCOUNTED) {
        slot->refs = 1;
    } else {
        slot->refs = -1;
    }
    slot->f07   = hdr.b4;
    slot->flags = hdr.b5;
    slot->f09   = hdr.b6;
    slot->f0a   = hdr.b7;
    slot->count = hdr.w8;
    slot->f10   = hdr.wc;
    slot->f14   = hdr.w10;
    slot->f18   = hdr.w14;
    if (slot->f0a & SND_F0A_SET) {
        slot->f0a &= ~SND_F0A_SET;
    } else {
        slot->f0a = SND_F0A_DEFAULT;
    }
    func_020ba778(*(s32 *) (data_0210db84 + 0x5C) + hdr.off * 4, 0);
    func_020ba798(&pos, 4);
    func_020ba778(pos, 0);
    if (slot->count != 0) {
        decoded   = 0;
        slot->ptr = 0;
        fl        = slot->flags;
        if (fl & SND_FLAG_PACKED) {
            count = slot->count;
            size  = count << 2;
            if (arg.kind != SND_KIND_REFCOUNTED) {
                slot->flags &= ~SND_FLAG_PACKED;
                width = count << 3;
                if (slot->flags & SND_FLAG_WIDE) {
                    width <<= 1;
                }
                decoded   = 1;
                slot->ptr = (void *) func_0205e540(width, SND_ALLOC_A, SND_ALLOC_B);
                if (slot->ptr == 0) {
                    return SND_NO_ENTRY;
                }
            }
        } else {
            size = slot->count << 2;
        }
        data = (u8 *) func_0205e540(size, SND_ALLOC_A, SND_ALLOC_B);
        if (data == 0) {
            if (slot->ptr != 0) {
                func_0205e5b0(slot->ptr);
                slot->ptr = 0;
            }
            return SND_NO_ENTRY;
        }
        func_020ba798(data, size);
        func_020ba7e0();
        if (decoded == 1) {
            func_020b9cc4(slot->ptr, data, slot->count << 3, (u8) ((slot->flags & SND_FLAG_WIDE) != 0));
            func_0205e5b0(data);
        } else {
            slot->ptr = data;
        }
        func_020bace0(slot, arg);
    } else {
        return SND_NO_ENTRY;
    }
    return found;
}
