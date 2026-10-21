#include "m2c.h"

/* Object list: pointer array plus count; each object has a vtable method at +4. */
typedef struct {
    void **arr;
    u16 count;
    u16 pad6;
} S;

typedef void (*Method)(void *);

extern void func_0205e860(s32);

void func_0205e8d0(S *arg0) {
    u32 i;

    for (i = 0; i < arg0->count; i++) {
        void *obj = arg0->arr[i];
        if (obj != NULL) {
            Method *vtbl = *(Method **) obj;
            vtbl[1](obj);
        }
    }
    if (arg0->arr != NULL) {
        func_0205e860(arg0->arr);
        arg0->arr = NULL;
    }
    arg0->count = 0;
}
