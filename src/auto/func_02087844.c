#include "m2c.h"

typedef void (*Method)(void *);
typedef struct VObj {
    Method *vtbl;
} VObj;

typedef struct Owner {
    u8 pad0[0x28];
    u8 data28[0x40];
    u8 data68[0x5c];
    VObj *obj;
    u8 flag_c8;
    u8 flag_c9;
    u8 padca[0x1e];
    u8 sub[1];
} Owner;

void *func_0205e80c(s32, s32, s32);
void *func_02075d00(void *, void *);
void *func_020682c4(void *, void *, void *, void *, s32, s32, u8);
void *func_0207a9c4(void *, void *, void *, void *);
void *func_0209e7dc(void *, void *, void *);
s32 func_0208877c(void *);
s32 func_02088754(void *);
u16 func_02088790(void *);
u16 func_02088774(void *);
void func_0208837c(void *, s32, s32);
void func_02088734(void *);
s32 func_0208868c(void *);
void func_020b8f70(s32, s32);
void func_02075fe0(void *);
void func_02088574(void *);
void func_020536a8(void *, s32);
void func_020691a0(void *);
void func_0208816c(void *);

enum {
    KIND_0_SIZE = 0x28,
    KIND_1_SIZE = 0x38,
    KIND_2_SIZE = 0x50,
    KIND_3_SIZE = 0x34,
    ALLOC_ARG_B = 3,
    ALLOC_ARG_C = 4,
};

/* Per-frame step. While the sub-object at 0xe8 reports a pending kind, the old
   object at 0xc4 is released through virtual slot 1 and a replacement of that
   kind (0..3) is allocated and constructed; returns 0 when handled, else 1. */
s32 func_02087844(Owner *self) {
    s32 result = 1;
    s32 kind;
    void *p;

    if (func_0208877c(self->sub) != 0) {
        if (func_02088754(self->sub) != 0) {
            kind   = func_02088790(self->sub);
            result = kind;
            func_0208837c(self->sub, kind, self->flag_c8);
            if (self->obj != NULL) {
                self->obj->vtbl[1](self->obj);
            }
            self->obj = NULL;
            switch (kind) {
                case 0:
                    p = func_0205e80c(KIND_0_SIZE, ALLOC_ARG_B, ALLOC_ARG_C);
                    if (p != NULL) {
                        p = func_02075d00(p, self);
                    }
                    self->obj = p;
                    break;
                case 1:
                    p = func_0205e80c(KIND_1_SIZE, ALLOC_ARG_B, ALLOC_ARG_C);
                    if (p != NULL) {
                        p = func_020682c4(p, self, self->data28, self->data68, -1, -1, self->flag_c8);
                    }
                    self->obj     = p;
                    self->flag_c9 = 1;
                    break;
                case 2:
                    p = func_0205e80c(KIND_2_SIZE, ALLOC_ARG_B, ALLOC_ARG_C);
                    if (p != NULL) {
                        p = func_0207a9c4(p, self, self->data28, self->data68);
                    }
                    self->obj = p;
                    break;
                case 3:
                    p = func_0205e80c(KIND_3_SIZE, ALLOC_ARG_B, ALLOC_ARG_C);
                    if (p != NULL) {
                        p = func_0209e7dc(p, self, self->data28);
                    }
                    self->obj = p;
                    break;
            }
            result = 0;
        }
    } else if (func_02088790(self->sub) != 4) {
        func_02088734(self->sub);
    } else if (func_0208868c(self->sub) != 4) {
        func_020b8f70(0xb4, 0);
        if (func_02088774(self->sub) == 0) {
            func_02075fe0(self->obj);
            func_02088574(self->sub);
        } else if (func_02088774(self->sub) == 1) {
            func_020536a8(self->data28, 0);
            func_020691a0(self->obj);
            func_0208816c(self);
        } else if (func_02088774(self->sub) == 3) {
            func_020536a8(self->data28, 0);
        }
    } else {
        result = 0;
    }
    return result;
}
