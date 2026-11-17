#include "m2c.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

typedef struct {
    s32 year;
    s32 month;
    s32 day;
    s32 week;
} Date;

typedef struct {
    s32 hour;
    s32 minute;
    s32 second;
} Time;

typedef struct {
    u8 v[6];
} Entry6;

typedef struct {
    Date date;
    Time time;
} DateTime;

typedef struct {
    s32 f0000;          /* 0x0000 */
    u8 pad0004[0x30];   /* 0x0004 */
    s32 f0034;          /* 0x0034 */
    u8 pad0038[0x1A];   /* 0x0038 */
    Entry6 f0052[3];    /* 0x0052 */
    u8 pad0064[0x2A78]; /* 0x0064 */
    s32 f2adc;          /* 0x2ADC */
    u8 pad2ae0[0xC6];   /* 0x2AE0 */
    u8 f2ba6[10];       /* 0x2BA6 */
    s16 f2bb0;          /* 0x2BB0 */
    u8 f2bb2;           /* 0x2BB2 */
    u8 f2bb3;           /* 0x2BB3 */
    u8 f2bb4;           /* 0x2BB4 */
    u8 pad2bb5;         /* 0x2BB5 */
    u8 f2bb6;           /* 0x2BB6 */
    u8 pad2bb7[0x1755]; /* 0x2BB7 */
    Vec3 f430c[4];      /* 0x430C */
    u8 f433c[4];        /* 0x433C */
    s8 f4340[4];        /* 0x4340 */
    Vec3 f4344[4];      /* 0x4344 */
    u8 pad4374[0xC8];   /* 0x4374 */
    u8 f443c;           /* 0x443C */
    u8 pad443d[0x4B];   /* 0x443D */
    s32 f4488[2];       /* 0x4488 */
    DateTime dt;        /* 0x4490 */
    DateTime dt2;       /* 0x44AC */
    s32 f44c8;          /* 0x44C8 */
    s32 f44cc[4];       /* 0x44CC */
    s32 f44dc[4];       /* 0x44DC */
    s32 f44ec[8];       /* 0x44EC */
    s32 f450c[2];       /* 0x450C */
    s32 f4514;          /* 0x4514 */
    s32 f4518;          /* 0x4518 */
    u32 f451c;          /* 0x451C */
    u32 f4520;          /* 0x4520 */
    u8 f4524[0x39];     /* 0x4524 */
    u8 pad455d[3];      /* 0x455D */
    s8 f4560;           /* 0x4560 */
} Obj;

extern "C" {
extern const u32 data_020f86f8[];
extern Vec3 data_020ff9b4;

void *func_0205e624(void *dst, u32 value, u32 size);
void func_02062e38(void *arg0);
void func_02086330(Obj *arg0);
void func_020863a4(Obj *arg0);
void func_020863e4(Obj *arg0);
void func_02086e1c(void *base, s32 bit);
void func_0208c60c(s32 *arg0);
void func_02095e8c(void *arg0);

static inline void set_flag(Obj *obj, s32 bit) {
    u32 mask   = 1U << (bit & 0x1F);
    u32 *table = &obj->f451c;
    table[bit >> 5] &= ~mask;
    table[bit >> 5] |= mask;
}

static inline void vec_set(Vec3 *d, const Vec3 *s) {
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

void func_02085948(Obj *arg0) {

    s32 i;

    u8 j;

    u32 k;
    u32 n;
    s32 y;
    s32 month;
    s32 days;
    s32 idx;
    Date *d;
    Time *t;

    func_02062e38(&arg0->dt);
    arg0->f4560 = -1;
    arg0->f2bb6 = 0;
    for (j = 0; j < 4; j++) {
        arg0->f4340[j] = -1;
    }
    for (i = 0; i < 2; i++) {
        arg0->f4488[i] = 0;
    }
    func_0208c60c(&arg0->f0034);
    func_0205e624(arg0->f4524, 0, sizeof(arg0->f4524));
    func_0205e624(arg0->f2ba6, 0, sizeof(arg0->f2ba6));
    arg0->f2bb0 = 0x28;
    arg0->f0000 = 0;
    func_02095e8c(&arg0->f2adc);
    arg0->f4514 = 0;
    arg0->f4518 = 0;
    for (i = 0; i < 2; i++) {
        arg0->f450c[i] = 0;
    }
    for (i = 0; i < 8; i++) {
        arg0->f44ec[i] = 0;
    }
    arg0->f451c = 0;
    arg0->f4520 = 0;
    set_flag(arg0, 0x10);
    set_flag(arg0, 0x11);
    arg0->f2bb4 = 0;
    func_02086e1c(arg0, 0);
    for (i = 0; i < 4; i++) {
        arg0->f44cc[i] = 0;
    }
    for (i = 0; i < 4; i++) {
        arg0->f44dc[i] = 0;
    }
    func_02086330(arg0);
    func_020863a4(arg0);
    func_020863e4(arg0);
    arg0->f443c = 0;
    arg0->f2bb2 = 0xE;
    arg0->f2bb3 = 0;
    arg0->dt2   = arg0->dt;
    d           = &arg0->dt2.date;
    t           = &arg0->dt2.time;

    days  = d->day;
    month = d->month;
    y     = d->year + 2000;
    idx   = month - 1;
    y -= 2000;
    days += y * 365 + (y >> 2);
    days += data_020f86f8[idx];
    days += ((y & 3) != 0 || month > 2);
    arg0->f44c8 = (days - 1) * 86400 + 0x80000000 + (t->second + (t->minute * 60 + t->hour * 3600));

    for (k = 0; k < 4; k++) {
        vec_set(&arg0->f4344[k], &data_020ff9b4);
    }
    for (n = 0; n < 3; n++) {
        arg0->f0052[n].v[0] = 8;
        arg0->f0052[n].v[1] = 0x90;
        arg0->f0052[n].v[2] = 0x41;
        arg0->f0052[n].v[3] = 0xB2;
        arg0->f0052[n].v[4] = 0xFA;
        arg0->f0052[n].v[5] = 0x1A;
    }
    for (j = 0; j < 4; j++) {
        vec_set(&arg0->f430c[j], &data_020ff9b4);
        arg0->f433c[j] = 0xFF;
    }
}
}
