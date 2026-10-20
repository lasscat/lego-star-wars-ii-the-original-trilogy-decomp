#include "m2c.h"

/* One 16-byte entry of the linked VRAM block pool.
 * 0x00: block size, 0x04: block alignment,
 * 0x08: pointer to the previous block, 0x0C: pointer to the next block.
 */
typedef struct {
    s32 size;
    s32 align;
    void *prev;
    void *next;
} GfdVramBlock;

/* Initialises a pool of `count` blocks as a doubly linked list. */
GfdVramBlock *NNSi_GfdInitLnkVramBlockPool(GfdVramBlock *pool, u32 count) {
    s32 i;
    for (i = 0; i < count - 1; i++) {
        pool[i].next     = &pool[i + 1];
        pool[i + 1].prev = &pool[i];
    }
    pool[0].prev         = NULL;
    pool[count - 1].next = NULL;
    return pool;
}
