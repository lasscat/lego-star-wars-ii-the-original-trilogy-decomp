#include "m2c.h"

typedef struct Item {
    /* 0x00 */ u8 pad0[8];
    /* 0x08 */ s32 pos;
    /* 0x0C */ u8 pad1[0x19];
    /* 0x25 */ s8 kind;
    /* 0x26 */ u8 pad2[2];
    /* 0x28 */ s32 lenA;
    /* 0x2C */ s32 lenB;
} Item;

enum {
    KIND_0 = 0,
    KIND_3 = 3,
    KIND_5 = 5,
    KIND_B = 11,
};

/* Stores to *out a combined extent of two records a and b, selected by their
 * kind byte (+0x25): the offset (+0x08) difference b - a, plus one length
 * field of each record (+0x28 or +0x2C depending on kind), plus 1.
 * Stores 0 when the kind pair is not handled. */
void func_02007f60(s32 *out, Item *a, Item *b) {
    s32 d;

    switch (a->kind) {
        case KIND_0:
            switch (b->kind) {
                case KIND_0:
                    *out = 0;
                    return;
                case KIND_3:
                case KIND_5:
                case KIND_B:
                    break;
            }
            break;
        case KIND_3:
            switch (b->kind) {
                case KIND_0:
                    break;
                case KIND_3:
                    d = b->pos - a->pos;
                    d += a->lenA;
                    d += b->lenA;
                    *out = d + 1;
                    return;
                case KIND_5:
                    d = b->pos - a->pos;
                    d += a->lenA;
                    d += b->lenB;
                    *out = d + 1;
                    return;
                case KIND_B:
                    d = b->pos - a->pos;
                    d += a->lenA;
                    d += b->lenB;
                    *out = d + 1;
                    return;
            }
            break;
        case KIND_5:
            switch (b->kind) {
                case KIND_0:
                    break;
                case KIND_3:
                    d = b->pos - a->pos;
                    d += a->lenB;
                    d += b->lenA;
                    *out = d + 1;
                    return;
                case KIND_5:
                    d = b->pos - a->pos;
                    d += a->lenB;
                    d += b->lenB;
                    *out = d + 1;
                    return;
                case KIND_B:
                    d = b->pos - a->pos;
                    d += a->lenB;
                    d += b->lenB;
                    *out = d + 1;
                    return;
            }
            break;
        case KIND_B:
            switch (b->kind) {
                case KIND_0:
                    break;
                case KIND_3:
                    d = b->pos - a->pos;
                    d += a->lenB;
                    d += b->lenA;
                    *out = d + 1;
                    return;
                case KIND_5:
                    d = b->pos - a->pos;
                    d += a->lenB;
                    d += b->lenB;
                    *out = d + 1;
                    return;
                case KIND_B:
                    d = b->pos - a->pos;
                    d += a->lenB;
                    d += b->lenB;
                    *out = d + 1;
                    return;
            }
            break;
    }
    *out = 0;
}
