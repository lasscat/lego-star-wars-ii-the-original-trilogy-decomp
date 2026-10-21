#include "m2c.h"

typedef struct {
    u16 v;
} HalfWord;

extern u8 data_02101b98[];
extern u16 data_020edec8;
extern u32 data_027e02a4;
extern u8 data_0210930c[];
extern u8 data_02106d90[];

M2C_UNK func_02053ee8(void *, s32, s32);                      /* extern */
M2C_UNK func_02053f44(void *, s32);                           /* extern */
M2C_UNK func_020534f4(void *, s32, s32, HalfWord);            /* extern */
M2C_UNK func_0205365c(void *, s32);                           /* extern */
M2C_UNK func_02065600(void *, s32);                           /* extern */
M2C_UNK func_02065658(void *, void *);                        /* extern */
M2C_UNK func_02055a18(s32, s32, s32, s32, s32, s32);          /* extern */
M2C_UNK func_0206653c(s32, s32, s32, s32, s32, s32, s32);     /* extern */
M2C_UNK func_0206574c(void *, s32, s32);                      /* extern */
M2C_UNK func_02072f30(void *, s32, s32, s32);                 /* extern */
M2C_UNK func_02093c9c(void *, s32);                           /* extern */
M2C_UNK func_02066168(void *, M2C_UNK);                       /* extern */
M2C_UNK *func_02066708(s32);                                  /* extern */
M2C_UNK func_02065af8(void *, s32, s32, s32, s32, void *, s32, void *); /* extern */
M2C_UNK func_0206d6cc(void *);                                /* extern */
M2C_UNK func_0206d7fc(void *, s8);                            /* extern */
M2C_UNK func_0206f200(void *);                                /* extern */

void func_0206ed3c(void *arg0) {
    u8 *p;
    u32 f;
    u8 i;

    func_02053ee8(data_02101b98, 0, 0);
    func_02053f44(data_02101b98, 0x1000);
    func_0206d6cc(arg0 + 0x28);
    func_0206d7fc(arg0 + 0x28, 1);
    M2C_FIELD(arg0, u8 *, 0x91)  = 0;
    M2C_FIELD(arg0, u16 *, 0x92) = 0;
    func_020534f4(arg0 + 0x84, 1, 0, *(HalfWord *) &data_020edec8);
    func_0205365c(arg0 + 0x84, 0);
    func_02065600(arg0 + 0x54, 4);
    func_02065658(arg0 + 0x54, arg0 + 0x84);
    func_02055a18(0x8f9, 4, 3, 3, 6, 0xf);
    func_0206653c(1, 0, 1, 3, 7, 7, 0);
    func_0206574c(arg0 + 0x54, 6, -1);
    func_02072f30(data_027e02a4, 0xee, 4, 0);
    func_02093c9c(data_0210930c, 1);
    M2C_FIELD(arg0, s32 *, 0x8c) = 1;
    func_02066168(arg0 + 0x54, *(s32 *) (data_02106d90 + 0xad0) + 0x69);
    i                           = 0;
    M2C_FIELD(arg0, u8 *, 0x90) = 0;
    p                           = func_02066708(0x7c);
    f                           = 0x7FFFFFFF;
    while (*p != 0) {
        M2C_FIELD(arg0, s32 *, 0x8c) =
            func_02065af8(arg0 + 0x54, M2C_FIELD(arg0, s32 *, 0x8c), 0x80, i * 0x19 + 8, 0xff, &p, 1, &f);
        i = (u8) (i + 1);
    }
    func_0206f200(arg0);
}
