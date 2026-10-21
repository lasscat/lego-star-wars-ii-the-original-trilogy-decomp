#include "m2c.h"

void func_02074c7c(volatile u8 *base, s32 index, s32 clear);

typedef struct {
    u8 count;
    struct {
        u8 id;
        u8 flags;
    } recs[];
} RecList;

void func_02075540(void ***arg0, s32 arg1, s32 arg2) {
    RecList *arr;
    RecList *sub;
    s32 i;
    s32 j;

    arr = (RecList *) arg0[0][arg1];
    for (i = 0; i < arr->count; i++) {
        func_02074c7c((u8 *) arr, i, arg2);
        sub = (RecList *) arg0[0][arr->recs[i].id];
        for (j = 0; j < sub->count; j++) {
            if (sub->recs[j].id == arg1) {
                func_02074c7c((u8 *) sub, j, arg2);
                break;
            }
        }
    }
}
