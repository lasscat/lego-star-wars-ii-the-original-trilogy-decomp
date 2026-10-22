#include "m2c.h"

/* One halfword struct passed by value (see src/auto/func_020534f4.c). */
typedef struct {
    u16 v;
} HalfWord;

extern void func_020ac278(void *, s32, s32);
extern void func_02053ee8(void *, s32, s32);
extern void func_02053f44(void *, s32);
extern void func_0206d6cc(void *);
extern void func_0206d7fc(void *, s8);
extern void func_020534f4(void *, s32, s32, HalfWord);
extern void func_0205365c(void *, s32);
extern void func_0209bef4(void *, s32 *);
extern M2C_UNK data_027e0874;
extern M2C_UNK data_02101b78;
extern HalfWord data_020f7720;

void func_0209be44(void *self) {
    s32 v;

    func_020ac278(&data_027e0874, 4, 0);
    func_02053ee8(&data_02101b78, 0, 0);
    func_02053f44(&data_02101b78, 0x1000);
    M2C_FIELD(self, s32 *, 0xb4) = 0;
    func_0206d6cc(self + 0x64);
    func_0206d7fc(self + 0x64, 1);
    M2C_FIELD(self, s32 *, 0xb0) = 0;
    v                            = 1;
    func_020534f4(self + 0x2c, 0, 0, data_020f7720);
    func_0205365c(self + 0x2c, 0);
    func_0209bef4(self, &v);
}
