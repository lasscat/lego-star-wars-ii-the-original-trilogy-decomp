/* Reconstructed from USA ARM9 at 0x02075018 (76 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_0205e84c(s32);                         /* extern */

typedef struct {
    s32 *items;
    s32 count;
} List;

void func_02075018(void *arg0) {
    List *l = (List *) arg0;
    volatile u8 tmp;
    s32 *p   = l->items;
    s32 size = l->count;
    s32 *end = p + size;

    while (p != end) {
        func_0205e84c(*p++);
        size = l->count;
        end  = l->items + size;
    }
    tmp                             = 0;
    M2C_FIELD(l, volatile s32 *, 4) = M2C_FIELD(l, volatile s32 *, 4) - size;
}
