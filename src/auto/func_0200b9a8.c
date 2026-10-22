#include "m2c.h"

void func_0200b998(void *); /* extern */

typedef struct {
    u8 counter;
    u8 mode : 7;
    u8 flag : 1;
} Obj;

void func_0200b9a8(Obj *o) {
    switch (o->mode) {
        case 0:
            return;
        case 1:
        case 3:
            o->counter--;
            if (o->counter == 0) {
                func_0200b998(o);
            }
            break;
        case 2:
            if (o->flag == 0) {
                o->counter++;
                if (o->counter == 15) {
                    o->flag = 1;
                }
            } else {
                o->counter--;
                if (o->counter == 0) {
                    o->flag = 0;
                }
            }
            break;
    }
}
