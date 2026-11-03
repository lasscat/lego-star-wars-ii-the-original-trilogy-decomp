#include "m2c.h"

typedef struct {
    s32 f00;
    s32 f04;
    u8 *f08;
    s32 f0c;
    s32 f10;
    s32 f14;
    u8 f18[1];
} Iter;

extern int func_020e4a8c(void *ctx, Iter *it);
extern void func_020e3254(int addr, Iter *it);
extern void func_020e4ae8(void *ctx, Iter *it);
extern u8 *func_020e30d8(u8 *p, int *out);
extern u8 *func_020e3164(u8 *p, int *out);

static inline u8 *read_addr(u8 *p, void *out) {
    *(u32 *) out = p[0] | (p[1] << 8) | (p[2] << 16) | (p[3] << 24);
    return p + 4;
}

/* Advances it->f08 past the operands of the current action record (varint
 * fields read by func_020e30d8/func_020e3164), then skips type-1 records by
 * their encoded offset. A NULL pointer or a record with bit 0x80 set moves to
 * the next frame via func_020e4a8c/func_020e3254/func_020e4ae8. Returns the
 * record type (low 5 bits), or 0xFF when no frame is left or the type is
 * unknown. */
u8 func_020e3378(Iter *it) {
    u8 *p;
    u8 type;

    for (;;) {
        p = it->f08;
        if (p == NULL || (*p & 0x80)) {
            func_020e3254(func_020e4a8c(it->f18, it), it);
            if (it->f04 == 0) {
                return 0xFF;
            }
            func_020e4ae8(it->f18, it);
            if (it->f08 != NULL) {
                break;
            }
        } else {
            switch (*p & 0x1F) {
                case 2: {
                    int a;
                    p       = func_020e30d8(p + 1, &a);
                    it->f08 = p + 4;
                    break;
                }
                case 3: {
                    int b, a;
                    p       = func_020e30d8(p + 1, &a);
                    p       = func_020e30d8(p, &b);
                    it->f08 = p + 4;
                    break;
                }
                case 4: {
                    int a;
                    p       = func_020e30d8(p + 1, &a);
                    it->f08 = p + 4;
                    break;
                }
                case 5: {
                    int c, b, a;
                    p       = func_020e30d8(p + 1, &a);
                    p       = func_020e3164(p, &b);
                    p       = func_020e3164(p, &c);
                    it->f08 = p + 4;
                    break;
                }
                case 6: {
                    int b, a;
                    p       = func_020e30d8(p + 1, &a);
                    p       = func_020e30d8(p, &b);
                    it->f08 = p + 4;
                    break;
                }
                case 7: {
                    int b, a;
                    p       = func_020e30d8(p + 1, &a);
                    p       = func_020e30d8(p, &b);
                    it->f08 = p + 4;
                    break;
                }
                case 8: {
                    int c, b, a;
                    p       = func_020e30d8(p + 1, &a);
                    p       = func_020e30d8(p, &b);
                    p       = func_020e30d8(p, &c);
                    it->f08 = p + 4;
                    break;
                }
                case 9: {
                    int d, c, b, a;
                    p       = func_020e30d8(p + 1, &a);
                    p       = func_020e30d8(p, &b);
                    p       = func_020e3164(p, &c);
                    p       = func_020e3164(p, &d);
                    it->f08 = p + 4;
                    break;
                }
                case 10: {
                    int a;
                    p       = func_020e30d8(p + 1, &a);
                    it->f08 = p + 4;
                    break;
                }
                case 11: {
                    int b, a;
                    p       = func_020e30d8(p + 1, &a);
                    p       = func_020e30d8(p, &b);
                    it->f08 = p + 4;
                    break;
                }
                case 12: {
                    int b, a;
                    p       = func_020e3164(p + 5, &a);
                    p       = func_020e30d8(p, &b);
                    it->f08 = p;
                    break;
                }
                case 13: {
                    int a;
                    p       = func_020e30d8(p + 1, &a);
                    it->f08 = p;
                    break;
                }
                case 15: {
                    int c, b, a;
                    p       = func_020e3164(p + 1, &a);
                    p       = func_020e3164(p, &b);
                    p       = func_020e30d8(p, &c);
                    it->f08 = p + a * 4;
                    break;
                }
                case 16: {
                    void *d;
                    int c, b, a;
                    p       = func_020e30d8(p + 1, &a);
                    p       = func_020e30d8(p, &b);
                    p       = read_addr(p, &d);
                    p       = func_020e30d8(p, &c);
                    it->f08 = p + 4;
                    break;
                }
                case 17: {
                    int d, c, b, a;
                    p       = func_020e30d8(p + 1, &a);
                    p       = func_020e30d8(p, &c);
                    p       = func_020e30d8(p + 1, &b);
                    p       = func_020e30d8(p, &d);
                    it->f08 = p + 4;
                    break;
                }
                case 18: {
                    int c, b, a;
                    p       = func_020e30d8(p + 1, &a);
                    p       = func_020e30d8(p + 1, &b);
                    p       = func_020e3164(p, &c);
                    it->f08 = p + 4;
                    break;
                }
                case 19: {
                    int a;
                    p       = func_020e30d8(p + 1, &a);
                    it->f08 = p;
                    break;
                }
                default:
                    return 0xFF;
            }
            break;
        }
    }

    {
        int off;
        while ((type = *it->f08 & 0x1F) == 1) {
            func_020e30d8(it->f08 + 1, &off);
            it->f08 += off;
        }
    }
    return type;
}
