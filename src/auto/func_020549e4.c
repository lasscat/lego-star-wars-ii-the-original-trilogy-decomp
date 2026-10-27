#include "m2c.h"

/*
 * func_020549e4: load one indexed graphics resource and return its size.
 *
 * Evidence from the callees:
 *   - func_0205ab58(id) looks up the resource header (id 0xffff = none: the
 *     result is cleared to {0, 0} and nothing is loaded).
 *   - func_02054db8(header) maps the 2-bit header class to a leading block of
 *     0x200, 0x20 or 0 bytes; func_02054da8(header) returns the data after the
 *     2-byte header. With FLAG_FULL_BANK the bank step is 0x100 entries,
 *     otherwise 0x10, matching 0x200/0x20 bytes of u16 entries, so the leading
 *     block is handled first by func_02054954 (entry count = bytes >> 1,
 *     capped by max_count) unless FLAG_SKIP_LEAD is set or the block is empty.
 *   - The rest of the data is handled per header kind:
 *       kind 1:    func_02054858 (unless FLAG_SKIP_KIND1);
 *       kind 2, 6: size from func_02054674 (full load) or func_02054178 (only read
 *                  the packed size, FLAG_SIZE_ONLY), step past that block
 *                  (func_02054194), then fall into kind 4 (kind 2 sets
 *                  FLAG_SKIP_TAIL);
 *       kind 4:    func_02054900 (unless FLAG_SKIP_TAIL).
 *   - vram_select reaches the callees' (vram_select << 21) + 0x06000000 base.
 *   - The result is the size returned by the kind's callee (20.12 fixed point,
 *     x and y), or {0, 0}.
 */

typedef struct {
    s32 x;
    s32 y;
} Pair;

typedef struct {
    u8 x;
    u8 y;
    u8 cols;
    u8 rows;
} P4;

typedef struct {
    u16 f0 : 2;
    u16 c : 4;
    u16 f6 : 2;
    u16 d : 5;
    u16 f13 : 1;
    u16 e : 2;
} Info;

typedef struct {
    u16 f0 : 2;
    u16 kind : 3;
    u16 b : 2;
    u16 f7 : 5;
    u16 n : 4;
} TileHdr;

typedef struct {
    u16 *ptr;
} UnkCursor;

extern TileHdr *func_0205ab58(u32 id);
extern s32 func_02054db8(TileHdr *p);
extern u8 *func_02054da8(TileHdr *p);
extern void func_02054954(TileHdr *p, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7);
extern void func_02054858(Pair *out, u8 *p, u32 a, ...);
extern void func_02054178(Pair *out, u8 *p);
extern s32 func_02054194(u8 *p, s32 flag);
extern void func_02054674(Pair *out, u8 *a1, s32 a2, s32 a3, s32 a4, P4 p, s16 *hdr, u32 add, u32 add2, u32 add3);
extern void func_02054900(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);

enum {
    ID_NONE            = 0xffff,
    DEFAULT_MAX_COUNT  = 0x100,
    FULL_BANK_ENTRIES  = 0x100,
    SMALL_BANK_ENTRIES = 0x10,
    PACKED_SIZE_BYTES  = 4,
};

enum {
    FLAG_SKIP_LEAD  = 0x1,
    FLAG_SIZE_ONLY  = 0x2,
    FLAG_SKIP_TAIL  = 0x4,
    FLAG_SKIP_KIND1 = 0x8,
    FLAG_10         = 0x10,
    FLAG_20         = 0x20,
    FLAG_FULL_BANK  = 0x40,
    FLAG_80         = 0x80,
    FLAG_100        = 0x100,
};

static inline void pair_clear(Pair *p) {
    p->x = 0;
    p->y = 0;
}

void func_020549e4(Pair *out, u32 vram_select, Info info, u32 id, u32 flags, u32 s74, s32 s78, s32 s7c, s32 s80, s32 max_count,
                   s16 *hdr, P4 p) {
    Pair kind1_size;
    Pair drawn_size;
    s16 hh[2];
    Pair packed_size;
    TileHdr *header;
    u8 *data;
    Pair result;
    s32 bank_offset;
    s32 lead_bytes;

    if (id == ID_NONE) {
        pair_clear(out);
        return;
    }
    if (max_count <= 0) {
        max_count = DEFAULT_MAX_COUNT;
    }
    header      = func_0205ab58(id);
    bank_offset = header->n * ((flags & FLAG_FULL_BANK) ? FULL_BANK_ENTRIES : SMALL_BANK_ENTRIES);
    s80 += bank_offset;
    s7c += bank_offset;
    lead_bytes = func_02054db8(header);
    if (lead_bytes == 0) {
        flags |= FLAG_SKIP_LEAD;
    }
    if (!(flags & FLAG_SKIP_LEAD)) {
        func_02054954(header, lead_bytes >> 1, max_count, (flags & FLAG_FULL_BANK) ? 1 : 0, s78, s7c, s80, vram_select);
    }
    data     = func_02054da8(header) + lead_bytes;
    result.x = 0;
    result.y = 0;
    switch (header->kind) {
        case 1:
            if (!(flags & FLAG_SKIP_KIND1)) {
                func_02054858(&kind1_size, data, vram_select);
                result.x = kind1_size.x;
                result.y = kind1_size.y;
            }
            break;
        case 2:
            flags |= FLAG_SKIP_TAIL;
        case 6:
            if (!(flags & FLAG_SIZE_ONLY)) {
                s32 add2;
                s32 mode;
                s16 *hp;
                if (flags & FLAG_100) {
                    add2 = (flags & FLAG_FULL_BANK) ? s7c >> 8 : s7c >> 4;
                } else {
                    add2 = 0;
                }
                hp    = hh;
                hp[0] = hdr[0];
                hp[1] = hdr[1];
                if (flags & FLAG_80) {
                    mode = 2;
                } else if (flags & FLAG_10) {
                    mode = 1;
                } else {
                    mode = 0;
                }
                func_02054674(&drawn_size, data, info.d, info.e, mode, p, hp, s74, add2, vram_select);
                result.x = drawn_size.x;
                result.y = drawn_size.y;
            } else {
                func_02054178(&packed_size, data);
                result.x = packed_size.x;
                result.y = packed_size.y;
            }
            data += func_02054194(data, (flags & FLAG_10) ? 1 : 0) + PACKED_SIZE_BYTES;
        case 4:
            if (!(flags & FLAG_SKIP_TAIL)) {
                func_02054900(data, info.c, s74, (flags & FLAG_20) ? 1 : 0, header->b, vram_select);
            }
            break;
    }
    pair_clear(out);
    out->x = result.x;
    out->y = result.y;
}
