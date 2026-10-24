/* Reconstructed from USA ARM9 at 0x020bace0 (200 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

extern void *func_0205e624(void *dst, u32 value, u32 size);
extern void func_020ba104(void *a0);
extern void func_020ba4b8(void *a0, void *a1, s32 a2);

typedef struct Unk020bace0Src {
    s32 head;
    u8 pad_04[4];
    u8 flags;
    u8 pad_09[3];
    s32 count;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
} Unk020bace0Src;

typedef struct Unk020bace0Pair {
    s32 first;
    s32 second;
} Unk020bace0Pair;

typedef struct Unk020bace0Arg {
    u8 kind;
    Unk020bace0Pair p;
} Unk020bace0Arg;

typedef struct Unk020bace0Work {
    Unk020bace0Arg arg;
    u8 data[0x20];
} Unk020bace0Work;

typedef struct Unk020bace0Out {
    s32 head;
    s32 zero;
    s32 size;
    u8 data[0x20];
    u8 flag;
} Unk020bace0Out;

void func_020bace0(Unk020bace0Src *src, Unk020bace0Arg arg) {
    Unk020bace0Work work;
    Unk020bace0Out out;
    s32 count;
    s32 size;

    if (arg.kind == 7) {
        return;
    }
    count = src->count;
    if (src->flags & 2) {
        out.flag = 1;
        size     = count << 1;
    } else {
        out.flag = 0;
        size     = count << 2;
    }
    work.arg.kind = arg.kind;
    work.arg.p    = arg.p;
    if (work.arg.kind >= 3 && work.arg.kind < 7 && work.arg.p.second == 0) {
        work.arg.p.second = src->unk_18;
    }
    out.zero = 0;
    out.head = src->head;
    out.size = size;
    func_0205e624(out.data, 0, 0x20);
    func_020ba104(&work);
    func_020ba4b8(&work, &out, size);
}
