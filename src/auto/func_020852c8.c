#include "m2c.h"

s32 func_02053b14(s32 *);                          /* extern */
void MIi_CpuClearFast(void *, void *, u32);        /* extern */
M2C_UNK *func_02066708(M2C_UNK);                   /* extern */
s32 func_0208671c(s32 *, s32);                     /* extern */
s32 func_02086740(s32 *, s32);                     /* extern */
s32 func_020867ec(s32 *, s32);                     /* extern */
void func_0206574c(void *, s32, s32);              /* extern */
s32 func_02065be8(void *, void *, s32, s32, char *, s32); /* extern */
s32 func_02065840(void *, u8 *);                   /* extern */
void func_02064b10(void *, void *, void *);        /* extern */
extern int sprintf(char *, const char *, ...);
extern char *strcat(char *, const char *);

extern s32 data_02104d90;
extern char data_020ff400[];
extern char data_020ff408[];

typedef struct {
    u8 pad00[0x0c];
    void *f0c;
    s32 *f10;
    s32 f14;
    s32 f18;
    s32 f1c;
    u32 f20;
    u8 pad24[0x0c];
    u8 f30[0xc];
} Unk_020852c8;

void func_020852c8(Unk_020852c8 *p) {
    char buf[0x40];
    char *text;
    s32 prev;
    s32 y;
    u8 *entry;
    s32 id;
    s16 v[4];

    prev = p->f14;
    y    = 0x20;
    MIi_CpuClearFast(NULL, func_02053b14(p->f10) + 0x100, 0x440);
    entry = p->f30;
    text  = buf;

    id = p->f20;
    while (id < 0x12 && id < p->f20 + 8) {
        sprintf(text, data_020ff400, func_02066708(id + 0x243));
        if (func_0208671c(&data_02104d90, id) != 0) {
            strcat(text, func_02066708(func_020867ec(&data_02104d90, id) + 0x53));
        } else {
            strcat(text, func_02066708(0x240));
        }
        strcat(text, data_020ff408);
        if (p->f1c == id) {
            func_0206574c(p->f0c, 3, -2);
        } else {
            if (!func_02086740(&data_02104d90, id)) {
                func_0206574c(p->f0c, 9, -2);
            } else {
                func_0206574c(p->f0c, 0, -2);
            }
        }
        prev = func_02065be8(p->f0c, prev, 0x80, y, text, 1);
        v[2] = func_02065840(p->f0c, text);
        v[3] = 0xe;
        v[0] = 0x80;
        v[0] -= (v[2] + 1) / 2;
        v[1] = y;
        func_02064b10(entry, &v[0], &v[2]);
        y += 0x10;
        id++;
        entry += 0xc;
    }
}
