/* Reconstructed from USA ARM9 at 0x0206fe00 (0x164 bytes).
 *
 * Constructor-like initialiser: it creates the scene manager, resets the
 * render lists held by the global display state and fills in the camera /
 * viewport parameters of the object it is given.
 *
 * The fourth argument of func_020534f4 is a one halfword struct passed by
 * value, so the value read from the global data_020edef0 is copied through a
 * stack slot before it is handed over.
 */
#include "m2c.h"

/* One halfword struct passed by value (see src/auto/func_020534f4.c). */
typedef struct {
    u16 v;
} HalfWord;

extern void func_02072ad8(void);
extern void func_02053ee8(void *a, s32 b, s32 c);
extern void func_02053f44(void *a, s32 b);
extern void func_020867a4(void *a);
extern void func_02087088(void *a);
extern void func_0206d6cc(void *a);
extern void func_0206d7fc(void *a, s8 b);
extern void func_020534f4(void *a, s32 b, s32 c, HalfWord d);
extern void func_0205365c(void *a, s32 b);
extern void func_02065600(void *a, s32 b);
extern void func_02065658(void *a, void *b);
extern void func_0206574c(void *a, s32 b, s32 c);
extern void func_0206653c(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g);
extern void func_02055a18(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
extern void func_020701a0(void *a);
extern void func_02072f30(s32 a, s32 b, s32 c, s32 d);

extern M2C_UNK data_02101b98;
extern M2C_UNK data_02104d90;
extern HalfWord data_020edef0;
extern M2C_UNK data_027e02a4;

void func_0206fe00(void *self) {
    func_02072ad8();
    M2C_FIELD(self, s32 *, 0xa0) = 1;
    M2C_FIELD(self, s32 *, 0x9c) = 1;
    func_02053ee8(&data_02101b98, 0, 0);
    func_02053f44(&data_02101b98, 0x1000);
    M2C_FIELD(self, s32 *, 0x94) = -1;
    M2C_FIELD(self, u8 *, 0x98)  = 1;
    func_020867a4(&data_02104d90);
    func_02087088(&data_02104d90);
    func_0206d6cc(self + 0x30);
    func_0206d7fc(self + 0x30, 1);
    func_020534f4(self + 0x28, 1, 0, data_020edef0);
    func_0205365c(self + 0x28, 0);
    func_02065600(self + 0x5c, 4);
    func_02065658(self + 0x5c, self + 0x28);
    func_0206574c(self + 0x5c, 3, -1);
    func_0206653c(1, 0, 1, 3, 6, 7, 0);
    func_02055a18(0x8f9, 4, 3, 3, 6, 15);
    func_0206574c(self + 0x5c, 0, -2);
    func_020701a0(self);
    func_02072f30(M2C_FIELD(&data_027e02a4, s32 *, 0), 0xee, 4, 0);
    M2C_FIELD(self, s32 *, 0x8c) = 0;
}
