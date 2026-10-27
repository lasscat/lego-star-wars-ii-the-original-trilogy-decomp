/* Reconstructed from USA ARM9 at 0x02075064 (216 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

typedef struct {
    u32 *data;
    u32 size;
    u32 capacity;
} Vec;

typedef struct {
    u8 b;
} Tag;

M2C_UNK func_02075698(Vec *, u32, Tag);   /* extern */
M2C_UNK func_02075710(Vec *, u32 *, Tag); /* extern */

static inline void push_back(Vec *v, u32 *value) {
    volatile s8 tag; // FAKE: dead one-byte temporary kept in its own stack slot
    u32 size;

    tag  = 0;
    size = *(volatile u32 *) &v->size; // FAKE: size is re-read after the tag store
    if (size < v->capacity) {
        u32 n = size + 1;
        u32 *slot;

        v->size = n;
        slot    = &v->data[n - 1];
        *slot   = *value;
        return;
    }
    func_02075710(v, value, (Tag) {0});
}

void func_02075064(Vec *v, u32 value, u32 idx) {
    volatile s8 tag; // FAKE: dead one-byte temporary kept in its own stack slot
    u32 need = idx + 1;

    if (v->capacity < need) {
        u32 size = v->size;
        if (need > size) {
            func_02075698(v, need - size, (Tag) {0});
        } else if (need < size) {
            tag     = 0;
            v->size = *(volatile u32 *) &v->size - (size - need); // FAKE: size is re-read after the tag store
        }
    }
    push_back(v, &value);
}
