#include "m2c.h"

typedef struct Slot {
    u8 data[0x340];
    u8 count;
    u8 pad[3];
} Slot;

typedef struct Obj {
    u8 pad[0x70];
    Slot a[3];
    Slot b[4];
} Obj;

struct Src;
typedef struct SrcVtbl {
    u32 *(*get)(struct Src *, s32);
} SrcVtbl;
typedef struct Src {
    SrcVtbl *vtbl;
} Src;

extern Src *data_021092f4;
extern s32 func_020ad1f0(u32 *);
extern void func_0205e6e0(void *dst, void *src, u32 size);

void func_020b070c(Obj *self) {
    s32 n;
    u8 i;
    u8 j;
    u32 *buf;
    u32 *src;
    u8 len;

    if (data_021092f4 == 0) {
        return;
    }
    n = func_020ad1f0(data_021092f4->vtbl->get(data_021092f4, 0));
    for (i = 0; i < n; i++) {
        j = 0;
        if (data_021092f4 == 0) {
            return;
        }
        while (1) {
            buf = data_021092f4->vtbl->get(data_021092f4, i);
            len = ((u8 *) buf)[j * 4];
            if (len == 0 || j >= 24) {
                break;
            }
            src = &buf[j];
            j += len;
            func_0205e6e0(&self->b[i].data[self->b[i].count * 4], src, len * 4);
            self->b[i].count += len;
        }
    }
}
