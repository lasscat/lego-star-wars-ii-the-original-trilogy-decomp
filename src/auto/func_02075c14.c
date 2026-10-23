/* Reconstructed from USA ARM9 at 0x02075c14 (236 bytes).
 *
 * Collects the objects of a list that are close enough to the target and
 * sorts them by distance:
 *  - ctx->entries[] holds {object, distance} pairs (8 bytes each, 32 slots),
 *    ctx->radius is the search radius and ctx->count the number of hits.
 *  - func_0200f5d0() measures the squared distance and returns non-zero when
 *    the object is inside the radius; the distance is written through the
 *    last argument.
 *  - func_020dde64() is the engine's quicksort; its fifth argument is the
 *    scratch stack it uses, so a 48 byte buffer (6 words per level, 6 levels
 *    for 32 elements) is passed on the stack.
 */
#include "m2c.h"

s32 func_0200f5d0(void *a, void *b, s32 r, s32 *out);
void func_020dde64(void *base, u32 n, u32 size, s32 (*cmp)(void *, void *), void *stack);
s32 func_02075bc0(void *a, void *b);

typedef struct {
    void *obj;
    s32 dist;
} Entry;

typedef struct {
    Entry entries[32];
    s32 radius;
    u32 count;
} Ctx;

typedef struct ListNode {
    void *obj;
    struct ListNode *next;
} ListNode;

typedef struct {
    u32 pad;
    ListNode *head;
} List;

void func_02075c14(Ctx *ctx, void *target, List *list) {
    s32 dist;
    void *stack[12];
    ListNode *node;

    ctx->count = 0;
    dist       = 0;
    for (node = list->head; node != NULL && ctx->count < 0x20; node = node->next) {
        void *obj = node->obj;
        if (obj == target) {
            continue;
        }
        if ((M2C_FIELD(obj, u16 *, 0xc) & 0x17) == 0) {
            continue;
        }
        if ((M2C_FIELD(obj, u32 *, 8) & 0x100803) != 0x100001) {
            continue;
        }
        if (func_0200f5d0((void *) ((u8 *) target + 0xb0), (void *) ((u8 *) obj + 0xb0), ctx->radius, &dist) == 0) {
            continue;
        }
        ctx->entries[ctx->count].obj  = obj;
        ctx->entries[ctx->count].dist = dist;
        ctx->count++;
    }
    if (ctx->count <= 1) {
        return;
    }
    func_020dde64(ctx->entries, ctx->count, 8, func_02075bc0, stack);
}
