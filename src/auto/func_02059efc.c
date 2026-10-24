#include "m2c.h"

void func_0205e6e0();
void func_020cf544();
void func_01ff8000();
void func_02059fa8();

typedef struct {
    u32 unk : 4;
    u32 kind : 4;
    u32 size : 24;
} Header;

u32 func_02059efc(Header *src, void *dst) {
    u32 kind = src->kind & ~8;
    u32 size = src->size;

    switch (kind) {
        case 0:
            func_0205e6e0(dst, src + 1, src->size);
            break;
        case 2:
            func_020cf544(src, dst);
            break;
        case 6:
            func_01ff8000(src + 1, dst, &size);
            break;
        case 8:
            break;
    }
    if (src->kind & 8) {
        func_02059fa8(dst, size);
    }
    return src->size;
}
