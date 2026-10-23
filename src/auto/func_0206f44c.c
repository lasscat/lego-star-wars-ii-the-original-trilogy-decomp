#include "m2c.h"

/* One halfword struct passed by value (see func_020534f4). */
typedef struct {
    u16 v;
} HalfWord;

/* Owner information block filled in by OS_GetOwnerInfo. */
typedef struct {
    u8 head[4];
    char name[0x14];
    u16 language;
    u8 mid[0x34];
    u16 tail;
} OwnerInfo;

extern void func_02053ee8(void *a, s32 b, s32 c);
extern void func_02053f44(void *a, s32 b);
extern void func_0206d6cc(void *a);
extern void func_0206d7fc(void *a, s8 b);
extern void func_020534f4(void *a, s32 b, s32 c, HalfWord d);
extern void func_0205365c(void *a, s32 b);
extern void func_02065600(void *a, s32 b);
extern void func_02065658(void *a, void *b);
extern void func_0206574c(void *a, s32 b, s32 c);
extern void func_0206653c(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g);
extern void func_02055a18(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
extern void func_0206f748(void *a);
extern void func_02072f30(s32 a, s32 b, s32 c, s32 d);
extern void func_0209bd08(s32 a, s32 b, void *c, s32 d);
extern void OS_GetOwnerInfo(void *a);

extern M2C_UNK data_02101b98;
extern HalfWord data_020ededc;
extern u8 data_02106d90[];
extern u32 data_027e02a4;

void func_0206f44c(void *self) {
    OwnerInfo owner;

    func_02053ee8(&data_02101b98, 0, 0);
    func_02053f44(&data_02101b98, 0x1000);
    func_0206d6cc(self + 0x30);
    func_0206d7fc(self + 0x30, 1);
    func_020534f4(self + 0x28, 1, 0, data_020ededc);
    func_0205365c(self + 0x28, 0);
    func_02065600(self + 0x5c, 4);
    func_02065658(self + 0x5c, self + 0x28);
    func_0206574c(self + 0x5c, 3, -1);
    func_0206653c(1, 0, 1, 3, 6, 7, 0);
    func_02055a18(0x8f9, 4, 3, 3, 6, 15);
    func_0206574c(self + 0x5c, 0, -2);
    func_0206f748(self);
    func_02072f30(*(s32 *) &data_027e02a4, 0xee, 4, 0);
    *(s32 *) (self + 0x8c) = 0;
    *(u8 *) (self + 0x90)  = *(s32 *) (self + 0x10);
    *(s32 *) (self + 0x94) = 1;
    OS_GetOwnerInfo(&owner);
    func_0209bd08(*(s32 *) (data_02106d90 + 0xad0), 0, owner.name, owner.language & 0xff);
}
