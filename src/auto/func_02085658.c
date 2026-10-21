#include "m2c.h"

typedef struct {
    s32 f00;
    s32 f04;
    s32 f08;
} func_02085658_Elem;

typedef struct {
    s32 f000;                    /* 0x000 */
    func_02085658_Elem arr4[4];  /* 0x004 */
    s32 f034[6];                 /* 0x034 */
    u8 f04c[4];                  /* 0x04C */
    u8 f050;                     /* 0x050 */
    s8 f051;                     /* 0x051 */
    u8 f052[0x12];               /* 0x052 */
    u8 f064[0x2A6C];             /* 0x064 */
    s32 f2ad0;                   /* 0x2AD0 */
    s32 f2ad4;                   /* 0x2AD4 */
    s32 f2ad8;                   /* 0x2AD8 */
    u8 f2adc[0xD9];              /* 0x2ADC */
    u8 f2bb5;                    /* 0x2BB5 */
    u8 f2bb6[2];                 /* 0x2BB6 */
    s32 f2bb8;                   /* 0x2BB8 */
    u8 f2bbc[0x1750];            /* 0x2BBC */
    func_02085658_Elem f430c[4]; /* 0x430C */
    u8 f433c[8];                 /* 0x433C */
    func_02085658_Elem f4344[4]; /* 0x4344 */
    u8 f4374[8];                  /* 0x4374 */
    u8 f437c[0x10C];              /* 0x437C */
    s32 f4488[2];                /* 0x4488 */
    u8 f4490[0x1C];              /* 0x4490 */
    u8 f44ac[0x1C];              /* 0x44AC */
    s32 f44c8;                   /* 0x44C8 */
    s32 f44cc[4];                /* 0x44CC */
    s32 f44dc[4];                /* 0x44DC */
    s32 f44ec[8];                /* 0x44EC */
    s32 f450c[2];                /* 0x450C */
    s32 f4514[4];                /* 0x4514 */
} func_02085658_Obj;

extern void func_020e46bc(void *, s32, s32, void (*)(void *), void (*)(void *, s32, s32));
extern void func_0208c5ec(s32 *);
extern void func_020887fc(void *);
extern void func_02095e6c(void *);
extern void func_020b02e0(void *);
extern s32 func_02062dec(s32);
extern void func_02085640(void *);
extern void func_02085654(void *, s32, s32);

void *func_02085658(func_02085658_Obj *arg0) {
    func_02085658_Elem *p;
    s32 i;
    s32 j;
    s32 k;
    s32 l;

    arg0->f000 = 0;
    func_020e46bc(&arg0->arr4[0], 4, 0xC, func_02085640, func_02085654);
    func_0208c5ec(&arg0->f034[0]);
    arg0->f050 = 0;
    arg0->f051 = -1;
    func_020887fc(&arg0->f064[0]);
    func_02095e6c(&arg0->f2adc[0]);
    func_020b02e0(&arg0->f2bbc[0]);

    p = &arg0->f430c[0];
    do {
        p->f00 = 0;
        p->f04 = 0;
        p->f08 = 0;
        p++;
    } while (p < &arg0->f430c[4]);

    p = &arg0->f4344[0];
    do {
        p->f00 = 0;
        p->f04 = 0;
        p->f08 = 0;
        p++;
    } while (p < &arg0->f4344[4]);

    for (i = 0; i < 2; i++) {
        arg0->f4488[i] = 0;
    }
    func_02062dec((s32) &arg0->f4490[0]);
    func_02062dec((s32) &arg0->f44ac[0]);
    arg0->f44c8 = 0x80000000;
    for (j = 0; j < 4; j++) {
        arg0->f44cc[j] = 0;
    }
    for (k = 0; k < 4; k++) {
        arg0->f44dc[k] = 0;
    }
    for (l = 0; l < 8; l++) {
        arg0->f44ec[l] = 0;
    }
    for (i = 0; i < 2; i++) {
        arg0->f450c[i] = 0;
    }
    arg0->f4514[0] = 0;
    arg0->f4514[1] = 0;
    arg0->f4514[2] = 0;
    arg0->f4514[3] = 0;
    arg0->f2bb5    = 0;
    arg0->f2ad0    = 0;
    arg0->f2ad8    = 0;
    arg0->f2ad4    = 0;
    arg0->f2bb8    = 0;
    return arg0;
}
