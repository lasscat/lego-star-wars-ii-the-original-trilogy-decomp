#include "m2c.h"

typedef struct Link {
    struct Link **first;
    struct Link *next;
} Link;

typedef struct Owner {
    u8 pad[0x220];
    Link entries[2];
    u8 count;
} Owner;

void func_02025024(Owner *self, Link **arg1) {
    int i;
    for (i = 0; i < self->count; i++) {
        Link **p;
        Link **n;
        Link **a = self->entries[i].first;
        n        = a;
        if (a != 0) {
            n = a - 1;
        }
        if (n != 0) {
            continue;
        }
        if (arg1 != 0) {
            arg1 = arg1 + 1;
        }
        if (a != 0) {
            p = ((volatile Owner *) self)->entries[i].first; // FAKE: volatile cast forces reload of first
            while (*p != self->entries + i) {
                p = &(*p)->next;
            }
            *p = self->entries[i].next;
        }
        if (arg1 != 0) {
            self->entries[i].first = arg1;
            self->entries[i].next  = *arg1;
            *arg1                  = self->entries + i;
        } else {
            self->entries[i].first = 0;
            self->entries[i].next  = 0;
        }
        return;
    }
}
